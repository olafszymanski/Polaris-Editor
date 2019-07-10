#pragma once

#include "../../Utils/NonCopyable.h"

#include "../Types/WorldViewProjection.h"
#include "../Buffers/ConstantBuffer.h"

class Shader : public NonCopyable
{
public:
	Shader();
	~Shader() = default;

	virtual void Bind() const = 0;

	void UpdateWorldViewProjection(const WorldViewProjection& worldViewProjection);

protected:
	WorldViewProjection m_WorldViewProjection;
	ConstantBuffer<WorldViewProjection> m_WorldViewProjectionBuffer;
};