/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <device.h>
#include <init.h>
#include <kernel.h>

#include <logging/log.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include <zmk/event_manager.h>
#include <zmk/events/cpm_state_changed.h>
#include <zmk/events/keycode_state_changed.h>

#include <zmk/cpm.h>

#define cpm_UPDATE_INTERVAL_SECONDS 0.5
#define cpm_RESET_INTERVAL_SECONDS 5

// See https://en.wikipedia.org/wiki/Words_per_minute
// "Since the length or duration of words is clearly variable, for the purpose of measurement of
// text entry, the definition of each "word" is often standardized to be five characters or
// keystrokes long in English"
#define CHARS_PER_WORD 1.0

static uint8_t cpm_state = -1;
static uint8_t last_cpm_state;
static uint8_t cpm_update_counter;
static uint32_t key_pressed_count;

int zmk_cpm_get_state() { return cpm_state; }

int cpm_event_listener(const zmk_event_t *eh) {
    const struct zmk_keycode_state_changed *ev = as_zmk_keycode_state_changed(eh);
    if (ev) {
        // count only key up events
        if (!ev->state) {
            key_pressed_count++;
            LOG_DBG("key_pressed_count %d keycode %d", key_pressed_count, ev->keycode);
        }
    }
    return 0;
}

void cpm_work_handler(struct k_work *work) {
    cpm_update_counter++;
    cpm_state = (key_pressed_count / CHARS_PER_WORD) /
                (cpm_update_counter * cpm_UPDATE_INTERVAL_SECONDS / 60.0);

    if (last_cpm_state != cpm_state) {
        LOG_DBG("Raised cpm state changed %d cpm_update_counter %d", cpm_state, cpm_update_counter);

        ZMK_EVENT_RAISE(
            new_zmk_cpm_state_changed((struct zmk_cpm_state_changed){.state = cpm_state}));

        last_cpm_state = cpm_state;
    }

    if (cpm_update_counter >= cpm_RESET_INTERVAL_SECONDS) {
        cpm_update_counter = 0;
        key_pressed_count = 0;
    }
}

K_WORK_DEFINE(cpm_work, cpm_work_handler);

void cpm_expiry_function() { k_work_submit(&cpm_work); }

K_TIMER_DEFINE(cpm_timer, cpm_expiry_function, NULL);

int cpm_init() {
    cpm_state = 0;
    cpm_update_counter = 0;
    k_timer_start(&cpm_timer, K_SECONDS(cpm_UPDATE_INTERVAL_SECONDS),
                  K_SECONDS(cpm_UPDATE_INTERVAL_SECONDS));
    return 0;
}

ZMK_LISTENER(cpm, cpm_event_listener);
ZMK_SUBSCRIPTION(cpm, zmk_keycode_state_changed);

SYS_INIT(cpm_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
