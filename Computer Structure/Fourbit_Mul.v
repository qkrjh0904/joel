module Fourbit_Mul(
	x,
	y,
	mul
);


input wire	[3:0] x;
input wire	[3:0] y;
output wire	[7:0] mul;

wire	[7:0] mul_ALTERA_SYNTHESIZED;
wire	SYNTHESIZED_WIRE_0;
wire	SYNTHESIZED_WIRE_1;
wire	SYNTHESIZED_WIRE_2;
wire	SYNTHESIZED_WIRE_3;
wire	SYNTHESIZED_WIRE_4;
wire	SYNTHESIZED_WIRE_5;
wire	SYNTHESIZED_WIRE_6;
wire	SYNTHESIZED_WIRE_7;
wire	SYNTHESIZED_WIRE_8;
wire	SYNTHESIZED_WIRE_9;
wire	SYNTHESIZED_WIRE_10;
wire	SYNTHESIZED_WIRE_11;
wire	SYNTHESIZED_WIRE_12;
wire	SYNTHESIZED_WIRE_13;
wire	SYNTHESIZED_WIRE_14;
wire	SYNTHESIZED_WIRE_15;
wire	SYNTHESIZED_WIRE_16;
wire	SYNTHESIZED_WIRE_17;
wire	SYNTHESIZED_WIRE_18;
wire	SYNTHESIZED_WIRE_19;
wire	SYNTHESIZED_WIRE_20;
wire	SYNTHESIZED_WIRE_21;
wire	SYNTHESIZED_WIRE_22;
wire	SYNTHESIZED_WIRE_23;
wire	SYNTHESIZED_WIRE_24;
wire	SYNTHESIZED_WIRE_25;
wire	SYNTHESIZED_WIRE_26;
wire	SYNTHESIZED_WIRE_27;
wire	SYNTHESIZED_WIRE_28;
wire	SYNTHESIZED_WIRE_29;
wire	SYNTHESIZED_WIRE_30;
wire	SYNTHESIZED_WIRE_31;





FullAdder	b2v_inst(
	.x_in(SYNTHESIZED_WIRE_0),
	.y_in(SYNTHESIZED_WIRE_1),
	.c_in(SYNTHESIZED_WIRE_2),
	.sum(SYNTHESIZED_WIRE_8),
	.c_out(SYNTHESIZED_WIRE_27));


HalfAdder	b2v_inst1(
	.x_in(SYNTHESIZED_WIRE_3),
	.y_in(SYNTHESIZED_WIRE_4),
	.sum(mul_ALTERA_SYNTHESIZED[1]),
	.c_out(SYNTHESIZED_WIRE_7));


FullAdder	b2v_inst10(
	.x_in(SYNTHESIZED_WIRE_5),
	.y_in(SYNTHESIZED_WIRE_6),
	.c_in(SYNTHESIZED_WIRE_7),
	.sum(SYNTHESIZED_WIRE_30),
	.c_out(SYNTHESIZED_WIRE_2));


FullAdder	b2v_inst11(
	.x_in(SYNTHESIZED_WIRE_8),
	.y_in(SYNTHESIZED_WIRE_9),
	.c_in(SYNTHESIZED_WIRE_10),
	.sum(SYNTHESIZED_WIRE_28),
	.c_out(SYNTHESIZED_WIRE_13));


FullAdder	b2v_inst12(
	.x_in(SYNTHESIZED_WIRE_11),
	.y_in(SYNTHESIZED_WIRE_12),
	.c_in(SYNTHESIZED_WIRE_13),
	.sum(SYNTHESIZED_WIRE_23),
	.c_out(SYNTHESIZED_WIRE_16));


FullAdder	b2v_inst13(
	.x_in(SYNTHESIZED_WIRE_14),
	.y_in(SYNTHESIZED_WIRE_15),
	.c_in(SYNTHESIZED_WIRE_16),
	.sum(SYNTHESIZED_WIRE_20),
	.c_out(SYNTHESIZED_WIRE_17));


FullAdder	b2v_inst14(
	.x_in(SYNTHESIZED_WIRE_17),
	.y_in(SYNTHESIZED_WIRE_18),
	.c_in(SYNTHESIZED_WIRE_19),
	.sum(mul_ALTERA_SYNTHESIZED[6]),
	.c_out(mul_ALTERA_SYNTHESIZED[7]));


FullAdder	b2v_inst15(
	.x_in(SYNTHESIZED_WIRE_20),
	.y_in(SYNTHESIZED_WIRE_21),
	.c_in(SYNTHESIZED_WIRE_22),
	.sum(mul_ALTERA_SYNTHESIZED[5]),
	.c_out(SYNTHESIZED_WIRE_19));

assign	SYNTHESIZED_WIRE_3 = x[1] & y[0];

assign	SYNTHESIZED_WIRE_5 = x[2] & y[0];

assign	SYNTHESIZED_WIRE_0 = x[3] & y[0];


FullAdder	b2v_inst19(
	.x_in(SYNTHESIZED_WIRE_23),
	.y_in(SYNTHESIZED_WIRE_24),
	.c_in(SYNTHESIZED_WIRE_25),
	.sum(mul_ALTERA_SYNTHESIZED[4]),
	.c_out(SYNTHESIZED_WIRE_22));

assign	SYNTHESIZED_WIRE_1 = x[2] & y[1];

assign	SYNTHESIZED_WIRE_6 = x[1] & y[1];

assign	SYNTHESIZED_WIRE_4 = x[0] & y[1];

assign	SYNTHESIZED_WIRE_26 = x[3] & y[1];

assign	SYNTHESIZED_WIRE_31 = x[0] & y[2];

assign	SYNTHESIZED_WIRE_9 = x[1] & y[2];

assign	SYNTHESIZED_WIRE_12 = x[2] & y[2];

assign	SYNTHESIZED_WIRE_15 = x[3] & y[2];

assign	SYNTHESIZED_WIRE_29 = x[0] & y[3];

assign	SYNTHESIZED_WIRE_24 = x[1] & y[3];


HalfAdder	b2v_inst3(
	.x_in(SYNTHESIZED_WIRE_26),
	.y_in(SYNTHESIZED_WIRE_27),
	.sum(SYNTHESIZED_WIRE_11),
	.c_out(SYNTHESIZED_WIRE_14));

assign	SYNTHESIZED_WIRE_21 = x[2] & y[3];

assign	SYNTHESIZED_WIRE_18 = x[3] & y[3];


HalfAdder	b2v_inst39(
	.x_in(SYNTHESIZED_WIRE_28),
	.y_in(SYNTHESIZED_WIRE_29),
	.sum(mul_ALTERA_SYNTHESIZED[3]),
	.c_out(SYNTHESIZED_WIRE_25));


HalfAdder	b2v_inst5(
	.x_in(SYNTHESIZED_WIRE_30),
	.y_in(SYNTHESIZED_WIRE_31),
	.sum(mul_ALTERA_SYNTHESIZED[2]),
	.c_out(SYNTHESIZED_WIRE_10));

assign	mul_ALTERA_SYNTHESIZED[0] = x[0] & y[0];

assign	mul = mul_ALTERA_SYNTHESIZED;

endmodule