library verilog;
use verilog.vl_types.all;
entity FullAdder is
    port(
        y_in            : in     vl_logic;
        x_in            : in     vl_logic;
        c_in            : in     vl_logic;
        c_out           : out    vl_logic;
        sum             : out    vl_logic
    );
end FullAdder;
