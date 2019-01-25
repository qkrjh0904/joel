library verilog;
use verilog.vl_types.all;
entity InenOen4bit is
    port(
        clr             : in     vl_logic;
        clk             : in     vl_logic;
        Inen            : in     vl_logic;
        Oen             : in     vl_logic;
        data_in         : in     vl_logic_vector(3 downto 0);
        data_out        : out    vl_logic_vector(3 downto 0)
    );
end InenOen4bit;
