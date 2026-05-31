/* Colemak DHm with home row mods and hybrid steno
 * for the Polilla Keyboard */

#include QMK_KEYBOARD_H

#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

#include "keymap_japanese.h"

#include "version.h" // For QK_VERS

// All custom keycodes and aliases can be found in precondition_keymap.h
#include "precondition_keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK_DH] = LAYOUT(
           UNDO, REDO  ,DED_CIR, BNAV  , KC_F4 , KC_F5 ,                 DED_UML, KC_GRV,E_GRAVE,E_ACUTE, KC_F10, KC_F11,
        A_GRAVE, KC_Q  , KC_W  , KC_F  , KC_P  , KC_B  ,                 KC_J   , KC_L  , KC_U  , KC_Y  ,KC_COLN,KC_MINS,
         KC_ESC, HOME_A, HOME_R, HOME_S, HOME_T, KC_G  ,                 KC_M   , HOME_N, HOME_E, HOME_I, HOME_O,KC_QUOT,
           KC_Z, REPEAT, KC_X  , KC_C  , KC_D  , KC_V  ,MS_BTN1, COMPOSE,KC_K   , KC_H  ,KC_COMM, TD_DOT,KC_SLSH,ARROW_R,

                       BDED_TOG,C_CDILA,NAV_TAB, KC_SPC,OS_LSFT, OS_RSFT,KC_BSPC,SYM_ENT,KC_RALT,JALO
  ),

  [_JALO] = LAYOUT(
        _______,_______,_______,_______,_______,_______,                 _______,_______,_______,_______,_______,_______,
        KC_Q   , KC_X  , KC_L  , KC_C  , KC_P  , KC_K  ,                 KC_M   , KC_F  , KC_U  ,  KC_O ,  KC_Y ,KC_MINS,
        QK_REP ,HOME2_R,HOME2_N,HOME2_S,HOME2_T, KC_B  ,                 KC_H   ,HOMERET,OS_RSFT,HOME2_A,HOME2_I, KC_DOT,
        KC_J   , KC_ESC,NAV_TAB, KC_G  , KC_D  , KC_V  ,_______, _______,KC_QUOT,KC_BSPC, KC_W  ,KC_SLSH,KC_COLN, KC_Z  ,

                        _______,_______,OSL(_NAV), KC_SPC,LT(_ALTTABCP, MAGIC_L), MAGIC_R,HOME2_E,OSL(_SYM2),_______,_______
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
        KC_X   , KC_4  , KC_2  , KC_3  , KC_1  , KC_5  ,                 KC_6   , KC_0  , KC_8  , KC_9  , KC_7  ,KC_MINS,
        KC_LABK,O_BRQOT,KC_LBRC,KC_RBRC,C_BRQOT,KC_RABK,                 O_BRACE,KC_LCBR,KC_LPRN,KC_RPRN,KC_RCBR,C_BRACE,
        KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC, PLOVER, _______,KC_CIRC,KC_AMPR,KC_ASTR,KC_EQL ,KC_PLUS,A_GRAVE,

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
        MS_CAPS,KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,  GNAV ,                 KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END ,KC_VOLU,
        QK_LOCK,_______,C(KC_A),C(KC_C),C(KC_V),_______,_______, KC_BRIU,_______,KC_PSCR,KC_LCBR,KC_RCBR,KC_INS ,KC_VOLD,

                         GAMING,_______,_______,_______,_______, KC_BRID,_______,_______,_______,_______
  ),

    [_NAV2] = LAYOUT(
        _______,_______,_______,_______,_______,_______,                 _______,_______,_______,_______,_______,_______,
        KC_X   , KC_4  , KC_2  , KC_3  , KC_1  , KC_5  ,                 KC_6   , KC_0  , KC_8  , KC_9  , KC_7  ,KC_MINS,
        _______,OS_LGUI,OS_LALT,OS_LSFT,OS_LCTL,_______,                 KC_LEFT,KC_DOWN, KC_UP ,KC_RGHT,KC_HOME, KC_END,
        _______,DOWN4  ,  DOWN2, DOWN3 , DOWN1 , DOWN5 ,_______, _______,  UP5  , UP1   ,  UP3  ,  UP2  ,  UP4  ,_______,

                        _______,_______,_______,_______,_______, TG(_NAV2) ,_______,_______,_______,_______
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

                        _______,_______,_______,KC_SPACE,XXXXXXX, NUM_OV ,_______,_______,_______,_______
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

    [_ALTTABCP] = LAYOUT(
        _______,_______,_______,_______,_______,_______,                 _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                 _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                 _______,_______,_______,_______,_______,_______,
        _______,OS_LALT,KC_TAB ,C(KC_C),S(KC_INS),C(KC_V),_______, _______,_______,_______,_______,_______,_______,_______,

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
        _______,_______,_______,_______,_______,_______,                 _______,KC_WBAK,  MS_UP,KC_WFWD,_______,_______,
        _______,KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,_______,                 _______,MS_LEFT,MS_DOWN,MS_RGHT,_______,_______,
        _______,_______,_______,_______,_______,QK_VERS,_______, _______,_______,MS_BTN3,MS_WHLU,MS_WHLD,_______,_______,

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
        case MAGIC_L:
        case LT(_ALTTABCP, MAGIC_L):
        case LT(_ALTTABCP, MAGIC_L) & 0xFF:
        case MAGIC_R:
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
        case KC_1 ... KC_0:
        case SYM:
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

static uint8_t last_oneshot_mods = 0;
static uint16_t last_keycode = KC_NO;
static uint16_t penultimate_keycode = KC_NO;
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

            if (base_dead_keys) {
                switch (last_keycode) {
                    case KC_QUOTE:
                    case KC_DOUBLE_QUOTE:
                    case KC_TILDE:
                    case KC_GRAVE:
                    case KC_CIRCUMFLEX:
                        tap_code(KC_SPACE);
                }
            }

        } else {
            unregister_code16(last_keycode);
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
            if (last_keycode == O_BRQOT) {
                in_smart_square_brackets -= 1;
            }
            break;

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
        if (oneshot_mod_state & MOD_MASK_SHIFT || (get_repeat_key_count() > 0)) {
            if (record->event.pressed) {
                //tap_code(KC_MINS); // The one-shot shift will convert it to an underscore
                tap_code16(KC_UNDS); // Needed for proper QK_REP support.
            }
            retv = false;
            break;
        }
        retv = true;
        break;

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
                retv = false;
                break;
            }
        } else {
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                retv = false;
                break;
            }
        }
        retv = true;
        break;
    }

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
            SEND_STRING("=>");
            set_mods(mod_state);
          } else {
            SEND_STRING("->");
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
            if (base_dead_keys) {
                // The double quotes will consume the space next to them.
                SEND_STRING_DELAY("std::cout <<  << \" \\n\" ;", KEY_SEQ_DELAY);
            } else {
                SEND_STRING_DELAY("std::cout <<  << \"\\n\";", KEY_SEQ_DELAY);
            }
            for (int i = 0; i < 9; ++i)  {
                tap_code(KC_LEFT);
            }
        }
        retv = false;
        break;

    case QK_VERS:
        if (record->event.pressed) {
            SEND_STRING(
                    QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION "(" QMK_GIT_HASH ")" \
                    ", Built on: " QMK_BUILDDATE
                    );
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

    case KC_X:
        if (IS_LAYER_ON(_JALO) && record->event.pressed) {
            if (last_keycode == KC_L) {
                tap_code(KC_L);
                retv = false;
            }
            break;
        }
        retv = true;
        break;

    case MAGIC_L:
        if (record->event.pressed) {
            if (get_repeat_key_count() > 0) {
                tap_code(last_summoned_keycode);
            } else {
                // get_last_keycode() cannot be used here because at this
                // point, get_last_keycode already points to MAGIC_L so we lost
                // the info.
                process_magic_key_left(last_keycode, penultimate_keycode);
            }
        }
        retv = false;
        break;

    case LT(_ALTTABCP, MAGIC_L):
        if (record->event.pressed && record->tap.count > 0) {
            if (get_repeat_key_count() > 0) {
                tap_code(last_summoned_keycode);
            } else {
                // get_last_keycode() cannot be used here because at this
                // point, get_last_keycode already points to MAGIC_L so we lost
                // the info.
                process_magic_key_left(last_keycode, penultimate_keycode);
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
                process_magic_key_right(last_keycode, penultimate_keycode);
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

#ifdef REPEAT_KEY_ENABLE
    case KC_O:
    case KC_U:
    case HOME2_E:
    case HOME2_A:
    case HOME2_I:
        // Bypass the "l_n" skipgram by pressing it as "l_↻".
        // "lin", "lan", "lon", etc. are way more frequent than "lii", "laa",
        // "loo", ...
        // Another related problem is the "ll_n" skipgram. The L's are repeated
        // so they are naturally typed as KC_L QK_REP but this means that once
        // we reach the point at which we need to type "n", the
        // penultimate_keycode is QK_REP (resolved as "l"), not KC_L.
        // Two options are available:
        //  1. KC_L QK_REP _ KC_N → left ring finger skip-2-gram l__n
        //  2. KC_L QK_REP _ QK_REP → left pinky finger same key skipgram ↻_↻
        //  Ideally, we would need to check if the antepenultimate keycode is
        //  KC_L but that means adding yet another variable in SRAM...
        if (get_repeat_key_count() > 0) {
            if (record->event.pressed && (penultimate_keycode == KC_L || penultimate_keycode == QK_REP)) {
                register_code(KC_N);
                retv = false;
            } else {
                unregister_code(KC_N);
                retv = true;
            }
            break;
        }
#endif
        retv = true;
        break;

    }

#ifdef REPEAT_KEY_ENABLE
    if (record->event.pressed) {
        penultimate_keycode = last_keycode;
        if (get_repeat_key_count() < 1) {
            last_keycode = get_last_keycode();
        } else {
            last_keycode = QK_REP;
        }
    }
#else
    process_repeat_key(keycode, record);
#endif
    last_oneshot_mods = oneshot_mod_state;

    return retv;
};

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
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
            return keycode != LT(_ALTTABCP, MAGIC_L);
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

#ifdef TAP_DANCE_ENABLE
static void sentence_end(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {

        // Double tapping TD_DOT produces
        // ". <one-shot shift>" i.e. dot, space and capitalize next letter.
        // This helps to quickly end a sentence and begin another one
        // without having to hit shift.
        case 2:
            tap_code(KC_SPC);
            // Calling one shot shift here produces unreliable results. More
            // reliable results are achieved by calling one shot shift in
            // sentence_end.
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
    if (state->count == 2) {
        /* Internal code of OSM(MOD_LSFT) */
        add_oneshot_mods(MOD_BIT(KC_LEFT_SHIFT));
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [DOT_TD] = ACTION_TAP_DANCE_FN_ADVANCED(sentence_end, sentence_end_finished, NULL),
};
#endif

#ifdef KEY_OVERRIDE_ENABLE
const key_override_t colon_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLON, KC_SEMICOLON);
const key_override_t slash_key_override = ko_make_basic(MOD_BIT(KC_LALT), KC_SLASH, KC_BACKSLASH);
const key_override_t lt_slash_key_override = ko_make_basic(MOD_BIT(KC_LALT), SYM_SLSH, KC_BACKSLASH);
const key_override_t quote_key_override = ko_make_basic(MOD_BIT(KC_LALT), KC_QUOTE, KC_GRAVE);
//const key_override_t minus_key_override = ko_make_with_layers_and_negmods(
//        MOD_MASK_SHIFT, KC_MINS, KC_EQUAL, ~0, ~MOD_MASK_SHIFT);
const key_override_t dot_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_COMMA, 1 << _JALO);

const key_override_t *key_overrides[] = {
    &colon_key_override,
    &slash_key_override,
    &lt_slash_key_override,
    &quote_key_override,
    //&minus_key_override
    &dot_key_override,
};
#endif
