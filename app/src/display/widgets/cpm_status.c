/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include <zmk/display.h>
#include <zmk/display/widgets/cpm_status.h>
#include <zmk/events/cpm_state_changed.h>
#include <zmk/event_manager.h>
#include <zmk/endpoints.h>
#include <zmk/cpm.h>

static sys_slist_t widgets = SYS_SLIST_STATIC_INIT(&widgets);

struct cpm_status_state {
    uint8_t cpm;
};

struct cpm_status_state cpm_status_get_state(const zmk_event_t *eh) {
    return (struct cpm_status_state){.cpm = zmk_cpm_get_state()};
};

void set_cpm_symbol(lv_obj_t *label, struct cpm_status_state state, int cpm) {
    char text[8] = {};

    LOG_DBG("cpm changed to %i", state.cpm);
    sprintf(text, "CPM:%i", cpm > 999 ? 999 : cpm < 0 ? 0 : cpm);

    lv_label_set_text(label, text);
}

void cpm_status_update_cb(struct cpm_status_state state) {
    struct ZMK_WIDGET_CPM_STATUS *widget;
    SYS_SLIST_FOR_EACH_CONTAINER(&widgets, widget, node) { set_cpm_symbol(widget->obj, state); }
}

ZMK_DISPLAY_WIDGET_LISTENER(widget_cpm_status, struct cpm_status_state, cpm_status_update_cb,
                            cpm_status_get_state)
ZMK_SUBSCRIPTION(widget_cpm_status, zmk_cpm_state_changed);

int ZMK_WIDGET_CPM_STATUS_init(struct ZMK_WIDGET_CPM_STATUS *widget, lv_obj_t *parent) {
    widget->obj = lv_label_create(parent, NULL);
    lv_label_set_align(widget->obj, LV_LABEL_ALIGN_RIGHT);

    lv_obj_set_size(widget->obj, 40, 15);

    sys_slist_append(&widgets, &widget->node);

    widget_cpm_status_init();
    return 0;
}

lv_obj_t *zmk_widget_cpm_status_obj(struct ZMK_WIDGET_CPM_STATUS *widget) { return widget->obj; }