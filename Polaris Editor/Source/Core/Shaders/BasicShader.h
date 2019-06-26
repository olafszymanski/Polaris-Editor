#pragma once

#include "../../Utils/NonCopyable.h"

#include "../Graphics.h"

#include "../Types/WorldViewProjection.h"
#include "../Buffers/ConstantBuffer.h"

class BasicShader : public NonCopyable, protected Graphics
{
public:
	BasicShader();
	~BasicShader() = default;

	void UpdateWorldViewProjection(const WorldViewProjection& worldViewProjection);

private:
	const wchar_t* m_VertexShaderSource = L"Resources/Shaders/Compiled/BasicVertexShader.cso";
	const wchar_t* m_PixelShaderSource = L"Resources/Shaders/Compiled/BasicPixelShader.cso";

	Microsoft::WRL::ComPtr<ID3D11VertexShader> m_VertexShader;
	Microsoft::WRL::ComPtr<ID3D11PixelShader> m_PixelShader;

	Microsoft::WRL::ComPtr<ID3D11InputLayout> m_InputLayout;

	WorldViewProjection m_WorldViewProjection;
	ConstantBuffer<WorldViewProjection> m_WorldViewProjectionBuffer;
};