template<unsigned int V_N, unsigned int I_N>
Mesh::Mesh(const std::array<VertexStructure, V_N>& vertices, const std::array<unsigned short, I_N>& indices, const MaterialStructure& material, const Texture& diffuseTexture, const Texture& specularTexture)
	: m_VertexBuffer(vertices), m_IndexBuffer(indices)
	, m_IndexCount(I_N)
	, m_Material(material)
	, m_DiffuseTexture(diffuseTexture), m_SpecularTexture(m_SpecularTexture)
	, m_UpdateDiffuseTexture(false), m_UpdateSpecularTexture(false)
{
}
template<unsigned int V_N, unsigned int I_N>
Mesh::Mesh(const std::array<VertexStructure, V_N>& vertices, const std::array<unsigned int, I_N>& indices, const MaterialStructure& material, const Texture& diffuseTexture, const Texture& specularTexture)
	: m_VertexBuffer(vertices), m_IndexBuffer(indices)
	, m_IndexCount(I_N)
	, m_Material(material)
	, m_DiffuseTexture(diffuseTexture), m_SpecularTexture(specularTexture)
	, m_UpdateDiffuseTexture(false), m_UpdateSpecularTexture(false)
{
}
template<unsigned int N>
Mesh::Mesh(const std::vector<VertexStructure>& vertices, const std::array<unsigned short, N>& indices, const MaterialStructure& material, const Texture& diffuseTexture, const Texture& specularTexture)
	: m_VertexBuffer(vertices), m_IndexBuffer(indices)
	, m_IndexCount(N)
	, m_Material(material)
	, m_DiffuseTexture(diffuseTexture), m_SpecularTexture(specularTexture)
	, m_UpdateDiffuseTexture(false), m_UpdateSpecularTexture(false)
{
}
template<unsigned int N>
Mesh::Mesh(const std::vector<VertexStructure>& vertices, const std::array<unsigned int, N>& indices, const MaterialStructure& material, const Texture& diffuseTexture, const Texture& specularTexture)
	: m_VertexBuffer(vertices), m_IndexBuffer(indices)
	, m_IndexCount(N)
	, m_Material(material)
	, m_DiffuseTexture(diffuseTexture), m_SpecularTexture(specularTexture)
	, m_UpdateDiffuseTexture(false), m_UpdateSpecularTexture(false)
{
}