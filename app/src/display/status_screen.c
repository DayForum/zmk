/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zmk/display/widgets/output_status.h>
#include <zmk/display/widgets/battery_status.h>
#include <zmk/display/widgets/layer_status.h>
#include <zmk/display/widgets/wpm_status.h>
#include <zmk/display/widgets/cpm_status.h>
#include <zmk/display/status_screen.h>

#include <logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

////////////////////////////////////////////////////////////
//#if IS_ENABLED(CONFIG_ZMK_WIDGET_ZAPHOD_BONGO_CAT_WIDGET)
// static struct zaphod_bongo_cat_widget bongo_widget;
//#endif
////////////////////////////////////////////////////////////

#if IS_ENABLED(CONFIG_ZMK_WIDGET_BATTERY_STATUS)
static struct zmk_widget_battery_status battery_status_widget;
#endif

#if IS_ENABLED(CONFIG_ZMK_WIDGET_OUTPUT_STATUS)
static struct zmk_widget_output_status output_status_widget;
#endif

#if IS_ENABLED(CONFIG_ZMK_WIDGET_LAYER_STATUS)
static struct zmk_widget_layer_status layer_status_widget;
#endif

#if IS_ENABLED(CONFIG_ZMK_WIDGET_WPM_STATUS)
static struct zmk_widget_wpm_status wpm_status_widget;
#endif

#if IS_ENABLED(CONFIG_ZMK_WIDGET_CPM_STATUS)
static struct zmk_widget_cpm_status cpm_status_widget;
#endif

lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *screen;

    screen = lv_obj_create(NULL, NULL);

////////////////////////////////////////////////////////////
//#if IS_ENABLED(CONFIG_ZMK_WIDGET_ZAPHOD_BONGO_CAT_WIDGET)
//    zaphod_bongo_cat_widget_init(&bongo_widget, screen);
//    lv_obj_align(zaphod_bongo_cat_widget_obj(&bongo_widget), NULL, LV_ALIGN_IN_TOP_RIGHT,
//                 0, 0);
//#endif
////////////////////////////////////////////////////////////

#if IS_ENABLED(CONFIG_ZMK_WIDGET_BATTERY_STATUS)
    zmk_widget_battery_status_init(&battery_status_widget, screen);
    lv_obj_align(zmk_widget_battery_status_obj(&battery_status_widget), NULL, LV_ALIGN_IN_TOP_RIGHT,
                 0, 0);
#endif

#if IS_ENABLED(CONFIG_ZMK_WIDGET_OUTPUT_STATUS)
    zmk_widget_output_status_init(&output_status_widget, screen);
    lv_obj_align(zmk_widget_output_status_obj(&output_status_widget), NULL, LV_ALIGN_IN_TOP_LEFT, 0,
                 0);
#endif

#if IS_ENABLED(CONFIG_ZMK_WIDGET_LAYER_STATUS)
    zmk_widget_layer_status_init(&layer_status_widget, screen);
    lv_obj_set_style_local_text_font(zmk_widget_layer_status_obj(&layer_status_widget),
                                     LV_LABEL_PART_MAIN, LV_STATE_DEFAULT,
                                     lv_theme_get_font_small());
    lv_obj_align(zmk_widget_layer_status_obj(&layer_status_widget), NULL, LV_ALIGN_IN_BOTTOM_LEFT,
                 0, 0);
#endif

#if IS_ENABLED(CONFIG_ZMK_WIDGET_WPM_STATUS)
    zmk_widget_wpm_status_init(&wpm_status_widget, screen);
    lv_obj_align(zmk_widget_wpm_status_obj(&wpm_status_widget), NULL, LV_ALIGN_IN_BOTTOM_RIGHT, -12,
                 0);
#endif

#if IS_ENABLED(CONFIG_ZMK_WIDGET_CPM_STATUS)
    zmk_widget_cpm_status_init(&cpm_status_widget, screen);
    lv_obj_align(zmk_widget_cpm_status_obj(&cpm_status_widget), NULL, LV_ALIGN_IN_BOTTOM_MID, -5,
                 0);
#endif
    return screen;
}
