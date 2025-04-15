/* Colemak DHm with home row mods and hybrid steno
 * for the Polilla Keyboard */

#include QMK_KEYBOARD_H

#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

#include "keymap_japanese.h"

#include "version.h"

// All custom keycodes and aliases can be found in precondition_keymap.h
#include "precondition_keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK_DH] = LAYOUT(
           UNDO, REDO  , KC_GRV, BNAV  , KC_F4 , KC_F5 ,                 DED_UML,DED_CIR,E_GRAVE,E_ACUTE, KC_F10, KC_F11,
        A_GRAVE, KC_Q  , KC_W  , KC_F  , KC_P  , KC_B  ,                 KC_J   , KC_L  , KC_U  , KC_Y  ,KC_COLN,KC_MINS,
         KC_ESC, HOME_A, HOME_R, HOME_S, HOME_T, KC_G  ,                 KC_M   , HOME_N, HOME_E, HOME_I, HOME_O,KC_QUOT,
           KC_Z, REPEAT, KC_X  , KC_C  , KC_D  , KC_V  ,TG_MIC,  COMPOSE,KC_K   , KC_H  ,KC_COMM, TD_DOT,KC_SLSH,ARROW_R,

                         GAMING,C_CDILA,NAV_TAB, KC_SPC,OS_LSFT, OS_RSFT,KC_BSPC,SYM_ENT,KC_RALT,TG_MIC
  ),

  [_GAMING] = LAYOUT(
           KC_1, KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                 DED_UML,DED_CIR,E_GRAVE,E_ACUTE, KC_F10, KC_F11,
        KC_LALT, KC_Q  , KC_W  , KC_F  , KC_P  , KC_B  ,                 KC_J   , KC_L  , KC_U  , KC_Y  ,KC_SCLN,KC_MINS,
         KC_ESC, KC_A  , KC_R  , KC_S  , KC_T  , KC_G  ,                 KC_M   , HOME_N, HOME_E, HOME_I, HOME_O,KC_QUOT,
        KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_D  , KC_V  ,TG_MIC,  COMPOSE,KC_K   , KC_H  ,KC_COMM, TD_DOT,KC_SLSH,ARROW_R,

                         GAMING,C_CDILA,NAV_TAB, KC_SPC,OS_LSFT, OS_RSFT,KC_BSPC,SYM_ENT,KC_RALT, KC_GRV
  ),

  [_SYM] = LAYOUT(
        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                 KC_F6  , KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11,
           KC_X, KC_4  , KC_2  , KC_3  , KC_1  , KC_5  ,                 KC_6   , KC_0  , KC_8  , KC_9  , KC_7  ,KC_MINS,
        GUILL_L,O_BRQOT,KC_LBRC,KC_RBRC,C_BRQOT,GUILL_R,                 O_BRACE,KC_LCBR,KC_LPRN,KC_RPRN,KC_RCBR,C_BRACE,
        KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC, PLOVER, _______,KC_CIRC,KC_AMPR,KC_ASTR,KC_EQL ,KC_PLUS, KC_GRV,

                        _______,_______,  NAV  ,_______,_______, _______,_______,_______,KC_COMM, KC_DOT
  ),

  [_NAV] = LAYOUT(
        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                 KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 , KC_F11,
        _______,_______, KC_NUM,KC_SCRL,KC_INS ,  BNAV ,                 _______,KC_PGUP, KC_UP ,KC_PGDN,_______,KC_MUTE,
        MS_CAPS,KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,  GNAV ,                 KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END ,KC_VOLU,
        _______, COUTLN,C(KC_A),C(KC_C),C(KC_V),_______,_______, KC_BRIU,_______,KC_PSCR,KC_LCBR,KC_RCBR,KC_INS ,KC_VOLD,

                        _______,_______,_______,_______,_______, KC_BRID,_______,_______,_______,_______
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
        _______,_______,_______,_______,_______,_______,                 _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                 _______,KC_WBAK,KC_MS_U,KC_WFWD,_______,_______,
        _______,KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,_______,                 _______,KC_MS_L,KC_MS_D,KC_MS_R,_______,_______,
        _______,_______,_______,_______,_______,QK_VERS,_______, _______,_______,KC_BTN3,KC_WH_U,KC_WH_D,_______,_______,

                        _______,_______,_______,_______,_______, KC_BTN3,KC_BTN1,KC_BTN2,_______,_______
    )
};


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

static void process_caps_word(uint16_t keycode, const keyrecord_t *record) {
    // Nothing to process if caps_word isn't on
    if (!caps_word_on) { return; }

    // This switch(keycode) cannnot be fused with the second switch(keycode)
    // because this first switch conditionally changes the value of `keycode`.
    // The second switch has to be able to take this change into account.
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            // Earlier return if this has not been considered tapped yet
            if (record->tap.count == 0) { return; }
            // Get the base tapping keycode of a mod- or layer-tap key
            keycode = get_tap_kc(keycode);
            break;
        default:
            break;
    }

    switch (keycode) {
        // Keycodes to shift
        case KC_A ... KC_Z:
        case A_GRAVE:
        case E_ACUTE:
        case E_GRAVE:
        case C_CDILA:
            if (record->event.pressed) {
                if (get_oneshot_mods() & MOD_MASK_SHIFT) {
                    caps_word_disable();
                    add_oneshot_mods(MOD_MASK_SHIFT);
                } else {
                    caps_word_enable();
                }
            }
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
}

static uint16_t last_keycode = KC_NO;
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
                    last_keycode = get_tap_kc(keycode);
                }
                break;
            case TD_DOT:
                if (record->event.pressed) {
                    last_keycode = KC_DOT;
                }
                break;
            default:
                if (record->event.pressed) {
                    last_keycode = keycode;
                }
                break;
        }
    } else { // keycode == REPEAT
        if (record->event.pressed) {
            register_mods(last_modifier);
            register_code16(last_keycode);
        } else {
            unregister_code16(last_keycode);
            unregister_mods(last_modifier);
        }
    }
}


bool base_dead_keys = true;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    const bool is_combo = record->event.type == COMBO_EVENT;
    uprintf("0x%04X\t%u\t%u\t0x%X\t%u\t0x%02X\t0x%02X\t%u\n",
         keycode,
         is_combo ? 254 : record->event.key.row,
         is_combo ? 254 : record->event.key.col,
         layer_state|default_layer_state,
         record->event.pressed,
         get_mods(),
         get_oneshot_mods(),
         record->tap.count
         );
#endif
    process_caps_word(keycode, record);
    process_repeat_key(keycode, record);

    const uint8_t mod_state = get_mods();
    const uint8_t oneshot_mod_state = get_oneshot_mods();
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
        return false;

    case KC_SPC:
        if (oneshot_mod_state & MOD_MASK_SHIFT) {
            if (record->event.pressed) {
                tap_code(KC_MINS); // The one-shot shift will convert it to an underscore
            }
            return false;
        }
        return true;

    case KC_BSPC:
        {
        static bool delkey_registered;
        if (record->event.pressed) {
            if (mod_state & MOD_MASK_SHIFT) {
                // In case only one shift is held
                // see https://stackoverflow.com/questions/1596668/logical-xor-operator-in-c
                // This also means that in case of holding both shifts and pressing KC_BSPC,
                // Shift+Delete is sent (useful in Firefox) since the shift modifiers aren't deleted.
                if (!(mod_state & MOD_BIT(KC_LEFT_SHIFT)) != !(mod_state & MOD_BIT(KC_RIGHT_SHIFT))) {
                    del_mods(MOD_MASK_SHIFT);
                }
                register_code(KC_DEL);
                delkey_registered = true;
                set_mods(mod_state);
                return false;
            }
        } else {
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        return true;
    }

     case A_GRAVE:
         if (record->event.pressed) {
             del_mods(MOD_MASK_SHIFT);
             del_oneshot_mods(MOD_MASK_SHIFT);
             tap_code_delay(KC_GRV, 30);
             set_mods(mod_state);
             set_oneshot_mods(oneshot_mod_state);
             tap_code_delay(KC_A, 30);
         }
         return false;

     case E_GRAVE:
         if (record->event.pressed) {
             del_mods(MOD_MASK_SHIFT);
             del_oneshot_mods(MOD_MASK_SHIFT);
             tap_code_delay(KC_GRV, 30);
             set_mods(mod_state);
             set_oneshot_mods(oneshot_mod_state);
             tap_code_delay(KC_E, 30);
         }
         return false;

    case ARROW_R:
      if (record->event.pressed) {
          if (mod_state & MOD_MASK_SHIFT || oneshot_mod_state & MOD_MASK_SHIFT) {
            del_mods(MOD_MASK_SHIFT);
            del_oneshot_mods(MOD_MASK_SHIFT);
            SEND_STRING("=>");
            set_mods(mod_state);
          } else {
            SEND_STRING("->");
          }
      }
      break;

    case G_DOWN:
        if (record->event.pressed) {
            register_code(KC_G);
            register_code(KC_J);
        } else {
            unregister_code(KC_G);
            unregister_code(KC_J);
        }
      break;

    case G_UP:
        if (record->event.pressed) {
            register_code(KC_G);
            register_code(KC_K);
        } else {
            unregister_code(KC_G);
            unregister_code(KC_K);
        }
      break;

    case G_HOME:
        if (record->event.pressed) {
            register_code(KC_G);
            register_code(KC_0);
        } else {
            unregister_code(KC_G);
            unregister_code(KC_0);
        }
      break;

    case G_END:
        if (record->event.pressed) {
            register_code(KC_G);
            register_code16(KC_DLR);
        } else {
            unregister_code(KC_G);
            unregister_code16(KC_DLR);
        }
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
      break;

    case UPDIR:
      if (record->event.pressed) {
          tap_code(KC_DOT);
          tap_code(KC_DOT);
          tap_code(KC_SLSH);
          return false;
      }
      break;

    case O_BRACE:
      if (record->event.pressed) {
          tap_code16(KC_LEFT_CURLY_BRACE);
          tap_code(KC_ENTER);
          return false;
      }
      break;

    case C_BRACE:
      if (record->event.pressed) {
          tap_code16(KC_RIGHT_CURLY_BRACE);
          tap_code(KC_ENTER);
          return false;
      }
      break;

    case O_BRQOT:
        if (record->event.pressed) {
            tap_code(KC_LEFT_BRACKET);
            tap_code16(KC_DOUBLE_QUOTE);
        }
        return false;

    case C_BRQOT:
        if (record->event.pressed) {
            tap_code16(KC_DOUBLE_QUOTE);
            tap_code(KC_RIGHT_BRACKET);
        }
        return false;

    case COUTLN:
        if (record->event.pressed) {
            SEND_STRING_DELAY("std::cout <<  << \"\\n\";", 10);
            for (int i = 0; i < 9; ++i)  {
                tap_code(KC_LEFT);
            }
        }
        return false;

    case QK_VERS:
        if (record->event.pressed) {
            SEND_STRING_DELAY(
                    QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION "(" QMK_GIT_HASH ")" \
                    ", Built on: " QMK_BUILDDATE,
                    0);
        }
        return false;


    // tmux window navigation
    case B_CREAT:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code(KC_C);
        }
        return false;

    case B_PREV:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code(KC_P);
        }
        return false;

    case B_NEXT:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code(KC_N);
        }
        return false;

    // tmux pane navigation
    case B_VERT:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code16(KC_PERCENT);
        }
        return false;

    case B_HORIZ:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code16(KC_DOUBLE_QUOTE);
        }
        return false;
    case B_UP:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code(KC_UP);
        }
        return false;

    case B_LEFT:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code(KC_LEFT);
        }
        return false;

    case B_DOWN:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code(KC_DOWN);
        }
        return false;

    case B_RIGHT:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code(KC_RIGHT);
        }
        return false;

    // tmux copy mode and paste buffer
    case B_PASTE:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code(KC_RIGHT_BRACKET);
        }
        return false;

    case B_CPY_M:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code(KC_LEFT_BRACKET);
        }
        return false;

    // tmux zoom
    case B_ZOOM:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code(KC_Z);
        }
        return false;

    // tmux clone pane
    case B_CLOSE:
        if (record->event.pressed) {
            tap_code16(TMUX_PREFIX_KEY);
            tap_code(KC_X);
        }
        return false;

    // Set a separate keycode for dead circumflex
    case DED_CIR:
        if (record->event.pressed) {
            register_code16(KC_CIRCUMFLEX);
        } else {
            register_code16(KC_CIRCUMFLEX);
        }
        return true;

    }
    return true;
};

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
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
            return true;
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

/// Tap Dances ///
#ifdef TAP_DANCE_ENABLE
static void sentence_end(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {

        // Double tapping TD_DOT produces
        // ". <one-shot-shift>" i.e. dot, space and capitalize next letter.
        // This helps to quickly end a sentence and begin another one
        // without having to hit shift.
        case 2:
            /* Check that Shift is inactive */
            if (!(get_mods() & MOD_MASK_SHIFT)) {
                tap_code(KC_SPC);
                /* Internal code of OSM(MOD_LSFT) */
                add_oneshot_mods(MOD_BIT(KC_LEFT_SHIFT));

            } else {
                // send ">" (KC_DOT + shift → ">")
                tap_code(KC_DOT);
            }
            break;

        // Since `sentence_end` is called on each tap
        // and not at the end of the tapping term,
        // the third tap needs to cancel the effects
        // of the double tap in order to get the expected
        // three dots ellipsis.
        case 3:
            // remove the added space of the double tap case
            tap_code(KC_BSPC);
            // replace the space with a second dot
            tap_code(KC_DOT);
            // tap the third dot
            tap_code(KC_DOT);
            break;

        // send KC_DOT on every normal tap of TD_DOT
        default:
            tap_code(KC_DOT);
    }
};

void sentence_end_finished (tap_dance_state_t *state, void *user_data) {
    last_keycode = KC_DOT;
}

tap_dance_action_t tap_dance_actions[] = {
    [DOT_TD] = ACTION_TAP_DANCE_FN_ADVANCED(sentence_end, NULL, NULL),
};
#endif

#ifdef KEY_OVERRIDE_ENABLE
const key_override_t colon_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLON, KC_SEMICOLON);

const key_override_t *key_overrides[] = {
    &colon_key_override
};
#endif
