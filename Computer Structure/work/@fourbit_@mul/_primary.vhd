library verilog;
use verilog.vl_types.all;
entity Fourbit_Mul is
    port(
        x               : in     vl_logic_vector(3 downto 0);
        y               : in     vl_logic_vector(3 downto 0);
        mul             : out    vl_logic_vector(7 downto 0)
    );
end Fourbit_Mul;
