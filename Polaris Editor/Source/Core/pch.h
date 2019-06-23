#pragma once

#include <iostream>
#include <memory>

#include <string>
#include <sstream>
#include <vector>

#include <d3d11.h>
#include <d3dcompiler.h>

#include <Keyboard.h>
#include <Mouse.h>

#include <DirectXMath.h> 

#include <Windows.h>
#include <wrl.h>

#define __FILENAME__ (std::strrchr(__FILE__, '\\') ? std::strrchr(__FILE__, '\\') + 1 : __FILE__)