#pragma once

#include "../../../Utils/NonCopyable.h"

#include "../../Structures/Structures.h"

#include "../Buffers/ConstantBuffer.h"

class Shader : public NonCopyable
{
public:
	Shader();
	virtual ~Shader() = default;

	virtual void Bind() const = 0;

	void UpdateLighting(const LightingStructure& lighting);
	void UpdateMatrices(const MatricesStructure& matrices);
	void UpdateMaterial(const MaterialStructure& material);

protected:
	Microsoft::WRL::ComPtr<ID3D11SamplerState> m_SamplerState;

	ConstantBuffer<MatricesStructure> m_MatricesBuffer;
	ConstantBuffer<LightingStructure> m_LightingBuffer;
	ConstantBuffer<MaterialStructure> m_MaterialBuffer;
};