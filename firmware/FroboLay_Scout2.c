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
# File: FroboLay_Scout2.c
# Project: FroboLay_Scout2_SW
# Platform: FroboMind Controller Feb. 2014 http://www.frobomind.org
# Microcontroller: AT90CAN128
# Author: Mikkel K. Larsen
# Created:  2014-10-23 Mikkel K. Larsen
# Modified: 
******************************************************************************/
/* includes */
#include "FroboLay_Scout2.h"

/***************************************************************************/

void FroboLay_Scout2_Update(int spray_signal)
{
	if (spray_signal == 0){
		spray_state = 0;
		}
	else if (spray_signal == 1){
		spray_state = 1;
		}
	else if (spray_signal == 2){
		spray_state = 2;
		}
	else {
		spray_state = 0;
		}

	switch (spray_state)
	{
		case SPRAY_POWERLESS:
			INT_SPRAY_OFF;
			INT_SPRAY_STOP_OFF;
			break;

		case SPRAY_ON:
			INT_SPRAY_STOP_OFF;
			INT_SPRAY_ON;
			break;

		case SPRAY_OFF:
			INT_SPRAY_OFF;
			INT_SPRAY_STOP_ON;
			break;

		default:
			INT_SPRAY_OFF;
			INT_SPRAY_STOP_OFF;
			break;

	}



}

