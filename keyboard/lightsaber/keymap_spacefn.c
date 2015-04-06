#include "keymap_common.h"
#include "backlight.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: QWERTY */
    KEYMAP(\
        ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL, INS, PSCR,SLCK,PAUS, \
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,NLCK,PSLS,PAST,PMNS, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,P7,  P8,  P9,  PPLS, \
        CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,PGUP,ENT, P4,  P5,  P6,  NO,   \
        LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,NO,  RSFT,P1,  P2,  P3,  PENT, \
        LCTL,LGUI,LALT,               FN0,                NO,  RALT,RGUI,RCTL,P0,  NO,  PDOT,NO),  \
    /* Layer 2: Functions */
    KEYMAP(\
        SLEP,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,FN1, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,BTN1,MS_U,BTN2,HOME,PSCR,SLCK,PAUS,INS, END, PPLS,MPRV,MNXT,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,MS_L,MS_D,MS_R,PGDN,TRNS,LEFT,DOWN,UP  ,RGHT,TRNS,TRNS,TRNS,MPLY,TRNS,TRNS,TRNS,NO,   \
        TRNS,     TRNS,DEL, BSPC,SPC, PGUP,TRNS,PMNS,VOLD,VOLU,MSEL,NO,  TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,               TRNS,               NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO),
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TAP_KEY(1, KC_SPACE),
    [1] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_ALL)
};
