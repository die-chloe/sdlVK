
float4 main(uint VertexIndex : SV_VertexID) : SV_POSITION
{
	float2 positions[3] =
	{
		float2(0.0, -0.5),
		float2(0.5, 0.5),
		float2(-0.5, 0.5)
	};
	
	return float4(positions[VertexIndex], 0.0, 1.0);
}