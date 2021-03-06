/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_qsys_0' in SOPC Builder design 'nios2e'
 * SOPC Builder design path: ../../nios2e.sopcinfo
 *
 * Generated: Sat Jul 03 21:04:02 KST 2021
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x00000820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x13
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x00010020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x13
#define ALT_CPU_NAME "nios2_qsys_0"
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x00070000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00000820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x13
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x00010020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x13
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x00070000


/*
 * DECODE1 configuration
 *
 */

#define ALT_MODULE_CLASS_DECODE1 altera_avalon_pio
#define DECODE1_BASE 0x35000
#define DECODE1_BIT_CLEARING_EDGE_REGISTER 0
#define DECODE1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DECODE1_CAPTURE 0
#define DECODE1_DATA_WIDTH 28
#define DECODE1_DO_TEST_BENCH_WIRING 0
#define DECODE1_DRIVEN_SIM_VALUE 0
#define DECODE1_EDGE_TYPE "NONE"
#define DECODE1_FREQ 50000000
#define DECODE1_HAS_IN 0
#define DECODE1_HAS_OUT 1
#define DECODE1_HAS_TRI 0
#define DECODE1_IRQ -1
#define DECODE1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DECODE1_IRQ_TYPE "NONE"
#define DECODE1_NAME "/dev/DECODE1"
#define DECODE1_RESET_VALUE 0
#define DECODE1_SPAN 16
#define DECODE1_TYPE "altera_avalon_pio"


/*
 * DECODE2 configuration
 *
 */

#define ALT_MODULE_CLASS_DECODE2 altera_avalon_pio
#define DECODE2_BASE 0x36000
#define DECODE2_BIT_CLEARING_EDGE_REGISTER 0
#define DECODE2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DECODE2_CAPTURE 0
#define DECODE2_DATA_WIDTH 28
#define DECODE2_DO_TEST_BENCH_WIRING 0
#define DECODE2_DRIVEN_SIM_VALUE 0
#define DECODE2_EDGE_TYPE "NONE"
#define DECODE2_FREQ 50000000
#define DECODE2_HAS_IN 0
#define DECODE2_HAS_OUT 1
#define DECODE2_HAS_TRI 0
#define DECODE2_IRQ -1
#define DECODE2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DECODE2_IRQ_TYPE "NONE"
#define DECODE2_NAME "/dev/DECODE2"
#define DECODE2_RESET_VALUE 0
#define DECODE2_SPAN 16
#define DECODE2_TYPE "altera_avalon_pio"


/*
 * DECODE3 configuration
 *
 */

#define ALT_MODULE_CLASS_DECODE3 altera_avalon_pio
#define DECODE3_BASE 0x37000
#define DECODE3_BIT_CLEARING_EDGE_REGISTER 0
#define DECODE3_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DECODE3_CAPTURE 0
#define DECODE3_DATA_WIDTH 28
#define DECODE3_DO_TEST_BENCH_WIRING 0
#define DECODE3_DRIVEN_SIM_VALUE 0
#define DECODE3_EDGE_TYPE "NONE"
#define DECODE3_FREQ 50000000
#define DECODE3_HAS_IN 0
#define DECODE3_HAS_OUT 1
#define DECODE3_HAS_TRI 0
#define DECODE3_IRQ -1
#define DECODE3_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DECODE3_IRQ_TYPE "NONE"
#define DECODE3_NAME "/dev/DECODE3"
#define DECODE3_RESET_VALUE 0
#define DECODE3_SPAN 16
#define DECODE3_TYPE "altera_avalon_pio"


/*
 * DECODE4 configuration
 *
 */

#define ALT_MODULE_CLASS_DECODE4 altera_avalon_pio
#define DECODE4_BASE 0x38000
#define DECODE4_BIT_CLEARING_EDGE_REGISTER 0
#define DECODE4_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DECODE4_CAPTURE 0
#define DECODE4_DATA_WIDTH 28
#define DECODE4_DO_TEST_BENCH_WIRING 0
#define DECODE4_DRIVEN_SIM_VALUE 0
#define DECODE4_EDGE_TYPE "NONE"
#define DECODE4_FREQ 50000000
#define DECODE4_HAS_IN 0
#define DECODE4_HAS_OUT 1
#define DECODE4_HAS_TRI 0
#define DECODE4_IRQ -1
#define DECODE4_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DECODE4_IRQ_TYPE "NONE"
#define DECODE4_NAME "/dev/DECODE4"
#define DECODE4_RESET_VALUE 0
#define DECODE4_SPAN 16
#define DECODE4_TYPE "altera_avalon_pio"


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_EPCS_FLASH_CONTROLLER
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_UART
#define __ALTERA_NIOS2_GEN2


/*
 * HEX0 configuration
 *
 */

#define ALT_MODULE_CLASS_HEX0 altera_avalon_pio
#define HEX0_BASE 0x40000
#define HEX0_BIT_CLEARING_EDGE_REGISTER 0
#define HEX0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX0_CAPTURE 0
#define HEX0_DATA_WIDTH 8
#define HEX0_DO_TEST_BENCH_WIRING 0
#define HEX0_DRIVEN_SIM_VALUE 0
#define HEX0_EDGE_TYPE "NONE"
#define HEX0_FREQ 50000000
#define HEX0_HAS_IN 0
#define HEX0_HAS_OUT 1
#define HEX0_HAS_TRI 0
#define HEX0_IRQ -1
#define HEX0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX0_IRQ_TYPE "NONE"
#define HEX0_NAME "/dev/HEX0"
#define HEX0_RESET_VALUE 0
#define HEX0_SPAN 16
#define HEX0_TYPE "altera_avalon_pio"


/*
 * HEX1 configuration
 *
 */

#define ALT_MODULE_CLASS_HEX1 altera_avalon_pio
#define HEX1_BASE 0x41000
#define HEX1_BIT_CLEARING_EDGE_REGISTER 0
#define HEX1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX1_CAPTURE 0
#define HEX1_DATA_WIDTH 8
#define HEX1_DO_TEST_BENCH_WIRING 0
#define HEX1_DRIVEN_SIM_VALUE 0
#define HEX1_EDGE_TYPE "NONE"
#define HEX1_FREQ 50000000
#define HEX1_HAS_IN 0
#define HEX1_HAS_OUT 1
#define HEX1_HAS_TRI 0
#define HEX1_IRQ -1
#define HEX1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX1_IRQ_TYPE "NONE"
#define HEX1_NAME "/dev/HEX1"
#define HEX1_RESET_VALUE 0
#define HEX1_SPAN 16
#define HEX1_TYPE "altera_avalon_pio"


/*
 * HEX2 configuration
 *
 */

#define ALT_MODULE_CLASS_HEX2 altera_avalon_pio
#define HEX2_BASE 0x42000
#define HEX2_BIT_CLEARING_EDGE_REGISTER 0
#define HEX2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX2_CAPTURE 0
#define HEX2_DATA_WIDTH 8
#define HEX2_DO_TEST_BENCH_WIRING 0
#define HEX2_DRIVEN_SIM_VALUE 0
#define HEX2_EDGE_TYPE "NONE"
#define HEX2_FREQ 50000000
#define HEX2_HAS_IN 0
#define HEX2_HAS_OUT 1
#define HEX2_HAS_TRI 0
#define HEX2_IRQ -1
#define HEX2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX2_IRQ_TYPE "NONE"
#define HEX2_NAME "/dev/HEX2"
#define HEX2_RESET_VALUE 0
#define HEX2_SPAN 16
#define HEX2_TYPE "altera_avalon_pio"


/*
 * HEX3 configuration
 *
 */

#define ALT_MODULE_CLASS_HEX3 altera_avalon_pio
#define HEX3_BASE 0x43000
#define HEX3_BIT_CLEARING_EDGE_REGISTER 0
#define HEX3_BIT_MODIFYING_OUTPUT_REGISTER 0
#define HEX3_CAPTURE 0
#define HEX3_DATA_WIDTH 8
#define HEX3_DO_TEST_BENCH_WIRING 0
#define HEX3_DRIVEN_SIM_VALUE 0
#define HEX3_EDGE_TYPE "NONE"
#define HEX3_FREQ 50000000
#define HEX3_HAS_IN 0
#define HEX3_HAS_OUT 1
#define HEX3_HAS_TRI 0
#define HEX3_IRQ -1
#define HEX3_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HEX3_IRQ_TYPE "NONE"
#define HEX3_NAME "/dev/HEX3"
#define HEX3_RESET_VALUE 0
#define HEX3_SPAN 16
#define HEX3_TYPE "altera_avalon_pio"


/*
 * PERIOD1 configuration
 *
 */

#define ALT_MODULE_CLASS_PERIOD1 altera_avalon_pio
#define PERIOD1_BASE 0x31000
#define PERIOD1_BIT_CLEARING_EDGE_REGISTER 0
#define PERIOD1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PERIOD1_CAPTURE 0
#define PERIOD1_DATA_WIDTH 28
#define PERIOD1_DO_TEST_BENCH_WIRING 0
#define PERIOD1_DRIVEN_SIM_VALUE 0
#define PERIOD1_EDGE_TYPE "NONE"
#define PERIOD1_FREQ 50000000
#define PERIOD1_HAS_IN 0
#define PERIOD1_HAS_OUT 1
#define PERIOD1_HAS_TRI 0
#define PERIOD1_IRQ -1
#define PERIOD1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PERIOD1_IRQ_TYPE "NONE"
#define PERIOD1_NAME "/dev/PERIOD1"
#define PERIOD1_RESET_VALUE 0
#define PERIOD1_SPAN 16
#define PERIOD1_TYPE "altera_avalon_pio"


/*
 * PERIOD2 configuration
 *
 */

#define ALT_MODULE_CLASS_PERIOD2 altera_avalon_pio
#define PERIOD2_BASE 0x32000
#define PERIOD2_BIT_CLEARING_EDGE_REGISTER 0
#define PERIOD2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PERIOD2_CAPTURE 0
#define PERIOD2_DATA_WIDTH 28
#define PERIOD2_DO_TEST_BENCH_WIRING 0
#define PERIOD2_DRIVEN_SIM_VALUE 0
#define PERIOD2_EDGE_TYPE "NONE"
#define PERIOD2_FREQ 50000000
#define PERIOD2_HAS_IN 0
#define PERIOD2_HAS_OUT 1
#define PERIOD2_HAS_TRI 0
#define PERIOD2_IRQ -1
#define PERIOD2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PERIOD2_IRQ_TYPE "NONE"
#define PERIOD2_NAME "/dev/PERIOD2"
#define PERIOD2_RESET_VALUE 0
#define PERIOD2_SPAN 16
#define PERIOD2_TYPE "altera_avalon_pio"


/*
 * PERIOD3 configuration
 *
 */

#define ALT_MODULE_CLASS_PERIOD3 altera_avalon_pio
#define PERIOD3_BASE 0x33000
#define PERIOD3_BIT_CLEARING_EDGE_REGISTER 0
#define PERIOD3_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PERIOD3_CAPTURE 0
#define PERIOD3_DATA_WIDTH 28
#define PERIOD3_DO_TEST_BENCH_WIRING 0
#define PERIOD3_DRIVEN_SIM_VALUE 0
#define PERIOD3_EDGE_TYPE "NONE"
#define PERIOD3_FREQ 50000000
#define PERIOD3_HAS_IN 0
#define PERIOD3_HAS_OUT 1
#define PERIOD3_HAS_TRI 0
#define PERIOD3_IRQ -1
#define PERIOD3_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PERIOD3_IRQ_TYPE "NONE"
#define PERIOD3_NAME "/dev/PERIOD3"
#define PERIOD3_RESET_VALUE 0
#define PERIOD3_SPAN 16
#define PERIOD3_TYPE "altera_avalon_pio"


/*
 * PERIOD4 configuration
 *
 */

#define ALT_MODULE_CLASS_PERIOD4 altera_avalon_pio
#define PERIOD4_BASE 0x34000
#define PERIOD4_BIT_CLEARING_EDGE_REGISTER 0
#define PERIOD4_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PERIOD4_CAPTURE 0
#define PERIOD4_DATA_WIDTH 28
#define PERIOD4_DO_TEST_BENCH_WIRING 0
#define PERIOD4_DRIVEN_SIM_VALUE 0
#define PERIOD4_EDGE_TYPE "NONE"
#define PERIOD4_FREQ 50000000
#define PERIOD4_HAS_IN 0
#define PERIOD4_HAS_OUT 1
#define PERIOD4_HAS_TRI 0
#define PERIOD4_IRQ -1
#define PERIOD4_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PERIOD4_IRQ_TYPE "NONE"
#define PERIOD4_NAME "/dev/PERIOD4"
#define PERIOD4_RESET_VALUE 0
#define PERIOD4_SPAN 16
#define PERIOD4_TYPE "altera_avalon_pio"


/*
 * PUSH configuration
 *
 */

#define ALT_MODULE_CLASS_PUSH altera_avalon_pio
#define PUSH_BASE 0x50000
#define PUSH_BIT_CLEARING_EDGE_REGISTER 0
#define PUSH_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PUSH_CAPTURE 0
#define PUSH_DATA_WIDTH 4
#define PUSH_DO_TEST_BENCH_WIRING 0
#define PUSH_DRIVEN_SIM_VALUE 0
#define PUSH_EDGE_TYPE "NONE"
#define PUSH_FREQ 50000000
#define PUSH_HAS_IN 1
#define PUSH_HAS_OUT 0
#define PUSH_HAS_TRI 0
#define PUSH_IRQ -1
#define PUSH_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PUSH_IRQ_TYPE "NONE"
#define PUSH_NAME "/dev/PUSH"
#define PUSH_RESET_VALUE 0
#define PUSH_SPAN 16
#define PUSH_TYPE "altera_avalon_pio"


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone IV E"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/uart_0"
#define ALT_STDERR_BASE 0x60000
#define ALT_STDERR_DEV uart_0
#define ALT_STDERR_IS_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_uart"
#define ALT_STDIN "/dev/uart_0"
#define ALT_STDIN_BASE 0x60000
#define ALT_STDIN_DEV uart_0
#define ALT_STDIN_IS_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_uart"
#define ALT_STDOUT "/dev/uart_0"
#define ALT_STDOUT_BASE 0x60000
#define ALT_STDOUT_DEV uart_0
#define ALT_STDOUT_IS_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_uart"
#define ALT_SYSTEM_NAME "nios2e"


/*
 * epcs_flash_controller_0 configuration
 *
 */

#define ALT_MODULE_CLASS_epcs_flash_controller_0 altera_avalon_epcs_flash_controller
#define EPCS_FLASH_CONTROLLER_0_BASE 0x70000
#define EPCS_FLASH_CONTROLLER_0_IRQ 1
#define EPCS_FLASH_CONTROLLER_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define EPCS_FLASH_CONTROLLER_0_NAME "/dev/epcs_flash_controller_0"
#define EPCS_FLASH_CONTROLLER_0_REGISTER_OFFSET 1024
#define EPCS_FLASH_CONTROLLER_0_SPAN 2048
#define EPCS_FLASH_CONTROLLER_0_TYPE "altera_avalon_epcs_flash_controller"


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 4
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK none


/*
 * onchip_memory2_0 configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_memory2_0 altera_avalon_onchip_memory2
#define ONCHIP_MEMORY2_0_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEMORY2_0_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY2_0_BASE 0x10000
#define ONCHIP_MEMORY2_0_CONTENTS_INFO ""
#define ONCHIP_MEMORY2_0_DUAL_PORT 0
#define ONCHIP_MEMORY2_0_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_INIT_CONTENTS_FILE "nios2e_onchip_memory2_0"
#define ONCHIP_MEMORY2_0_INIT_MEM_CONTENT 1
#define ONCHIP_MEMORY2_0_INSTANCE_ID "NONE"
#define ONCHIP_MEMORY2_0_IRQ -1
#define ONCHIP_MEMORY2_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY2_0_NAME "/dev/onchip_memory2_0"
#define ONCHIP_MEMORY2_0_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEMORY2_0_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_0_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY2_0_SINGLE_CLOCK_OP 0
#define ONCHIP_MEMORY2_0_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY2_0_SIZE_VALUE 16384
#define ONCHIP_MEMORY2_0_SPAN 16384
#define ONCHIP_MEMORY2_0_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY2_0_WRITABLE 1


/*
 * uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_uart_0 altera_avalon_uart
#define UART_0_BASE 0x60000
#define UART_0_BAUD 115200
#define UART_0_DATA_BITS 8
#define UART_0_FIXED_BAUD 1
#define UART_0_FREQ 50000000
#define UART_0_IRQ 0
#define UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define UART_0_NAME "/dev/uart_0"
#define UART_0_PARITY 'N'
#define UART_0_SIM_CHAR_STREAM ""
#define UART_0_SIM_TRUE_BAUD 0
#define UART_0_SPAN 32
#define UART_0_STOP_BITS 1
#define UART_0_SYNC_REG_DEPTH 2
#define UART_0_TYPE "altera_avalon_uart"
#define UART_0_USE_CTS_RTS 0
#define UART_0_USE_EOP_REGISTER 0

#endif /* __SYSTEM_H_ */
