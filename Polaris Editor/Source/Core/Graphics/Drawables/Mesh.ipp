template<unsigned int V_N, unsigned int I_N>
Mesh::Mesh(const std::array<Vertex, V_N>& vertices, const std::array<unsigned short, I_N>& indices, const Texture& diffuseTexture, const Texture& specularTexture)
	: m_VertexBuffer(vertices), m_IndexBuffer(indices)
	, m_IndexCount(I_N)
	, m_DiffuseTexture(diffuseTexture), m_SpecularTexture(m_SpecularTexture)
	, m_UpdateDiffuseTexture(false), m_UpdateSpecularTexture(false)
{
}
template<unsigned int V_N, unsigned int I_N>
Mesh::Mesh(const std::array<Vertex, V_N>& vertices, const std::array<unsigned int, I_N>& indices, const Texture& diffuseTexture, const Texture& specularTexture)
	: m_VertexBuffer(vertices), m_IndexBuffer(indices)
	, m_IndexCount(I_N)
	, m_DiffuseTexture(diffuseTexture), m_SpecularTexture(specularTexture)
	, m_UpdateDiffuseTexture(false), m_UpdateSpecularTexture(false)
{
}
template<unsigned int N>
Mesh::Mesh(const std::vector<Vertex>& vertices, const std::array<unsigned short, N>& indices, const Texture& diffuseTexture, const Texture& specularTexture)
	: m_VertexBuffer(vertices), m_IndexBuffer(indices)
	, m_IndexCount(N)
	, m_DiffuseTexture(diffuseTexture), m_SpecularTexture(specularTexture)
	, m_UpdateDiffuseTexture(false), m_UpdateSpecularTexture(false)
{
}
template<unsigned int N>
Mesh::Mesh(const std::vector<Vertex>& vertices, const std::array<unsigned int, N>& indices, const Texture& diffuseTexture, const Texture& specularTexture)
	: m_VertexBuffer(vertices), m_IndexBuffer(indices)
	, m_IndexCount(N)
	, m_DiffuseTexture(diffuseTexture), m_SpecularTexture(specularTexture)
	, m_UpdateDiffuseTexture(false), m_UpdateSpecularTexture(false)
{
}