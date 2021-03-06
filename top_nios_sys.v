module top_nios_sys (
	RST_N,
	CLK,
	LED0, LED1, LED2, LED3,
	HEX0A, HEX0B, HEX0C, HEX0D, HEX0E, HEX0F, HEX0G, HEX0DP,
	SEG7_CS0, SEG7_CS1, SEG7_CS2, SEG7_CS3,
	PUSH0, PUSH1, PUSH2, PUSH3,
	//UART_RXD, UART_TXD,
	DCLK, SCE, SDO, DATA,
	SDRAM_ADDR, SDRAM_BA, SDRAM_CAS_N, SDRAM_CKE, SDRAM_CS_N,
	SDRAM_DQ, SDRAM_DQM, SDRAM_RAS_N, SDRAM_WE_N, SDRAM_CLK
 ); 

input		CLK, RST_N;
output		LED0, LED1, LED2, LED3;
output		HEX0A, HEX0B, HEX0C, HEX0D, HEX0E, HEX0F, HEX0G, HEX0DP; 
output		SEG7_CS0, SEG7_CS1, SEG7_CS2, SEG7_CS3;
input		PUSH0, PUSH1, PUSH2, PUSH3; 
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



reg	[25:0]		cs_cnt;
wire	[7:0]		w_HEX;
wire	[7:0]		w_HEX0;
wire	[7:0]		w_HEX1;
wire	[7:0]		w_HEX2;
wire	[7:0]		w_HEX3;

assign HEX0A = w_HEX[0];
assign HEX0B = w_HEX[1];
assign HEX0C = w_HEX[2];
assign HEX0D = w_HEX[3];
assign HEX0E = w_HEX[4];
assign HEX0F = w_HEX[5];
assign HEX0G = w_HEX[6];
assign HEX0DP = w_HEX[7];

assign SEG7_CS0 = (cs_cnt[18:15] == 4'b0001) ? 1'b0 : 1'b1;
assign SEG7_CS1 = (cs_cnt[18:15] == 4'b0101) ? 1'b0 : 1'b1;
assign SEG7_CS2 = (cs_cnt[18:15] == 4'b1001) ? 1'b0 : 1'b1;
assign SEG7_CS3 = (cs_cnt[18:15] == 4'b1101) ? 1'b0 : 1'b1;

assign w_HEX = (cs_cnt[18:17] == 2'b00) ? w_HEX0 :
               (cs_cnt[18:17] == 2'b01) ? w_HEX1 :
               (cs_cnt[18:17] == 2'b10) ? w_HEX2 : w_HEX3 ;

always @(negedge RST_N or posedge CLK)
begin
	if(RST_N == 1'b0)begin
		cs_cnt <= 0;
	end else begin
		if(cs_cnt == 26'h3FFFFFF)begin
			cs_cnt <= 0;
		end else begin
			cs_cnt <= cs_cnt + 1'b1;
		end
	end

end

//assign w_HEX1 = 8'hf9;
//assign w_HEX2 = 8'ha4;
//assign w_HEX3 = 8'hb0;


    PwmCtrl u0 (
        .RST_N                  (RST_N),  
        .CLK                    (CLK),  
        .LED0 			(LED0), 
        .LED1 			(LED1), 
        .LED2 			(LED2), 
        .LED3 			(LED3), 
        .HEX0A 			(w_HEX0[0]),  
        .HEX0B 			(w_HEX0[1]),  
        .HEX0C 			(w_HEX0[2]),  
        .HEX0D 			(w_HEX0[3]),  
        .HEX0E 			(w_HEX0[4]),  
        .HEX0F 			(w_HEX0[5]),  
        .HEX0G 			(w_HEX0[6]),  
        .HEX0DP 		(w_HEX0[7]),  
        .HEX1A 			(w_HEX1[0]),  
        .HEX1B 			(w_HEX1[1]),  
        .HEX1C 			(w_HEX1[2]),  
        .HEX1D 			(w_HEX1[3]),  
        .HEX1E 			(w_HEX1[4]),  
        .HEX1F 			(w_HEX1[5]),  
        .HEX1G 			(w_HEX1[6]),  
        .HEX1DP 		(w_HEX1[7]),  
        .HEX2A 			(w_HEX2[0]),  
        .HEX2B 			(w_HEX2[1]),  
        .HEX2C 			(w_HEX2[2]),  
        .HEX2D 			(w_HEX2[3]),  
        .HEX2E 			(w_HEX2[4]),  
        .HEX2F 			(w_HEX2[5]),  
        .HEX2G 			(w_HEX2[6]),  
        .HEX2DP 		(w_HEX2[7]),  
        .HEX3A 			(w_HEX3[0]),  
        .HEX3B 			(w_HEX3[1]),  
        .HEX3C 			(w_HEX3[2]),  
        .HEX3D 			(w_HEX3[3]),  
        .HEX3E 			(w_HEX3[4]),  
        .HEX3F 			(w_HEX3[5]),  
        .HEX3G 			(w_HEX3[6]),  
        .HEX3DP 		(w_HEX3[7]),  
        .PUSH0 			(~PUSH0),   // Active Low   
        .PUSH1 			(~PUSH1),  
        .PUSH2 			(~PUSH2),  
        .PUSH3 			(~PUSH3),  
        //.UART_RXD 		(UART_RXD),  
        //.UART_TXD 		(UART_TXD), 
        .DCLK	 		(DCLK), 
        .SCE	 		(SCE), 
        .SDO	 		(SDO), 
        .DATA	 		(DATA), 
	.SDRAM_ADDR		(SDRAM_ADDR), 
	.SDRAM_BA		(SDRAM_BA), 
	.SDRAM_CAS_N		(SDRAM_CAS_N), 
	.SDRAM_CKE		(SDRAM_CKE), 
	.SDRAM_CS_N		(SDRAM_CS_N),
	.SDRAM_DQ		(SDRAM_DQ), 
	.SDRAM_DQM		(SDRAM_DQM), 
	.SDRAM_RAS_N		(SDRAM_RAS_N), 
	.SDRAM_WE_N		(SDRAM_WE_N), 
	.SDRAM_CLK		(SDRAM_CLK)
    );


endmodule
