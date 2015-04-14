/****************************************************************************
# FrobolLightHouse FroboMind Controller interface
# Control unit FroboLightHouse.
# Copyright (c) 2014-2016, Mikkel K. Larsen
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#    * Redistributions of source code must retain the above copyright
#      notice, this list of conditions and the following disclaimer.
#    * Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the following disclaimer in the
#      documentation and/or other materials provided with the distribution.
#    * Neither the name of the copyright holder nor the names of its
#      contributors may be used to endorse or promote products derived from
#      this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
# DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
# ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************
# File: FroboLay_Scout2
# Project: FroboLay_Scout2_SW
# Platform: FroboMind Controller Feb. 2014 http://www.frobomind.org
# Microcontroller: AT90CAN128
# Author: Mikkel K. Larsen
# Created:  2015-04-13 Mikkel K. Larsen
# Modified: 2015-04-13 

****************************************************************************/
/* includes */
#include <stdlib.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>

/***************************************************************************/

/* FroboLay_Scout2 defines  */

#define false					0
#define true					1

#define FLH_Port			PORTA

#define SPRAY_POWERLESS			0
#define SPRAY_ON				1
#define SPRAY_OFF				2


/* FroboLay_Scout2 defines  */
#define BV(bit)						(1<<bit) /* return bit value for a bit */

/* ATmega port defines (output) */
#define PB_OUT( ddr, bit)			ddr |= BV(bit) /* set port bit as output */
#define PB_HIGH( port, bit)			port |= BV(bit) /* set port bit high */
#define PB_LOW( port, bit)			port &= ~BV(bit) /* set port bit low */
#define PB_FLIP( port, bit)			port ^= BV(bit) /* flip port bit */

/* ATmega port defines (input) */
#define PB_IN( ddr, bit)			ddr &= ~BV(bit) /* set port bit as input */
#define PB_PULL_UP( port, bit)		PB_HIGH(port, bit) /* enable pull-up resistor */
#define PB_IS_HIGH( inport, bit)	inport & BV(bit) /* true if port bit is high */
#define PB_IS_LOW( inport, bit)		!(inport & BV(bit)) /* true if port bit is low */

/* FroboLay_Scout2 Spray defines */
#define INT_SPRAY_INIT				PB_OUT (DDRE,DDE0) /* set LED bit as output */
#define INT_SPRAY_OFF				PB_LOW (PORTE,PE0) /* turn LED off */
#define INT_SPRAY_ON				PB_HIGH (PORTE,PE0) /* turn LED on */

#define INT_SPRAY_STOP_INIT			PB_OUT (DDRE,DDE1) /* set LED bit as output */
#define INT_SPRAY_STOP_OFF			PB_LOW (PORTE,PE1) /* turn LED off */
#define INT_SPRAY_STOP_ON			PB_HIGH (PORTE,PE1) /* turn LED on */


/* FroboLay_Scout2 variables */

char spray_state;
char spray_signal;

/***************************************************************************/

/* Funktion declarations */

void FroboLay_Scout2_Update(int spray_signal);

