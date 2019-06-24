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
	pixelInput.Position = float4(vertexInput.Position, 1.0f);

	return pixelInput;
}