#pragma once

#include "Model.h"

class Object
{
public:
	Object(const Model& model, const DirectX::SimpleMath::Vector3& position = { 0.0f, 0.0f, 0.0f }, const DirectX::SimpleMath::Vector3& rotation = { 0.0f, 0.0f, 0.0f }, const DirectX::SimpleMath::Vector3& scale = { 1.0f, 1.0f, 1.0f });
	~Object() = default;

	Object(const Object& other);
	Object& operator=(const Object& other);

	void Bind(unsigned int index) const;

	void UpdateMatrix();
	void UpdateMesh(unsigned int index);

	// Getters
	inline const Model& GetModel() const { return m_Model; }

	inline const DirectX::SimpleMath::Vector3& GetPosition() const { return m_Position; }
	inline const DirectX::SimpleMath::Vector3& GetRotation() const { return m_Position; }
	inline const DirectX::SimpleMath::Vector3& GetScale() const { return m_Position; }

	inline const DirectX::SimpleMath::Matrix& GetMatrix() const { return m_Matrix; }

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

private:
	Model m_Model;

	DirectX::SimpleMath::Vector3 m_Position, m_Rotation, m_Scale;

	DirectX::SimpleMath::Matrix m_Matrix;
	bool m_UpdateMatrix;
};