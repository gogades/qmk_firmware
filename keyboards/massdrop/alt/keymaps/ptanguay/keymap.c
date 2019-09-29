#include QMK_KEYBOARD_H

#define RGBLIGHT_VAL_STEP 17

#define _WINDOWS 0
#define _MAC     1
#define _FUNC    2
#define _FUNCALT 3

enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
    WINDOWS,
    MAC
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode

void persistent_default_layer_set(uint16_t default_layer) {
	eeconfig_update_default_layer(default_layer);
	default_layer_set(default_layer);
}


keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* windows layout */
    [_WINDOWS] = LAYOUT(
        KC_GESC,              KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        LT(2,KC_TAB),         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END , \
        MT(MOD_LCTL,KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSFT,              KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   LT(3,KC_PGDN), \
        KC_LCTL,              KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(2),   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    /* mac layout */
    /* so far we only swap lctl and gui */
    [_MAC] = LAYOUT(
        KC_GESC,              KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        LT(2,KC_TAB),         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END , \
        MT(MOD_LCTL,KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSFT,              KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   LT(3,KC_PGDN), \
        KC_LGUI,              KC_LCTL, KC_LALT,                            KC_SPC,                             KC_RALT, MO(2),   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [_FUNC] = LAYOUT(
        KC_GRV,               KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_MUTE, \
        _______,              RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, U_T_AUTO,U_T_AGCR,_______, KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_HOME, \
        _______,              RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______,DF(_WINDOWS), DF(_MAC)   , _______, _______,          _______, KC_VOLU, \
        _______,              RGB_TOG, _______, _______, _______, RESET  , TG_NKRO, DBG_TOG, _______, _______, _______, _______,          KC_PGUP, KC_VOLD, \
        _______,              _______, _______,                            _______,                            _______, _______, KC_HOME, KC_PGDN, KC_END  \
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

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))
uint8_t offset = 0;


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        /* case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false; */
	case RGB_VAI:
	     offset = offset+RGBLIGHT_VAL_STEP;
	     return true;
	case RGB_VAD:
	     layer_state_set_user(layer_state);
	     offset = offset-RGBLIGHT_VAL_STEP;
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
        /* case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_KEYLIGHT: {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false; */
        default:
            return true; //Process all other keycodes normally
    }
}

void set_layer_color(uint8_t h, uint8_t s, uint8_t v) {
uint8_t val;
int tmp = v+offset;
if( tmp > 255)
	val=255;
else if(tmp < 0 )
	val=0;
else
	val = tmp;
rgblight_sethsv(h,s,val);
}

#define rgblight_set_blue        set_layer_color(170,255,255);
#define rgblight_set_red         set_layer_color(0,255,255);
#define rgblight_set_green       set_layer_color (85,  0xFF, 0xFF);
#define rgblight_set_orange      set_layer_color (0x1E,  0xFF, 0xFF);
#define rgblight_set_teal        rgblight_sethsv (128,255,128+offset );
#define rgblight_set_magenta     set_layer_color (0x12C, 0xFF, 0xFF);
#define rgblight_set_yellow      set_layer_color (43,  0xFF, 0xFF );
#define rgblight_set_purple      set_layer_color (0x10E, 0xFF, 0xFF);
#define rgblight_set_white       rgblight_sethsv (0x00,  0x00, 0xFF+offset);
#define rgblight_set_azure       set_layer_color (132,102,255);
#define rgblight_set_cyan       set_layer_color (128,255,255);

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

layer_state_t layer_state_set_user(layer_state_t state) {
    switch(get_highest_layer(state))
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
    }
  return state;
}

void keyboard_post_init_user(void) {
	rgblight_set_teal
	rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
}
