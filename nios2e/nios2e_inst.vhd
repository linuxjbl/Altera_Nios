	component nios2e is
		port (
			clk_clk                            : in  std_logic                     := 'X';             -- clk
			decode1_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			decode2_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			decode3_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			decode4_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			hex0_external_connection_export    : out std_logic_vector(7 downto 0);                     -- export
			hex1_external_connection_export    : out std_logic_vector(7 downto 0);                     -- export
			hex2_external_connection_export    : out std_logic_vector(7 downto 0);                     -- export
			hex3_external_connection_export    : out std_logic_vector(7 downto 0);                     -- export
			period1_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			period2_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			period3_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			period4_external_connection_export : out std_logic_vector(27 downto 0);                    -- export
			push_external_connection_export    : in  std_logic_vector(3 downto 0)  := (others => 'X'); -- export
			reset_reset_n                      : in  std_logic                     := 'X';             -- reset_n
			uart_0_external_connection_rxd     : in  std_logic                     := 'X';             -- rxd
			uart_0_external_connection_txd     : out std_logic                                         -- txd
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
			hex1_external_connection_export    => CONNECTED_TO_hex1_external_connection_export,    --    hex1_external_connection.export
			hex2_external_connection_export    => CONNECTED_TO_hex2_external_connection_export,    --    hex2_external_connection.export
			hex3_external_connection_export    => CONNECTED_TO_hex3_external_connection_export,    --    hex3_external_connection.export
			period1_external_connection_export => CONNECTED_TO_period1_external_connection_export, -- period1_external_connection.export
			period2_external_connection_export => CONNECTED_TO_period2_external_connection_export, -- period2_external_connection.export
			period3_external_connection_export => CONNECTED_TO_period3_external_connection_export, -- period3_external_connection.export
			period4_external_connection_export => CONNECTED_TO_period4_external_connection_export, -- period4_external_connection.export
			push_external_connection_export    => CONNECTED_TO_push_external_connection_export,    --    push_external_connection.export
			reset_reset_n                      => CONNECTED_TO_reset_reset_n,                      --                       reset.reset_n
			uart_0_external_connection_rxd     => CONNECTED_TO_uart_0_external_connection_rxd,     --  uart_0_external_connection.rxd
			uart_0_external_connection_txd     => CONNECTED_TO_uart_0_external_connection_txd      --                            .txd
		);

