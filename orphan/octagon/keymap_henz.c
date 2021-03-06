#include "keymap_common.h"
#include "backlight.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: QWERTY */
    KEYMAP(\
        ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, HOME,END, \
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   SLSH,EQL, BSLS,PGUP, \
        TAB, QUOT,   COMM, DOT,  P,  Y,  F,  G,  C,  R, L, LBRC,RBRC,BSPC,DEL, \
        LCTL, A,   O,   E,   U,   I,   D,   H,   T,   N, S,MINS,SLCK,ENT, PGDN,  \
        LSFT,     SCLN,   Q,   J,   K,   X,   B,   M,   W, V, Z,RSFT,UP,  FN0,  \
        LGUI,LALT,NO,               SPC,           RALT,RALT,  FN1,LEFT,DOWN,RGHT),
    /* Layer 1: Space fn */
    KEYMAP(\
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        CAPS,TRNS,TRNS,MS_BTN1,MS_BTN2, MS_BTN3,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS, MS_LEFT,MS_DOWN,MS_UP,MS_RIGHT,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,VOLD,VOLU,MUTE,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,               FN4,           TRNS,NO,  TRNS,TRNS,TRNS,TRNS),
    /* Layer 2: Mouse */
    KEYMAP(\
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,BTN3,BTN1,BTN2, \
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,WH_D,MS_U,WH_U, \
        TRNS,TRNS,TRNS,               TRNS,          TRNS,NO,  TRNS,MS_L,MS_D,MS_R),
    /* Layer 3: Toggle */
    KEYMAP(\
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        FN5, FN6, FN7, FN8, FN9, FN10,FN11,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,               TRNS,          TRNS,NO,  TRNS,TRNS,TRNS,TRNS),
    /* Layer 4: Functions */
    KEYMAP(\
        SLEP,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PWR, TRNS, \
        TRNS,MSEL,VOLU,MPLY,PSCR,SLCK,PAUS,HOME,INS, DEL, END, TRNS,TRNS,TRNS,TRNS, \
        CAPS,MPRV,VOLD,MNXT,TRNS,TRNS,LEFT,DOWN,UP,  RGHT,TRNS,TRNS,TRNS,WSCH,TRNS, \
        TRNS,     MUTE,TRNS,TRNS,TRNS,TRNS,FN12,PGDN,PGUP,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,               TRNS,          TRNS,NO,  TRNS,TRNS,TRNS,TRNS)
};

const uint16_t PROGMEM fn_actions[] = {
     [0]  = ACTION_LAYER_TOGGLE(1),
     [1]  = ACTION_LAYER_TOGGLE(2),
     [2]  = ACTION_LAYER_TOGGLE(0),
     [3]  = ACTION_LAYER_TOGGLE(3),

};
