	component nios2e is
		port (
			clk_clk                                : in    std_logic                     := 'X';             -- clk
			decode1_external_connection_export     : out   std_logic_vector(27 downto 0);                    -- export
			decode2_external_connection_export     : out   std_logic_vector(27 downto 0);                    -- export
			decode3_external_connection_export     : out   std_logic_vector(27 downto 0);                    -- export
			decode4_external_connection_export     : out   std_logic_vector(27 downto 0);                    -- export
			epcs_flash_controller_0_external_dclk  : out   std_logic;                                        -- dclk
			epcs_flash_controller_0_external_sce   : out   std_logic;                                        -- sce
			epcs_flash_controller_0_external_sdo   : out   std_logic;                                        -- sdo
			epcs_flash_controller_0_external_data0 : in    std_logic                     := 'X';             -- data0
			hex0_external_connection_export        : out   std_logic_vector(7 downto 0);                     -- export
			hex1_external_connection_export        : out   std_logic_vector(7 downto 0);                     -- export
			hex2_external_connection_export        : out   std_logic_vector(7 downto 0);                     -- export
			hex3_external_connection_export        : out   std_logic_vector(7 downto 0);                     -- export
			new_sdram_controller_0_wire_addr       : out   std_logic_vector(11 downto 0);                    -- addr
			new_sdram_controller_0_wire_ba         : out   std_logic_vector(1 downto 0);                     -- ba
			new_sdram_controller_0_wire_cas_n      : out   std_logic;                                        -- cas_n
			new_sdram_controller_0_wire_cke        : out   std_logic;                                        -- cke
			new_sdram_controller_0_wire_cs_n       : out   std_logic;                                        -- cs_n
			new_sdram_controller_0_wire_dq         : inout std_logic_vector(15 downto 0) := (others => 'X'); -- dq
			new_sdram_controller_0_wire_dqm        : out   std_logic_vector(1 downto 0);                     -- dqm
			new_sdram_controller_0_wire_ras_n      : out   std_logic;                                        -- ras_n
			new_sdram_controller_0_wire_we_n       : out   std_logic;                                        -- we_n
			period1_external_connection_export     : out   std_logic_vector(27 downto 0);                    -- export
			period2_external_connection_export     : out   std_logic_vector(27 downto 0);                    -- export
			period3_external_connection_export     : out   std_logic_vector(27 downto 0);                    -- export
			period4_external_connection_export     : out   std_logic_vector(27 downto 0);                    -- export
			push_external_connection_export        : in    std_logic_vector(3 downto 0)  := (others => 'X'); -- export
			reset_reset_n                          : in    std_logic                     := 'X'              -- reset_n
		);
	end component nios2e;

	u0 : component nios2e
		port map (
			clk_clk                                => CONNECTED_TO_clk_clk,                                --                              clk.clk
			decode1_external_connection_export     => CONNECTED_TO_decode1_external_connection_export,     --      decode1_external_connection.export
			decode2_external_connection_export     => CONNECTED_TO_decode2_external_connection_export,     --      decode2_external_connection.export
			decode3_external_connection_export     => CONNECTED_TO_decode3_external_connection_export,     --      decode3_external_connection.export
			decode4_external_connection_export     => CONNECTED_TO_decode4_external_connection_export,     --      decode4_external_connection.export
			epcs_flash_controller_0_external_dclk  => CONNECTED_TO_epcs_flash_controller_0_external_dclk,  -- epcs_flash_controller_0_external.dclk
			epcs_flash_controller_0_external_sce   => CONNECTED_TO_epcs_flash_controller_0_external_sce,   --                                 .sce
			epcs_flash_controller_0_external_sdo   => CONNECTED_TO_epcs_flash_controller_0_external_sdo,   --                                 .sdo
			epcs_flash_controller_0_external_data0 => CONNECTED_TO_epcs_flash_controller_0_external_data0, --                                 .data0
			hex0_external_connection_export        => CONNECTED_TO_hex0_external_connection_export,        --         hex0_external_connection.export
			hex1_external_connection_export        => CONNECTED_TO_hex1_external_connection_export,        --         hex1_external_connection.export
			hex2_external_connection_export        => CONNECTED_TO_hex2_external_connection_export,        --         hex2_external_connection.export
			hex3_external_connection_export        => CONNECTED_TO_hex3_external_connection_export,        --         hex3_external_connection.export
			new_sdram_controller_0_wire_addr       => CONNECTED_TO_new_sdram_controller_0_wire_addr,       --      new_sdram_controller_0_wire.addr
			new_sdram_controller_0_wire_ba         => CONNECTED_TO_new_sdram_controller_0_wire_ba,         --                                 .ba
			new_sdram_controller_0_wire_cas_n      => CONNECTED_TO_new_sdram_controller_0_wire_cas_n,      --                                 .cas_n
			new_sdram_controller_0_wire_cke        => CONNECTED_TO_new_sdram_controller_0_wire_cke,        --                                 .cke
			new_sdram_controller_0_wire_cs_n       => CONNECTED_TO_new_sdram_controller_0_wire_cs_n,       --                                 .cs_n
			new_sdram_controller_0_wire_dq         => CONNECTED_TO_new_sdram_controller_0_wire_dq,         --                                 .dq
			new_sdram_controller_0_wire_dqm        => CONNECTED_TO_new_sdram_controller_0_wire_dqm,        --                                 .dqm
			new_sdram_controller_0_wire_ras_n      => CONNECTED_TO_new_sdram_controller_0_wire_ras_n,      --                                 .ras_n
			new_sdram_controller_0_wire_we_n       => CONNECTED_TO_new_sdram_controller_0_wire_we_n,       --                                 .we_n
			period1_external_connection_export     => CONNECTED_TO_period1_external_connection_export,     --      period1_external_connection.export
			period2_external_connection_export     => CONNECTED_TO_period2_external_connection_export,     --      period2_external_connection.export
			period3_external_connection_export     => CONNECTED_TO_period3_external_connection_export,     --      period3_external_connection.export
			period4_external_connection_export     => CONNECTED_TO_period4_external_connection_export,     --      period4_external_connection.export
			push_external_connection_export        => CONNECTED_TO_push_external_connection_export,        --         push_external_connection.export
			reset_reset_n                          => CONNECTED_TO_reset_reset_n                           --                            reset.reset_n
		);

