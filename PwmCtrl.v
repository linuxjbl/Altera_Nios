module PwmCtrl (
	HEX0A, HEX0B, HEX0C, HEX0D, HEX0E, HEX0F, HEX0G, HEX0DP,
	HEX1A, HEX1B, HEX1C, HEX1D, HEX1E, HEX1F, HEX1G, HEX1DP,
	HEX2A, HEX2B, HEX2C, HEX2D, HEX2E, HEX2F, HEX2G, HEX2DP,
	HEX3A, HEX3B, HEX3C, HEX3D, HEX3E, HEX3F, HEX3G, HEX3DP,
	PUSH0, PUSH1, PUSH2, PUSH3,
	LED0, LED1, LED2, LED3,
	CLK,
	RST_N,
	//UART_RXD, UART_TXD,
	DCLK, SCE, SDO, DATA,
	SDRAM_ADDR, SDRAM_BA, SDRAM_CAS_N, SDRAM_CKE, SDRAM_CS_N,
	SDRAM_DQ, SDRAM_DQM, SDRAM_RAS_N, SDRAM_WE_N, SDRAM_CLK
 ); 

//======= PORT DEFINITION ================================================
output		HEX0A, HEX0B, HEX0C, HEX0D, HEX0E, HEX0F, HEX0G, HEX0DP; 
output		HEX1A, HEX1B, HEX1C, HEX1D, HEX1E, HEX1F, HEX1G, HEX1DP; 
output		HEX2A, HEX2B, HEX2C, HEX2D, HEX2E, HEX2F, HEX2G, HEX2DP; 
output		HEX3A, HEX3B, HEX3C, HEX3D, HEX3E, HEX3F, HEX3G, HEX3DP; 
input		PUSH0, PUSH1, PUSH2, PUSH3; 
output		LED0, LED1, LED2, LED3;
input		CLK, RST_N;
//input		UART_RXD;
//output		UART_TXD;
output 		DCLK, SCE, SDO;
input  		DATA;
output	[11:0]	SDRAM_ADDR;
output	[1:0]	SDRAM_BA;
output		SDRAM_CAS_N;
output		SDRAM_CKE;
output		SDRAM_CS_N;
inout	[15:0]	SDRAM_DQ;
output	[1:0]	SDRAM_DQM;
output		SDRAM_RAS_N;
output		SDRAM_WE_N;
output		SDRAM_CLK;

wire	[28*4-1:0]	tDecode;
wire	[28*4-1:0]	tPeriod;
wire	[27:0]	Period0;
wire	[27:0]	Period1;
wire	[27:0]	Period2;
wire	[27:0]	Period3;
wire	[27:0]	Decode0;
wire	[27:0]	Decode1;
wire	[27:0]	Decode2;
wire	[27:0]	Decode3;
wire	[3:0]	LED;


assign LED0 = LED[0];
assign LED1 = LED[1];
assign LED2 = LED[2];
assign LED3 = LED[3];

assign tDecode = {Decode3, Decode2, Decode1, Decode0 };
assign tPeriod = {Period3, Period2, Period1, Period0 };

/////////////////////////////////////////////
// for PWM0

genvar genIdx;

generate
	for(genIdx=0; genIdx < 4; genIdx=genIdx+1)begin : genbit
		PwmSub u00(
			.Decode		(tDecode[genIdx*28+27:genIdx*28]),
			.Period		(tPeriod[genIdx*28+27:genIdx*28]),
			.LED0		(LED[genIdx]),
			.CLK		(CLK),
			.RST_N		(RST_N)
		 ); 
 	end
endgenerate

	mypll u1 (
	.areset		(~RST_N),
	.inclk0		(CLK),
	.c0		(SDRAM_CLK),
	.locked		() );


    nios2e u0 (
        .clk_clk                           (CLK),
        .reset_reset_n                     (RST_N), 
        .decode1_external_connection_export (Decode0),
        .period1_external_connection_export (Period0),
        .decode2_external_connection_export (Decode1),
        .period2_external_connection_export (Period1),
        .decode3_external_connection_export (Decode2),
        .period3_external_connection_export (Period2),
        .decode4_external_connection_export (Decode3),
        .period4_external_connection_export (Period3),
        .push_external_connection_export ({PUSH3, PUSH2, PUSH1, PUSH0}),
        .hex0_external_connection_export   ({HEX0DP, HEX0G, HEX0F, HEX0E, HEX0D, HEX0C, HEX0B, HEX0A}),
        .hex1_external_connection_export   ({HEX1DP, HEX1G, HEX1F, HEX1E, HEX1D, HEX1C, HEX1B, HEX1A}),
        .hex2_external_connection_export   ({HEX2DP, HEX2G, HEX2F, HEX2E, HEX2D, HEX2C, HEX2B, HEX2A}),
        .hex3_external_connection_export   ({HEX3DP, HEX3G, HEX3F, HEX3E, HEX3D, HEX3C, HEX3B, HEX3A}),
	//.uart_0_external_connection_rxd    (UART_RXD),     //  uart_0_external_connection.rxd
	//.uart_0_external_connection_txd    (UART_TXD),      //                            .txd
	.epcs_flash_controller_0_external_dclk  (DCLK),  // epcs_flash_controller_0_external.dclk
	.epcs_flash_controller_0_external_sce   (SCE),   //                                 .sce
	.epcs_flash_controller_0_external_sdo   (SDO),   //                                 .sdo
	.epcs_flash_controller_0_external_data0 (DATA),  //                                 .data0
	.new_sdram_controller_0_wire_addr       (SDRAM_ADDR),       //      new_sdram_controller_0_wire.addr
	.new_sdram_controller_0_wire_ba         (SDRAM_BA),         //                                 .ba
	.new_sdram_controller_0_wire_cas_n      (SDRAM_CAS_N),      //                                 .cas_n
	.new_sdram_controller_0_wire_cke        (SDRAM_CKE),        //                                 .cke
	.new_sdram_controller_0_wire_cs_n       (SDRAM_CS_N),       //                                 .cs_n
	.new_sdram_controller_0_wire_dq         (SDRAM_DQ),         //                                 .dq
	.new_sdram_controller_0_wire_dqm        (SDRAM_DQM),        //                                 .dqm
	.new_sdram_controller_0_wire_ras_n      (SDRAM_RAS_N),      //                                 .ras_n
	.new_sdram_controller_0_wire_we_n       (SDRAM_WE_N)        //                                 .we_n


    );

endmodule


