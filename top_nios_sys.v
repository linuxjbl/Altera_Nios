module top_nios_sys (
	RST_N,
	CLK,
	LED0
 ); 

input		CLK, RST_N;
output		LED0;
reg [27:0]	counter0;

always @(negedge RST_N or posedge CLK)
begin
	if (RST_N == 1'b0) begin
		counter0 <= 0;
	end else begin
		counter0 <= counter0 + 1;
	end
end

assign LED0 = counter0[27];

endmodule
