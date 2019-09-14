template<unsigned int N>
void Renderer::PushObjects(const std::array<Object*, N>& objects)
{
	for (auto& object : objects)
	{
		m_Objects.push_back(object);
	}
}