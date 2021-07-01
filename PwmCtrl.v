module PwmCtrl (
	HEX0A, HEX0B, HEX0C, HEX0D, HEX0E, HEX0F, HEX0G, HEX0DP,
	PUSH0, PUSH1,
	LED0, LED1, LED2, LED3,
	CLK,
	RST_N
 ); 

//======= PORT DEFINITION ================================================
output		HEX0A, HEX0B, HEX0C, HEX0D, HEX0E, HEX0F, HEX0G, HEX0DP; 
input		PUSH0, PUSH1; 
output		LED0, LED1, LED2, LED3;
input		CLK, RST_N;

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
        .push_external_connection_export ({PUSH1, PUSH0}),
        .hex0_external_connection_export   ({HEX0DP, HEX0G, HEX0F, HEX0E, HEX0D, HEX0C, HEX0B, HEX0A})
    );

endmodule


