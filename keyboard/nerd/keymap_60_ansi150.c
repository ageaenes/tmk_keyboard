#include "keymap_common.h"
#include "backlight.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: QWERTY */
    KEYMAP_60(ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, \
              TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS, \
              CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NO,  ENT,  \
              LSFT,NO,  Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,NO,   \
              LCTL,LGUI,LALT,               SPC,                NO,  RALT,FN0 ,RCTL),
    /* Layer 1: Functions */
    KEYMAP_60(SLEP,F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, FN1,  \
              TRNS,BTN1,MS_U,BTN2,HOME,PSCR,SLCK,PAUS,INS, END, PPLS,MPRV,MNXT,TRNS, \
              CAPS,MS_L,MS_D,MS_R,PGDN,TRNS,LEFT,DOWN,UP,  RGHT,TRNS,TRNS,NO,  MPLY, \
              TRNS,NO,  TRNS,DEL, BSPC,SPC, PGUP,TRNS,PMNS,VOLD,VOLU,MSEL,TRNS,NO,   \
              TRNS,TRNS,TRNS,               TRNS,               NO,  TRNS,TRNS,TRNS)
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_SWITCH)
};
