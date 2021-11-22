# Copyright (c) 2020 The ZMK Contributors
# SPDX-License-Identifier: MIT

target_sources_ifdef(CONFIG_ZMK_WIDGET_BATTERY_STATUS app PRIVATE battery_status.c)
target_sources_ifdef(CONFIG_ZMK_WIDGET_OUTPUT_STATUS app PRIVATE output_status.c)
target_sources_ifdef(CONFIG_ZMK_WIDGET_LAYER_STATUS app PRIVATE layer_status.c)
target_sources_ifdef(CONFIG_ZMK_WIDGET_WPM_STATUS app PRIVATE wpm_status.c)
target_sources_ifdef(CONFIG_ZMK_WIDGET_CPM_STATUS app PRIVATE cpm_status.c)

###############################################################################
#target_sources_ifdef(CONFIG_ZMK_WIDGET_ZAPHOD_BONGO_CAT_WIDGET app PRIVATE zaphod_bongo_cat_widget.c)
#target_sources_ifdef(CONFIG_ZMK_WIDGET_ZAPHOD_BONGO_CAT_IMAGES app PRIVATE zaphod_bongo_cat_images.c)
###############################################################################