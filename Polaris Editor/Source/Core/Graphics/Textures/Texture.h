#pragma once

class Texture
{
public:
	Texture(const std::string& filePath);
	Texture(int width, int height, const DirectX::SimpleMath::Vector4& color);
	~Texture() = default;

	Texture(const Texture& other);
	Texture& operator=(const Texture& other);

	void Bind(unsigned int slot = 0) const;

private:
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_ShaderTextureView;
};