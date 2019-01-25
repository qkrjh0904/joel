// Copyright (C) 1991-2013 Altera Corporation
// Your use of Altera Corporation's design tools, logic functions 
// and other software and tools, and its AMPP partner logic 
// functions, and any output files from any of the foregoing 
// (including device programming or simulation files), and any 
// associated documentation or information are expressly subject 
// to the terms and conditions of the Altera Program License 
// Subscription Agreement, Altera MegaCore Function License 
// Agreement, or other applicable license agreement, including, 
// without limitation, that your use is for the sole purpose of 
// programming logic devices manufactured by Altera and sold by 
// Altera or its authorized distributors.  Please refer to the 
// applicable agreement for further details.

// PROGRAM		"Quartus II 64-Bit"
// VERSION		"Version 13.0.1 Build 232 06/12/2013 Service Pack 1 SJ Web Edition"
// CREATED		"Wed Sep 13 20:26:38 2017"

module InenOen8bit(
	Oen,
	clk,
	clr,
	Inen,
	data_in,
	data_out
);


input wire	Oen;
input wire	clk;
input wire	clr;
input wire	Inen;
input wire	[7:0] data_in;
output wire	[7:0] data_out;

wire	[7:0] data_out_ALTERA_SYNTHESIZED;





InenOen4bit	b2v_inst(
	.Oen(Oen),
	.clk(clk),
	.Inen(Inen),
	.clr(clr),
	.data_in(data_in[3:0]),
	.data_out(data_out_ALTERA_SYNTHESIZED[3:0]));


InenOen4bit	b2v_inst4(
	.Oen(Oen),
	.clk(clk),
	.Inen(Inen),
	.clr(clr),
	.data_in(data_in[7:4]),
	.data_out(data_out_ALTERA_SYNTHESIZED[7:4]));

assign	data_out = data_out_ALTERA_SYNTHESIZED;

endmodule
