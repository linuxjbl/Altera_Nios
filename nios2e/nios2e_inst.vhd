	component nios2e is
		port (
			clk_clk                            : in  std_logic                     := 'X';             -- clk
			decode1_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			decode2_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			decode3_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			decode4_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			hex0_external_connection_export    : out std_logic_vector(7 downto 0);                     -- export
			period1_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			period2_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			period3_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			period4_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			push_external_connection_export    : in  std_logic_vector(1 downto 0)  := (others => 'X'); -- export
			reset_reset_n                      : in  std_logic                     := 'X'              -- reset_n
		);
	end component nios2e;

	u0 : component nios2e
		port map (
			clk_clk                            => CONNECTED_TO_clk_clk,                            --                         clk.clk
			decode1_external_connection_export => CONNECTED_TO_decode1_external_connection_export, -- decode1_external_connection.export
			decode2_external_connection_export => CONNECTED_TO_decode2_external_connection_export, -- decode2_external_connection.export
			decode3_external_connection_export => CONNECTED_TO_decode3_external_connection_export, -- decode3_external_connection.export
			decode4_external_connection_export => CONNECTED_TO_decode4_external_connection_export, -- decode4_external_connection.export
			hex0_external_connection_export    => CONNECTED_TO_hex0_external_connection_export,    --    hex0_external_connection.export
			period1_external_connection_export => CONNECTED_TO_period1_external_connection_export, -- period1_external_connection.export
			period2_external_connection_export => CONNECTED_TO_period2_external_connection_export, -- period2_external_connection.export
			period3_external_connection_export => CONNECTED_TO_period3_external_connection_export, -- period3_external_connection.export
			period4_external_connection_export => CONNECTED_TO_period4_external_connection_export, -- period4_external_connection.export
			push_external_connection_export    => CONNECTED_TO_push_external_connection_export,    --    push_external_connection.export
			reset_reset_n                      => CONNECTED_TO_reset_reset_n                       --                       reset.reset_n
		);

