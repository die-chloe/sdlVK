
	

struct VSOutput
{
	float4 Pos : SV_POSITION;
};

VSOutput main(uint VertexIndex : SV_VertexID)
{
	float2 positions[3] =
	{
		float2(0.0, -0.5),
		float2(0.5, 0.5),
		float2(-0.5, 0.5)
	};
	
	VSOutput output = (VSOutput) 0;
	output.Pos = float4(positions[VertexIndex], 0.0, 1.0);
	return output;
}