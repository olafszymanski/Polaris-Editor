#pragma once

#include "Object.h"

#include "../Textures/Texture.h"

class TexturedObject : public Object
{
public:
	TexturedObject(const Mesh& mesh, const Texture& texture, const DirectX::SimpleMath::Vector3& position = { 0.0f, 0.0f, 0.0f }, const DirectX::SimpleMath::Vector3& rotation = { 0.0f, 0.0f, 0.0f }, const DirectX::SimpleMath::Vector3& scale = { 1.0f, 1.0f, 1.0f });
	~TexturedObject() = default;

	TexturedObject(const TexturedObject& other);
	TexturedObject& operator=(const TexturedObject& other);

	virtual void Bind() const override;

	virtual void Update() override;

	// Getter
	inline Texture GetTexture() const { return m_Texture; }

	// Setter
	inline void SetTexture(const Texture& texture) 
	{ 
		m_Texture = texture;

		m_UpdateTexture = true;
	}

protected:
	Texture m_Texture;

private:
	bool m_UpdateTexture;
};