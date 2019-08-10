#pragma once

enum class LightType
{
	NONE, DIRECTIONAL, POINT, SPOT
};

class Light
{
public:
	// Getters
	inline const LightType& GetType() const { return m_Type; }

	inline const float& GetIntensity() const { return m_Intensity; }

	inline const DirectX::SimpleMath::Vector4& GetAmbient() const { return m_Ambient; }
	inline const DirectX::SimpleMath::Vector4& GetDiffuse() const { return m_Diffuse; }
	inline const DirectX::SimpleMath::Vector4& GetSpecular() const { return m_Specular; }

	// Setters
	inline void SetIntensity(float intensity) { m_Intensity = intensity; }

	inline void SetAmbient(const DirectX::SimpleMath::Vector4& ambient) { m_Ambient = ambient; }
	inline void SetDiffuse(const DirectX::SimpleMath::Vector4& diffuse) { m_Diffuse = diffuse; }
	inline void SetSpecular(const DirectX::SimpleMath::Vector4& specular) { m_Specular = specular; }

	inline void SetColor(const DirectX::SimpleMath::Vector3& color) 
	{ 
		m_Ambient.x = color.x;
		m_Ambient.y = color.y;
		m_Ambient.z = color.z;
		m_Ambient.w = 1.0f;

		m_Diffuse.x = color.x;
		m_Diffuse.y = color.y;
		m_Diffuse.z = color.z;
		m_Diffuse.w = 1.0f;

		m_Specular.x = color.x;
		m_Specular.y = color.y;
		m_Specular.z = color.z;
		m_Specular.w = 1.0f;
	}

protected:
	LightType m_Type;
	DirectX::SimpleMath::Vector2 m_TypePadding;
	
	float m_Intensity;

	DirectX::SimpleMath::Vector4 m_Ambient, m_Diffuse, m_Specular;

protected:
	Light();
	Light(const LightType& type, const DirectX::SimpleMath::Vector4& ambient, const DirectX::SimpleMath::Vector4& diffuse, const DirectX::SimpleMath::Vector4& specular, float intensity);
	Light(const LightType& type, const DirectX::SimpleMath::Vector3& color, float intensity);
	~Light() = default;

	Light(const Light& other);
	Light& operator=(const Light& other);
};