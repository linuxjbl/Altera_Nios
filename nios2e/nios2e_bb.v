
module nios2e (
	clk_clk,
	decode1_external_connection_export,
	decode2_external_connection_export,
	decode3_external_connection_export,
	decode4_external_connection_export,
	hex0_external_connection_export,
	period1_external_connection_export,
	period2_external_connection_export,
	period3_external_connection_export,
	period4_external_connection_export,
	push_external_connection_export,
	reset_reset_n,
	hex1_external_connection_export,
	hex2_external_connection_export,
	hex3_external_connection_export);	

	input		clk_clk;
	output	[27:0]	decode1_external_connection_export;
	output	[27:0]	decode2_external_connection_export;
	output	[27:0]	decode3_external_connection_export;
	output	[27:0]	decode4_external_connection_export;
	output	[7:0]	hex0_external_connection_export;
	output	[27:0]	period1_external_connection_export;
	output	[27:0]	period2_external_connection_export;
	output	[27:0]	period3_external_connection_export;
	output	[27:0]	period4_external_connection_export;
	input	[1:0]	push_external_connection_export;
	input		reset_reset_n;
	output	[7:0]	hex1_external_connection_export;
	output	[7:0]	hex2_external_connection_export;
	output	[7:0]	hex3_external_connection_export;
endmodule
