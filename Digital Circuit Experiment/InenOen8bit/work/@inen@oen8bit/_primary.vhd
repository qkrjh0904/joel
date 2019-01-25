library verilog;
use verilog.vl_types.all;
entity InenOen8bit is
    port(
        Oen             : in     vl_logic;
        clk             : in     vl_logic;
        clr             : in     vl_logic;
        Inen            : in     vl_logic;
        data_in         : in     vl_logic_vector(7 downto 0);
        data_out        : out    vl_logic_vector(7 downto 0)
    );
end InenOen8bit;
