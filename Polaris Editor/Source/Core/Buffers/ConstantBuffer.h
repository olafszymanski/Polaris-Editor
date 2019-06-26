#pragma once

#include "../Graphics.h"

#include "../Logger.h"

template<typename T>
class ConstantBuffer : protected Graphics
{
public:
	ConstantBuffer(const T& data);
	~ConstantBuffer() = default;

	ConstantBuffer(const ConstantBuffer& other);
	ConstantBuffer& operator=(const ConstantBuffer& other);

	void BindVertex(unsigned int slot = 0) const;
	void BindHull(unsigned int slot = 0) const;
	void BindDomain(unsigned int slot = 0) const;
	void BindGeometry(unsigned int slot = 0) const;
	void BindPixel(unsigned int slot = 0) const;
	void BindCompute(unsigned int slot = 0) const;

	void Update(const T& data) const;

private:
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_Buffer;
};

#include "ConstantBuffer.ipp"