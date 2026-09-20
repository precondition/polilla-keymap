#include QMK_KEYBOARD_H
#include "precondition_keymap.h"

enum combo_events {
    BV_Z,

    // This must be the last item in the enum.
    // This is used to automatically update the combo count.
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM B_V_COMBO[]        = {KC_B,     KC_V,    COMBO_END};

combo_t key_combos[] = {
    [BV_Z]            = COMBO(B_V_COMBO, KC_Z),
};

