// momentary-mode.c: Momentary mode for Anduril.
// Copyright (C) 2017-2023 Selene ToyKeeper
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "anduril/momentary-mode.h"

uint8_t momentary_state(Event event, uint16_t arg) {
    // 1 click: off
    if (event == EV_1click) {
        set_state(off_state, 0);
        return EVENT_HANDLED;
    }

    // set the aux leds to high red
    set_level_auxred(1);
    return EVENT_HANDLED;
}

