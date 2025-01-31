/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define DYNAMIC_KEYMAP_LAYER_COUNT 10
#define DYNAMIC_KEYMAP_MACRO_COUNT 30
#define TAPPING_TERM 100
#define PERMISSIVE_HOLD

/* make use of the mounted WS2812 led from the Waveshare RP2040-zero */
#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_LED_COUNT 1
#    define RGBLIGHT_SPLIT
#    define RGBLIGHT_DEFAULT_HUE 110
#    define RGBLIGHT_LIMIT_VAL 10
#    define RGBLIGHT_SLEEP
#    define RGBLIGHT_LAYERS
#    define RGBLIGHT_HUE_STEP 20
#    define WS2812_DI_PIN GP16
#endif
