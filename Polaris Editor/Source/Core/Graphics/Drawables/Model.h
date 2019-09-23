#pragma once

#include "Mesh.h"

class Model
{
public:
	Model(const std::string& filePath);
	~Model() = default;

	Model(const Model& other);
	Model& operator=(const Model& other);

	// Getters
	inline const std::vector<std::shared_ptr<Mesh>>& GetMeshes() const { return m_Meshes; }

	inline const std::string& GetName() const { return m_Name; }

	// Setter
	inline void SetName(const std::string& name) { m_Name = name; }

private:
	std::vector<std::shared_ptr<Mesh>> m_Meshes;

	std::string m_Name;

private:
	MaterialStructure GetMaterial(aiMaterial* material);
	Texture GetMaterialTexture(const aiScene* scene, const aiMaterial* material, aiTextureType type, const std::string& directory);
};