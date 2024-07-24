// Emisar D18 (FET+13+1) reduced-FET config options for Anduril
// Copyright (C) 2019-2023 Selene ToyKeeper
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

#include "hank/emisar-d18/anduril.h"

// don't turn off first channels at turbo level
#undef PWM1_LEVELS
#undef PWM2_LEVELS
#define PWM1_LEVELS 1,1,2,2,3,4,4,5,6,7,8,9,10,11,15,16,18,20,22,24,26,28,30,33,36,39,43,47,51,56,61,66,72,78,85,92,99,107,116,125,135,145,156,168,180,194,208,222,238,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255
#define PWM2_LEVELS 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,8,10,11,13,14,16,18,19,21,23,26,28,30,33,35,38,41,44,47,51,54,58,62,66,70,75,79,84,90,95,101,106,112,119,126,133,140,147,155,164,172,181,190,200,210,221,232,243,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255
// 85% FET power
#undef PWM3_LEVELS
#define PWM3_LEVELS 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,6,8,10,12,13,16,17,20,22,24,27,29,32,34,38,40,44,46,50,53,57,60,64,68,72,76,80,85,89,94,98,103,108,114,119,125,131,137,143,150,156,163,170,177,185,193,200,209,217

