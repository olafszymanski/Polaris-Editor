struct PixelInput
{
	float4 Position : SV_POSITION;
};

float4 main(PixelInput pixelInput) : SV_TARGET
{
	return float4(1.0f, 1.0f, 1.0f, 1.0f);
}