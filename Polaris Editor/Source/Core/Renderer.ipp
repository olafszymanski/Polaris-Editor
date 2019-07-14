template<unsigned int N>
void Renderer::PushDrawables(const std::array<Drawable*, N>& drawables)
{
	for (auto& drawable : m_Objects)
	{
		drawable->Bind();

		m_BasicShader.Bind();

		drawable->Update();

		m_BasicShader.UpdateWorldViewProjection(drawable->GetMatrix());

		Graphics::GetDeviceContext()->DrawIndexed(drawable->GetIndexCount(), 0, 0);
	}

	for (auto& drawable : m_TexturedObjects)
	{
		drawable->Bind();

		m_TextureShader.Bind();

		drawable->Update();

		m_TextureShader.UpdateWorldViewProjection(drawable->GetMatrix());

		Graphics::GetDeviceContext()->DrawIndexed(drawable->GetIndexCount(), 0, 0);
	}
}