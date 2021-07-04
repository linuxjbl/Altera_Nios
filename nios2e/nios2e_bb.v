
module nios2e (
	clk_clk,
	decode1_external_connection_export,
	decode2_external_connection_export,
	decode3_external_connection_export,
	decode4_external_connection_export,
	epcs_flash_controller_0_external_dclk,
	epcs_flash_controller_0_external_sce,
	epcs_flash_controller_0_external_sdo,
	epcs_flash_controller_0_external_data0,
	hex0_external_connection_export,
	hex1_external_connection_export,
	hex2_external_connection_export,
	hex3_external_connection_export,
	new_sdram_controller_0_wire_addr,
	new_sdram_controller_0_wire_ba,
	new_sdram_controller_0_wire_cas_n,
	new_sdram_controller_0_wire_cke,
	new_sdram_controller_0_wire_cs_n,
	new_sdram_controller_0_wire_dq,
	new_sdram_controller_0_wire_dqm,
	new_sdram_controller_0_wire_ras_n,
	new_sdram_controller_0_wire_we_n,
	period1_external_connection_export,
	period2_external_connection_export,
	period3_external_connection_export,
	period4_external_connection_export,
	push_external_connection_export,
	reset_reset_n);	

	input		clk_clk;
	output	[27:0]	decode1_external_connection_export;
	output	[27:0]	decode2_external_connection_export;
	output	[27:0]	decode3_external_connection_export;
	output	[27:0]	decode4_external_connection_export;
	output		epcs_flash_controller_0_external_dclk;
	output		epcs_flash_controller_0_external_sce;
	output		epcs_flash_controller_0_external_sdo;
	input		epcs_flash_controller_0_external_data0;
	output	[7:0]	hex0_external_connection_export;
	output	[7:0]	hex1_external_connection_export;
	output	[7:0]	hex2_external_connection_export;
	output	[7:0]	hex3_external_connection_export;
	output	[11:0]	new_sdram_controller_0_wire_addr;
	output	[1:0]	new_sdram_controller_0_wire_ba;
	output		new_sdram_controller_0_wire_cas_n;
	output		new_sdram_controller_0_wire_cke;
	output		new_sdram_controller_0_wire_cs_n;
	inout	[15:0]	new_sdram_controller_0_wire_dq;
	output	[1:0]	new_sdram_controller_0_wire_dqm;
	output		new_sdram_controller_0_wire_ras_n;
	output		new_sdram_controller_0_wire_we_n;
	output	[27:0]	period1_external_connection_export;
	output	[27:0]	period2_external_connection_export;
	output	[27:0]	period3_external_connection_export;
	output	[27:0]	period4_external_connection_export;
	input	[3:0]	push_external_connection_export;
	input		reset_reset_n;
endmodule
