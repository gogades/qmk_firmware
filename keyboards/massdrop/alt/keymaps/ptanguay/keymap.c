#include QMK_KEYBOARD_H

#include "macros.h"

#define RGBLIGHT_VAL_STEP 17

#define HSV_WHITE 0, 0, 255
#define HSV_RED 0, 255, 255
#define HSV_CORAL 11, 176, 255
#define HSV_ORANGE 28, 255, 255
#define HSV_GOLDENROD 30, 218, 218
#define HSV_GOLD 36, 255, 255
#define HSV_YELLOW 43, 255, 255
#define HSV_CHARTREUSE 64, 255, 255
#define HSV_GREEN 85, 255, 255
#define HSV_SPRINGGREEN 106, 255, 255
#define HSV_TURQUOISE 123, 90, 112
#define HSV_TEAL 128, 255, 128
#define HSV_CYAN 128, 255, 255
#define HSV_AZURE 132, 102, 255
#define HSV_BLUE 170, 255, 255
#define HSV_PURPLE 191, 255, 255
#define HSV_MAGENTA 213, 255, 255
#define HSV_PINK 234, 128, 255

#define _WINDOWS 0
#define _MAC     1
#define _FUNC    2
#define _FUNCALT 3
#define _RGB     4

enum alt_keycodes {
    MD_BOOT = SAFE_RANGE, //Restart into bootloader after hold timeout
    WINDOWS,
    MAC,
    CMD_TAB,
    ALT_TAB,
    KC_FN
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

uint8_t offset = 0;
uint8_t current_layer=0;
uint8_t previous_layer=0;

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* windows layout */
    [_WINDOWS] = LAYOUT(
        KC_GESC,              KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_PGUP,  \
        LT(2,KC_TAB),         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGDN , \
        ALT_TAB,              KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_DEL, \
        KC_LSFT,              KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   LT(3,KC_END), \
        KC_LCTL,              KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_FN,   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    /* mac layout */
    /* so far we only swap lctl and gui */
    [_MAC] = LAYOUT(
        KC_GESC,              KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_PGUP,  \
        LT(2,KC_TAB),         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGDN , \
        CMD_TAB,              KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_DEL, \
        KC_LSFT,              KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   LT(3,KC_END), \
        KC_LGUI,              KC_LCTL, KC_LALT,                            KC_SPC,                             KC_RALT, KC_FN,   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [_FUNC] = LAYOUT(
        KC_GRV,               KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,      KC_F9,     KC_F10,  KC_F11,  KC_F12,  _______, KC_MUTE, \
        _______,              RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, _______, _______ ,   _______,   KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_HOME, \
        _______,              RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, DF(_WINDOWS),DF(_MAC), _______, _______,          _______, KC_INS, \
        _______,              RGB_TOG, _______, _______, _______, RESET  , TG_NKRO, _______, _______,    _______,   _______, _______,          KC_PGUP, KC_HOME, \
        _______,              _______, _______,                            _______,                                 _______, _______, KC_HOME, KC_PGDN, KC_END  \
    ),
    [_RGB] = LAYOUT(
        _______,              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______,              RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______,              RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______,              RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______,              _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    [_FUNCALT] = LAYOUT(
        _______,              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ESC , \
        _______,              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______,              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______,              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______,              _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    */
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL   (get_mods() & MOD_BIT(KC_LCTL)   || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT    (get_mods() & MOD_BIT(KC_LALT)   || get_mods() & MOD_BIT(KC_RALT))
#define MODS_GUI    (get_mods() & MOD_BIT(KC_LGUI)   || get_mods() & MOD_BIT(KC_RGUI))

struct hsv {
    uint8_t h;
    uint8_t s;
    uint8_t v;
} layer_color[4];

void set_layer_color(void) {
    rgblight_sethsv(layer_color[current_layer].h,
        layer_color[current_layer].s,
        layer_color[current_layer].v);
}


void keyboard_post_init_user(void) {
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    layer_color[_WINDOWS].h= 128;
    layer_color[_WINDOWS].s = 255;
    layer_color[_WINDOWS].v = 128;

    layer_color[_MAC].h= 0;
    layer_color[_MAC].s = 0;
    layer_color[_MAC].v = 255;

    layer_color[_FUNC].h= 43;
    layer_color[_FUNC].s = 255;
    layer_color[_FUNC].v = 255;

    layer_color[_FUNCALT].h= 85;
    layer_color[_FUNCALT].s = 255;
    layer_color[_FUNCALT].v = 255;

    current_layer = _WINDOWS;
    set_layer_color();
}

void save_val(uint8_t offset) {
    layer_color[current_layer].v = rgblight_get_val();
}

bool process_macros(uint16_t keycode, keyrecord_t *record) {
    // macros trigger on ctrl+gui
    if(record->event.pressed && MODS_CTRL && MODS_GUI) {
        // unregister the modifiers that triggered the macros
        unregister_code(KC_LCTL);
        unregister_code(KC_RCTRL);
        unregister_code(KC_LGUI);
        unregister_code(KC_RGUI);
        switch (keycode) {
            case KC_1:
                SEND_STRING(MACRO_OCNA);
                return false;
            break;
            case KC_2:
                SEND_STRING(MACRO_OPCCLOUD);
                SEND_STRING(SS_TAP(X_ENTER));
                return false;
            break;
            case KC_3:
                SEND_STRING(MACRO_UNIX);
                return false;
            break;
            case KC_S:
                SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_SYSTEM_POWER))));
                return false;
            break;
        }
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case KC_FN:
            if(record->event.pressed && MODS_ALT ) {
                layer_on(_RGB);
            } else 
            if (record->event.pressed) {
                layer_on(_FUNC);
                previous_layer = current_layer;
                current_layer = _FUNC;
                set_layer_color();
            } else {
                layer_off(_FUNC);
                layer_off(_RGB);
                current_layer = previous_layer;
                set_layer_color();
            }
            return false;
            break;
        case RGB_VAI:
            save_val(RGBLIGHT_VAL_STEP);
            return true;
        case RGB_VAD:
            save_val(0-RGBLIGHT_VAL_STEP);
            return true;
        case ALT_TAB:
        case CMD_TAB:
            if( record->event.pressed ) {
                key_timer = timer_read32();
                register_code(KC_LCTL);
            } else {
                unregister_code(KC_LCTL);
                if(timer_elapsed32(key_timer) < TAPPING_TERM) {
                    if(keycode == CMD_TAB)  // mac
                        SEND_STRING(SS_LGUI(SS_TAP(X_TAB)));
                    else // windows
                        SEND_STRING(SS_LALT(SS_TAP(X_TAB)));
                }
            }
            return true;
            break;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        default:
            return process_macros(keycode, record);
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch(get_highest_layer(state)){
        case _FUNCALT:
            previous_layer = current_layer;
            current_layer = _FUNCALT;
            set_layer_color();
        break;
        default:
            current_layer = previous_layer;
            set_layer_color();
        break;
    }
    return state;
}

uint32_t default_layer_state_set_kb(uint32_t state) {
    // switching default layer
    current_layer = previous_layer =  biton32(state);
    set_layer_color();
    return state;
}
