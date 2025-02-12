struct PSOutput
{
	[[vk::location(0)]]float4 outColor : SV_Target0;
};


PSOutput main()
{
	PSOutput output = (PSOutput) 0;
	output.outColor = float4(1.0, 0.0, 0.0, 1.0);
	
	return output;
}