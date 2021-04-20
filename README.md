# Peripheral-MEC1501
Microchip MEC1501 peripheral CMSIS style header files

Microchip CPG MEC1501 Peripheral Library

Origin: Microchip CPG

Status: version 0.6

Purpose: Official peripheral firmware library for MEC1501

Description: Microchip MEC1501 Perihperal Library provides a set of low-level header files to configure and use MEC1501 hardware peripheral blocks.

URL: https://github.com/MicrochipTech/Peripheral-MEC1501

commit: n/a

Maintained-by: Microchip CPG FW team

License: Apache-2.0

License Link: https://www.apache.org/licenses/LICENSE-2.0

Patch List:
Update this README.md
Add header files.

v0.3
Add array register access to identical arrays of registers in ADC, DMA, ECIA,
GPIO, and QMSPI.
Remove unnecessary semi-colons from ESPI_IO.
Remove unnecessary casting from regaccess.h

v0.4
Re-name KBC register structure register at offset 0x330 to "ACTV" to match
MEC1501 device inventory chapter.

v0.5
Fix missing GIRQ22 in ECIA enumeration.

v0.6
For each GIRQ add bit definitions for each interrupt source.
Add BIT() macro if not defined.
Add peripheral instance macros.
Synchronize with hal_microchip. 