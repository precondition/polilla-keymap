/* Colemak DHm with home row mods and hybrid steno
 * for the Polilla Keyboard */

#include QMK_KEYBOARD_H

#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

#ifdef STENO_ENABLE
#include "keymap_steno.h"
#endif
#include "keymap_japanese.h"

// All custom keycodes and aliases can be found in keymap.h
#include "keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK_DH] = LAYOUT(
           UNDO, REDO  , KC_GRV,KC_DQUO,KC_F4 , KC_F5 ,                 DED_UML,DED_CIR,E_GRAVE,E_ACUTE, KC_F10, KC_F11,
        A_GRAVE, KC_Q  , KC_W  , KC_F  , KC_P  , KC_B  ,                 KC_J   , KC_L  , KC_U  , KC_Y  ,KC_SCLN,KC_MINS,
         KC_ESC, HOME_A, HOME_R, HOME_S, HOME_T, KC_G  ,                 KC_M   , HOME_N, HOME_E, HOME_I, HOME_O,KC_QUOT,
           KC_Z, REPEAT, KC_X  , KC_C  , KC_D  , KC_V  ,TG_MIC,  COMPOSE,KC_K   , KC_H  ,KC_COMM, TD_DOT,KC_SLSH,ARROW_R,

                         GAMING,C_CDILA,NAV_TAB, KC_SPC,OS_LSFT, OS_RSFT,KC_BSPC,SYM_ENT,KC_RALT, JP_KANA
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
        _______,_______,KC_NUM,KC_SCRL,KC_INS ,_______,                 _______,KC_PGUP, KC_UP ,KC_PGDN,_______,KC_MUTE,
        MS_CAPS,KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,  GNAV ,                 KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END ,KC_VOLU,
        _______, YICODE,C(KC_A),C(KC_C),C(KC_V),_______,_______, KC_BRIU,_______,KC_PSCR,KC_LCBR,KC_RCBR,KC_INS ,KC_VOLD,

                        _______,_______,_______,_______,_______, KC_BRID,_______,_______,_______,_______
  ),

    [_GNAV] = LAYOUT(
        _______,_______,_______,_______,_______,_______,                 _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                 _______,_______, G_UP  ,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                 G_HOME ,_______, G_DOWN,_______, G_END ,_______,
        _______,_______,_______,_______,_______,_______,_______, _______,_______,_______,_______,_______,_______,_______,

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
        _______,_______,_______,_______,_______,_______,_______, _______,_______,KC_BTN3,KC_WH_U,KC_WH_D,_______,_______,

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

// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF

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
            keycode = GET_TAP_KC(keycode);
            break;
        default:
            break;
    }

    switch (keycode) {
        // Keycodes to shift
        case KC_A ... KC_Z:
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
static uint8_t last_modifier = 0;
static void process_repeat_key(uint16_t keycode, const keyrecord_t *record) {
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
            last_modifier = get_oneshot_mods() > get_mods() ? get_oneshot_mods() : get_mods();
        }
        switch (keycode) {
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
                if (record->event.pressed) {
                    last_keycode = GET_TAP_KC(keycode);
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


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("0x%04X,%u,%u,%u,%b,0x%02X,0x%02X,%u\n",
         keycode,
         record->event.key.row,
         record->event.key.col,
         get_highest_layer(layer_state),
         record->event.pressed,
         get_mods(),
         get_oneshot_mods(),
         record->tap.count
         );
#endif
    process_caps_word(keycode, record);
    process_repeat_key(keycode, record);

    uint8_t mod_state = get_mods();
    uint8_t oneshot_mod_state = get_oneshot_mods();
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
             tap_code16(ALGR(KC_GRV));
             set_mods(mod_state);
             set_oneshot_mods(oneshot_mod_state);
             tap_code(KC_A);
         }
         return false;

     case E_GRAVE:
         if (record->event.pressed) {
             del_mods(MOD_MASK_SHIFT);
             del_oneshot_mods(MOD_MASK_SHIFT);
             tap_code16(ALGR(KC_GRV));
             set_mods(mod_state);
             set_oneshot_mods(oneshot_mod_state);
             tap_code(KC_E);
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

    case YICODE:
      if (record->event.pressed) {
          SEND_STRING("$yi{");
          return false;
      }
      break;

    case OS_LSFT:
      if (record->event.pressed && record->tap.count == 0 && (oneshot_mod_state & MOD_BIT(KC_RSFT))) {
        del_oneshot_mods(MOD_BIT(KC_RSFT));
      }
      return true;

    case OS_RSFT:
      if (record->event.pressed && record->tap.count == 0 && (oneshot_mod_state & MOD_BIT(KC_LSFT))) {
        del_oneshot_mods(MOD_BIT(KC_LSFT));
      }
      return true;

    case C_CDILA:
    if (record->event.pressed && record->tap.count > 0) {
        tap_code16(ALGR(KC_COMMA));
        return false;
    }
    return true;

    }
    return true;

};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NAV_TAB:
        case HOME_R:
            return false;
        default:
            return true;
    }
}

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
