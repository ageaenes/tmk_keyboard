#include "keymap_common.h"
#include "backlight.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: QWERTY */
    KEYMAP(\
        ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, PGUP,PAUS, \
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,INS,  \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,DEL,  \
        CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,PGDN,ENT, HOME, \
        LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,UP,  FN0,  \
        LCTL,LGUI,LALT,               SPC,           RALT,NO,  RCTL,LEFT,DOWN,RGHT),
    /* Layer 1: Functions */
    KEYMAP(\
        SLEP,MYCM,WSCH,WHOM,MAIL,MUTE,VOLD,VOLU,MSEL,MSTP,MPLY,MPRV,MNXT,TRNS,TRNS, \
        FN1, FN2, FN3, FN4, FN5, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,               TRNS,          RALT,NO,  TRNS,TRNS,TRNS,TRNS)
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_BACKLIGHT_TOGGLE(),
    [2] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_SWITCH),
    [3] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_RGBRED),
    [4] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_RGBGREEN),
    [5] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_RGBBLUE)
};
