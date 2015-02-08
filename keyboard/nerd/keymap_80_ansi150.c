#include "keymap_common.h"
#include "backlight.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: QWERTY */
    KEYMAP_80(ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,   PSCR,SLCK,PAUS,  \
              GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,  INS, HOME,PGUP,  \
              TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,  DEL, END, PGDN,  \
              CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NO,  ENT,                    \
              LSFT,NO,  Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,NO,         UP,         \
              LCTL,LGUI,LALT,               SPC,                NO,  RALT,FN0, RCTL,  LEFT,DOWN,RGHT),
    /* Layer 1: Functions */
    KEYMAP_80(SLEP,     MYCM,WSCH,WHOM,MAIL,VOLD,VOLU,MUTE,MSEL,MPLY,MPRV,MNXT,MSTP,  TRNS,TRNS,TRNS,  \
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN1,   TRNS,TRNS,TRNS,  \
              PGUP,TRNS,UP,  END, PSCR,SLCK,TRNS,TRNS,INS, TRNS,TRNS,TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS,  \
              PGDN,LEFT,DOWN,RGHT,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,                   \
              TRNS,NO,  TRNS,DEL, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,         TRNS,       \
              TRNS,TRNS,TRNS,               TRNS,               NO,  TRNS,TRNS,TRNS,  TRNS,TRNS,TRNS),
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_SWITCH)
};
