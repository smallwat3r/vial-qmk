#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
    const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_RED});
    const rgblight_segment_t PROGMEM osm_shift_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_YELLOW});

    const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(capslock_layer, osm_shift_layer);
    void keyboard_post_init_user(void) { rgblight_layers = rgb_layers; }

    /* light up led in red when caps lock in on */
    bool led_update_user(led_t led_state) {
        rgblight_set_layer_state(0, led_state.caps_lock);
        return true;
    }

    /* light up led in yellow when sticky shift is activated */
    void oneshot_mods_changed_user(uint8_t mods) {
        if (mods & MOD_MASK_SHIFT) { rgblight_set_layer_state(1, true); }
        if (!mods) { rgblight_set_layer_state(1, false); }
    }
#endif

enum custom_keycodes {
    M_UPDIR = SAFE_RANGE,
    M_ION,
    M_ENT,
    M_THE,
    M_OU,
    M_EFORE,
    M_ON,
    M_UST,
    M_ER,
    M_HICH,
    M_BUT,
    M_ETURN,
};

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_DOT: return M_UPDIR;
        case KC_T: return M_ION;
        case KC_N: return M_ION;

        case KC_SPC:
        case KC_ENT:
        case KC_TAB:
            return M_THE;

        case KC_S: return KC_C;
        case KC_Y: return M_OU;
        case KC_I: return M_ON;
        case KC_B: return M_EFORE;
        case KC_J: return M_UST;
        case KC_V: return M_ER;
        case KC_W: return M_HICH;
        case KC_COMMA: return M_BUT;
        case KC_MINUS: return KC_GT;
        case KC_EQUAL: return KC_GT;
        case KC_R: return M_ETURN;
    }
    return KC_TRNS;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case M_UPDIR: SEND_STRING("./"); break;
        case M_ION: SEND_STRING("ion"); break;
        case M_THE: SEND_STRING("The"); break;
        case M_ENT: SEND_STRING("ent"); break;
        case M_OU: SEND_STRING("ou"); break;
        case M_ON: SEND_STRING("on"); break;
        case M_EFORE: SEND_STRING("efore"); break;
        case M_UST: SEND_STRING("ust"); break;
        case M_ER: SEND_STRING("er"); break;
        case M_HICH: SEND_STRING("hich"); break;
        case M_BUT: SEND_STRING(" but"); break;
        case M_ETURN: SEND_STRING("eturn"); break;
    }
    return true;
}

/* default empty layout */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
              KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS,
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
              KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};
