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
    BSPCH_HERE,
    // I use the word "key" much more frequently than the common folk
    // and if you're reading this, you probably do too
    BSPCK_KEY,

    /* Other steno-lite combos */
    // Additional steno-lite combos for common words and n-grams
    // that do not involve the backspace thumb key because these
    // combinations of keys do not generate too many conflicts
    // in normal typing.
    HV_HAVE,
    QK_QMK,
    WA_WHAT,

    /* Non-alphanumeric combos */
    // Combos for which the output isn't one or more alphanumeric characters
    OS_SFT_CAPS,
    REPEATX_BSLS,
    ZEROEIGHT_COMMA,
    EIGHTNINE_DOT,
    PT_MOUSE,

    // Vertical combos mimicking Vim arrows.
    JM_LEFT,
    LN_DOWN,
    UE_UP,
    YI_RIGHT,

    // Vertical combos for home and end, inspired by the above cursor combos.
    MK_HOME,
    IDOT_END,

    // This must be the last item in the enum.
    // This is used to automatically update the combo count.
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM BSPC_U_COMBO[]     = {KC_BSPC,  KC_U,    COMBO_END};
const uint16_t PROGMEM BSPC_N_COMBO[]     = {KC_BSPC,  HOME_N,  COMBO_END};
const uint16_t PROGMEM BSPC_H_COMBO[]     = {KC_BSPC,  KC_H,    COMBO_END};
const uint16_t PROGMEM BSPC_K_COMBO[]     = {KC_BSPC,  KC_K,    COMBO_END};
const uint16_t PROGMEM H_V_COMBO[]        = {KC_H,     KC_V,    COMBO_END};
const uint16_t PROGMEM Q_K_COMBO[]        = {KC_Q,     KC_K,    COMBO_END};
const uint16_t PROGMEM W_A_COMBO[]        = {KC_W,     HOME_A,  COMBO_END};
const uint16_t PROGMEM OS_SFT_COMBO[]     = {OS_LSFT,  OS_RSFT, COMBO_END};
const uint16_t PROGMEM REPEAT_X_COMBO[]   = {REPEAT,   KC_X,    COMBO_END};
const uint16_t PROGMEM ZERO_EIGHT_COMBO[] = {KC_0,     KC_8,    COMBO_END};
const uint16_t PROGMEM EIGHT_NINE_COMBO[] = {KC_8,     KC_9,    COMBO_END};
const uint16_t PROGMEM P_T_COMBO[]        = {KC_P,     HOME_T,  COMBO_END};
const uint16_t PROGMEM J_M_COMBO[]        = {KC_J,     KC_M,    COMBO_END};
const uint16_t PROGMEM L_N_COMBO[]        = {KC_L,     HOME_N,  COMBO_END};
const uint16_t PROGMEM U_E_COMBO[]        = {KC_U,     HOME_E,  COMBO_END};
const uint16_t PROGMEM Y_I_COMBO[]        = {KC_Y,     HOME_I,  COMBO_END};
const uint16_t PROGMEM SCLN_O_COMBO[]     = {KC_SCLN,  HOME_O,  COMBO_END};
const uint16_t PROGMEM M_K_COMBO[]        = {KC_M,     KC_K,    COMBO_END};
const uint16_t PROGMEM I_DOT_COMBO[]      = {HOME_I,   TD_DOT,  COMBO_END};

combo_t key_combos[] = {
    [BSPCU_YOU]       = COMBO_ACTION(BSPC_U_COMBO),
    [BSPCH_HERE]      = COMBO_ACTION(BSPC_H_COMBO),
    [BSPCK_KEY]       = COMBO_ACTION(BSPC_K_COMBO),
    [HV_HAVE]         = COMBO_ACTION(H_V_COMBO),
    [QK_QMK]          = COMBO_ACTION(Q_K_COMBO),
    [WA_WHAT]         = COMBO_ACTION(W_A_COMBO),
    [OS_SFT_CAPS]     = COMBO(OS_SFT_COMBO, CAPS_WORD_LOCK),
    [REPEATX_BSLS]    = COMBO(REPEAT_X_COMBO, KC_BACKSLASH),
    [ZEROEIGHT_COMMA] = COMBO(ZERO_EIGHT_COMBO, KC_COMMA),
    [EIGHTNINE_DOT]   = COMBO(EIGHT_NINE_COMBO, KC_DOT),
    [PT_MOUSE]        = COMBO(P_T_COMBO, MOUSE),
    [JM_LEFT]         = COMBO(J_M_COMBO, KC_LEFT),
    [LN_DOWN]         = COMBO(L_N_COMBO, KC_DOWN),
    [UE_UP]           = COMBO(U_E_COMBO, KC_UP),
    [YI_RIGHT]        = COMBO(Y_I_COMBO, KC_RIGHT),
    [MK_HOME]         = COMBO(M_K_COMBO, KC_HOME),
    [IDOT_END]        = COMBO(I_DOT_COMBO, KC_END),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    // Process mod-taps before the combo is fired,
    // this helps making modifier-aware combos,
    // like UYCLN_INDEX more fluid
    // when I use them with home row mods.
    action_tapping_process((keyrecord_t){});
    const uint8_t mod_state = get_mods();
    const uint8_t oneshot_mod_state = get_oneshot_mods();
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

        case QK_QMK:
            if (pressed) {
                if (mod_state & MOD_MASK_SHIFT || oneshot_mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    del_oneshot_mods(MOD_MASK_SHIFT);
                    SEND_STRING("QMK");
                    set_mods(mod_state);
                }
                else {
                    SEND_STRING("qmk");
                }
        }
        break;

        case BSPCU_YOU:
            if (pressed) {
                SEND_STRING("you");
            }
        break;

        case BSPCH_HERE:
            if (pressed) {
                SEND_STRING("here");
            }
        break;

        case BSPCK_KEY:
            if (pressed) {
                SEND_STRING("key");
            }
        break;

        case WA_WHAT:
            if (pressed) {
                SEND_STRING("what");
            }
        break;

    }
};
