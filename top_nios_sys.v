module top_nios_sys (
	RST_N,
	CLK,
	LED0, LED1, LED2, LED3,
	HEX0A, HEX0B, HEX0C, HEX0D, HEX0E, HEX0F, HEX0G, HEX0DP,
	SEG7_CS0, SEG7_CS1, SEG7_CS2, SEG7_CS3,
	PUSH0, PUSH1, PUSH2, PUSH3

 ); 

input		CLK, RST_N;
output		LED0, LED1, LED2, LED3;
output		HEX0A, HEX0B, HEX0C, HEX0D, HEX0E, HEX0F, HEX0G, HEX0DP; 
output		SEG7_CS0, SEG7_CS1, SEG7_CS2, SEG7_CS3;
input		PUSH0, PUSH1, PUSH2, PUSH3; 

reg	[25:0]		cs_cnt;


assign SEG7_CS0 = (cs_cnt[18:17] == 2'b00) ? 1'b0 : 1'b1;
assign SEG7_CS1 = (cs_cnt[18:17] == 2'b01) ? 1'b0 : 1'b1;
assign SEG7_CS2 = (cs_cnt[18:17] == 2'b10) ? 1'b0 : 1'b1;
assign SEG7_CS3 = (cs_cnt[18:17] == 2'b11) ? 1'b0 : 1'b1;


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


    PwmCtrl u0 (
        .RST_N                  (RST_N),  
        .CLK                    (CLK),  
        .LED0 			(LED0), 
        .LED1 			(LED1), 
        .LED2 			(LED2), 
        .LED3 			(LED3), 
        .HEX0A 			(HEX0A),  
        .HEX0B 			(HEX0B),  
        .HEX0C 			(HEX0C),  
        .HEX0D 			(HEX0D),  
        .HEX0E 			(HEX0E),  
        .HEX0F 			(HEX0F),  
        .HEX0G 			(HEX0G),  
        .HEX0DP 		(HEX0DP),  
        .PUSH0 			(PUSH0),  
        .PUSH1 			(PUSH1)  
    );


endmodule
