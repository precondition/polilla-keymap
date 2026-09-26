#include QMK_KEYBOARD_H

#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

#include "keymap_japanese.h"


// All custom keycodes and aliases can be found in precondition_keymap.h
#include "precondition_keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_XYLOCUP] = LAYOUT(
           UNDO, REDO  ,DED_CIR, BNAV  , KC_F4 , KC_F5 ,                 DED_UML,LAEDER,E_GRAVE,E_ACUTE, KC_F10, KC_F11,
        KC_Q   , KC_X  , KC_L  , KC_C  , KC_P  , KC_K  ,                 KC_F   , KC_M  , KC_U  ,  KC_O ,  KC_Y ,KC_MINS,
        QK_REP ,HOME2_R,HOME2_N,HOME2_S,HOME2_T, KC_B  ,                 KC_H   ,HOMERET,OS_RSFT,HOME2_A,HOME2_I, KC_DOT,
 KC_J   , KC_ESC,RALT_T(KC_TAB), KC_G  , KC_D  , KC_V  ,MS_BTN1, MS_BTN2,KC_QUOT,KC_BSPC, KC_W  ,KC_SLSH,KC_COLN,CAPS_WORD_LOCK,

                      BDED_TOG,C_CDILA,OSL(_NAV), KC_SPC,MAGIC_L, MAGIC_R,HOME2_E,OSL(_SYM),S(KC_W),XYLOCUP
  ),

  [_GAMING] = LAYOUT(
           KC_1, KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                 DED_UML,DED_CIR,E_GRAVE,E_ACUTE, KC_F10, KC_F11,
        KC_LALT, KC_Q  , KC_W  , KC_F  , KC_P  , KC_B  ,                 KC_J   , KC_L  , KC_U  , KC_Y  ,KC_SCLN,KC_MINS,
         KC_ESC, KC_A  , KC_R  , KC_S  , KC_T  , KC_G  ,                 KC_M   , HOME_N, HOME_E, HOME_I, HOME_O,KC_QUOT,
        KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_D  , KC_V  ,TG_MIC,  COMPOSE,KC_K   , KC_H  ,KC_COMM, KC_DOT,KC_SLSH,ARROW_R,

                         GAMING,C_CDILA,NAV_TAB, KC_SPC,OS_LSFT, OS_RSFT,KC_BSPC,SYM_ENT,KC_RALT, KC_GRV
  ),

  [_SYM] = LAYOUT(
        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                 KC_F6  , KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11,
        KC_LABK,KC_BSLS,KC_LBRC,KC_RBRC, KC_GRV,KC_RABK,                 O_BRACE,KC_LCBR,KC_LPRN,KC_RPRN,KC_RCBR,KC_MINS,
        A_GRAVE, KC_4  , KC_2  , KC_3  , KC_1  , KC_5  ,                 KC_6   , KC_0  , KC_8  , KC_9  , KC_7  , KC_DOT,
        KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC, PLOVER, _______,KC_CIRC,KC_AMPR,KC_ASTR,KC_EQL ,KC_PLUS,KC_COMM,

                        _______,_______,  NAV  ,_______,_______, _______,_______,_______,KC_COMM, KC_DOT
  ),

  [_SYM2] = LAYOUT(
        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                 KC_F6  , KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11,
        _______,KC_HASH,KC_RBRC,KC_MINS,KC_RABK,KC_LABK,                 GUILL_L,KC_CIRC,O_BRQOT,KC_EXLM, LALT  ,C_BRQOT,
        NUM_OV ,KC_LBRC, KC_GRV,KC_LPRN,KC_RPRN,KC_PERC,                 GUILL_R, KC_EQL,KC_ASTR, KC_DLR,A_GRAVE, NUM_OV,
        _______, KC_AT ,KC_LCBR,KC_RCBR,KC_PLUS,_______, PLOVER, _______,  LALT ,KC_BSLS,KC_TILD,KC_PIPE,KC_AMPR,_______,

                        _______,_______,OSL(_NAV),_______,_______, _______,_______,_______,_______,_______
  ),

  [_NAV] = LAYOUT(
        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                 KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 , KC_F11,
        KC_INS , KC_4  , KC_2  , KC_3  , KC_1  , KC_5  ,                 _______,KC_PGUP, KC_UP ,KC_PGDN,_______,KC_MUTE,
        REP2   ,OS_LGUI,OS_LALT,OS_LSFT,OS_LCTL,  GNAV ,                 KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END ,KC_VOLU,
        QK_LOCK,_______,C(KC_A),C(KC_C),C(KC_V),_______,_______, KC_BRIU,KC_PSCR,_______,KC_LCBR,KC_RCBR,KC_INS ,KC_VOLD,

                         GAMING,_______,_______,_______,_______, KC_BRID,_______,_______,_______,_______
  ),

    [_NAV2] = LAYOUT(
        _______,_______,_______,_______,_______,_______,                 _______,_______,_______,_______,_______,_______,
        KC_X   , KC_4  , KC_2  , KC_3  , KC_1  , KC_5  ,                 KC_6   , KC_0  , KC_8  , KC_9  , KC_7  ,KC_MINS,
        _______,OS_LGUI,OS_LALT,OS_LSFT,OS_LCTL,_______,                 KC_LEFT,KC_DOWN, KC_UP ,KC_RGHT,KC_HOME, KC_END,
        _______,DOWN4  ,  DOWN2, DOWN3 , DOWN1 , DOWN5 ,_______, _______,  UP5  , UP1   ,  UP3  ,  UP2  ,  UP4  ,_______,

                        _______,_______,_______,_______,_______, TG(_NAV2) ,_______,_______,_______,_______
    ),

    [_NAV3] = LAYOUT(
        _______,_______,_______,_______,_______,_______,                 _______,_______,_______,_______,_______,_______,
        KC_LPRN, KC_X  , KC_P9 , KC_P8 , KC_P7 ,KC_RPRN,                 _______,KC_PGUP, KC_UP ,KC_PGDN,KC_PLUS,KC_MINS,
        KC_LABK,OS_LGUI, KC_P6 , KC_P5 , KC_P4 ,KC_RABK,                 KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,RGUI_T(KC_END), KC_DOT,
        _______,KC_EQL , KC_P3 , KC_P2 , KC_P1 ,_______,_______, _______,KC_PSCR,_______,KC_ASTR,KC_SLSH,KC_COLN,KC_COMM,

                        _______,_______, KC_P0 ,_______,_______, TG(_NAV3) ,_______,_______,_______,_______
    ),

    [_NAV_OVER] = LAYOUT(
        _______,_______,_______,_______,_______,_______,                 _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                 _______,_______,_______,_______,_______,_______,
      //_______,OS_LGUI,OS_LALT,OS_LSFT,HOMERET,_______,                 KC_LEFT,KC_DOWN, KC_UP ,KC_RGHT,KC_HOME, KC_END,
        KC_HOME, KC_END,KC_LEFT, KC_UP ,KC_DOWN,KC_RGHT,                 GNAV_OV,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______, _______,_______,_______,_______,_______,_______,_______,

                        _______,_______,_______,_______,_______, XXXXXXX ,_______,_______,_______,_______
    ),

    [_NUM_OVER] = LAYOUT(
        _______,_______,_______,_______,KC_PLUS,_______,                 _______,KC_EQL,_______,_______,_______,_______,
        KC_X   , KC_4  , KC_2  , KC_3  , KC_1  , KC_5  ,                 KC_6   , KC_0  , KC_8  , KC_9  , KC_7  ,KC_MINS,
        _______,_______,_______,_______,_______,_______,                 _______,_______,_______,_______,_______, KC_DOT,
        _______,_______,_______,_______,_______,_______,_______, _______,_______,KC_BSPC,_______,_______,_______,KC_COMM,

                        _______,_______,_______,_______,XXXXXXX, NUM_OV ,_______,_______,_______,_______
    ),

    [_GNAV_OVER] = LAYOUT(
        _______,_______,_______,_______,_______,_______,                 _______,_______,_______,_______,_______,_______,
        _______,_______,C(KC_PGUP),KC_PGUP,KC_PGDN,C(KC_PGDN),                 _______,_______,_______,_______,_______,_______,
        G_HOME , G_END ,_______, G_UP  , G_DOWN,_______,                 _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,_______, _______,_______,_______,_______,_______,_______,_______,

                        _______,_______,_______,_______,_______, _______,_______,_______,_______,_______
    ),

    [_OSMS_OVER] = LAYOUT(
        _______,_______,_______,_______,_______,_______,                 _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                 _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                 _______,OS_RCTL,OS_RSFT,OS_LALT,OS_RGUI,_______,
        _______,_______,_______,_______,_______,_______,_______, _______,_______,_______,_______,_______,_______,_______,

                        _______,_______,_______,_______,_______, _______,_______,_______,_______,_______
    ),

    [_GNAV] = LAYOUT(
        _______,_______,_______,_______,_______,_______,                 _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                 _______,_______, G_UP  ,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                 G_HOME ,_______, G_DOWN,_______, G_END ,_______,
        _______,_______,_______,_______,_______,_______,_______, _______,_______,_______,_______,_______,_______,_______,

                        _______,_______,_______,_______,_______, _______,_______,_______,_______,_______
    ),

    [_BNAV] = LAYOUT(
        _______,_______,_______,_______,_______,_______,                 _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                 _______,B_PREV , B_UP  , B_NEXT,_______,_______,
        _______,_______,_______,_______,_______,_______,                 _______, B_LEFT, B_DOWN,B_RIGHT, B_VERT,_______,
        _______,_______,_______,_______,_______,_______,_______, _______,B_PASTE,B_CPY_M,B_CREAT,B_CLOSE,B_HORIZ, B_ZOOM,

                        _______,_______,_______,_______,_______, _______,_______,_______,_______,_______
    ),

#ifdef STENO_ENABLE
    [_PLOVER] = LAYOUT(
        _______, STN_N1, STN_N2, STN_N3, STN_N4, STN_N5,                  STN_N6, STN_N7, STN_N8, STN_N9, STN_NA,KC_BSPC,
        _______, STN_S1, STN_TL, STN_PL, STN_HL,STN_ST1,                 STN_ST3, STN_FR, STN_PR, STN_LR, STN_TR, STN_DR,
        _______, STN_S2, STN_KL, STN_WL, STN_RL,STN_ST2,                 STN_ST4, STN_RR, STN_BR, STN_GR, STN_SR, STN_ZR,
        _______,_______,_______,_______,_______,_______, PLOVER, _______,_______,_______,_______,_______,_______,_______,

                        _______, STN_RL,  STN_A,  STN_O,_______, _______,  STN_E,  STN_U, STN_RR,_______
    ),
#endif


    [_MOUSE] = LAYOUT(
        _______, KC_P4 , KC_P2 , KC_P3 , KC_P1 , KC_P5 ,                 KC_P6  , KC_P0 , KC_P8 , KC_P9 , KC_P7 ,_______,
        _______, KC_Y  ,_______,_______,KC_BSPC,_______,                 _______,KC_WBAK,  MS_UP,KC_WFWD,_______,_______,
        _______,C(KC_A),KC_LALT,KC_LSFT,HOMERET,_______,                 _______,MS_LEFT,MS_DOWN,MS_RGHT,_______,_______,
        _______,KC_LALT,KC_TAB ,C(KC_C), PASTE ,QOTPAST,_______, _______,_______,MS_BTN3,MS_WHLU,MS_WHLD,_______,_______,

                        _______,_______,_______,_______,_______, MS_BTN3,MS_BTN1,MS_BTN2,_______,_______
    )
};

bool base_dead_keys = true;

// CAPS_WORD_LOCK: A "smart" Caps Lock key that only capitalizes the next identifier you type
// and then toggles off Caps Lock automatically when you're done.
void caps_word_enable(void) {
    caps_word_on = true;
    if (!(host_keyboard_led_state().caps_lock)) {
        tap_code(KC_CAPS);
    }
}

void caps_word_disable(void) {
    caps_word_on = false;
    unregister_mods(MOD_MASK_SHIFT);
    if (host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}

inline uint8_t get_tap_kc(uint16_t dual_role_key) {
    // Used to extract the basic tapping keycode from a dual-role key.
    // Example: get_tap_kc(MT(MOD_RSFT, KC_E)) == KC_E
    return dual_role_key & 0xFF;
}

static void process_caps_word(uint16_t keyc, const keyrecord_t *record) {
    // Nothing to process if caps_word isn't on
    if (!caps_word_on) { return; }

    // This switch(keycode) cannnot be fused with the second switch(keycode)
    // because this first switch conditionally changes the value of `keycode`.
    // The second switch has to be able to take this change into account.
    uint16_t keycode = keyc ==  MAGIC_L || keyc == MAGIC_R ? last_summoned_keycode : keyc;
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ...  MAGIC_L - 1 :
        case MAGIC_L + 1 ... QK_LAYER_TAP_MAX:
            // Earlier return if this has not been considered tapped yet
            if (record->tap.count == 0) { return; }
            // Get the base tapping keycode of a mod- or layer-tap key
            keycode = get_tap_kc(keycode);
            break;

    }

    switch (keycode) {
        // Keycodes to shift
        case KC_A ... KC_Z:
        case A_GRAVE:
        case E_ACUTE:
        case E_GRAVE:
        case C_CDILA:
        case MAGIC_L:
        case MAGIC_R:
        case GET_TAP_KC(MAGIC_L):
            if (record->event.pressed) {
                if (get_oneshot_mods() & MOD_MASK_SHIFT) {
                    caps_word_disable();
                    add_oneshot_mods(MOD_MASK_SHIFT);
                } else {
                    caps_word_enable();
                }
            }
            break;

        // Keycodes that enable caps word but shouldn't get shifted
        case CAPS_WORD_LOCK:
        case DED_CIR:
        case DED_UML:
        case KC_BSPC:
        case KC_LPRN:
        case KC_MINS:
        case KC_PIPE:
        case KC_RPRN:
        case KC_UNDS:
        case OS_LSFT:
        case OS_RSFT:
        case REPEAT:
        case KC_1 ... KC_0:
        case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
            // If chording mods, disable caps word
            if (record->event.pressed && (get_mods() != MOD_LSFT) && (get_mods() != 0)) {
                caps_word_disable();
            }
            break;

        default:
            // Any other keycode should automatically disable caps
            if (record->event.pressed && !(get_oneshot_mods() & MOD_MASK_SHIFT)) {
                caps_word_disable();
            }
            break;
    }
    //if (record->event.pressed) {
    //    tap_code(KC_SPACE);
    //    send_word(keycode);
    //    tap_code(KC_SPACE);
    //}
}

keyrecord_t prev_records[PREV_KEYS_WINDOW_LENGTH] = { 0 };
uint8_t prev_mods[PREV_KEYS_WINDOW_LENGTH] = { 0 };
static uint8_t last_oneshot_mods = 0;

uint16_t prev_keycode(uint8_t i) {
    return prev_records[i].keycode;
}

keypos_t prev_keypos(uint8_t i) {
    return prev_records[i].event.key;
}

#ifdef REPEAT_KEY_ENABLE
// Set when QMK's repeat key feature remembers the key being pressed, so that
// it gets pushed to prev_records. The push is deferred to the end of
// process_record_user so that prev_records[0] is still the previous key while
// the current one is being processed.
static bool should_push_prev_key = false;
// Set while REP2 replays keys.
static bool is_rep2_replaying = false;

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods) {
    // REP2 must not overwrite the keys it is about to repeat.
    if (keycode == REP2) {
        return false;
    }
    should_push_prev_key = true;
    return true;
}

static void push_prev_key(const keyrecord_t *record, uint16_t keycode, uint8_t mods) {
    for (int i = PREV_KEYS_WINDOW_LENGTH - 1 ; i > 0 ; --i) {
        prev_records[i] = prev_records[i - 1];
        prev_mods[i] = prev_mods[i - 1];
    }
    prev_records[0] = *record;
    prev_records[0].keycode = keycode;
    prev_mods[0] = mods;
}

// Index of the key that prev_records[i] stands for, skipping QK_REP entries.
static uint8_t resolve_prev_rep(uint8_t i) {
    while (i < PREV_KEYS_WINDOW_LENGTH - 1 && prev_records[i].keycode == QK_REP) {
        ++i;
    }
    return i;
}
#endif

#ifndef REPEAT_KEY_ENABLE
static void process_repeat_key(uint16_t keycode, const keyrecord_t *record) {
    static uint8_t last_modifier = 0;
    if (keycode != REPEAT) {
        // Early return when holding down a pure layer key
        // to retain modifiers
        switch (keycode) {
            case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
            case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
            case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
            case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
            case QK_TO ... QK_TO_MAX:
            case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
                return;
        }
        if (record->event.pressed) {
            last_modifier = get_oneshot_mods() | get_mods();
        }
        switch (keycode) {
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
                if (record->event.pressed) {
                    prev_keycodes[0] = get_tap_kc(keycode);
                }
                break;
            default:
                if (record->event.pressed) {
                    prev_keycodes[0] = keycode;
                }
                break;
        }
    } else { // keycode == REPEAT
        if (record->event.pressed) {
            register_mods(last_modifier);
            register_code16(prev_keycodes[0]);

            if (base_dead_keys) {
                switch (prev_keycodes[0]) {
                    case KC_QUOTE:
                    case KC_DOUBLE_QUOTE:
                    case KC_TILDE:
                    case KC_GRAVE:
                    case KC_CIRCUMFLEX:
                        tap_code(KC_SPACE);
                }
            }

        } else {
            unregister_code16(prev_keycodes[0]);
            unregister_mods(last_modifier);
        }
    }
}
#endif

// Sorted from highest on the layer stack to lowest.
static const unsigned int overlay_layers[] = { _OSMS_OVER, _NUM_OVER, _NAV_OVER };
#define NUM_OVERLAY_LAYERS (sizeof(overlay_layers) / sizeof(*overlay_layers))

static void process_layer_auto_leave(uint16_t keycode, keyrecord_t* record) {
    if (!record->event.pressed || keycode == NUM_OV || keycode == NAV_OV) {
        return;
    }

    const unsigned int topmost_layer_for_key = layer_switch_get_layer(record->event.key);

    const bool is_mod_tap = QK_MOD_TAP <= keycode && keycode <= QK_MOD_TAP_MAX;
    const bool is_oneshot_mod = QK_ONE_SHOT_MOD <= keycode && keycode <= QK_ONE_SHOT_MOD_MAX;
    const bool is_held_dual_role_mod = record->tap.count == 0 && (is_mod_tap || is_oneshot_mod);

    for (int i = 0; i < NUM_OVERLAY_LAYERS; ++i) {
        if (IS_LAYER_OFF(overlay_layers[i])) { continue; }
        // KC_NO is the layer cancel key (reports nothing to the host OS).
        // Use `<` instead of `!=` to support stacked overlays.
        if (keycode == KC_NO || (topmost_layer_for_key < overlay_layers[i] && !is_held_dual_role_mod)) {
            layer_off(overlay_layers[i]);
        }
        if (keycode == HOMERET && record->tap.count > 0) {
            // RCTL_T(KC_ENTER) or LCTL_T(KC_ENTER) may appear on the overlay
            // layers but tapping it should still auto-leave the layer.
            // However, holding the mod-tap should keep the layer on.
            layer_off(overlay_layers[i]);
        }
        if (overlay_layers[i] == _NUM_OVER) {
            // Directly leave NUM overlay if the number is part of a keyboard shortcut.
            if (KC_1 <= keycode && keycode <= KC_0 && (get_mods() || get_oneshot_mods() || last_oneshot_mods)) {
                layer_off(overlay_layers[i]);
            }
        }
    }
}

static int in_smart_square_brackets = 0;
static bool in_smart_quoted_square_brackets = false;
static void process_smart_square_brackets(uint16_t keycode, keyrecord_t* record) {
    /* Automatically closes square brackets and (most importantly) moves the
     * cursor forward, outside of the brackets. */
    if (in_smart_square_brackets < 1 || !record->event.pressed) {
        return;
    }

    const uint8_t mod_state = get_mods();
    const uint8_t oneshot_mod_state = get_oneshot_mods();

    if (keycode == KC_SPACE && last_oneshot_mods & MOD_MASK_SHIFT) {
        return;  // do not break on underscore.
    }

    switch (keycode) {
        case KC_SPACE:
        case KC_ENTER:
        case HOMERET:
        case KC_DOT:
        case KC_COMMA:
        case KC_ESC:
            del_mods(MOD_MASK_SHIFT);
            del_oneshot_mods(MOD_MASK_SHIFT);
            if (in_smart_quoted_square_brackets) {
                tap_code16(KC_DOUBLE_QUOTE);
                in_smart_quoted_square_brackets = false;
            }
            for (; in_smart_square_brackets > 0; --in_smart_square_brackets) {
                tap_code(KC_RIGHT_BRACKET);
            }
            set_mods(mod_state);
            set_oneshot_mods(oneshot_mod_state);
            break;

        case KC_QUOTE:
            in_smart_quoted_square_brackets = !in_smart_quoted_square_brackets;
            break;

        case KC_BACKSPACE:
            if (prev_keycode(0) == O_BRQOT) {
                in_smart_square_brackets -= 1;
            }
            break;

    }
}

static bool is_letter_keycode(uint16_t keycode) {
    switch (keycode & 0xFF) {
        case KC_A ... KC_Z:
            return true;

        default:
            return false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    const bool is_combo = record->event.type == COMBO_EVENT;
    uprintf("0x%04X\t%u\t%u\t0x%lX\t%u\t0x%02X\t0x%02X\t%u\t%s\n",
         keycode,
         is_combo ? 254 : record->event.key.row,
         is_combo ? 254 : record->event.key.col,
         layer_state|default_layer_state,
         record->event.pressed,
         get_mods(),
         get_oneshot_mods(),
         record->tap.count,
         get_keycode_string(keycode)
         );
#endif
#ifndef REPEAT_KEY_ENABLE
    process_repeat_key(keycode, record);
#endif
    process_caps_word(keycode, record);
    process_smart_square_brackets(keycode, record);

    const uint8_t mod_state = get_mods();
    const uint8_t oneshot_mod_state = get_oneshot_mods();
    bool retv = true;
    switch (keycode) {

    case CAPS_WORD_LOCK:
        // Toggle `caps_word_on`
        if (record->event.pressed) {
            if (caps_word_on) {
                caps_word_disable();
            } else {
                caps_word_enable();
            }
        }
        retv = false;
        break;

    case KC_SPC:
        if (record->event.pressed) {
            if (oneshot_mod_state & MOD_MASK_SHIFT) {
                tap_code(KC_MINS); // The one-shot shift will convert it to an underscore
                //tap_code16(KC_UNDS); // Needed for proper QK_REP support.
                retv = false;
                break;
            } else if (get_repeat_key_count() > 0) {
                if (last_oneshot_mods || get_repeat_key_count() > 1) {
                    tap_code16(KC_UNDS);
                } else {
                    // Terminal commands like « vim path/to/file », « chd
                    // path/to/dir » caused regular right index finger SFS
                    // because I typically use the Ctrl+T shell shortcut from
                    // fzf to insert a file path in the console but both Ctrl
                    // and KC_T/HOME_T are on index fingers. To work around
                    // this, I came up with the idea of triggering the
                    // __fzf_select() command by pressing KC_SPACE (home left
                    // thumb) + QK_REP (outer left pinky). I never need to
                    // repeat space and this has the added benefit of
                    // eliminating a SFS *and* the need to hold down a (home
                    // row) modifier key.
                    tap_code16(C(KC_T));  // CTRL-T - Open fzf and paste the
                                          // selected file path(s) into the
                                          // command line
                }
                retv = false;
                break;
            }
        }
        retv = true;
        break;

     case A_GRAVE:
         if (record->event.pressed) {
             del_mods(MOD_MASK_SHIFT);
             del_oneshot_mods(MOD_MASK_SHIFT);
             if (base_dead_keys) {
                tap_code(KC_GRV);
                wait_ms(KEY_SEQ_DELAY);
             } else {
                 tap_code16(ALGR(KC_GRV));
                 // If I am on US Intl. with AltGr dead keys, that means I am
                 // typically on Linux, so I do not need to add a
                 // `wait_ms(KEY_SEQ_DELAY)` to please Remote Desktop.
             }
             set_mods(mod_state);
             set_oneshot_mods(oneshot_mod_state);
             tap_code(KC_A);
         }
         retv = false;
         break;

     case E_GRAVE:
         if (record->event.pressed) {
             del_mods(MOD_MASK_SHIFT);
             del_oneshot_mods(MOD_MASK_SHIFT);
             if (base_dead_keys) {
                 tap_code(KC_GRV);
                 wait_ms(KEY_SEQ_DELAY);
             } else {
                 tap_code16(ALGR(KC_GRV));
             }
             set_mods(mod_state);
             set_oneshot_mods(oneshot_mod_state);
             tap_code(KC_E);
         }
         retv = false;
         break;

    case ARROW_R:
      if (record->event.pressed) {
          if ((mod_state|oneshot_mod_state) & MOD_MASK_SHIFT) {
            del_mods(MOD_MASK_SHIFT);
            del_oneshot_mods(MOD_MASK_SHIFT);
            tap_code(KC_EQUAL);
            tap_code16(KC_GT);
            set_mods(mod_state);
          } else {
            tap_code(KC_MINUS);
            tap_code16(KC_GT);
          }
      }
      retv = false;
      break;

    case G_DOWN:
        if (record->event.pressed) {
            register_code(KC_G);
            register_code(KC_J);
        } else {
            unregister_code(KC_G);
            unregister_code(KC_J);
        }
        retv = false;
        break;

    case G_UP:
        if (record->event.pressed) {
            register_code(KC_G);
            register_code(KC_K);
        } else {
            unregister_code(KC_G);
            unregister_code(KC_K);
        }
        retv = false;
        break;

    case G_HOME:
        if (record->event.pressed) {
            register_code(KC_G);
            register_code(KC_0);
        } else {
            unregister_code(KC_G);
            unregister_code(KC_0);
        }
        retv = false;
        break;

    case G_END:
        if (record->event.pressed) {
            register_code(KC_G);
            register_code(KC_END);
        } else {
            unregister_code(KC_G);
            unregister_code(KC_END);
        }
        retv = false;
        break;

    case GUILL_L:
        if (record->event.pressed) {
            tap_code(COMPOSE);
            tap_code16(KC_LT);
            tap_code16(KC_LT);
            tap_code(COMPOSE);
            tap_code(KC_SPACE);
            tap_code(KC_SPACE);
        }
        retv = false;
        break;

    case GUILL_R:
        if (record->event.pressed) {
            tap_code(COMPOSE);
            tap_code(KC_SPACE);
            tap_code(KC_SPACE);
            tap_code(COMPOSE);
            tap_code16(KC_GT);
            tap_code16(KC_GT);
        }
        retv = false;
        break;

    case UPDIR:
        if (record->event.pressed) {
            tap_code(KC_DOT);
            tap_code(KC_DOT);
            tap_code(KC_SLSH);
        }
        retv = false;
        break;

    case O_BRACE:
        if (record->event.pressed) {
            tap_code16(KC_LEFT_CURLY_BRACE);
            tap_code(KC_ENTER);
            tap_code(KC_ENTER);
            tap_code(KC_UP);
            tap_code(KC_TAB);
        }
        retv = false;
        break;

    case C_BRACE:
        if (record->event.pressed) {
            tap_code16(KC_RIGHT_CURLY_BRACE);
            tap_code(KC_ENTER);
        }
        retv = false;
        break;

    case O_BRQOT:
        if (record->event.pressed) {
            tap_code(KC_LEFT_BRACKET);
            in_smart_square_brackets += 1;
            //tap_code16(KC_DOUBLE_QUOTE);
            //if (base_dead_keys) {
            //    tap_code(KC_SPACE);
            //}
        }
        retv = false;
        break;

    case C_BRQOT:
        if (record->event.pressed) {
            tap_code16(KC_DOUBLE_QUOTE);
            if (base_dead_keys) {
                tap_code(KC_SPACE);
            }
            tap_code(KC_RIGHT_BRACKET);
        }
        retv = false;
        break;

    case COUTLN:
        if (record->event.pressed) {
            // Not SEND_STRING: it pulls in QMK's send_string code and its
            // ASCII-to-keycode lookup table, which is too much flash for the
            // STM32F042. Once the firmware grows into the emulated EEPROM pages,
            // the keyboard becomes unresponsive. Replacing every SEND_STRING
            // saved ≈670 bytes.
            // With dead keys, the double quotes consume the space next to them.
            static const uint16_t dead_keys_keycodes[] = {
                // « std::cout <<  << " \n" ; »
                KC_S, KC_T, KC_D, KC_COLN, KC_COLN, KC_C, KC_O, KC_U, KC_T, KC_SPC,
                KC_LT, KC_LT, KC_SPC, KC_SPC, KC_LT, KC_LT, KC_SPC,
                KC_DQUO, KC_SPC, KC_BSLS, KC_N, KC_DQUO, KC_SPC, KC_SCLN, KC_NO
            };
            static const uint16_t keycodes[] = {
                // « std::cout <<  << "\n"; »
                KC_S, KC_T, KC_D, KC_COLN, KC_COLN, KC_C, KC_O, KC_U, KC_T, KC_SPC,
                KC_LT, KC_LT, KC_SPC, KC_SPC, KC_LT, KC_LT, KC_SPC,
                KC_DQUO, KC_BSLS, KC_N, KC_DQUO, KC_SCLN, KC_NO
            };
            for (const uint16_t *kc = base_dead_keys ? dead_keys_keycodes : keycodes; *kc != KC_NO; ++kc) {
                tap_code16(*kc);
                wait_ms(KEY_SEQ_DELAY);
            }
            for (int i = 0; i < 9; ++i)  {
                tap_code(KC_LEFT);
            }
        }
        retv = false;
        break;



    // tmux window navigation
    case B_CREAT:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code(KC_C);
        }
        retv = false;
        break;

    case B_PREV:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code(KC_P);
        }
        retv = false;
        break;

    case B_NEXT:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code(KC_N);
        }
        retv = false;
        break;

    // tmux pane navigation
    case B_VERT:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code16(KC_PERCENT);
        }
        retv = false;
        break;

    case B_HORIZ:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code16(KC_DOUBLE_QUOTE);
            if (base_dead_keys) {
                tap_code(KC_SPACE);
            }
        }
        retv = false;
        break;

    case B_UP:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code(KC_UP);
        }
        retv = false;
        break;

    case B_LEFT:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code(KC_LEFT);
        }
        retv = false;
        break;

    case B_DOWN:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code(KC_DOWN);
        }
        retv = false;
        break;

    case B_RIGHT:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code(KC_RIGHT);
        }
        retv = false;
        break;

    // tmux copy mode and paste buffer
    case B_PASTE:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code(KC_RIGHT_BRACKET);
        }
        retv = false;
        break;

    case B_CPY_M:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code(KC_LEFT_BRACKET);
        }
        retv = false;
        break;

    // tmux zoom
    case B_ZOOM:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code(KC_Z);
        }
        retv = false;
        break;

    // tmux clone pane
    case B_CLOSE:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code(KC_X);
        }
        retv = false;
        break;

    case DED_CIR:
    {
        const uint16_t dead_circumflex = base_dead_keys ? KC_CIRCUMFLEX : ALGR(KC_6);
        if (record->event.pressed) {
            register_code16(dead_circumflex);
        } else {
            unregister_code16(dead_circumflex);
        }
        retv = true;
        break;
    }

    case DED_UML:
    {
        const uint16_t dead_umlaut = base_dead_keys ? KC_DOUBLE_QUOTE : ALGR(KC_DOUBLE_QUOTE);
        if (record->event.pressed) {
            register_code16(dead_umlaut);
        } else {
            unregister_code16(dead_umlaut);
        }
        retv = true;
        break;
    }

    case C_CDILA:
        // A simple `ALGR(KC_COMMA)` alias may go too fast for Remote Desktop
        // Protocol on Windows, so it works better to override the keycode in
        // order to add a `wait_ms` between the modifier press and the comma
        // press. You may be tempted to think that increasing the
        // `TAP_CODE_DELAY` in config.h would help for this but it does not
        // because that only increases the time between the press and release
        // of the same keycode without affecting the delay between the events
        // of two different keycodes.
        if (record->event.pressed) {
            register_weak_mods(MOD_BIT(KC_RALT));
            wait_ms(KEY_SEQ_DELAY);
            register_code(KC_COMMA);
        } else {
            unregister_code(KC_COMMA);
            unregister_weak_mods(MOD_BIT(KC_RALT));
        }
        retv = false;
        break;


    case E_ACUTE:
        // See C_CDILA comment.
        if (record->event.pressed) {
            register_weak_mods(MOD_BIT(KC_RALT));
            wait_ms(KEY_SEQ_DELAY);
            register_code(KC_E);
        } else {
            unregister_code(KC_E);
            unregister_weak_mods(MOD_BIT(KC_RALT));
        }
        retv = false;
        break;

    // Toggle `base_dead_keys` dynamically at runtime.
    case BDED_TOG:
        if (record->event.pressed) {
            base_dead_keys = !base_dead_keys;
        }
        retv = false;
        break;


    case OS_LSFT:
    case OS_RSFT:
        // Double tap one-shot shift to enable caps word.
        if (record->event.pressed && (record->tap.count > 1 || get_oneshot_mods() & MOD_BIT(KC_LSFT) || get_oneshot_mods() & MOD_BIT(KC_RSFT))) {
            caps_word_enable();
            retv = false;
            break;
        }
        retv = true;
        break;

    case MAGIC_L:
        if (record->tap.count > 0) {
            if (record->event.pressed) {
                // TODO: refactor.
                if (get_repeat_key_count() > 0) {
                    tap_code(last_summoned_keycode);
                } else {
                    process_magic_key_left();
                }
            }
            retv = false;
        } else {
            retv = true;
        }
        break;

    case MAGIC_R:
        if (record->event.pressed) {
            if (get_repeat_key_count() > 0) {
                tap_code(last_summoned_keycode);
            } else {
                process_magic_key_right();
            }
        }
        retv = true;
        break;

    case NAV_OV:
        if (record->event.pressed) {
            layer_on(_NAV_OVER);
            layer_on(_NUM_OVER);
            layer_on(_OSMS_OVER);
        }
        retv = false;
        break;

    case NUM_OV:
        // Do not disable the layer when releasing the key.
        // There is another mechanism in place to leave the layer (the
        // overlay auto-leave).
        retv = record->event.pressed;
        break;

    case LALT:
        if (record->event.pressed) {
            register_code(KC_LALT);
        } else {
            unregister_code(KC_LALT);
        }
        retv = false;
        break;

    case DOWN1 ... DOWN5:
        if (record->event.pressed) {
            tap_code(KC_1 + (keycode - DOWN1));
            tap_code(KC_DOWN);
        }
        retv = false;
        break;

    case UP1 ... UP5:
        if (record->event.pressed) {
            tap_code(KC_1 + (keycode - UP1));
            tap_code(KC_UP);
        }
        retv = false;
        break;

    case QOTPAST:
        // Quoted paste.
        if (record->event.pressed) {
            tap_code(KC_QUOTE);
            wait_ms(KEY_SEQ_DELAY);
            if (base_dead_keys) {
                tap_code(KC_SPACE);
                wait_ms(KEY_SEQ_DELAY);
            }
            tap_code16(S(KC_INS));
            wait_ms(KEY_SEQ_DELAY);
            tap_code(KC_QUOTE);
            wait_ms(KEY_SEQ_DELAY);
            if (base_dead_keys) {
                tap_code(KC_SPACE);
            }
        }
        retv = false;
        break;

    // Adaptive swap: CP CK
    // To eliminate the LSB on the common « ck » bigram.
    // Not if either key has a mod (held or one-shot), e.g. to type camelCase
    // like « HilcParameter » or shortcuts like Ctrl+C followed by P.
    // Only within 1500 ms of the C press. The 16-bit press times wrap around
    // after ≈65 s, so last_input_activity_elapsed() rules out long pauses.
    // See https://github.com/qmk/qmk_firmware/issues/26464
    case KC_P:
        if (record->event.pressed && !(mod_state | oneshot_mod_state | prev_mods[0]) && prev_keycode(0) == KC_C && last_input_activity_elapsed() < 1500 && TIMER_DIFF_16(record->event.time, prev_records[0].event.time) < 1500) {
            tap_code(KC_K);
            last_summoned_keycode = KC_K;
            retv = false;
            break;
        }
        retv = true;
        break;

    case KC_K:
        if (record->event.pressed && !(mod_state | oneshot_mod_state | prev_mods[0]) && prev_keycode(0) == KC_C && last_input_activity_elapsed() < 1500 && TIMER_DIFF_16(record->event.time, prev_records[0].event.time) < 1500) {
            tap_code(KC_P);
            last_summoned_keycode = KC_P;
            retv = false;
            break;
        }
        retv = true;
        break;

    // Adaptive swap: I_X I_Y
    // To eliminate the SFS on the common « i_y » skipgram.
    case KC_X:
        if (record->event.pressed && is_letter_keycode(prev_keycode(0)) && (GET_TAP_KC(prev_keycode(1))) == KC_I) {
            tap_code(KC_Y);
            last_summoned_keycode = KC_Y;
            retv = false;
            break;
        }
        retv = true;
        break;

    case KC_Y:
        if (record->event.pressed && is_letter_keycode(prev_keycode(0)) && (GET_TAP_KC(prev_keycode(1))) == KC_I) {
            tap_code(KC_X);
            last_summoned_keycode = KC_X;
            retv = false;
            break;
        }
        retv = true;
        break;

#ifdef REPEAT_KEY_ENABLE
    case REP2:
        // Replay the last two keys through QMK's repeat key machinery so
        // that custom keycodes, mod-taps and mods behave like with QK_REP.
        if (record->event.pressed) {
            // Copy the last two keys first since replaying them updates the
            // history. QK_REP entries stand for the key they repeated.
            const uint8_t sources[2] = { resolve_prev_rep(1), resolve_prev_rep(0) };
            keyrecord_t records[2];
            uint8_t mods[2];
            for (int i = 0; i < 2; ++i) {
                records[i] = prev_records[sources[i]];
                mods[i] = prev_mods[sources[i]];
            }
            keyevent_t event = record->event;
            is_rep2_replaying = true;
            for (int i = 0; i < 2; ++i) {
                if (!records[i].keycode || records[i].keycode == QK_REP) {
                    continue;
                }
                set_last_record(records[i].keycode, &records[i]);
                set_last_mods(mods[i]);
                event.pressed = true;
                repeat_key_invoke(&event);
                event.pressed = false;
                repeat_key_invoke(&event);
            }
            is_rep2_replaying = false;
        }
        retv = false;
        break;
#endif

    case LAEDER:
        const bool is_shift_on = (mod_state | oneshot_mod_state) & MOD_MASK_SHIFT;
        const uint16_t laeder_keycode = base_dead_keys ^ is_shift_on ? KC_LALT : COMPOSE;
        if (record->event.pressed) {
            register_code(laeder_keycode);
        } else {
            unregister_code(KC_LALT);
            unregister_code(COMPOSE);
        }
        retv = false;
        break;


    }

#ifdef REPEAT_KEY_ENABLE
    if (record->event.pressed) {
        if (get_repeat_key_count() < 1) {
            // Keys that QMK does not remember (mods, layer keys, one-shot
            // keys, REP2, …) do not enter the history.
            if (should_push_prev_key) {
                push_prev_key(get_last_record(), get_last_keycode(), get_last_mods());
                should_push_prev_key = false;
            }
        } else if (is_rep2_replaying) {
            // Keys replayed by REP2 enter the history as themselves.
            push_prev_key(get_last_record(), get_last_keycode(), get_last_mods());
        } else {
            // QMK does not remember QK_REP but the magic rules need it,
            // e.g. « o↻k ». Keep the position of the QK_REP key itself.
            push_prev_key(record, QK_REP, get_mods());
        }
    }
#else
    process_repeat_key(keycode, record);
#endif
    if (record->event.pressed) {
        last_oneshot_mods = oneshot_mod_state;
    }

    return retv;
};

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (QK_ONE_SHOT_LAYER <= last_summoned_keycode && last_summoned_keycode <= QK_ONE_SHOT_LAYER_MAX) {
        clear_oneshot_layer_state(ONESHOT_PRESSED);
        last_summoned_keycode = KC_NO;
    }
    process_layer_auto_leave(keycode, record);
    switch (keycode) {
        case KC_QUOTE:
        case KC_DOUBLE_QUOTE:
        case KC_TILDE:
        case KC_GRAVE:
        case KC_CIRCUMFLEX:
            if (base_dead_keys && record->event.pressed) {
                tap_code(KC_SPACE);
            }
            break;
    }
}

#ifdef QUICK_TAP_TERM_PER_KEY
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_R:
            return GET_TAPPING_TERM(keycode, record);
        case NAV_TAB:
            return 100;
        default:
            return 16;
    }
}
#endif

#ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            // Immediately select the hold action when another key is pressed.
            return keycode != MAGIC_L;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}
#endif

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_O:
            return TAPPING_TERM + 20;
        case SYM_ENT:
            // Very low tapping term to make sure I don't hit Enter accidentally.
            return TAPPING_TERM - 65;
        default:
            return TAPPING_TERM;
    }
};
#endif


#ifdef KEY_OVERRIDE_ENABLE
const key_override_t colon_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLON, KC_SEMICOLON);
const key_override_t dot_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_COMMA, 1 << _XYLOCUP);
const key_override_t shift_ins_key_override = ko_make_basic(MOD_MASK_SHIFT, S(KC_INS), C(S(KC_V)));
const key_override_t minus_key_override = ko_make_with_layers_and_negmods(
        MOD_MASK_SHIFT, KC_MINS, KC_EQUAL, ~0, MOD_MASK_ALT);
// TODO: LShift+RShift+KC_BACKSPACE = Shift+KC_DELETE (to delete entries in Firefox)
const key_override_t backspace_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BACKSPACE, KC_DELETE);

const key_override_t *key_overrides[] = {
    &colon_key_override,
    &dot_key_override,
    &shift_ins_key_override,
    &backspace_key_override,
    &minus_key_override
};
#endif
