#include "keymap_common.h"
#include "led_l3.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Standard ANSI layer */
    KEYMAP(\
        ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, NO,  FN0, HOME,PSCR,SLCK,PAUS, \
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, NO,  BSPC,NLCK,PSLS,PAST,PMNS, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     P7,  P8,  P9,  NO,   \
        CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NO,  ENT,      P4,  P5,  P6,  PPLS, \
        LSFT,NO,  Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,     UP,  P1,  P2,  P3,  PENT, \
        LCTL,LGUI,LALT,NO,  NO,       SPC,      NO,       NO,  RALT,RCTL,LEFT,DOWN,RGHT,P0,  PDOT,NO),  \
    /* Layer 1: Function layer */
    KEYMAP(\
        SLEP,MYCM,WSCH,WHOM,MAIL,VOLD,VOLU,MSEL,MSTP,MPLY,MPRV,MNXT,TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,FN1, FN2, FN3, FN4, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,NO,   \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO,  TRNS,     TRNS,TRNS,TRNS,TRNS, \
        TRNS,NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,NO,  NO,       TRNS,     NO,       NO,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NO)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
      case 1:
        led_change_mode();
      break;
      case 2:
        rgb_change_mode();
      break;
      default:
      break;
    }
}

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
    [1] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_SWITCH),
    [2] = ACTION_BACKLIGHT_LEVEL(BACKLIGHT_PCB),
    [3] = ACTION_FUNCTION(1),
    [4] = ACTION_FUNCTION(2)
};
