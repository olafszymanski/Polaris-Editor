#include "pch.h"

#include "Shader.h"

#include "../Graphics.h"

Shader::Shader()
	: m_WorldViewProjection(), m_WorldViewProjectionBuffer(m_WorldViewProjection)
{
}

void Shader::UpdateWorldViewProjection(const WorldViewProjection& worldViewProjection)
{
	m_WorldViewProjection = worldViewProjection;
	m_WorldViewProjectionBuffer.Update(m_WorldViewProjection);
}