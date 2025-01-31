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
  EDIT,
  FUN,
  FRENCH,
  SYS,
};

/* define one name per key, this is a useful level of abstraction */
/* in order to change combos and edit the config */
#define K_1 MT(KC_L, KC_L)
#define K_2 MT(KC_D, KC_D)
#define K_3 MT(KC_M, KC_M)
#define K_4 MT(KC_H, MOD_LSFT)
#define K_5 LT(SYM, KC_R)
#define K_6 LT(NUM, KC_T)
#define K_7 LT(NAV, KC_S)
#define K_8 MT(KC_G, KC_G)
#define K_9 MT(KC_TAB, MOD_LCTL)
#define K_10 MT(KC_QUOT, MOD_LALT)
#define K_11 MT(KC_C, MOD_GUI)
#define K_12 LT(KC_NO, EDIT)
#define K_13 LT(FUN, KC_SPC)
#define K_14 MT(KC_F, KC_F)
#define K_15 MT(KC_O, KC_O)
#define K_16 MT(KC_U, KC_U)
#define K_17 MT(KC_Y, KC_U)
#define K_18 LT(FRENCH, KC_N)
#define K_19 LT(NUM, KC_A)
#define K_20 LT(SYM, KC_E)
#define K_21 MT(KC_I, MOD_LSFT)
#define K_22 MT(KC_P, MOD_LGUI)
#define K_23 MT(KC_COMM, MOD_LALT)
#define K_24 MT(KC_DOT, MOD_LCTL)
#define K_25 LT(SYS, KC_BSPC)
#define K_26 LT(SYM, KC_ENT)

enum custom_keycodes {
    K_ION = SAFE_RANGE,
    K_YOU,
    K_SH,
    K_TH,
    K_VER,
    K_ING,
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case K_5:
        case K_7:
        case K_20:
          return 80;
        default: return TAPPING_TERM;  // 100
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x5_2;
              K_1, K_2, K_3,               K_14, K_15, K_16,
        KC_4, K_5, K_6, K_7, K_8,    K_17, K_18, K_19, K_20, K_21,
              K_9, K_10, K_11,             K_22, K_23, K_24,
                        K_12, K_13, K_25, K_26
    ),
    [NUM] = LAYOUT_split_3x5_2;
              KC_7, KC_8, KC_9,               KC_7, KC_8, KC_9,
        KC_0, KC_4, KC_5, KC_6, KC_NO,  K_NO, KC_4, KC_5, KC_6, KC_0,
              KC_1, KC_2, KC_3,               KC_1, KC_2, KC_3,
                        KC_NO, KC_SPC,  KC_BSPC, KC_DEL
    ),
};


/* combo definitions */

// left
// base
const uint16_t PROGMEM combo_x[] = {K_1, K_2, COMBO_END};
const uint16_t PROGMEM combo_q[] = {K_2, K_3, COMBO_END};
const uint16_t PROGMEM combo_w[] = {K_5, K_6, COMBO_END};
const uint16_t PROGMEM combo_th[] = {K_6, K_7, COMBO_END};
const uint16_t PROGMEM combo_z[] = {K_9, K_10, COMBO_END};
const uint16_t PROGMEM combo_v[] = {K_10, K_11, COMBO_END};
const uint16_t PROGMEM combo_b[] = {K_6, K_11, COMBO_END};
const uint16_t PROGMEM combo_lbrc[] = {K_1, K_3, COMBO_END};
const uint16_t PROGMEM combo_sh[] = {K_5, K_7, COMBO_END};
const uint16_t PROGMEM combo_lpar[] = {K_9, K_11, COMBO_END};
const uint16_t PROGMEM combo_ver[] = {K_4, K_7, COMBO_END};
// right
// base
const uint16_t PROGMEM combo_j[] = {K_14, K_15, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {K_15, K_16, COMBO_END};
const uint16_t PROGMEM combo_osmsft[] = {K_18, K_19, COMBO_END};
const uint16_t PROGMEM combo_underscore[] = {K_19, K_20, COMBO_END};
const uint16_t PROGMEM combo_scln[] = {K_23, K_24, COMBO_END};
const uint16_t PROGMEM combo_k[] = {K_19, K_22, COMBO_END};
const uint16_t PROGMEM combo_rbrc[] = {K_14, K_16, COMBO_END};
const uint16_t PROGMEM combo_rpar[] = {K_22, K_24, COMBO_END};
const uint16_t PROGMEM combo_dash[] = {K_18, K_20, COMBO_END};
const uint16_t PROGMEM combo_you[] = {K_16, K_18, COMBO_END};
const uint16_t PROGMEM combo_ion[] = {K_18, K_20, COMBO_END};
const uint16_t PROGMEM combo_ing[] = {K_18, K_21, COMBO_END};
// both
// base
const uint16_t PROGMEM combo_caps[] = {K_8, K_17, COMBO_END};

combo_t key_combos[] = {
    // left
    // base
    COMBO(combo_x, KC_X),
    COMBO(combo_q, KC_Q),
    COMBO(combo_w, KC_Z),
    COMBO(combo_th, K_TH),
    COMBO(combo_z, KC_Z),
    COMBO(combo_v, KC_V),
    COMBO(combo_b, KC_B),
    COMBO(combo_lbrc, KC_LBRC),
    COMBO(combo_sh, K_SH),
    COMBO(combo_lpar, KC_LSFT(KC_9)),
    COMBO(combo_ver, K_VER),
    // right
    // base
    COMBO(combo_j, KC_J),
    COMBO(combo_esc, KC_ESC),
    COMBO(combo_osmsft, OSM(MOD_LSFT)),
    COMBO(combo_underscore, KC_LSFT(KC_MINS)),
    COMBO(combo_scln, KC_LSFT(KC_SCLN)),
    COMBO(combo_k, KC_K),
    COMBO(combo_rbrc, KC_RBRC),
    COMBO(combo_rpar, KC_LSFT(KC_0)),
    COMBO(combo_dash, KC_MINS),
    COMBO(combo_you, K_YOU),
    COMBO(combo_ion, K_ION),
    COMBO(combo_ing, K_ING),
    // both
    // base
    COMBO(combo_caps, KC_CAPS),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == K_TH && record->event.pressed) {
        SEND_STRING("th"); return false;
    }
    if (keycode == K_SH && record->event.pressed) {
        SEND_STRING("sh"); return false;
    }
    if (keycode == K_VER && record->event.pressed) {
        SEND_STRING("ver"); return false;
    }
    if (keycode == K_YOU && record->event.pressed) {
        SEND_STRING("you"); return false;
    }
    if (keycode == K_ION && record->event.pressed) {
        SEND_STRING("ion"); return false;
    }
    if (keycode == K_ING && record->event.pressed) {
        SEND_STRING("ing"); return false;
    }
    return true;
}
