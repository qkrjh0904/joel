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
// CREATED		"Wed Sep 13 19:49:08 2017"

module InenOen4bit(
	clr,
	clk,
	Inen,
	Oen,
	data_in,
	data_out
);


input wire	clr;
input wire	clk;
input wire	Inen;
input wire	Oen;
input wire	[3:0] data_in;
output wire	[3:0] data_out;

wire	[3:0] data_out_ALTERA_SYNTHESIZED;
wire	SYNTHESIZED_WIRE_4;
reg	DFFE_inst9;
reg	DFFE_inst10;
reg	DFFE_inst11;
reg	DFFE_inst12;





always@(posedge clk or negedge SYNTHESIZED_WIRE_4)
begin
if (!SYNTHESIZED_WIRE_4)
	begin
	DFFE_inst10 <= 0;
	end
else
if (Inen)
	begin
	DFFE_inst10 <= data_in[1];
	end
end


always@(posedge clk or negedge SYNTHESIZED_WIRE_4)
begin
if (!SYNTHESIZED_WIRE_4)
	begin
	DFFE_inst11 <= 0;
	end
else
if (Inen)
	begin
	DFFE_inst11 <= data_in[2];
	end
end


always@(posedge clk or negedge SYNTHESIZED_WIRE_4)
begin
if (!SYNTHESIZED_WIRE_4)
	begin
	DFFE_inst12 <= 0;
	end
else
if (Inen)
	begin
	DFFE_inst12 <= data_in[3];
	end
end

assign	SYNTHESIZED_WIRE_4 =  ~clr;

assign	data_out_ALTERA_SYNTHESIZED[0] = Oen ? DFFE_inst9 : 1'bz;

assign	data_out_ALTERA_SYNTHESIZED[1] = Oen ? DFFE_inst10 : 1'bz;

assign	data_out_ALTERA_SYNTHESIZED[2] = Oen ? DFFE_inst11 : 1'bz;

assign	data_out_ALTERA_SYNTHESIZED[3] = Oen ? DFFE_inst12 : 1'bz;


always@(posedge clk or negedge SYNTHESIZED_WIRE_4)
begin
if (!SYNTHESIZED_WIRE_4)
	begin
	DFFE_inst9 <= 0;
	end
else
if (Inen)
	begin
	DFFE_inst9 <= data_in[0];
	end
end

assign	data_out = data_out_ALTERA_SYNTHESIZED;

endmodule
