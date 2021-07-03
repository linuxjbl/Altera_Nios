#!/bin/sh
#
# This file was automatically generated.
#
# It can be overwritten by nios2-flash-programmer-generate or nios2-flash-programmer-gui.
#

#
# Converting SOF File: C:\JBL\Altera_Nios\output_files\top_nios_sys.sof to: "..\flash/top_nios_sys_epcs_flash_controller_0.flash"
#
sof2flash --input="C:/JBL/Altera_Nios/output_files/top_nios_sys.sof" --output="../flash/top_nios_sys_epcs_flash_controller_0.flash" --epcs --verbose 

#
# Programming File: "..\flash/top_nios_sys_epcs_flash_controller_0.flash" To Device: epcs_flash_controller_0
#
nios2-flash-programmer "../flash/top_nios_sys_epcs_flash_controller_0.flash" --base=0x70000 --epcs --accept-bad-sysid --device=1 --instance=0 '--cable=USB-Blaster on localhost [USB-0]' --program --verbose 

#
# Converting ELF File: C:\JBL\Altera_Nios\software\app02\app02.elf to: "..\flash/app02_epcs_flash_controller_0.flash"
#
elf2flash --input="app02.elf" --output="../flash/app02_epcs_flash_controller_0.flash" --epcs --after="../flash/top_nios_sys_epcs_flash_controller_0.flash" --verbose 

#
# Programming File: "..\flash/app02_epcs_flash_controller_0.flash" To Device: epcs_flash_controller_0
#
nios2-flash-programmer "../flash/app02_epcs_flash_controller_0.flash" --base=0x70000 --epcs --accept-bad-sysid --device=1 --instance=0 '--cable=USB-Blaster on localhost [USB-0]' --program --verbose 

