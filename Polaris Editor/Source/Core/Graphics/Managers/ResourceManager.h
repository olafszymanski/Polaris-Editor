#pragma once

#include "../Textures/Texture.h"

#include "../Drawables/Model.h"

class ResourceManager
{
public:
	static bool TextureExists(const std::string& filePath);
	static void AddTexture(const Texture& texture, const std::string& filePath);
	static const Texture& GetTexture(const std::string& filePath);

	static bool ModelExists(const std::string& filePath);
	static void AddModel(const Model& model, const std::string& filePath);
	static const Model& GetModel(const std::string& filePath);

private:
	static std::unordered_map<std::string, std::shared_ptr<Texture>> m_Textures;

	static std::unordered_map<std::string, std::shared_ptr<Model>> m_Models;

private:
	ResourceManager() = default;
	~ResourceManager() = default;
};