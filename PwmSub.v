module PwmSub (
	Decode,
	Period,
	LED0,
	CLK,
	RST_N
 ); 

//======= PORT DEFINITION ================================================
output		LED0;
input		CLK, RST_N;
input 	[27:0] 	Decode;
input 	[27:0] 	Period;

reg 	[27:0]	counter0;
wire 		counter0_clr, counter0_dec;


assign LED0 = counter0_dec;


always @(posedge CLK or negedge RST_N)
begin
	if (RST_N == 1'b0) begin
		counter0 <= 0;
	end else begin
		if(counter0_clr == 1'b1) begin
			counter0 <= 0;
		end else begin
			counter0 <= counter0 + 1;
		end
	end
end

assign counter0_clr = (counter0 >= Period-1) ? 1'b1 : 1'b0;
assign counter0_dec = (counter0 < Decode) ? 1 : 0;


endmodule


