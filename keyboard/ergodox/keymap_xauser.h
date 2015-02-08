static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(  // Layer 0: Standard ANSI
        ESC, 1,   2,   3,   4,   5,   MINS,
        TAB, Q,   W,   E,   R,   T,   LBRC,
        CAPS,A,   S,   D,   F,   G,
        LSFT,Z,   X,   C,   V,   B,   LGUI,
        LCTL,PSCR,SLCK,PAUS,LALT,
                                 TRNS,TRNS,
                                      TRNS,
                            BSPC,DEL, FN0,

        EQL, 6,   7,   8,   9,   0,   GRV,
        RBRC,Y,   U,   I,   O,   P,   BSLS,
             H,   J,   K,   L,   SCLN,QUOT,
        RGUI,N,   M,   COMM,DOT, SLSH,RSFT,
                  RALT,TRNS,PGUP,PGDN,RCTL,
        TRNS,TRNS,
        TRNS,
        FN0, ENT, SPC
    ),
    KEYMAP(  // Layer 1: Space Fn
        MINS,TRNS,TRNS,TRNS,TRNS,TRNS,GRV,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        ESC, TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                 TRNS,TRNS,
                                      TRNS,
                            FN1, TRNS,TRNS,

        APP, TRNS,TRNS,TRNS,TRNS,TRNS,EQL,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,FN2
    ),
    KEYMAP(  // Layer 2: Space Fn Functions
        TRNS,TRNS,TRNS,TRNS,END, TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,PGDN,TRNS,
        TRNS,TRNS,DEL, TRNS,TRNS,PGUP,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                 TRNS,TRNS,
                                      TRNS,
                            TRNS,TRNS,TRNS,

        TRNS,TRNS,TRNS,TRNS,TRNS,HOME,TRNS,
        TRNS,TRNS,TRNS,INS, TRNS,TRNS,TRNS,
             LEFT,DOWN,UP,  RGHT,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),
    KEYMAP(  // Layer 3: Standard Functions
        TRNS,F1,  F2,  F3,  F4,  F5,  TRNS,
        TRNS,TRNS,UP,  TRNS,TRNS,TRNS, F11,
        TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,
        TRNS,TRNS,DEL, TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                 MPRV,MNXT,
                                      VOLU,
                            MPLY,MUTE,VOLD,

        TRNS,F6,  F7,  F8,  F9,  F10, TRNS,
         F12,TRNS,TRNS,INS, TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,
        FN3, TRNS,
        SLEP,
        TRNS,TRNS,TRNS
    ),
};

static const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(3),
    [1] = ACTION_LAYER_TAP_KEY(2, KC_BSPC),
    [2] = ACTION_LAYER_TAP_KEY(2, KC_SPC),
    [3] = ACTION_LAYER_TOGGLE(1)
};
