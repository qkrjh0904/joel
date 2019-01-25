-- Copyright (C) 1991-2013 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus II 64-Bit"
-- VERSION "Version 13.0.0 Build 156 04/24/2013 SJ Web Edition"

-- DATE "10/30/2017 17:17:17"

-- 
-- Device: Altera EP2C50F672C8 Package FBGA672
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY CYCLONEII;
LIBRARY IEEE;
USE CYCLONEII.CYCLONEII_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	Fourbit_Mul IS
    PORT (
	x : IN std_logic_vector(3 DOWNTO 0);
	y : IN std_logic_vector(3 DOWNTO 0);
	mul : OUT std_logic_vector(7 DOWNTO 0)
	);
END Fourbit_Mul;

-- Design Ports Information
-- mul[0]	=>  Location: PIN_F18,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
-- mul[1]	=>  Location: PIN_G17,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
-- mul[2]	=>  Location: PIN_A19,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
-- mul[3]	=>  Location: PIN_H17,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
-- mul[4]	=>  Location: PIN_F17,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
-- mul[5]	=>  Location: PIN_J17,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
-- mul[6]	=>  Location: PIN_G18,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
-- mul[7]	=>  Location: PIN_C17,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
-- x[0]	=>  Location: PIN_C13,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- y[0]	=>  Location: PIN_D13,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- x[1]	=>  Location: PIN_B20,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- y[1]	=>  Location: PIN_D19,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- y[2]	=>  Location: PIN_B19,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- x[2]	=>  Location: PIN_D18,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- x[3]	=>  Location: PIN_E18,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- y[3]	=>  Location: PIN_D17,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default


ARCHITECTURE structure OF Fourbit_Mul IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_x : std_logic_vector(3 DOWNTO 0);
SIGNAL ww_y : std_logic_vector(3 DOWNTO 0);
SIGNAL ww_mul : std_logic_vector(7 DOWNTO 0);
SIGNAL \b2v_inst10|c_out~0_combout\ : std_logic;
SIGNAL \b2v_inst10|c_out~1_combout\ : std_logic;
SIGNAL \mul_ALTERA_SYNTHESIZED~0_combout\ : std_logic;
SIGNAL \b2v_inst1|sum~combout\ : std_logic;
SIGNAL \SYNTHESIZED_WIRE_5~combout\ : std_logic;
SIGNAL \b2v_inst10|sum~0_combout\ : std_logic;
SIGNAL \b2v_inst5|sum~combout\ : std_logic;
SIGNAL \b2v_inst5|c_out~combout\ : std_logic;
SIGNAL \SYNTHESIZED_WIRE_9~combout\ : std_logic;
SIGNAL \b2v_inst|SYNTHESIZED_WIRE_4~combout\ : std_logic;
SIGNAL \b2v_inst11|sum~combout\ : std_logic;
SIGNAL \b2v_inst39|sum~combout\ : std_logic;
SIGNAL \b2v_inst39|c_out~0_combout\ : std_logic;
SIGNAL \b2v_inst39|c_out~1_combout\ : std_logic;
SIGNAL \SYNTHESIZED_WIRE_24~combout\ : std_logic;
SIGNAL \SYNTHESIZED_WIRE_26~combout\ : std_logic;
SIGNAL \b2v_inst12|SYNTHESIZED_WIRE_4~combout\ : std_logic;
SIGNAL \b2v_inst11|c_out~0_combout\ : std_logic;
SIGNAL \b2v_inst19|sum~combout\ : std_logic;
SIGNAL \SYNTHESIZED_WIRE_21~combout\ : std_logic;
SIGNAL \b2v_inst13|SYNTHESIZED_WIRE_4~combout\ : std_logic;
SIGNAL \SYNTHESIZED_WIRE_12~combout\ : std_logic;
SIGNAL \SYNTHESIZED_WIRE_0~combout\ : std_logic;
SIGNAL \b2v_inst|c_out~0_combout\ : std_logic;
SIGNAL \b2v_inst12|c_out~0_combout\ : std_logic;
SIGNAL \b2v_inst19|c_out~0_combout\ : std_logic;
SIGNAL \b2v_inst15|sum~combout\ : std_logic;
SIGNAL \SYNTHESIZED_WIRE_15~combout\ : std_logic;
SIGNAL \b2v_inst13|c_out~0_combout\ : std_logic;
SIGNAL \b2v_inst15|c_out~0_combout\ : std_logic;
SIGNAL \b2v_inst14|sum~0_combout\ : std_logic;
SIGNAL \b2v_inst14|c_out~0_combout\ : std_logic;
SIGNAL \y~combout\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \x~combout\ : std_logic_vector(3 DOWNTO 0);

BEGIN

ww_x <= x;
ww_y <= y;
mul <= ww_mul;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

-- Location: LCCOMB_X63_Y43_N26
\b2v_inst10|c_out~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \b2v_inst10|c_out~0_combout\ = (\x~combout\(0)) # (\x~combout\(2))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111111001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \x~combout\(0),
	datad => \x~combout\(2),
	combout => \b2v_inst10|c_out~0_combout\);

-- Location: LCCOMB_X63_Y43_N12
\b2v_inst10|c_out~1\ : cycloneii_lcell_comb
-- Equation(s):
-- \b2v_inst10|c_out~1_combout\ = (\y~combout\(0) & (\b2v_inst10|c_out~0_combout\ & (\x~combout\(1) & \y~combout\(1))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \y~combout\(0),
	datab => \b2v_inst10|c_out~0_combout\,
	datac => \x~combout\(1),
	datad => \y~combout\(1),
	combout => \b2v_inst10|c_out~1_combout\);

-- Location: PIN_C13,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\x[0]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_x(0),
	combout => \x~combout\(0));

-- Location: PIN_D13,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\y[0]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_y(0),
	combout => \y~combout\(0));

-- Location: LCCOMB_X64_Y43_N0
\mul_ALTERA_SYNTHESIZED~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \mul_ALTERA_SYNTHESIZED~0_combout\ = (\x~combout\(0) & \y~combout\(0))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \x~combout\(0),
	datad => \y~combout\(0),
	combout => \mul_ALTERA_SYNTHESIZED~0_combout\);

-- Location: PIN_B20,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\x[1]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_x(1),
	combout => \x~combout\(1));

-- Location: PIN_D19,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\y[1]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_y(1),
	combout => \y~combout\(1));

-- Location: LCCOMB_X63_Y43_N0
\b2v_inst1|sum\ : cycloneii_lcell_comb
-- Equation(s):
-- \b2v_inst1|sum~combout\ = (\y~combout\(0) & (\x~combout\(1) $ (((\x~combout\(0) & \y~combout\(1)))))) # (!\y~combout\(0) & (\x~combout\(0) & ((\y~combout\(1)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0110110010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \y~combout\(0),
	datab => \x~combout\(0),
	datac => \x~combout\(1),
	datad => \y~combout\(1),
	combout => \b2v_inst1|sum~combout\);

-- Location: PIN_D18,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\x[2]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_x(2),
	combout => \x~combout\(2));

-- Location: LCCOMB_X63_Y43_N10
SYNTHESIZED_WIRE_5 : cycloneii_lcell_comb
-- Equation(s):
-- \SYNTHESIZED_WIRE_5~combout\ = (\y~combout\(0) & \x~combout\(2))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \y~combout\(0),
	datad => \x~combout\(2),
	combout => \SYNTHESIZED_WIRE_5~combout\);

-- Location: PIN_B19,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\y[2]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_y(2),
	combout => \y~combout\(2));

-- Location: LCCOMB_X63_Y43_N28
\b2v_inst10|sum~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \b2v_inst10|sum~0_combout\ = (\x~combout\(1) & (\y~combout\(1) & ((!\x~combout\(0)) # (!\y~combout\(0)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0111000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \y~combout\(0),
	datab => \x~combout\(0),
	datac => \x~combout\(1),
	datad => \y~combout\(1),
	combout => \b2v_inst10|sum~0_combout\);

-- Location: LCCOMB_X63_Y43_N6
\b2v_inst5|sum\ : cycloneii_lcell_comb
-- Equation(s):
-- \b2v_inst5|sum~combout\ = \SYNTHESIZED_WIRE_5~combout\ $ (\b2v_inst10|sum~0_combout\ $ (((\x~combout\(0) & \y~combout\(2)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001010101101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SYNTHESIZED_WIRE_5~combout\,
	datab => \x~combout\(0),
	datac => \y~combout\(2),
	datad => \b2v_inst10|sum~0_combout\,
	combout => \b2v_inst5|sum~combout\);

-- Location: LCCOMB_X63_Y43_N22
\b2v_inst5|c_out\ : cycloneii_lcell_comb
-- Equation(s):
-- \b2v_inst5|c_out~combout\ = (\x~combout\(0) & (\y~combout\(2) & (\SYNTHESIZED_WIRE_5~combout\ $ (\b2v_inst10|sum~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0100000010000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SYNTHESIZED_WIRE_5~combout\,
	datab => \x~combout\(0),
	datac => \y~combout\(2),
	datad => \b2v_inst10|sum~0_combout\,
	combout => \b2v_inst5|c_out~combout\);

-- Location: LCCOMB_X63_Y43_N16
SYNTHESIZED_WIRE_9 : cycloneii_lcell_comb
-- Equation(s):
-- \SYNTHESIZED_WIRE_9~combout\ = (\x~combout\(1) & \y~combout\(2))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010000010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \x~combout\(1),
	datac => \y~combout\(2),
	combout => \SYNTHESIZED_WIRE_9~combout\);

-- Location: PIN_E18,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\x[3]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_x(3),
	combout => \x~combout\(3));

-- Location: LCCOMB_X64_Y43_N26
\b2v_inst|SYNTHESIZED_WIRE_4\ : cycloneii_lcell_comb
-- Equation(s):
-- \b2v_inst|SYNTHESIZED_WIRE_4~combout\ = (\y~combout\(0) & (\x~combout\(3) $ (((\y~combout\(1) & \x~combout\(2)))))) # (!\y~combout\(0) & (((\y~combout\(1) & \x~combout\(2)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0111100010001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \y~combout\(0),
	datab => \x~combout\(3),
	datac => \y~combout\(1),
	datad => \x~combout\(2),
	combout => \b2v_inst|SYNTHESIZED_WIRE_4~combout\);

-- Location: LCCOMB_X63_Y43_N24
\b2v_inst11|sum\ : cycloneii_lcell_comb
-- Equation(s):
-- \b2v_inst11|sum~combout\ = \b2v_inst10|c_out~1_combout\ $ (\b2v_inst5|c_out~combout\ $ (\SYNTHESIZED_WIRE_9~combout\ $ (\b2v_inst|SYNTHESIZED_WIRE_4~combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0110100110010110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b2v_inst10|c_out~1_combout\,
	datab => \b2v_inst5|c_out~combout\,
	datac => \SYNTHESIZED_WIRE_9~combout\,
	datad => \b2v_inst|SYNTHESIZED_WIRE_4~combout\,
	combout => \b2v_inst11|sum~combout\);

-- Location: PIN_D17,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\y[3]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "input",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => GND,
	padio => ww_y(3),
	combout => \y~combout\(3));

-- Location: LCCOMB_X63_Y43_N2
\b2v_inst39|sum\ : cycloneii_lcell_comb
-- Equation(s):
-- \b2v_inst39|sum~combout\ = \b2v_inst11|sum~combout\ $ (((\x~combout\(0) & \y~combout\(3))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110011110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \x~combout\(0),
	datac => \b2v_inst11|sum~combout\,
	datad => \y~combout\(3),
	combout => \b2v_inst39|sum~combout\);

-- Location: LCCOMB_X63_Y43_N4
\b2v_inst39|c_out~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \b2v_inst39|c_out~0_combout\ = \b2v_inst10|c_out~1_combout\ $ (\b2v_inst5|c_out~combout\ $ (\b2v_inst|SYNTHESIZED_WIRE_4~combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001100101100110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b2v_inst10|c_out~1_combout\,
	datab => \b2v_inst5|c_out~combout\,
	datad => \b2v_inst|SYNTHESIZED_WIRE_4~combout\,
	combout => \b2v_inst39|c_out~0_combout\);

-- Location: LCCOMB_X63_Y43_N30
\b2v_inst39|c_out~1\ : cycloneii_lcell_comb
-- Equation(s):
-- \b2v_inst39|c_out~1_combout\ = (\y~combout\(3) & (\x~combout\(0) & (\SYNTHESIZED_WIRE_9~combout\ $ (\b2v_inst39|c_out~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0100100000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SYNTHESIZED_WIRE_9~combout\,
	datab => \y~combout\(3),
	datac => \b2v_inst39|c_out~0_combout\,
	datad => \x~combout\(0),
	combout => \b2v_inst39|c_out~1_combout\);

-- Location: LCCOMB_X63_Y43_N8
SYNTHESIZED_WIRE_24 : cycloneii_lcell_comb
-- Equation(s):
-- \SYNTHESIZED_WIRE_24~combout\ = (\y~combout\(3) & \x~combout\(1))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100000011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \y~combout\(3),
	datac => \x~combout\(1),
	combout => \SYNTHESIZED_WIRE_24~combout\);

-- Location: LCCOMB_X64_Y43_N8
SYNTHESIZED_WIRE_26 : cycloneii_lcell_comb
-- Equation(s):
-- \SYNTHESIZED_WIRE_26~combout\ = (\x~combout\(3) & \y~combout\(1))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100000011000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \x~combout\(3),
	datac => \y~combout\(1),
	combout => \SYNTHESIZED_WIRE_26~combout\);

-- Location: LCCOMB_X64_Y43_N10
\b2v_inst12|SYNTHESIZED_WIRE_4\ : cycloneii_lcell_comb
-- Equation(s):
-- \b2v_inst12|SYNTHESIZED_WIRE_4~combout\ = \b2v_inst|c_out~0_combout\ $ (\SYNTHESIZED_WIRE_26~combout\ $ (((\x~combout\(2) & \y~combout\(2)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001011001011010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b2v_inst|c_out~0_combout\,
	datab => \x~combout\(2),
	datac => \SYNTHESIZED_WIRE_26~combout\,
	datad => \y~combout\(2),
	combout => \b2v_inst12|SYNTHESIZED_WIRE_4~combout\);

-- Location: LCCOMB_X63_Y43_N18
\b2v_inst11|c_out~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \b2v_inst11|c_out~0_combout\ = (\b2v_inst5|c_out~combout\ & ((\SYNTHESIZED_WIRE_9~combout\) # (\b2v_inst10|c_out~1_combout\ $ (\b2v_inst|SYNTHESIZED_WIRE_4~combout\)))) # (!\b2v_inst5|c_out~combout\ & (\SYNTHESIZED_WIRE_9~combout\ & 
-- (\b2v_inst10|c_out~1_combout\ $ (\b2v_inst|SYNTHESIZED_WIRE_4~combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101010011101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b2v_inst10|c_out~1_combout\,
	datab => \b2v_inst5|c_out~combout\,
	datac => \SYNTHESIZED_WIRE_9~combout\,
	datad => \b2v_inst|SYNTHESIZED_WIRE_4~combout\,
	combout => \b2v_inst11|c_out~0_combout\);

-- Location: LCCOMB_X63_Y43_N20
\b2v_inst19|sum\ : cycloneii_lcell_comb
-- Equation(s):
-- \b2v_inst19|sum~combout\ = \b2v_inst39|c_out~1_combout\ $ (\SYNTHESIZED_WIRE_24~combout\ $ (\b2v_inst12|SYNTHESIZED_WIRE_4~combout\ $ (\b2v_inst11|c_out~0_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0110100110010110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b2v_inst39|c_out~1_combout\,
	datab => \SYNTHESIZED_WIRE_24~combout\,
	datac => \b2v_inst12|SYNTHESIZED_WIRE_4~combout\,
	datad => \b2v_inst11|c_out~0_combout\,
	combout => \b2v_inst19|sum~combout\);

-- Location: LCCOMB_X64_Y43_N12
SYNTHESIZED_WIRE_21 : cycloneii_lcell_comb
-- Equation(s):
-- \SYNTHESIZED_WIRE_21~combout\ = (\y~combout\(3) & \x~combout\(2))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \y~combout\(3),
	datad => \x~combout\(2),
	combout => \SYNTHESIZED_WIRE_21~combout\);

-- Location: LCCOMB_X64_Y43_N22
\b2v_inst13|SYNTHESIZED_WIRE_4\ : cycloneii_lcell_comb
-- Equation(s):
-- \b2v_inst13|SYNTHESIZED_WIRE_4~combout\ = (\x~combout\(3) & (\y~combout\(2) $ (((\b2v_inst|c_out~0_combout\ & \y~combout\(1))))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0100110010000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b2v_inst|c_out~0_combout\,
	datab => \x~combout\(3),
	datac => \y~combout\(1),
	datad => \y~combout\(2),
	combout => \b2v_inst13|SYNTHESIZED_WIRE_4~combout\);

-- Location: LCCOMB_X64_Y43_N14
SYNTHESIZED_WIRE_12 : cycloneii_lcell_comb
-- Equation(s):
-- \SYNTHESIZED_WIRE_12~combout\ = (\x~combout\(2) & \y~combout\(2))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \x~combout\(2),
	datad => \y~combout\(2),
	combout => \SYNTHESIZED_WIRE_12~combout\);

-- Location: LCCOMB_X64_Y43_N28
SYNTHESIZED_WIRE_0 : cycloneii_lcell_comb
-- Equation(s):
-- \SYNTHESIZED_WIRE_0~combout\ = (\y~combout\(0) & \x~combout\(3))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \y~combout\(0),
	datad => \x~combout\(3),
	combout => \SYNTHESIZED_WIRE_0~combout\);

-- Location: LCCOMB_X64_Y43_N6
\b2v_inst|c_out~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \b2v_inst|c_out~0_combout\ = (\b2v_inst10|c_out~1_combout\ & ((\SYNTHESIZED_WIRE_0~combout\) # ((\y~combout\(1) & \x~combout\(2))))) # (!\b2v_inst10|c_out~1_combout\ & (\SYNTHESIZED_WIRE_0~combout\ & (\y~combout\(1) & \x~combout\(2))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110100010001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b2v_inst10|c_out~1_combout\,
	datab => \SYNTHESIZED_WIRE_0~combout\,
	datac => \y~combout\(1),
	datad => \x~combout\(2),
	combout => \b2v_inst|c_out~0_combout\);

-- Location: LCCOMB_X64_Y43_N16
\b2v_inst12|c_out~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \b2v_inst12|c_out~0_combout\ = (\b2v_inst11|c_out~0_combout\ & ((\SYNTHESIZED_WIRE_12~combout\) # (\SYNTHESIZED_WIRE_26~combout\ $ (\b2v_inst|c_out~0_combout\)))) # (!\b2v_inst11|c_out~0_combout\ & (\SYNTHESIZED_WIRE_12~combout\ & 
-- (\SYNTHESIZED_WIRE_26~combout\ $ (\b2v_inst|c_out~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000111011101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b2v_inst11|c_out~0_combout\,
	datab => \SYNTHESIZED_WIRE_12~combout\,
	datac => \SYNTHESIZED_WIRE_26~combout\,
	datad => \b2v_inst|c_out~0_combout\,
	combout => \b2v_inst12|c_out~0_combout\);

-- Location: LCCOMB_X63_Y43_N14
\b2v_inst19|c_out~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \b2v_inst19|c_out~0_combout\ = (\b2v_inst39|c_out~1_combout\ & ((\SYNTHESIZED_WIRE_24~combout\) # (\b2v_inst12|SYNTHESIZED_WIRE_4~combout\ $ (\b2v_inst11|c_out~0_combout\)))) # (!\b2v_inst39|c_out~1_combout\ & (\SYNTHESIZED_WIRE_24~combout\ & 
-- (\b2v_inst12|SYNTHESIZED_WIRE_4~combout\ $ (\b2v_inst11|c_out~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000111011101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b2v_inst39|c_out~1_combout\,
	datab => \SYNTHESIZED_WIRE_24~combout\,
	datac => \b2v_inst12|SYNTHESIZED_WIRE_4~combout\,
	datad => \b2v_inst11|c_out~0_combout\,
	combout => \b2v_inst19|c_out~0_combout\);

-- Location: LCCOMB_X64_Y43_N2
\b2v_inst15|sum\ : cycloneii_lcell_comb
-- Equation(s):
-- \b2v_inst15|sum~combout\ = \SYNTHESIZED_WIRE_21~combout\ $ (\b2v_inst13|SYNTHESIZED_WIRE_4~combout\ $ (\b2v_inst12|c_out~0_combout\ $ (\b2v_inst19|c_out~0_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0110100110010110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SYNTHESIZED_WIRE_21~combout\,
	datab => \b2v_inst13|SYNTHESIZED_WIRE_4~combout\,
	datac => \b2v_inst12|c_out~0_combout\,
	datad => \b2v_inst19|c_out~0_combout\,
	combout => \b2v_inst15|sum~combout\);

-- Location: LCCOMB_X64_Y43_N30
SYNTHESIZED_WIRE_15 : cycloneii_lcell_comb
-- Equation(s):
-- \SYNTHESIZED_WIRE_15~combout\ = (\x~combout\(3) & \y~combout\(2))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \x~combout\(3),
	datad => \y~combout\(2),
	combout => \SYNTHESIZED_WIRE_15~combout\);

-- Location: LCCOMB_X64_Y43_N24
\b2v_inst13|c_out~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \b2v_inst13|c_out~0_combout\ = (\b2v_inst12|c_out~0_combout\ & ((\SYNTHESIZED_WIRE_15~combout\) # ((\SYNTHESIZED_WIRE_26~combout\ & \b2v_inst|c_out~0_combout\)))) # (!\b2v_inst12|c_out~0_combout\ & (\SYNTHESIZED_WIRE_15~combout\ & 
-- (\SYNTHESIZED_WIRE_26~combout\ & \b2v_inst|c_out~0_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110100010001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b2v_inst12|c_out~0_combout\,
	datab => \SYNTHESIZED_WIRE_15~combout\,
	datac => \SYNTHESIZED_WIRE_26~combout\,
	datad => \b2v_inst|c_out~0_combout\,
	combout => \b2v_inst13|c_out~0_combout\);

-- Location: LCCOMB_X64_Y43_N4
\b2v_inst15|c_out~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \b2v_inst15|c_out~0_combout\ = (\SYNTHESIZED_WIRE_21~combout\ & ((\b2v_inst19|c_out~0_combout\) # (\b2v_inst13|SYNTHESIZED_WIRE_4~combout\ $ (\b2v_inst12|c_out~0_combout\)))) # (!\SYNTHESIZED_WIRE_21~combout\ & (\b2v_inst19|c_out~0_combout\ & 
-- (\b2v_inst13|SYNTHESIZED_WIRE_4~combout\ $ (\b2v_inst12|c_out~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011111000101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \SYNTHESIZED_WIRE_21~combout\,
	datab => \b2v_inst13|SYNTHESIZED_WIRE_4~combout\,
	datac => \b2v_inst12|c_out~0_combout\,
	datad => \b2v_inst19|c_out~0_combout\,
	combout => \b2v_inst15|c_out~0_combout\);

-- Location: LCCOMB_X64_Y43_N18
\b2v_inst14|sum~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \b2v_inst14|sum~0_combout\ = \b2v_inst13|c_out~0_combout\ $ (\b2v_inst15|c_out~0_combout\ $ (((\y~combout\(3) & \x~combout\(3)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001011001011010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b2v_inst13|c_out~0_combout\,
	datab => \y~combout\(3),
	datac => \b2v_inst15|c_out~0_combout\,
	datad => \x~combout\(3),
	combout => \b2v_inst14|sum~0_combout\);

-- Location: LCCOMB_X64_Y43_N20
\b2v_inst14|c_out~0\ : cycloneii_lcell_comb
-- Equation(s):
-- \b2v_inst14|c_out~0_combout\ = (\b2v_inst13|c_out~0_combout\ & ((\b2v_inst15|c_out~0_combout\) # ((\y~combout\(3) & \x~combout\(3))))) # (!\b2v_inst13|c_out~0_combout\ & (\y~combout\(3) & (\b2v_inst15|c_out~0_combout\ & \x~combout\(3))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110100010100000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \b2v_inst13|c_out~0_combout\,
	datab => \y~combout\(3),
	datac => \b2v_inst15|c_out~0_combout\,
	datad => \x~combout\(3),
	combout => \b2v_inst14|c_out~0_combout\);

-- Location: PIN_F18,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
\mul[0]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	datain => \mul_ALTERA_SYNTHESIZED~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_mul(0));

-- Location: PIN_G17,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
\mul[1]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	datain => \b2v_inst1|sum~combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_mul(1));

-- Location: PIN_A19,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
\mul[2]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	datain => \b2v_inst5|sum~combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_mul(2));

-- Location: PIN_H17,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
\mul[3]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	datain => \b2v_inst39|sum~combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_mul(3));

-- Location: PIN_F17,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
\mul[4]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	datain => \b2v_inst19|sum~combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_mul(4));

-- Location: PIN_J17,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
\mul[5]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	datain => \b2v_inst15|sum~combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_mul(5));

-- Location: PIN_G18,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
\mul[6]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	datain => \b2v_inst14|sum~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_mul(6));

-- Location: PIN_C17,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 24mA
\mul[7]~I\ : cycloneii_io
-- pragma translate_off
GENERIC MAP (
	input_async_reset => "none",
	input_power_up => "low",
	input_register_mode => "none",
	input_sync_reset => "none",
	oe_async_reset => "none",
	oe_power_up => "low",
	oe_register_mode => "none",
	oe_sync_reset => "none",
	operation_mode => "output",
	output_async_reset => "none",
	output_power_up => "low",
	output_register_mode => "none",
	output_sync_reset => "none")
-- pragma translate_on
PORT MAP (
	datain => \b2v_inst14|c_out~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	devoe => ww_devoe,
	oe => VCC,
	padio => ww_mul(7));
END structure;


