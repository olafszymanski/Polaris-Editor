#pragma once

#include "Mesh.h"

class Model
{
public:
	Model(const std::string& filePath);
	~Model() = default;

	Model(const Model& other);
	Model& operator=(const Model& other);

	// Getter
	inline const std::vector<std::shared_ptr<Mesh>>& GetMeshes() const { return m_Meshes; }

private:
	std::vector<std::shared_ptr<Mesh>> m_Meshes;

private:
	Material GetMaterial(aiMaterial* material);
	Texture GetMaterialTexture(const aiScene* scene, const aiMaterial* material, aiTextureType type, const std::string& directory);
};