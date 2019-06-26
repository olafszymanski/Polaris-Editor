cbuffer Matrix : register(b0)
{
	matrix WVP;
};

struct VertexInput
{
	float3 Position : POSITION;
};

struct PixelInput
{
	float4 Position : SV_POSITION;
};

PixelInput main(VertexInput vertexInput)
{
	PixelInput pixelInput;
	pixelInput.Position = mul(float4(vertexInput.Position, 1.0f), WVP);

	return pixelInput;
}