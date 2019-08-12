#include "pch.h"

#include "ResourceManager.h"

std::unordered_map<std::string, std::shared_ptr<Texture>> ResourceManager::m_Textures { };

std::unordered_map<std::string, std::shared_ptr<Model>> ResourceManager::m_Models { };

bool ResourceManager::TextureExists(const std::string& filePath)
{
	for (const auto& texture : m_Textures)
	{
		if (texture.first == filePath) return true;
	}

	return false;
}
void ResourceManager::AddTexture(const Texture& texture, const std::string& filePath)
{
	m_Textures.insert_or_assign(filePath, std::make_shared<Texture>(texture));
}
const Texture& ResourceManager::GetTexture(const std::string& filePath)
{
	return *m_Textures[filePath].get();
}

bool ResourceManager::ModelExists(const std::string& filePath)
{
	for (const auto& model : m_Models)
	{
		if (model.first == filePath) return true;
	}

	return false;
}
void ResourceManager::AddModel(const Model& model, const std::string& filePath)
{
	m_Models.insert_or_assign(filePath, std::make_shared<Model>(model));
}
const Model& ResourceManager::GetModel(const std::string& filePath)
{
	return *m_Models[filePath].get();
}