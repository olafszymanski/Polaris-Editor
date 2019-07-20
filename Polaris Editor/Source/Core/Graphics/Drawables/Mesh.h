#pragma once

struct Vertex;

#include "../Buffers/VertexBuffer.h"
#include "../Buffers/IndexBuffer.h"

#include "../Textures/Texture.h"

class Mesh
{
public:
	template<unsigned int V_N, unsigned int I_N>
	Mesh(const std::array<Vertex, V_N>& vertices, const std::array<unsigned short, I_N>& indices, const Texture& diffuseTexture, const Texture& specularTexture);
	template<unsigned int V_N, unsigned int I_N>
	Mesh(const std::array<Vertex, V_N>& vertices, const std::array<unsigned int, I_N>& indices, const Texture& diffuseTexture, const Texture& specularTexture);
	template<unsigned int N>
	Mesh(const std::vector<Vertex>& vertices, const std::array<unsigned short, N>& indices, const Texture& diffuseTexture, const Texture& specularTexture);
	template<unsigned int N>
	Mesh(const std::vector<Vertex>& vertices, const std::array<unsigned int, N>& indices, const Texture& diffuseTexture, const Texture& specularTexture);
	Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned short>& indices, const Texture& diffuseTexture, const Texture& specularTexture);
	Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, const Texture& diffuseTexture, const Texture& specularTexture);
	~Mesh() = default;

	Mesh(const Mesh& other);
	Mesh& operator=(const Mesh& other);

	void Bind() const;

	void Update();

	// Getters
	inline const unsigned int& GetIndexCount() const { return m_IndexCount; }

	inline const Texture& GetDiffuseTexture() const { return m_DiffuseTexture; }
	inline const Texture& GetSpecularTexture() const { return m_SpecularTexture; }

	// Setters
	inline void SetDiffuseTexture(const Texture& texture) 
	{
		m_DiffuseTexture = texture;

		m_UpdateDiffuseTexture = true;
	}
	inline void SetSpecularTexture(const Texture& texture)
	{
		m_SpecularTexture = texture;

		m_UpdateSpecularTexture = true;
	}

private:
	VertexBuffer m_VertexBuffer;
	IndexBuffer m_IndexBuffer;

	unsigned int m_IndexCount;

	Texture m_DiffuseTexture, m_SpecularTexture;
	bool m_UpdateDiffuseTexture, m_UpdateSpecularTexture;
};

#include "Mesh.ipp"