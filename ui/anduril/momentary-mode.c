// momentary-mode.c: Momentary mode for Anduril.
// Copyright (C) 2017-2023 Selene ToyKeeper
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "anduril/momentary-mode.h"

uint8_t momentary_state(Event event, uint16_t arg) {
    // 1 click: off
    if (event == EV_1click) {
        // if entered from ramp mode exit to ramp mode
        if (momentary_mode == 1) {
            set_state(steady_state, memorized_level);
            return EVENT_HANDLED;
        }
        // if entered from off mode exit to off mode
        else {
            set_state(off_state, 0);
            return EVENT_HANDLED;
        }
    }

    // turn off main leds
    set_level(0);
    // set the aux leds to high red
    set_level_auxred(1);
    // set the button leds to low
    button_led_set(1);
    return EVENT_HANDLED;
}

