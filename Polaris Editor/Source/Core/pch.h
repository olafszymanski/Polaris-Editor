#pragma once

#include <iostream>
#include <memory>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>

#include <d3d11.h>
#include <d3dcompiler.h>

#include <Keyboard.h>
#include <Mouse.h>

#include <SimpleMath.h>

#include <Windows.h>
#include <wrl.h>

#include <assimp/scene.h>
#include <assimp/cimport.h>
#include <assimp/postprocess.h>
#include <assimp/material.h>

#include "Graphics/Widgets/ImGui/imgui.h"

#define __FILENAME__ (std::strrchr(__FILE__, '\\') ? std::strrchr(__FILE__, '\\') + 1 : __FILE__)

#define MAX_DIRECTIONAL_LIGHTS 32
#define MAX_POINT_LIGHTS 256
#define MAX_SPOT_LIGHTS 256