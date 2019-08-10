cbuffer Matrices : register(b0)
{
    matrix b_World;
    matrix b_WorldInverseTranspose;
    matrix b_WorldViewProjection;
};

struct VertexInput
{
    float3 Position : POSITION;
    float2 TextureCoordinate : TEXTURE_COORDINATE;
    float3 Normal : NORMAL;
};

struct PixelInput
{
    float4 Position : SV_POSITION;
    float3 WorldPosition : WORLD_POSITION;
    float2 TextureCoordinate : TEXTURE_COORDINATE;
    float3 Normal : NORMAL;
};

PixelInput main(VertexInput vertexInput)
{
    PixelInput pixelInput;
    pixelInput.Position = mul(float4(vertexInput.Position, 1.0f), b_WorldViewProjection);
    pixelInput.WorldPosition = mul(float4(vertexInput.Position, 1.0f), b_World).xyz;
    pixelInput.TextureCoordinate = vertexInput.TextureCoordinate;
    pixelInput.Normal = normalize(mul(vertexInput.Normal, (float3x3) b_WorldInverseTranspose));

    return pixelInput;
}