#include "pch.h"

#include "Window.h"

#include "Logger.h"

#include "Widgets/ImGui/imgui_impl_dx11.h"
#include "Widgets/ImGui/imgui_impl_win32.h"

const char* CLASS_NAME = "Polaris Editor";

Window::Window(unsigned int width, unsigned int height, const std::string& title, bool resizable)
	: m_Width(width), m_Height(height)
	, m_Title(title)
	, m_Resizable(resizable)
	, m_Instance(GetModuleHandle(NULL)), m_Handle(NULL)
	, m_Message({ })
	, m_Open(false) 
{
	WNDCLASSEX windowClass { };
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_OWNDC | CS_VREDRAW | CS_HREDRAW;
	windowClass.lpfnWndProc = WindowProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = m_Instance;
	windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = NULL;
	windowClass.lpszMenuName = nullptr;
	windowClass.lpszClassName = CLASS_NAME;
	windowClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	POLARIS_ASSERT(RegisterClassEx(&windowClass), "Failed to register WNDCLASSEX!");

	POLARIS_ASSERT((m_Handle = CreateWindowEx(NULL, CLASS_NAME, m_Title.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, m_Width, m_Height, NULL, NULL, m_Instance, this)), "Failed to create window!");

	ShowWindow(m_Handle, SW_SHOWDEFAULT);
	UpdateWindow(m_Handle);

	Mouse::SetWindow(*this);

	Graphics::Initialize(*this);

	ImGui::CreateContext();

	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard | ImGuiConfigFlags_DockingEnable | ImGuiConfigFlags_ViewportsEnable;
	io.ConfigViewportsNoTaskBarIcon = true;
	io.ConfigViewportsNoDefaultParent = true;
	io.ConfigDockingAlwaysTabBar = true;
	io.ConfigDockingTransparentPayload = true;

	ImGui::StyleColorsDark();

	ImGui_ImplWin32_Init(m_Handle);
	ImGui_ImplDX11_Init(Graphics::GetDevice().Get(), Graphics::GetDeviceContext().Get());

	m_Open = true;
}
Window::~Window()
{
	POLARIS_ASSERT(UnregisterClass(CLASS_NAME, m_Instance), "Failed to unregister window class!");
}

void Window::Update()
{
	while (PeekMessage(&m_Message, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&m_Message);
		DispatchMessage(&m_Message);
	}

	Keyboard::Update();
	Mouse::Update();
}

void Window::Close()
{
	m_Open = false;
}

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

LRESULT Window::WindowProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	if (Msg == WM_NCCREATE)
	{
		Window* window = reinterpret_cast<Window*>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);

		SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window));
		SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(Window::WindowProcAdapter));
	
		return window->HandleEvents(hWnd, Msg, wParam, lParam);
	}
	
	return DefWindowProc(hWnd, Msg, wParam, lParam);
}
LRESULT Window::WindowProcAdapter(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	return reinterpret_cast<Window*>(GetWindowLongPtr(hWnd, GWLP_USERDATA))->HandleEvents(hWnd, Msg, wParam, lParam);
}

LRESULT Window::HandleEvents(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, Msg, wParam, lParam)) return true;

	switch (Msg)
	{
	case WM_ACTIVATEAPP:
		Keyboard::HandleInput(Msg, wParam, lParam);
		Mouse::HandleInput(Msg, wParam, lParam);
		break;

	case WM_KEYDOWN:
	case WM_SYSKEYDOWN:
	case WM_KEYUP:
	case WM_SYSKEYUP:
		Keyboard::HandleInput(Msg, wParam, lParam);
		break;

	case WM_INPUT:
	case WM_MOUSEMOVE:
	case WM_LBUTTONDOWN:
	case WM_LBUTTONUP:
	case WM_RBUTTONDOWN:
	case WM_RBUTTONUP:
	case WM_MBUTTONDOWN:
	case WM_MBUTTONUP:
	case WM_MOUSEWHEEL:
	case WM_XBUTTONDOWN:
	case WM_XBUTTONUP:
	case WM_MOUSEHOVER:
		Mouse::HandleInput(Msg, wParam, lParam);
		break;

	case WM_CLOSE:
		PostQuitMessage(0);

		m_Open = false;

		POLARIS_ASSERT(DestroyWindow(m_Handle), "Failed to destroy window!");
		break;
	}

	return DefWindowProc(hWnd, Msg, wParam, lParam);
}