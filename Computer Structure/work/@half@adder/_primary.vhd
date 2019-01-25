library verilog;
use verilog.vl_types.all;
entity HalfAdder is
    port(
        x_in            : in     vl_logic;
        y_in            : in     vl_logic;
        sum             : out    vl_logic;
        c_out           : out    vl_logic
    );
end HalfAdder;
