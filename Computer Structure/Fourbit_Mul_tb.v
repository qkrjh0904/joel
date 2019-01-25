module Fourbit_Mul_tb();

//input
reg [3:0]x;
reg [3:0]y;

wire [7:0]mul;

Fourbit_Mul UUT(
	.x(x),
	.y(y),
	.mul(mul)
);
initial begin
	x=4'b0000;
	y=4'b0000;
	#100;
	
	x=4'b1101;
	y=4'b0101;
	#100;
	
	x=4'b0110;
	y=4'b0011;
	#100;
	
	x=4'b1100;
	y=4'b0011;
	#100;
	
	x=4'b0100;
	y=4'b1001;
	#100;
	
	x=4'b1110;
	y=4'b0111;
	#100;
	
	x=4'b0111;
	y=4'b1110;
	#100;


end
endmodule