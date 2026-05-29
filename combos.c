#include QMK_KEYBOARD_H
#include "precondition_keymap.h"
#include "action_tapping.h" // necessary for action_tapping_process
#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

enum combo_events {
    /* Backspace steno-lite combos */
    // These let me type common words and n-grams
    // more quickly, in one single stroke.
    BSPCU_YOU,
    BSPCW_WH,
    BSPCH_HERE,

    /* Other steno-lite combos */
    // Additional steno-lite combos for common words and n-grams
    // that do not involve the backspace thumb key because these
    // combinations of keys do not generate too many conflicts
    // in normal typing.
    HV_HAVE,

    /* Non-alphanumeric combos */
    // Combos for which the output isn't one or more alphanumeric characters
    OS_SFT_CAPS,
    REPEATX_BSLS,
    PT_MOUSE,

    BV_Z,

    // This must be the last item in the enum.
    // This is used to automatically update the combo count.
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM BSPC_U_COMBO[]     = {KC_BSPC,  KC_U,    COMBO_END};
const uint16_t PROGMEM BSPC_W_COMBO[]     = {KC_BSPC,  KC_W,    COMBO_END};
const uint16_t PROGMEM BSPC_H_COMBO[]     = {KC_BSPC,  KC_H,    COMBO_END};
const uint16_t PROGMEM H_V_COMBO[]        = {KC_H,     KC_V,    COMBO_END};
const uint16_t PROGMEM OS_SFT_COMBO[]     = {OS_LSFT,  OS_RSFT, COMBO_END};
const uint16_t PROGMEM REPEAT_X_COMBO[]   = {REPEAT,   KC_X,    COMBO_END};
const uint16_t PROGMEM P_T_COMBO[]        = {KC_P,     HOME_T,  COMBO_END};
const uint16_t PROGMEM B_V_COMBO[]        = {KC_B,     KC_V,    COMBO_END};

combo_t key_combos[] = {
    [BSPCU_YOU]       = COMBO_ACTION(BSPC_U_COMBO),
    [BSPCW_WH]        = COMBO_ACTION(BSPC_W_COMBO),
    [BSPCH_HERE]      = COMBO_ACTION(BSPC_H_COMBO),
    [HV_HAVE]         = COMBO_ACTION(H_V_COMBO),
    [OS_SFT_CAPS]     = COMBO(OS_SFT_COMBO, CAPS_WORD_LOCK),
    [REPEATX_BSLS]    = COMBO(REPEAT_X_COMBO, KC_BACKSLASH),
    [PT_MOUSE]        = COMBO(P_T_COMBO, MOUSE),
    [BV_Z]            = COMBO(B_V_COMBO, KC_Z),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    // Process mod-taps before the combo is fired,
    // this helps making modifier-aware combos,
    // like UYCLN_INDEX more fluid
    // when I use them with home row mods.
    action_tapping_process((keyrecord_t){});
#ifdef CONSOLE_ENABLE
    combo_t *combo = &key_combos[combo_index];
    uint8_t idx = 0;
    uint16_t combo_keycode;
    while ((combo_keycode = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        uprintf("0x%04X\t%u\t%u\t0x%lX\t%u\t0x%02X\t0x%02X\t0\t%s\n",
            combo_keycode,
            254,
            254,
            layer_state|default_layer_state,
            pressed,
            get_mods(),
            get_oneshot_mods(),
            /* tap_count==0 */
            get_keycode_string(combo_keycode)
        );
        idx++;
    }
#endif
    switch(combo_index) {

        case HV_HAVE:
            if (pressed) {
                SEND_STRING("have");
            }
        break;

        case BSPCU_YOU:
            if (pressed) {
                SEND_STRING("you");
            }
        break;

        case BSPCW_WH:
            if (pressed) {
                SEND_STRING("wh");
            }
        break;

        case BSPCH_HERE:
            if (pressed) {
                SEND_STRING("here");
            }
        break;

    }
};
