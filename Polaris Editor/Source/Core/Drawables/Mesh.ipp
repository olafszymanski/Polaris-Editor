template<unsigned int V_N, unsigned int I_N>
Mesh::Mesh(const std::array<BasicVertex, V_N>& vertices, const std::array<unsigned short, I_N>& indices)
	: m_VertexBuffer(vertices), m_IndexBuffer(indices)
	, m_IndexCount(I_N)
{
}
template<unsigned int V_N, unsigned int I_N>
Mesh::Mesh(const std::array<BasicVertex, V_N>& vertices, const std::array<unsigned int, I_N>& indices)
	: m_VertexBuffer(vertices), m_IndexBuffer(indices)
	, m_IndexCount(I_N)
{
}
template<unsigned int N>
Mesh::Mesh(const std::vector<BasicVertex>& vertices, const std::array<unsigned short, N>& indices)
	: m_VertexBuffer(vertices), m_IndexBuffer(indices)
	, m_IndexCount(N)
{
}
template<unsigned int N>
Mesh::Mesh(const std::vector<BasicVertex>& vertices, const std::array<unsigned int, N>& indices)
	: m_VertexBuffer(vertices), m_IndexBuffer(indices)
	, m_IndexCount(N)
{
}