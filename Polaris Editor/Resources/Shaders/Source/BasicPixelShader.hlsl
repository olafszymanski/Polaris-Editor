cbuffer ColorBuffer : register(b0)
{
	float4 Color;
}

struct PixelInput
{
	float4 Position : SV_POSITION;
};

float4 main(PixelInput pixelInput) : SV_TARGET
{
	return Color;
}