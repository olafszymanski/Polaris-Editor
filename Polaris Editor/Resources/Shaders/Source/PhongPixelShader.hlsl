#define MAX_DIRECTIONAL_LIGHTS 32
#define MAX_POINT_LIGHTS 256
#define MAX_SPOT_LIGHTS 256

struct Light
{
    uint Type;
    float2 TypePadding;
    
    float Intensity;

    float4 Ambient;
    float4 Diffuse;
    float4 Specular;
};

struct DirectionalLight : Light
{
    float3 Direction;
    float DirectionPadding;
};
struct PointLight : Light
{
    float3 Position;
    float PositionPadding;

    float3 Attenuation;
    float AttenuationPadding;
};
struct SpotLight : Light
{
    float3 Position;
    float CutOff;

    float3 Direction;
    float DirectionPadding;

    float3 Attenuation;
    float AttenuationPadding;
};

struct Material
{
    float4 Ambient;
    float4 Diffuse;
    float4 Specular;
};

cbuffer Lighting : register(b0)
{
    DirectionalLight b_DirectionalLights[MAX_DIRECTIONAL_LIGHTS];
    PointLight b_PointLights[MAX_POINT_LIGHTS];
    SpotLight b_SpotLights[MAX_SPOT_LIGHTS];

    float3 b_CameraPosition;
    float b_CameraPositionPadding;
}

cbuffer Material : register(b1)
{
    Material b_Material;
}

struct PixelInput
{
    float4 Position : SV_POSITION;
    float3 WorldPosition : WORLD_POSITION;
    float2 TextureCoordinate : TEXTURE_COORDINATE;
    float3 Normal : NORMAL;
};

Texture2D g_DiffuseTexture : register(t0);
Texture2D g_SpecularTexture : register(t1);

SamplerState g_SamplerState : register(s0);

float4 CalculateDirectionalLight(DirectionalLight light, float3 viewDirection, float4 diffuseTexture, float4 specularTexture, float3 normal)
{
    float4 ambient = light.Ambient * b_Material.Ambient * diffuseTexture;
    float4 diffuse = float4(0.0f, 0.0f, 0.0f, 0.0f);
    float4 specular = float4(0.0f, 0.0f, 0.0f, 0.0f);

    float diffuseFactor = dot(normal, -light.Direction);

    if (diffuseFactor > 0.0f)
    {
        diffuse = light.Diffuse * b_Material.Diffuse * diffuseFactor * diffuseTexture;

        float3 reflectionDirection = normalize(reflect(light.Direction, normal));
        float specularFactor = dot(viewDirection, reflectionDirection);
    
        if (specularFactor > 0.0f)
        {
            specularFactor = pow(specularFactor, b_Material.Specular.w);
            specular = light.Specular * b_Material.Specular * specularFactor * specularTexture;
        }
    }

    return ambient + diffuse + specular;
}
float4 CalculatePointLight(PointLight light, float3 worldPosition, float3 viewDirection, float4 diffuseTexture, float4 specularTexture, float3 normal)
{
    float4 ambient = b_Material.Ambient * diffuseTexture;
    float4 diffuse = float4(0.0f, 0.0f, 0.0f, 0.0f);
    float4 specular = float4(0.0f, 0.0f, 0.0f, 0.0f);

    float3 lightDirection = normalize(worldPosition - light.Position);

    float diffuseFactor = dot(normal, -lightDirection);

    if (diffuseFactor > 0.0f)
    {
        diffuse = light.Diffuse * b_Material.Diffuse * diffuseFactor * diffuseTexture * light.Intensity;

        float3 reflectionDirection = normalize(reflect(lightDirection, normal));
        float specularFactor = dot(viewDirection, reflectionDirection);
    
        if (specularFactor > 0.0f)
        {
            specularFactor = pow(specularFactor, b_Material.Specular.w);
            specular = light.Specular * b_Material.Specular * specularFactor * specularTexture;
        }
    }

    float distance = length(worldPosition - light.Position);
    float attenuation = 1.0f / (light.Attenuation.x + light.Attenuation.y * distance + light.Attenuation.z * (distance * distance));

    diffuse *= attenuation;
    specular *= attenuation;

    return ambient + diffuse + specular;
}
float4 CalculateSpotLight(SpotLight light, float3 worldPosition, float3 viewDirection, float4 diffuseTexture, float4 specularTexture, float3 normal)
{
    float4 ambient = b_Material.Ambient * diffuseTexture;
    float4 diffuse = float4(0.0f, 0.0f, 0.0f, 0.0f);
    float4 specular = float4(0.0f, 0.0f, 0.0f, 0.0f);

    float3 lightDirection = normalize(worldPosition - light.Position);

    float spotFactor = dot(lightDirection, light.Direction);

    if (spotFactor > light.CutOff)
    {
        float diffuseFactor = dot(normal, -lightDirection);

        if (diffuseFactor > 0.0f)
        {
            diffuse = light.Diffuse * b_Material.Diffuse * diffuseFactor * diffuseTexture * light.Intensity;

            float3 reflectionDirection = normalize(reflect(lightDirection, normal));
            float specularFactor = dot(viewDirection, reflectionDirection);
    
            if (specularFactor > 0.0f)
            {
                specularFactor = pow(specularFactor, b_Material.Specular.w);
                specular = light.Specular * b_Material.Specular * specularFactor * specularTexture;
            }
        }

        float distance = length(worldPosition - light.Position);
        float attenuation = 1.0f / (light.Attenuation.x + light.Attenuation.y * distance + light.Attenuation.z * (distance * distance));
    
        float smoothing = (1.0f - (1.0f - spotFactor) * 1.0f / (1.0f - light.CutOff));

        diffuse *= attenuation * smoothing;
        specular *= attenuation * smoothing;
    }

    return ambient + diffuse + specular;
}
float4 CalculateLighting(PixelInput pixelInput)
{
    float4 diffuseTexture = g_DiffuseTexture.Sample(g_SamplerState, pixelInput.TextureCoordinate);
    float4 specularTexture = g_SpecularTexture.Sample(g_SamplerState, pixelInput.TextureCoordinate);

    float3 viewDirection = normalize(b_CameraPosition - pixelInput.WorldPosition);

    float4 outputColor = float4(0.0f, 0.0f, 0.0f, 1.0f);

    for (uint i = 0; i < MAX_DIRECTIONAL_LIGHTS; ++i)
    {
        if (b_DirectionalLights[i].Intensity != 0.0f) outputColor += CalculateDirectionalLight(b_DirectionalLights[i], viewDirection, diffuseTexture, specularTexture, pixelInput.Normal);
    }
    for (uint j = 0; j < MAX_POINT_LIGHTS; ++j)
    {
        if (b_PointLights[j].Intensity != 0.0f) outputColor += CalculatePointLight(b_PointLights[j], pixelInput.WorldPosition, viewDirection, diffuseTexture, specularTexture, pixelInput.Normal);
    }
    for (uint k = 0; k < MAX_SPOT_LIGHTS; ++k)
    {
        if (b_SpotLights[k].Intensity != 0.0f) outputColor += CalculateSpotLight(b_SpotLights[k], pixelInput.WorldPosition, viewDirection, diffuseTexture, specularTexture, pixelInput.Normal);
    }

    if (outputColor.x == 0.0f && outputColor.y == 0.0f && outputColor.z == 0.0f) outputColor = b_Material.Ambient * diffuseTexture;

    return outputColor;
}

float4 main(PixelInput pixelInput) : SV_TARGET
{
    return CalculateLighting(pixelInput);
}