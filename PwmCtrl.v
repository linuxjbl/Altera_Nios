module PwmCtrl (
	HEX0A, HEX0B, HEX0C, HEX0D, HEX0E, HEX0F, HEX0G, HEX0DP,
	HEX1A, HEX1B, HEX1C, HEX1D, HEX1E, HEX1F, HEX1G, HEX1DP,
	HEX2A, HEX2B, HEX2C, HEX2D, HEX2E, HEX2F, HEX2G, HEX2DP,
	HEX3A, HEX3B, HEX3C, HEX3D, HEX3E, HEX3F, HEX3G, HEX3DP,
	PUSH0, PUSH1, PUSH2, PUSH3,
	LED0, LED1, LED2, LED3,
	CLK,
	RST_N,
	UART_RXD, UART_TXD,
	DCLK, SCE, SDO, DATA
 ); 

//======= PORT DEFINITION ================================================
output		HEX0A, HEX0B, HEX0C, HEX0D, HEX0E, HEX0F, HEX0G, HEX0DP; 
output		HEX1A, HEX1B, HEX1C, HEX1D, HEX1E, HEX1F, HEX1G, HEX1DP; 
output		HEX2A, HEX2B, HEX2C, HEX2D, HEX2E, HEX2F, HEX2G, HEX2DP; 
output		HEX3A, HEX3B, HEX3C, HEX3D, HEX3E, HEX3F, HEX3G, HEX3DP; 
input		PUSH0, PUSH1, PUSH2, PUSH3; 
output		LED0, LED1, LED2, LED3;
input		CLK, RST_N;
input		UART_RXD;
output		UART_TXD;
output 		DCLK, SCE, SDO;
input  		DATA;

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
//wire		w_UART_TXD;
//wire		w_UART_RXD;


assign LED0 = LED[0];
assign LED1 = LED[1];
assign LED2 = LED[2];
assign LED3 = LED[3];

assign tDecode = {Decode3, Decode2, Decode1, Decode0 };
assign tPeriod = {Period3, Period2, Period1, Period0 };

//assign w_UART_RXD = 1'b0;
//assign UART_TXD = UART_RXD;
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
	.uart_0_external_connection_rxd    (UART_RXD),     //  uart_0_external_connection.rxd
	.uart_0_external_connection_txd    (UART_TXD),      //                            .txd
	.epcs_flash_controller_0_external_dclk  (DCLK),  // epcs_flash_controller_0_external.dclk
	.epcs_flash_controller_0_external_sce   (SCE),   //                                 .sce
	.epcs_flash_controller_0_external_sdo   (SDO),   //                                 .sdo
	.epcs_flash_controller_0_external_data0 (DATA)  //                                 .data0

    );

endmodule


