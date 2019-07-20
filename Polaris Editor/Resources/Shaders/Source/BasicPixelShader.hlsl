struct PixelInput
{
    float4 Position : SV_POSITION;
    float2 TextureCoordinate : TEXTURE_COORDINATE;
};

Texture2D g_DiffuseTexture : register(t0);
Texture2D g_SpecularTexture : register(t1);

SamplerState g_SamplerState : register(s0);

float4 main(PixelInput pixelInput) : SV_TARGET
{
    return g_DiffuseTexture.Sample(g_SamplerState, pixelInput.TextureCoordinate);
}