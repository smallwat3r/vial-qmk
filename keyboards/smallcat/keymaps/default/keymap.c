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

enum layers {
  BASE,
  SYM,
  NUM,
  NAV,
  NAV2,
  EDIT,
  FUN,
  FRENCH,
  SYS,
};

/* define one name per key, this is a useful level of abstraction */
/* in order to change combos and edit the config */
#define CK_1 MT(KC_L, KC_L)
#define CK_2 MT(KC_D, KC_D)
#define CK_3 MT(KC_M, KC_M)
#define CK_4 MT(KC_H, MOD_LSFT)
#define CK_5 LT(SYM, KC_R)
#define CK_6 LT(NUM, KC_T)
#define CK_7 LT(NAV, KC_S)
#define CK_8 MT(KC_G, KC_G)
#define CK_9 MT(KC_TAB, MOD_LCTL)
#define CK_10 MT(KC_QUOT, MOD_LALT)
#define CK_11 MT(KC_C, MOD_LGUI)
#define CK_12 LT(KC_NO, EDIT)
#define CK_13 LT(FUN, KC_SPC)
#define CK_14 MT(KC_F, KC_F)
#define CK_15 MT(KC_O, KC_O)
#define CK_16 MT(KC_U, KC_U)
#define CK_17 MT(KC_Y, KC_U)
#define CK_18 LT(FRENCH, KC_N)
#define CK_19 LT(NUM, KC_A)
#define CK_20 LT(SYM, KC_E)
#define CK_21 MT(KC_I, MOD_LSFT)
#define CK_22 MT(KC_P, MOD_LGUI)
#define CK_23 MT(KC_COMM, MOD_LALT)
#define CK_24 MT(KC_DOT, MOD_LCTL)
#define CK_25 LT(SYS, KC_BSPC)
#define CK_26 LT(SYM, KC_ENT)

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_5:
        case CK_7:
        case CK_20:
          return 80;
        default: return TAPPING_TERM;  // 100
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
               CK_1,  CK_2,  CK_3,                CK_14, CK_15, CK_16,
         CK_4, CK_5,  CK_6,  CK_7,  CK_8,  CK_17, CK_18, CK_19, CK_20, CK_21,
               CK_9,  CK_10, CK_11,               CK_22, CK_23, CK_24,
                          CK_12, CK_13,    CK_25, CK_26
    ),
    [NUM] = LAYOUT(
               KC_7, KC_8, KC_9,                KC_7, KC_8, KC_9,
        KC_0,  KC_4, KC_5, KC_6, KC_NO,  KC_NO, KC_4, KC_5, KC_6, KC_0,
               KC_1, KC_2, KC_3,                KC_1, KC_2, KC_3,
                       KC_TRNS, KC_SPC,  KC_BSPC, KC_DEL
    ),
    [SYM] = LAYOUT(
              KC_AT, LSFT(KC_3), LSFT(KC_4),                   KC_BSLS, KC_SLASH, LSFT(KC_SLASH),
 LSFT(KC_8), LSFT(KC_EQUAL), KC_EQUAL, LSFT(KC_QUOTE), LSFT(KC_5), LSFT(KC_1), LSFT(KC_SCLN), RALT(KC_3), LSFT(KC_GRAVE), LSFT(KC_BSLS),
              KC_MINUS, LSFT(KC_7), KC_GRAVE,                  LSFT(KC_COMMA), LSFT(KC_DOT), KC_NO,
                                KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS
    ),
    [NAV] = LAYOUT(
                 KC_TRNS, KC_TRNS, KC_TRNS,                     LSFT(KC_LBRC), LSFT(KC_RBRC), KC_TRNS,
        KC_TRNS, KC_TRNS, MO(NAV2), KC_TRNS, KC_TRNS,   KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS,                     KC_LBRC, KC_RBRC, KC_TRNS,
                                KC_TRNS, KC_TRNS,      KC_BSPC, KC_DEL
    ),
    [NAV2] = LAYOUT(
                 KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  LALT(KC_LEFT), KC_TRNS, KC_TRNS, LALT(KC_RIGHT), KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS,
                                KC_TRNS, KC_TRNS,     LALT(KC_BSPC), LALT(KC_DEL)
    ),
    [EDIT] = LAYOUT(
                 SGUI(KC_G), LGUI(KC_F), LGUI(KC_G), LSFT(KC_LBRC), LSFT(KC_RBRC), KC_TRNS,
        LGUI(KC_A), LGUI(KC_X), LT(NAV2, LGUI(KC_C)), LGUI(KC_V), LCTL(KC_C),  KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS,
                 KC_TRNS, LGUI(KC_Z), SGUI(KC_Z),                    KC_LBRC, KC_RBRC, KC_TRNS,
                                KC_TRNS, KC_TRNS,      KC_BSPC, KC_DEL
    ),
    [FUN] = LAYOUT(
                 KC_TRNS, KC_TRNS, KC_TRNS,                    KC_F7, KC_F8, KC_F9,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_F4, KC_F5, KC_F6, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS,                    KC_F1, KC_F2, KC_F3,
                                KC_TRNS, KC_TRNS,      LALT(KC_BSPC), LALT(KC_DEL)
    ),
    [SYS] = LAYOUT(
                 KC_TRNS, KC_BTN4, KC_BTN5,                    KC_VOLD, KC_VOLU, KC_MUTE,
        RGB_HUD, KC_BRIU, KC_WH_U, KC_WH_D, KC_TRNS,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, RGB_HUI,
                 KC_BRID, RGB_SAD, RGB_SAI,                   LGUI(KC_KP_MINUS), LGUI(KC_KP_PLUS), KC_TRNS,
                                KC_BTN2, KC_BTN1,      KC_TRNS, KC_TRNS
    ),
};

tap_dance_action_t tap_dance_actions[] = {};

// left base
const uint16_t PROGMEM combo_x[] = {CK_1, CK_2, COMBO_END};
const uint16_t PROGMEM combo_q[] = {CK_2, CK_3, COMBO_END};
const uint16_t PROGMEM combo_w[] = {CK_5, CK_6, COMBO_END};
const uint16_t PROGMEM combo_th[] = {CK_6, CK_7, COMBO_END};
const uint16_t PROGMEM combo_z[] = {CK_9, CK_10, COMBO_END};
const uint16_t PROGMEM combo_v[] = {CK_10, CK_11, COMBO_END};
const uint16_t PROGMEM combo_b[] = {CK_6, CK_11, COMBO_END};
const uint16_t PROGMEM combo_lbrc[] = {CK_1, CK_3, COMBO_END};
const uint16_t PROGMEM combo_sh[] = {CK_5, CK_7, COMBO_END};
const uint16_t PROGMEM combo_lpar[] = {CK_9, CK_11, COMBO_END};
const uint16_t PROGMEM combo_ver[] = {CK_4, CK_7, COMBO_END};
// right base
const uint16_t PROGMEM combo_j[] = {CK_14, CK_15, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {CK_15, CK_16, COMBO_END};
const uint16_t PROGMEM combo_osmsft[] = {CK_18, CK_19, COMBO_END};
const uint16_t PROGMEM combo_underscore[] = {CK_19, CK_20, COMBO_END};
const uint16_t PROGMEM combo_scln[] = {CK_23, CK_24, COMBO_END};
const uint16_t PROGMEM combo_k[] = {CK_19, CK_22, COMBO_END};
const uint16_t PROGMEM combo_rbrc[] = {CK_14, CK_16, COMBO_END};
const uint16_t PROGMEM combo_rpar[] = {CK_22, CK_24, COMBO_END};
const uint16_t PROGMEM combo_dash[] = {CK_18, CK_20, COMBO_END};
const uint16_t PROGMEM combo_you[] = {CK_16, CK_18, COMBO_END};
const uint16_t PROGMEM combo_ion[] = {CK_18, CK_20, COMBO_END};
const uint16_t PROGMEM combo_ing[] = {CK_18, CK_21, COMBO_END};
// both base
const uint16_t PROGMEM combo_caps[] = {CK_8, CK_17, COMBO_END};

enum combo_events {
  CE_LPAR,
  CE_TH,
  CE_SH,
  CE_VER,
  CE_OSMSFT,
  CE_SCLN,
  CE_UNDERSCORE,
  CE_RPAR,
  CE_YOU,
  CE_ION,
  CE_ING,
};

combo_t key_combos[] = {
    // left base
    COMBO(combo_x, KC_X),
    COMBO(combo_q, KC_Q),
    COMBO(combo_w, KC_W),
    [CE_TH] = COMBO_ACTION(combo_th),
    COMBO(combo_z, KC_Z),
    COMBO(combo_v, KC_V),
    COMBO(combo_b, KC_B),
    COMBO(combo_lbrc, KC_LBRC),
    [CE_SH] = COMBO_ACTION(combo_sh),
    [CE_LPAR] = COMBO_ACTION(combo_lpar),
    [CE_VER] = COMBO_ACTION(combo_ver),
    // right base
    COMBO(combo_j, KC_J),
    COMBO(combo_esc, KC_ESC),
    [CE_OSMSFT] = COMBO_ACTION(combo_osmsft),
    [CE_UNDERSCORE] = COMBO_ACTION(combo_underscore),
    [CE_SCLN] = COMBO_ACTION(combo_scln),
    COMBO(combo_k, KC_K),
    COMBO(combo_rbrc, KC_RBRC),
    [CE_RPAR] = COMBO_ACTION(combo_rpar),
    COMBO(combo_dash, KC_MINS),
    [CE_YOU] = COMBO_ACTION(combo_you),
    [CE_ION] = COMBO_ACTION(combo_ion),
    [CE_ING] = COMBO_ACTION(combo_ing),
    // both base
    COMBO(combo_caps, KC_CAPS),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CE_LPAR: if (pressed) { tap_code16(C(KC_9)); } break;
    case CE_RPAR: if (pressed) { tap_code16(C(KC_0)); } break;
    case CE_TH: if (pressed) { SEND_STRING("th"); } break;
    case CE_SH: if (pressed) { SEND_STRING("sh"); } break;
    case CE_VER: if (pressed) { SEND_STRING("ver"); } break;
    case CE_OSMSFT: if (pressed) { tap_code16(OSM(MOD_LSFT)); } break;
    case CE_UNDERSCORE: if (pressed) { tap_code16(C(KC_MINS)); } break;
    case CE_SCLN: if (pressed) { tap_code16(C(KC_SCLN)); } break;
    case CE_YOU: if (pressed) { SEND_STRING("you"); } break;
    case CE_ION: if (pressed) { SEND_STRING("ion"); } break;
    case CE_ING: if (pressed) { SEND_STRING("ing"); } break;
  }
}
