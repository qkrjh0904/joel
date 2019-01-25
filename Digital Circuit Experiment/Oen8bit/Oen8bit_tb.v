module Oen8bit_tb();


//Intputs

	reg [7:0]data_in;
	reg clk;
	reg clr;
	reg Oen;
	
//Outputs	
	wire [7:0]data_out;
	
	
//Instantiate the UUT
Oen8bit UUT(
		.data_in(data_in),
		.clr(clr),
		.clk(clk),
		.Oen(Oen),
		.data_out(data_out)
		);
	
//Behavior
always begin
	#50;	
	clk = ~clk;
end
	
initial begin
	data_in=8'b00000000;
	clk=0;
	clr=0;
	Oen=0;
	#100;
	
	data_in=8'b00100011;
	#200;
	
	Oen=1;
	data_in=8'b11000110;
	#200;
	
	data_in=8'b11110000;
	#200;
	
	data_in=8'b00001111;
	#200;
	
	data_in=8'b01001100;
	#200;
	
	data_in=8'b01110000;
	#200;
	
	data_in=8'b11001100;
	clr=1;
	#200;
	
	data_in=8'b01100010;
	#200;
	
	end
	
	endmodule
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	