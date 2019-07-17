#pragma once

#include "Drawable.h"

#include "Mesh.h"

class Object : public Drawable
{
public:
	Object(const Mesh& mesh, const DirectX::SimpleMath::Vector3& position = { 0.0f, 0.0f, 0.0f }, const DirectX::SimpleMath::Vector3& rotation = { 0.0f, 0.0f, 0.0f }, const DirectX::SimpleMath::Vector3& scale = { 1.0f, 1.0f, 1.0f });
	~Object() = default;

	Object(const Object& other);
	Object& operator=(const Object& other);

	virtual void Bind() const override;

	virtual void Update() override;

	// Getters
	inline virtual const unsigned int& GetIndexCount() const override { return m_Mesh.GetIndexCount(); }

	inline const DirectX::SimpleMath::Vector3& GetPosition() const { return m_Position; }
	inline const DirectX::SimpleMath::Vector3& GetRotation() const { return m_Position; }
	inline const DirectX::SimpleMath::Vector3& GetScale() const { return m_Position; }

	inline virtual const DirectX::SimpleMath::Matrix& GetMatrix() const override { return m_Matrix; }

	// Setters
	inline void SetPosition(const DirectX::SimpleMath::Vector3& position) 
	{ 
		m_Position = position;
		
		m_UpdateMatrix = true;
	}
	inline void SetRotation(const DirectX::SimpleMath::Vector3& rotation) 
	{ 
		m_Rotation = rotation;
	
		m_UpdateMatrix = true;
	}
	inline void SetScale(const DirectX::SimpleMath::Vector3& scale) 
	{ 
		m_Scale = scale;

		m_UpdateMatrix = true;
	}

protected:
	Mesh m_Mesh;

	DirectX::SimpleMath::Vector3 m_Position;
	DirectX::SimpleMath::Vector3 m_Rotation;
	DirectX::SimpleMath::Vector3 m_Scale;

	DirectX::SimpleMath::Matrix m_Matrix;

private:
	bool m_UpdateMatrix;
};