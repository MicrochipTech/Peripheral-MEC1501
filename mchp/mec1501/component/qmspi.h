/**
 *
 * Copyright (c) 2019 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the Licence at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * \asf_license_stop
 *
 */

/** @file qmspi.h
 *MEC1501 Quad Master SPI Registers
 */
/** @defgroup MEC1501 Peripherals QMSPI
 */

#ifndef _QMSPI_H_
#define _QMSPI_H_

#include <stdint.h>
#include <stddef.h>

#include "regaccess.h"

#define QMPSPI_HW_VER	3u

#define MCHP_QMSPI_BASE_ADDR	0x40070000ul

#define MCHP_QMSPI_MAX_DESCR	16ul

#define MCHP_QMSPI_INPUT_CLOCK_FREQ_HZ	48000000ul
#define MCHP_QMSPI_MAX_FREQ_KHZ	((MCHP_QMSPI_INPUT_CLOCK_FREQ_HZ) / 1000ul)
#define MCHP_QMSPI_MIN_FREQ_KHZ	(MCHP_QMSPI_MAX_FREQ_KHZ / 256ul)

#define MCHP_QMSPI_GIRQ_NUM		18u
#define MCHP_QMSPI_GIRQ_POS		1u
#define MCHP_QMSPI_GIRQ_VAL		BIT(MCHP_QMSPI_GIRQ_POS)
#define MCHP_QMSPI_GIRQ_OFS		(((MCHP_QMSPI0_GIRQ_NUM) - 8) * 20u)

#define MCHP_QMSPI_GIRQ_NVIC_AGGR	10u
#define MCHP_QMSPI_GIRQ_NVIC_DIRECT	91u

#define MCHP_QMSPI_GIRQ_BASE_ADDR	0x4000E0C8ul
#define MCHP_QMSPI_GIRQ_SRC_ADDR	(MCHP_QMSPI_GIRQ_BASE_ADDR)
#define MCHP_QMSPI_GIRQ_ENSET_ADDR	(MCHP_QMSPI_GIRQ_BASE_ADDR + 0x04ul)
#define MCHP_QMSPI_GIRQ_RESULT_ADDR	(MCHP_QMSPI_GIRQ_BASE_ADDR + 0x08ul)
#define MCHP_QMSPI_GIRQ_ENCLR_ADDR	(MCHP_QMSPI_GIRQ_BASE_ADDR + 0x0Cul)

/* Sleep Enable 4 bit 8 */
#define MCHP_QMSPI_PCR_SLP_EN_ADDR	0x40080140ul
#define MCHP_QMSPI_PCR_SLP_EN_POS	8u

#define MCHP_QMSPI_GIRQ_EN		(1ul << (MCHP_QMSPI_GIRQ_POS))
#define MCHP_QMSPI_GIRQ_STS		(1ul << (MCHP_QMSPI_GIRQ_POS))

/* Mode 0: Clock idle = Low. Data change falling edge, sample rising edge */
#define MCHP_QMSPI_SPI_MODE0		0ul
/* Mode 1: Clock idle = Low. Data change rising edge, sample falling edge */
#define MCHP_QMSPI_SPI_MODE1		0x06ul
/* Mode 2: Clock idle = High. Data change rising edge, sample falling edge */
#define MCHP_QMSPI_SPI_MODE2		0x06ul
/* Mode 3: Clock idle = High. Data change falling edge, sample rising edge */
#define MCHP_QMSPI_SPI_MODE3		0x07ul

/* Device ID used in DMA channel Control.DeviceID field */
#define MCHP_QMSPI_TX_DMA_REQ_ID	10ul
#define MCHP_QMSPI_RX_DMA_REQ_ID	11ul

/* QMSPI transmit and receive FIFO lengths */
#define MCHP_QMSPI_TX_FIFO_LEN		8ul
#define MCHP_QMSPI_RX_FIFO_LEN		8ul

#define MCHP_QMSPI_M_ACT_SRST_OFS	0ul
#define MCHP_QMSPI_M_SPI_MODE_OFS	1ul
#define MCHP_QMSPI_M_CLK_DIV_OFS	2ul
#define MCHP_QMSPI_CTRL_OFS		4ul
#define MCHP_QMSPI_EXE_OFS		8ul
#define MCHP_QMSPI_IF_CTRL_OFS		0x0Cul
#define MCHP_QMSPI_STS_OFS		0x10ul
#define MCHP_QMSPI_BUF_CNT_STS_OFS	0x14ul
#define MCHP_QMSPI_IEN_OFS		0x18ul
#define MCHP_QMSPI_BUF_CNT_TRIG_OFS	0x1Cul
#define MCHP_QMSPI_TX_FIFO_OFS		0x20ul
#define MCHP_QMSPI_RX_FIFO_OFS		0x24ul
#define MCHP_QMSPI_CSTM_OFS		0x28ul
/* 0 <= n < MCHP_QMSPI_MAX_DESCR */
#define MCHP_QMSPI_DESCR_OFS(n)		(0x30ul + ((uint32_t)(n) * 4U))
#define MCHP_QMSPI_DESC0_OFS		0x30ul

#define MCHP_QMSPI_MODE_ADDR		(MCHP_QMSPI_BASE_ADDR + 0x00)
#define MCHP_QMSPI_CTRL_ADDR		(MCHP_QMSPI_BASE_ADDR + 0x04)
#define MCHP_QMSPI_EXE_ADDR		(MCHP_QMSPI_BASE_ADDR + 0x08)
#define MCHP_QMSPI_IFC_ADDR		(MCHP_QMSPI_BASE_ADDR + 0x0C)
#define MCHP_QMSPI_STS_ADDR		(MCHP_QMSPI_BASE_ADDR + 0x10)
#define MCHP_QMSPI_BUFCNT_STS_ADDR	(MCHP_QMSPI_BASE_ADDR + 0x14)
#define MCHP_QMSPI_TX_BCNT_STS_ADDR	(MCHP_QMSPI_BASE_ADDR + 0x14)
#define MCHP_QMSPI_RX_BCNT_STS_ADDR	(MCHP_QMSPI_BASE_ADDR + 0x16)
#define MCHP_QMSPI_IEN_ADDR		(MCHP_QMSPI_BASE_ADDR + 0x18)
#define MCHP_QMSPI_TXB_ADDR		(MCHP_QMSPI_BASE_ADDR + 0x20)
#define MCHP_QMSPI_RXB_ADDR		(MCHP_QMSPI_BASE_ADDR + 0x24)
#define MCHP_QMSPI_CSTM_ADDR		(MCHP_QMSPI_BASE_ADDR + 0x28)
#define MCHP_QMSPI_DESCR_ADDR(n) \
	(MCHP_QMSPI_BASE_ADDR + (0x30 + (((uint32_t)(n) & 0x0Ful) << 2)))

/* Mode Register */
#define MCHP_QMSPI_M_ACTIVATE		BIT(0)
#define MCHP_QMSPI_M_SRST		BIT(1)
#define MCHP_QMSPI_M_SAF_DMA_MODE_EN	BIT(2)
#define MCHP_QMSPI_M_CPOL_POS		8u
#define MCHP_QMSPI_M_CPOL_CLK_IDLE_LO	0
#define MCHP_QMSPI_M_CPOL_CLK_IDLE_HI	BIT(8)

#define MCHP_QMSPI_M_CPHA_MOSI_POS	9u
/* MOSI data changes on first clock edge of clock pulse */
#define MCHP_QMSPI_M_CPHA_MOSI_CE1	(0ul << 9)
/* MOSI data changes on second clock edge of clock pulse */
#define MCHP_QMSPI_M_CPHA_MOSI_CE2	BIT(9)

#define MCHP_QMSPI_M_CPHA_MIS0_POS	10u
/* MISO data capture on first clock edge of clock pulse */
#define MCHP_QMSPI_M_CPHA_MISO_CE1	0ul
/* MISO data capture on second clock edge of clock pulse */
#define MCHP_QMSPI_M_CPHA_MISO_CE2	BIT(10)

#define MCHP_QMSPI_M_SIG_POS		8u
#define MCHP_QMSPI_M_SIG_MASK0		0x07ul
#define MCHP_QMSPI_M_SIG_MASK		0x0700ul
#define MCHP_QMSPI_M_SIG_MODE0_VAL	0x00ul
#define MCHP_QMSPI_M_SIG_MODE1_VAL	0x06ul
#define MCHP_QMSPI_M_SIG_MODE2_VAL	0x01ul
#define MCHP_QMSPI_M_SIG_MODE3_VAL	0x07ul
#define MCHP_QMSPI_M_SIG_MODE0		0x00ul
#define MCHP_QMSPI_M_SIG_MODE1		(0x06ul << MCHP_QMSPI_M_SIG_POS)
#define MCHP_QMSPI_M_SIG_MODE2		(0x01ul << MCHP_QMSPI_M_SIG_POS)
#define MCHP_QMSPI_M_SIG_MODE3		(0x07ul << MCHP_QMSPI_M_SIG_POS)
#define MCHP_QMSPI_M_CS_POS		12u
#define MCHP_QMSPI_M_CS_MASK0		0x03ul
#define MCHP_QMSPI_M_CS_MASK		(0x03ul << 12)
#define MCHP_QMSPI_M_CS0		(0x00ul << 12)
#define MCHP_QMSPI_M_CS1		(0x01ul << 12)
/* Two chip selects only 0 and 1 */
#define MCHP_QMSPI_M_CS(n) \
	(((uint32_t)(n) & MCHP_QMSPI_M_CS_MASK0) << MCHP_QMSPI_M_CS_POS)
#define MCHP_QMSPI_M_FDIV_POS		16u
#define MCHP_QMSPI_M_FDIV_MASK0		0xFFul
#define MCHP_QMSPI_M_FDIV_MASK		0x00FF0000ul

/* Control/Descriptors */
#define MCHP_QMSPI_C_IFM_MASK		0x03ul
#define MCHP_QMSPI_C_IFM_1X		0x00ul
#define MCHP_QMSPI_C_IFM_2X		0x01ul
#define MCHP_QMSPI_C_IFM_4X		0x02ul
#define MCHP_QMSPI_C_TX_POS		2u
#define MCHP_QMSPI_C_TX_MASK		(0x03ul << MCHP_QMSPI_C_TX_POS)
#define MCHP_QMSPI_C_TX_DIS		(0x00ul << MCHP_QMSPI_C_TX_POS)
#define MCHP_QMSPI_C_TX_DATA		(0x01ul << MCHP_QMSPI_C_TX_POS)
#define MCHP_QMSPI_C_TX_ZEROS		(0x02ul << MCHP_QMSPI_C_TX_POS)
#define MCHP_QMSPI_C_TX_ONES		(0x03ul << MCHP_QMSPI_C_TX_POS)
#define MCHP_QMSPI_C_TX_DMA_POS		4u
#define MCHP_QMSPI_C_TX_DMA_MASK	(0x03ul << MCHP_QMSPI_C_TX_DMA_POS)
#define MCHP_QMSPI_C_TX_DMA_DIS		(0x00ul << MCHP_QMSPI_C_TX_DMA_POS)
#define MCHP_QMSPI_C_TX_DMA_1B		(0x01ul << MCHP_QMSPI_C_TX_DMA_POS)
#define MCHP_QMSPI_C_TX_DMA_2B		(0x02ul << MCHP_QMSPI_C_TX_DMA_POS)
#define MCHP_QMSPI_C_TX_DMA_4B		(0x03ul << MCHP_QMSPI_C_TX_DMA_POS)
#define MCHP_QMSPI_C_RX_POS		6u
#define MCHP_QMSPI_C_RX_DIS		(0ul << MCHP_QMSPI_C_RX_POS)
#define MCHP_QMSPI_C_RX_EN		(1ul << MCHP_QMSPI_C_RX_POS)
#define MCHP_QMSPI_C_RX_DMA_POS		7u
#define MCHP_QMSPI_C_RX_DMA_MASK	(0x03ul << MCHP_QMSPI_C_RX_DMA_POS)
#define MCHP_QMSPI_C_RX_DMA_DIS		(0x00ul << MCHP_QMSPI_C_RX_DMA_POS)
#define MCHP_QMSPI_C_RX_DMA_1B		(0x01ul << MCHP_QMSPI_C_RX_DMA_POS)
#define MCHP_QMSPI_C_RX_DMA_2B		(0x02ul << MCHP_QMSPI_C_RX_DMA_POS)
#define MCHP_QMSPI_C_RX_DMA_4B		(0x03ul << MCHP_QMSPI_C_RX_DMA_POS)
#define MCHP_QMSPI_C_CLOSE_POS		9u
#define MCHP_QMSPI_C_NO_CLOSE		(0ul << MCHP_QMSPI_C_CLOSE_POS)
#define MCHP_QMSPI_C_CLOSE		(1ul << MCHP_QMSPI_C_CLOSE_POS)
#define MCHP_QMSPI_C_XFR_UNITS_POS	10u
#define MCHP_QMSPI_C_XFR_UNITS_MASK	(0x03ul << MCHP_QMSPI_C_XFR_UNITS_POS)
#define MCHP_QMSPI_C_XFR_UNITS_BITS	(0x00ul << MCHP_QMSPI_C_XFR_UNITS_POS)
#define MCHP_QMSPI_C_XFR_UNITS_1	(0x01ul << MCHP_QMSPI_C_XFR_UNITS_POS)
#define MCHP_QMSPI_C_XFR_UNITS_4	(0x02ul << MCHP_QMSPI_C_XFR_UNITS_POS)
#define MCHP_QMSPI_C_XFR_UNITS_16	(0x03ul << MCHP_QMSPI_C_XFR_UNITS_POS)
#define MCHP_QMSPI_C_NEXT_DESCR_POS	12u
#define MCHP_QMSPI_C_NEXT_DESCR_MASK0	0x0Ful
#define MCHP_QMSPI_C_NEXT_DESCR_MASK	(MCHP_QMSPI_C_NEXT_DESCR_MASK0 << \
					 MCHP_QMSPI_C_NEXT_DESCR_POS)
#define MCHP_QMSPI_C_DESCR0		(0ul << MCHP_QMSPI_C_NEXT_DESCR_POS)
#define MCHP_QMSPI_C_DESCR1		(1ul << MCHP_QMSPI_C_NEXT_DESCR_POS)
#define MCHP_QMSPI_C_DESCR2		(2ul << MCHP_QMSPI_C_NEXT_DESCR_POS)
#define MCHP_QMSPI_C_DESCR3		(3ul << MCHP_QMSPI_C_NEXT_DESCR_POS)
#define MCHP_QMSPI_C_DESCR4		(4ul << MCHP_QMSPI_C_NEXT_DESCR_POS)
/* Control register start descriptor field */
#define MCHP_QMSPI_C_DESCR(n) (((uint32_t)(n) & \
				MCHP_QMSPI_C_NEXT_DESCR_MASK0) << \
				MCHP_QMSPI_C_NEXT_DESCR_POS)
/* Descriptor registers next descriptor field */
#define MCHP_QMSPI_C_NEXT_DESCR(n) (((uint32_t)(n) & \
				     MCHP_QMSPI_C_NEXT_DESCR_MASK0) << \
				     MCHP_QMSPI_C_NEXT_DESCR_POS)
/* Control register descriptor mode enable */
#define MCHP_QMSPI_C_DESCR_EN_POS	16u
#define MCHP_QMSPI_C_DESCR_EN		(1ul << MCHP_QMSPI_C_DESCR_EN_POS)
/* Descriptor registers last descriptor flag */
#define MCHP_QMSPI_C_DESCR_LAST		(1ul << MCHP_QMSPI_C_DESCR_EN_POS)
#define MCHP_QMSPI_C_MAX_UNITS		0x7FFFul
#define MCHP_QMSPI_C_MAX_UNITS_MASK	0x7FFFul
#define MCHP_QMSPI_C_XFR_NUNITS_POS	17u
#define MCHP_QMSPI_C_XFR_NUNITS_MASK0	0x7FFFul
#define MCHP_QMSPI_C_XFR_NUNITS_MASK	(MCHP_QMSPI_C_XFR_NUNITS_MASK0 << \
					 MCHP_QMSPI_C_XFR_NUNITS_POS)
#define MCHP_QMSPI_C_XFR_NUNITS(n) ((uint32_t)(n) << \
				    MCHP_QMSPI_C_XFR_NUNITS_POS)
#define MCHP_QMSPI_C_XFR_NUNITS_GET(n) (((uint32_t)(n) >> \
					 MCHP_QMSPI_C_XFR_NUNITS_POS) & \
					 MCHP_QMSPI_C_MAX_UNITS_MASK)

/* Exe */
#define MCHP_QMSPI_EXE_START		0x01ul
#define MCHP_QMSPI_EXE_STOP		0x02ul
#define MCHP_QMSPI_EXE_CLR_FIFOS	0x04ul

/* Interface Control */
#define MCHP_QMSPI_IFC_DFLT		0x00ul
#define MCHP_QMSPI_IFC_WP_OUT_HI	BIT(0)
#define MCHP_QMSPI_IFC_WP_OUT_EN	BIT(1)
#define MCHP_QMSPI_IFC_HOLD_OUT_HI	BIT(2)
#define MCHP_QMSPI_IFC_HOLD_OUT_EN	BIT(3)
#define MCHP_QMSPI_IFC_PD_ON_NS		BIT(4)
#define MCHP_QMSPI_IFC_PU_ON_NS		BIT(5)
#define MCHP_QMSPI_IFC_PD_ON_ND		BIT(6)
#define MCHP_QMSPI_IFC_PU_ON_ND		BIT(7)

/* Status Register */
#define MCHP_QMSPI_STS_REG_MASK		0x0F01FF1Ful
#define MCHP_QMSPI_STS_RO_MASK		0x0F013300ul
#define MCHP_QMSPI_STS_RW1C_MASK	0x0000CC1Ful
#define MCHP_QMSPI_STS_DONE		BIT(0)
#define MCHP_QMSPI_STS_DMA_DONE		BIT(1)
#define MCHP_QMSPI_STS_TXB_ERR		BIT(2)
#define MCHP_QMSPI_STS_RXB_ERR		BIT(3)
#define MCHP_QMSPI_STS_PROG_ERR		BIT(4)
#define MCHP_QMSPI_STS_TXBF_RO		BIT(8)
#define MCHP_QMSPI_STS_TXBE_RO		BIT(9)
#define MCHP_QMSPI_STS_TXBR		BIT(10)
#define MCHP_QMSPI_STS_TXBS		BIT(11)
#define MCHP_QMSPI_STS_RXBF_RO		BIT(12)
#define MCHP_QMSPI_STS_RXBE_RO		BIT(13)
#define MCHP_QMSPI_STS_RXBR		BIT(14)
#define MCHP_QMSPI_STS_RXBS		BIT(15)
#define MCHP_QMSPI_STS_ACTIVE_RO	BIT(16)
#define MCHP_QMSPI_STS_CD_POS		24u
#define MCHP_QMSPI_STS_CD_MASK0		0x0Ful
#define MCHP_QMSPI_STS_CD_MASK		(MCHP_QMSPI_STS_CD_MASK0 << \
					 MCHP_QMSPI_STS_CD_POS)

/* Buffer Count Status (RO) */
#define MCHP_QMSPI_TX_BUF_CNT_STS_POS	0u
#define MCHP_QMSPI_TX_BUF_CNT_STS_MASK	0xffffu
#define MCHP_QMSPI_RX_BUF_CNT_STS_POS	16u
#define MCHP_QMSPI_RX_BUF_CNT_STS_MASK	0xffff0000ul

/* Interrupt Enable Register */
#define MCHP_QMSPI_IEN_XFR_DONE		BIT(0)
#define MCHP_QMSPI_IEN_DMA_DONE		BIT(1)
#define MCHP_QMSPI_IEN_TXB_ERR		BIT(2)
#define MCHP_QMSPI_IEN_RXB_ERR		BIT(3)
#define MCHP_QMSPI_IEN_PROG_ERR		BIT(4)
#define MCHP_QMSPI_IEN_TXB_FULL		BIT(8)
#define MCHP_QMSPI_IEN_TXB_EMPTY	BIT(9)
#define MCHP_QMSPI_IEN_TXB_REQ		BIT(10)
#define MCHP_QMSPI_IEN_RXB_FULL		BIT(12)
#define MCHP_QMSPI_IEN_RXB_EMPTY	BIT(13)
#define MCHP_QMSPI_IEN_RXB_REQ		BIT(14)

/* Buffer Count Trigger (RW) */
#define MCHP_QMSPI_TX_BUF_CNT_TRIG_POS 0u
#define MCHP_QMSPI_RX_BUF_CNT_TRIG_POS 16u

/* Chip Select Timing (RW) */
#define MCHP_QMSPI_CSTM_MASK 0xFF0F0F0Ful
#define MCHP_QMSPI_CSTM_DFLT 0x06060406ul
#define MCHP_QMSPI_DLY_CS_ON_CK_STR_POS	0u
#define MCHP_QMSPI_DLY_CS_ON_CK_STR_MASK 0x0Ful
#define MCHP_QMSPI_DLY_CK_STP_CS_OFF_POS 8u
#define MCHP_QMSPI_DLY_CK_STP_CS_OFF_MASK (0x0Ful << \
					   MCHP_QMSPI_DLY_CK_STP_CS_OFF_POS)
#define MCHP_QMSPI_DLY_LST_DAT_HLD_POS 16u
#define MCHP_QMSPI_DLY_LST_DAT_HLD_MASK	(0x0Ful << \
					 MCHP_QMSPI_DLY_LST_DAT_HLD_POS)
#define MCHP_QMSPI_DLY_CS_OFF_CS_ON_POS	24u
#define MCHP_QMSPI_DLY_CS_OFF_CS_ON_MASK (0x0Ful << \
					  MCHP_QMSPI_DLY_CS_OFF_CS_ON_POS)

#define MCHP_QMSPI_PORT_MAX_IO_PINS	4u
#define MCHP_QMSPI_PORT_MAX_CS		2u

/* Full duplex and Dual I/O:
 * CS#, CLK, IO0(MOSI), IO1(MISO)
 * do not connect IO2(WP#) or IO3(HOLD#) to MCHP_QMSPI.
 */
#define MCHP_QMSPI_PORT_MASK_FULL_DUPLEX 0x0Ful
#define MCHP_QMSPI_PORT_MASK_DUAL 0x0Ful

#define MCHP_QMSPI_PIN_IO0_POS	0u
#define MCHP_QMSPI_PIN_IO1_POS	1u
#define MCHP_QMSPI_PIN_IO2_POS	2u
#define MCHP_QMSPI_PIN_IO3_POS	3u
#define MCHP_QMSPI_PIN_CLK_POS	4u
#define MCHP_QMSPI_PIN_CS0_POS	8u
#define MCHP_QMSPI_PIN_CS1_POS	9u

#define MCHP_QMSPI_PIN_IO0	(1ul << MCHP_QMSPI_PIN_IO0_POS)
#define MCHP_QMSPI_PIN_IO1	(1ul << MCHP_QMSPI_PIN_IO1_POS)
#define MCHP_QMSPI_PIN_IO2	(1ul << MCHP_QMSPI_PIN_IO2_POS)
#define MCHP_QMSPI_PIN_IO3	(1ul << MCHP_QMSPI_PIN_IO3_POS)
#define MCHP_QMSPI_PIN_CLK	(1ul << MCHP_QMSPI_PIN_CLK_POS)
#define MCHP_QMSPI_PIN_CS0	(1ul << MCHP_QMSPI_PIN_CS0_POS)
#define MCHP_QMSPI_PIN_CS1	(1ul << MCHP_QMSPI_PIN_CS1_POS)

/*
 * Register Access
 */
#define MCHP_QMSPI_MODE()		REG32(MCHP_QMSPI_MODE_ADDR)
#define MCHP_QMSPI_MODE_ACTRST()	REG8(MCHP_QMSPI_MODE_ADDR)
#define MCHP_QMSPI_MODE_SIG()		REG8(MCHP_QMSPI_MODE_ADDR + 1ul)
#define MCHP_QMSPI_MODE_FDIV()		REG16(MCHP_QMSPI_MODE_ADDR + 2ul)

/* Control register */
#define MCHP_QMSPI_CTRL() REG32(MCHP_QMSPI_CTRL_ADDR)

/* Execute register */
#define MCHP_QMSPI_EXE() REG8(MCHP_QMSPI_EXE_ADDR)

/* Interface Control register */
#define MCHP_QMSPI_IFC() REG8(MCHP_QMSPI_IFC_ADDR)

/* Status register */
#define MCHP_QMSPI_STS() REG32(MCHP_QMSPI_STS_ADDR)

/* Buffer Count Status register (read-only) */
#define MCHP_QMSPI_BCNT_STS() REG32(MCHP_QMSPI_BUFCNT_STS_ADDR)
/* b[15:0] = TX buffer count */
#define MCHP_QMSPI_BCNT_TX_STS() REG16(MCHP_QMSPI_BUFCNT_STS_ADDR)
/* b[31:15] = RX buffer count */
#define MCHP_QMSPI_BCNT_RX_STS() REG16(MCHP_QMSPI_BUFCNT_STS_ADDR + 2ul)

/* Interrupt Enable register */
#define MCHP_QMSPI_IEN() REG32(MCHP_QMSPI_IEN_ADDR)

/* TX FIFO write-only */
#define MCHP_QMSPI_TXB_32() REG32(MCHP_QMSPI_TXB_ADDR)
#define MCHP_QMSPI_TXB_16() REG16(MCHP_QMSPI_TXB_ADDR)
#define MCHP_QMSPI_TXB_8() REG8(MCHP_QMSPI_TXB_ADDR)

/* RX FIFO read-only */
#define MCHP_QMSPI_RXB_32() REG32(MCHP_QMSPI_RXB_ADDR)
#define MCHP_QMSPI_RXB_16() REG16(MCHP_QMSPI_RXB_ADDR)
#define MCHP_QMSPI_RXB_8() REG8(MCHP_QMSPI_RXB_ADDR)

/*
 * Descriptor registers
 * 0 <= id < MCHP_QMSPI_MAX_DESCR
 */
#define MCHP_QMSPI_DESCR(id) REG32(MCHP_QMSPI_DESCR_ADDR(id))

#define MCHP_QMSPI_DESCR_NUNITS(id, nu) MCHP_QMSPI_DESCR(id) = \
	((MCHP_QMSPI_DESCR(id) & ~(MCHP_QMSPI_C_XFR_NUNITS_MASK)) +\
	(((uint32_t)nu & MCHP_QMSPI_C_XFR_NUNITS_MASK0) \
		<< MCHP_QMSPI_C_XFR_NUNITS_POS))

/**
  * @brief Quad Master SPI (QMSPI) registers
  * MODE (@ 0x0000) Mode: frequency, chip select, signal sampling
  * CTRL (@ 0x0004) Control
  * EXE (@ 0x0008) Execute, write-only
  * IFCTRL (@ 0x000C) Interface control
  * STS (@ 0x0010) Status, RW/1C and RO
  * BCNT_STS (@ 0x0014) Buffer Count Status, RO
  * IEN (@ 0x0018) Interrupt Enable
  * BCNT_TRIG (@ 0x001C) Buffer Count Trigger
  * TX_FIFO (@ 0x0020) Transmit FIFO
  * RX_FIFO (@ 0x0024) Receive FIFO
  * CSTM (@ 0x0028) Chip select timing
  * DESCR[] (@ 0x0030 - 0x006F descriptors)
  */
typedef struct qmspi_regs {
	__IOM uint32_t MODE;
	__IOM uint32_t CTRL;
	__IOM uint32_t EXE;
	__IOM uint32_t IFCTRL;
	__IOM uint32_t STS;
	__IOM uint32_t BCNT_STS;
	__IOM uint32_t IEN;
	__IOM uint32_t BCNT_TRIG;
	__IOM uint32_t TX_FIFO;
	__IOM uint32_t RX_FIFO;
	__IOM uint32_t CSTM;
	uint8_t RSVD1[4];
	__IOM uint32_t DESCR[MCHP_QMSPI_MAX_DESCR];
} QMSPI_Type;

#endif				/* #ifndef _QMSPI_H */
/* end qmspi.h */
/**   @}
 */
