#pragma once

#include "Drawable.h"

#include "Mesh.h"

class Object : public Drawable
{
public:
	Object(Mesh mesh, const DirectX::XMFLOAT3& position, const DirectX::XMFLOAT3& rotation = { 0.0f, 0.0f, 0.0f }, const DirectX::XMFLOAT3& scale = { 1.0f, 1.0f, 1.0f });
	~Object() = default;

	Object(const Object& other);
	Object& operator=(const Object& other);

	void Bind() const;

	void Update();

	// Getters
	virtual unsigned int GetIndexCount() const override { return m_Mesh.GetIndexCount(); }

	DirectX::XMFLOAT3 GetPosition() const { return m_Position; }
	DirectX::XMFLOAT3 GetRotation() const { return m_Position; }
	DirectX::XMFLOAT3 GetScale() const { return m_Position; }

	virtual DirectX::XMMATRIX GetMatrix() const override { return m_Matrix; }

	// Setters
	void SetPosition(const DirectX::XMFLOAT3& position) { m_Position = position; }
	void SetRotation(const DirectX::XMFLOAT3& rotation) { m_Rotation = rotation; }
	void SetScale(const DirectX::XMFLOAT3& scale) { m_Scale = scale; }

protected:
	Mesh m_Mesh;

	DirectX::XMFLOAT3 m_Position;
	DirectX::XMFLOAT3 m_Rotation;
	DirectX::XMFLOAT3 m_Scale;

	DirectX::XMMATRIX m_Matrix;
};