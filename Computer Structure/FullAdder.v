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
// VERSION		"Version 13.0.0 Build 156 04/24/2013 SJ Web Edition"
// CREATED		"Mon Oct 30 10:55:01 2017"

module FullAdder(
	y_in,
	x_in,
	c_in,
	c_out,
	sum
);


input wire	y_in;
input wire	x_in;
input wire	c_in;
output wire	c_out;
output wire	sum;

wire	SYNTHESIZED_WIRE_4;
wire	SYNTHESIZED_WIRE_1;
wire	SYNTHESIZED_WIRE_2;




assign	SYNTHESIZED_WIRE_2 = c_in & SYNTHESIZED_WIRE_4;

assign	SYNTHESIZED_WIRE_1 = y_in & x_in;

assign	c_out = SYNTHESIZED_WIRE_1 | SYNTHESIZED_WIRE_2;

assign	SYNTHESIZED_WIRE_4 = x_in ^ y_in;

assign	sum = SYNTHESIZED_WIRE_4 ^ c_in;


endmodule
