module top_nios_sys (
	RST_N,
	CLK,
	LED0
 ); 


input		CLK, RST_N;
output		LED0;
reg [27:0]	counter0;
wire counter0_clr, counter0_dec;
wire [27:0] Decode0;
wire [27:0] Period0;

always @(negedge RST_N or posedge CLK)
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

assign counter0_clr = (counter0 >= Period0-1) ? 1'b1 : 1'b0;
assign counter0_dec = (counter0 < Decode0) ? 1'b1 : 1'b0;
assign LED0 = counter0_dec;

    nios2e u0 (
        .clk_clk                            (CLK),  
        .reset_reset_n                      (RST_N),  
        .period0_external_connection_export (Period0), 
        .decode0_external_connection_export (Decode0)  
    );


endmodule
