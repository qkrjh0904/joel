module Inen4bit_tb();


//Intputs

	reg [3:0]data_in;
	reg clk;
	reg clr;
	reg Inen;
	
//Outputs	
	wire [3:0]data_out;
	
	
//Instantiate the UUT
Inen4bit UUT(
		.data_in(data_in),
		.clr(clr),
		.clk(clk),
		.Inen(Inen),
		.data_out(data_out)
		);
	
//Behavior
always begin
	#50;	
	clk = ~clk;
end
	
initial begin
	data_in=4'b0000;
	clk=0;
	clr=0;
	Inen=0;
	#100;
	
	data_in=4'b0011;
	#200;
	
	data_in=4'b1010;
	#200;
	
	Inen=1;
	data_in=4'b1111;
	#200;
	
	data_in=4'b1001;
	#200;
	
	
	data_in=4'b0011;
	#200;
	
	data_in=4'b1010;
	#200;
	
	data_in=4'b1111;
	clr=1;
	#200;
	
	data_in=4'b1001;
	#200;
	
	end
	
	endmodule
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	