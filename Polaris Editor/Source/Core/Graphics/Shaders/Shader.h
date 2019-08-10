#pragma once

#include "../../../Utils/NonCopyable.h"

#include "../../Types/Matrices.h"
#include "../../Types/Lighting.h"
#include "../../Types/Material.h"

#include "../Buffers/ConstantBuffer.h"

class Shader : public NonCopyable
{
public:
	Shader();
	virtual ~Shader() = default;

	virtual void Bind() const = 0;

	void UpdateLighting(const Lighting& lighting);
	void UpdateMatrices(const Matrices& matrices);
	void UpdateMaterial(const Material& material);

protected:
	Microsoft::WRL::ComPtr<ID3D11SamplerState> m_SamplerState;

	ConstantBuffer<Matrices> m_MatricesBuffer;
	ConstantBuffer<Lighting> m_LightingBuffer;
	ConstantBuffer<Material> m_MaterialBuffer;
};