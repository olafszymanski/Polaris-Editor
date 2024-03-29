#include "pch.h"

#include "Model.h"

#include "../Managers/ResourceManager.h"

#include "../../../Utils/StringHelper.h"

Model::Model(const std::string& filePath)
	: m_Meshes({ })
	, m_Name(StringHelper::GetFileName(filePath))
{
	if (ResourceManager::ModelExists(filePath)) *this = ResourceManager::GetModel(filePath);
	else
	{
		const aiScene* scene = aiImportFile(filePath.c_str(), aiProcess_Triangulate | aiProcess_ConvertToLeftHanded | aiProcess_GenUVCoords | aiProcess_GenSmoothNormals);

		POLARIS_WARNING(!scene, "Failed to load '" + filePath + "'!");

		m_Meshes.reserve(scene->mNumMeshes);

		for (unsigned int i = 0; i < scene->mNumMeshes; ++i)
		{
			std::vector<VertexStructure> vertices { };
			std::vector<unsigned int> indices { };

			aiMesh* mesh = scene->mMeshes[i];

			vertices.reserve(mesh->mNumVertices);

			for (unsigned int j = 0; j < mesh->mNumVertices; ++j)
			{
				VertexStructure vertex;
				vertex.Position.x = mesh->mVertices[j].x;
				vertex.Position.y = mesh->mVertices[j].y;
				vertex.Position.z = mesh->mVertices[j].z;
				if (mesh->mTextureCoords[0])
				{
					vertex.TextureCoordinate.x = mesh->mTextureCoords[0][j].x;
					vertex.TextureCoordinate.y = mesh->mTextureCoords[0][j].y;
				}
				vertex.Normal.x = mesh->mNormals[j].x;
				vertex.Normal.y = mesh->mNormals[j].y;
				vertex.Normal.z = mesh->mNormals[j].z;

				vertices.push_back(vertex);
			}

			for (unsigned int k = 0; k < mesh->mNumFaces; ++k)
			{
				aiFace face = mesh->mFaces[k];

				indices.reserve(face.mNumIndices);

				for (unsigned int l = 0; l < face.mNumIndices; ++l)
				{
					indices.push_back(face.mIndices[l]);
				}
			}

			aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

			std::string directory = StringHelper::GetDirectoryFromPath(filePath);

			Texture diffuse = GetMaterialTexture(scene, material, aiTextureType_DIFFUSE, directory);
			Texture specular = GetMaterialTexture(scene, material, aiTextureType_SPECULAR, directory);

			m_Meshes.push_back(std::make_shared<Mesh>(vertices, indices, GetMaterial(material), diffuse, specular, std::string(mesh->mName.C_Str())));
		}

		aiReleaseImport(scene);

		ResourceManager::AddModel(*this, filePath);
	}
}

Model::Model(const Model& other)
	: m_Meshes(other.m_Meshes)
	, m_Name(other.m_Name)
{
}
Model& Model::operator=(const Model& other)
{
	if (this != &other)
	{
		m_Meshes = other.m_Meshes;

		m_Name = other.m_Name;
	}

	return *this;
}

MaterialStructure Model::GetMaterial(aiMaterial* material)
{
	float shininess = 0.0f;

	aiGetMaterialFloat(material, AI_MATKEY_SHININESS, &shininess);

	return MaterialStructure({ 1.0f, 1.0f, 1.0f }, shininess );
}
Texture Model::GetMaterialTexture(const aiScene* scene, const aiMaterial* material, aiTextureType type, const std::string& directory)
{
	unsigned int textureCount = material->GetTextureCount(type);

	std::unique_ptr<Texture> texture = nullptr;

	if (textureCount > 0)
	{
		aiString filename;
		material->GetTexture(type, 0, &filename);

		if (filename.C_Str()[0] == '*')
		{
			POLARIS_ASSERT(filename.length > 1, "There's something wrong with texture!");

			int index = atoi(&filename.C_Str()[1]);
			texture = std::make_unique<Texture>(scene->mTextures[index]->mWidth, reinterpret_cast<uint8_t*>(scene->mTextures[index]->pcData));
		}
		else if (auto embeddedTexture = scene->GetEmbeddedTexture(filename.C_Str())) texture = std::make_unique<Texture>(embeddedTexture->mWidth, reinterpret_cast<uint8_t*>(embeddedTexture->pcData));
		else texture = std::make_unique<Texture>(directory + static_cast<std::string>(filename.C_Str()));
	}
	else
	{
		aiColor4D color;

		switch (type)
		{
		case aiTextureType_DIFFUSE:
			aiGetMaterialColor(material, AI_MATKEY_COLOR_DIFFUSE, &color);
			break;
		case aiTextureType_SPECULAR:
			aiGetMaterialColor(material, AI_MATKEY_COLOR_SPECULAR, &color);
			break;
		}

		texture = std::make_unique<Texture>(1, 1, DirectX::SimpleMath::Vector4(color.r, color.g, color.b, color.a));
	}

	return *texture.get();
}