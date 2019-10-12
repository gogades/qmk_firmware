#include QMK_KEYBOARD_H

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

enum alt_keycodes {
    MD_BOOT = SAFE_RANGE, //Restart into bootloader after hold timeout
    WINDOWS,
    MAC
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

uint8_t offset = 0;
uint8_t current_layer=0;

keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* windows layout */
    [_WINDOWS] = LAYOUT(
        KC_GESC,              KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_PGUP,  \
        LT(2,KC_TAB),         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGDN , \
        MT(MOD_LCTL,KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_DEL, \
        KC_LSFT,              KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   LT(3,KC_END), \
        KC_LCTL,              KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(2),   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    /* mac layout */
    /* so far we only swap lctl and gui */
    [_MAC] = LAYOUT(
        KC_GESC,              KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_PGUP,  \
        LT(2,KC_TAB),         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGDN , \
        MT(MOD_LCTL,KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_DEL, \
        KC_LSFT,              KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   LT(3,KC_END), \
        KC_LGUI,              KC_LCTL, KC_LALT,                            KC_SPC,                             KC_RALT, MO(2),   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [_FUNC] = LAYOUT(
        KC_GRV,               KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,      KC_F9,     KC_F10,  KC_F11,  KC_F12,  _______, KC_MUTE, \
        _______,              RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, _______, _______ ,   _______,   KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_HOME, \
        _______,              RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, DF(_WINDOWS),DF(_MAC), _______, _______,          _______, KC_INS, \
        _______,              RGB_TOG, _______, _______, _______, RESET  , TG_NKRO, _______, _______,    _______,   _______, _______,          KC_PGUP, KC_HOME, \
        _______,              _______, _______,                            _______,                                 _______, _______, KC_HOME, KC_PGDN, KC_END  \
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
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

struct hsv {
    uint8_t h;
    uint8_t s;
    uint8_t v;
} layer_color[2];

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

    current_layer = _WINDOWS;
    set_layer_color();

}

void calc(uint8_t offset) {
    int tmp = layer_color[current_layer].v + offset;
    if(tmp > 255) {
        tmp = 255;
    } else if (tmp < 0) {
        tmp =0;
    }
    layer_color[current_layer].v = tmp;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case RGB_VAI:
            calc(RGBLIGHT_VAL_STEP);

            return true;
        case RGB_VAD:
            calc(0-RGBLIGHT_VAL_STEP);
            return true;
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
            return true; //Process all other keycodes normally
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
/*    switch(get_highest_layer(state))
    {
    case _WINDOWS:
    case _MAC:
	if(biton32(default_layer_state) == 0)
		rgblight_set_teal
	else
		rgblight_set_white
        break;
    case _FUNC:
        rgblight_set_yellow
        break;
    case _FUNCALT:
        rgblight_set_green
        break;
    default: //  for any other layers, or the default layer
        rgblight_set_white
        break;
    } */
  return state;
}

uint32_t default_layer_state_set_kb(uint32_t state) {

    current_layer= biton32(state);
    set_layer_color();

   return state;
}


