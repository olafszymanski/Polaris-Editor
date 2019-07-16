#pragma once

#include "../../Logger.h"

class IndexBuffer
{
public:
	template<unsigned int N>
	IndexBuffer(const std::array<unsigned short, N>& indices);
	template<unsigned int N>
	IndexBuffer(const std::array<unsigned int, N>& indices);
	IndexBuffer(const std::vector<unsigned short>& indices);
	IndexBuffer(const std::vector<unsigned int>& indices);
	~IndexBuffer() = default;

	IndexBuffer(const IndexBuffer& other);
	IndexBuffer& operator=(const IndexBuffer& other);

	void Bind() const;

private:
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_Buffer;

	DXGI_FORMAT m_Format;
};

#include "IndexBuffer.ipp"