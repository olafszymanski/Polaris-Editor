struct PixelInput
{
	float4 Position : SV_POSITION;
	float2 TextureCoordinate : TEXTURE_COORDINATE;
};

Texture2D g_Texture : register(t0);
SamplerState g_Sampler : register(s0);

float4 main(PixelInput pixelInput) : SV_TARGET
{
	return g_Texture.Sample(g_Sampler, pixelInput.TextureCoordinate);
}