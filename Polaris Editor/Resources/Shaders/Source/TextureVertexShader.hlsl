cbuffer Matrix : register(b0)
{
	matrix WVP;
};

struct VertexInput
{
	float3 Position : POSITION;
	float2 TextureCoordinate : TEXTURE_COORDINATE;
};

struct PixelInput
{
	float4 Position : SV_POSITION;
	float2 TextureCoordinate : TEXTURE_COORDINATE;
};

PixelInput main(VertexInput vertexInput)
{
	PixelInput pixelInput;
	pixelInput.Position = mul(float4(vertexInput.Position, 1.0f), WVP);
	pixelInput.TextureCoordinate = vertexInput.TextureCoordinate;

	return pixelInput;
}