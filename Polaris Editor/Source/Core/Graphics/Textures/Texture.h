#pragma once

class Texture
{
public:
	Texture(const std::string& filePath);
	Texture(unsigned int width, unsigned int height, const DirectX::SimpleMath::Vector4& color);
	Texture(unsigned int size, const uint8_t* data);
	~Texture() = default;

	Texture(const Texture& other);
	Texture& operator=(const Texture& other);

	void Bind(unsigned int slot = 0) const;

	// Getter
	inline const std::string& GetFilePath() const { return m_FilePath; }

	inline const Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>& GetShaderTextureView() const { return m_ShaderTextureView; }

private:
	std::string m_FilePath;

	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_ShaderTextureView;
};