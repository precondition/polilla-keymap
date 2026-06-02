#pragma once

#include QMK_KEYBOARD_H

enum layer_names {
    _COLEMAK_DH,
    _GAMING,
    _JALO,
    _SYM,
    _SYM2,
    _NAV,
    _NAV2,
    _NAV_OVER,
    _NUM_OVER,
    _GNAV_OVER,
    _OSMS_OVER,
    _ALTTABCP,
    _GNAV,
    _BNAV,
#ifdef MOUSEKEY_ENABLE
    _MOUSE,
#endif
#ifdef STENO_ENABLE
    _PLOVER,
#endif
};

// Layer keys
#define NAV MO(_NAV)
#define NUM_OV MO(_NUM_OVER)
#define NAV_TAB LT(_NAV, KC_TAB)
#define GNAV MO(_GNAV)
#define GNAV_OV OSL(_GNAV_OVER)
#define SYM OSL(_SYM2)
#define SYM_ENT LT(_SYM, KC_ENT)
#define GAMING TG(_GAMING)
#define BNAV OSL(_BNAV)
#define JALO TG(_JALO)
#define SYM_COLN LT(_SYM, KC_SCLN)
#define SYM_SLSH LT(_SYM, KC_SLASH)

#ifdef MOUSEKEY_ENABLE
#    define MOUSE MO(_MOUSE)
#    define MS_CAPS LT(_MOUSE, KC_CAPS)
#else
#    define MOUSE KC_TRNS
#    define MS_CAPS KC_CAPS
#endif

#ifdef STENO_ENABLE
#    define PLOVER TG(_PLOVER)
#else
#    define PLOVER KC_TRNS
#endif


// Miscellaneous keyboard shortcuts in direct access
#define UNDO LCTL(KC_Z)
#define REDO LCTL(KC_Y)
#define COMPOSE KC_APP
#define TG_MIC KC_F20 // Default binding for XF86AudioMicMute

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)
#define HOME2_R LGUI_T(KC_R)
#define HOME2_N LALT_T(KC_N)
#define HOME2_S LSFT_T(KC_S)
#define HOME2_T LCTL_T(KC_T)

// Right-hand home row mods
#define HOME_O RGUI_T(KC_O)
#define HOME_I LALT_T(KC_I)
#define HOME_E RSFT_T(KC_E)
#define HOME_N RCTL_T(KC_N)
#define HOME2_H RCTL_T(KC_H)
#define HOMERET RCTL_T(KC_ENTER)
#define HOME2_E RSFT_T(KC_E)
#define HOME2_A LALT_T(KC_A)
#define HOME2_I RGUI_T(KC_I)

// French accents
// The other common grave accented letters are custom keycodes
// And the rest of other accented letters are accessed using dead keys
#define E_ACUTE ALGR(KC_E)
#define C_CDILA ALGR(KC_COMMA)

#define TMUX_PREFIX_KEY C(KC_B)

// The tap keycode will get entirely overridden by process_magic_left.
#define MAGIC_L LT(_ALTTABCP, KC_COPY)

enum custom_keycodes {
    ARROW_R = SAFE_RANGE,
    // g navigation to move through screen lines in Vim
    G_DOWN,
    G_UP,
    G_HOME,
    G_END,
    // « French quotation marks »
    GUILL_R,
    GUILL_L,
    // Macro to refer to the parent directory in Linux ../
    UPDIR,
    // French grave accented letters
    E_GRAVE,
    A_GRAVE,
    // Macro for
    // std::cout << | << "\n";
    // (with | representing the cursor position)
    COUTLN,
    REPEAT,
    // "Opening brace"
    // Macro for
    // {<enter>
    O_BRACE,
    // "Closing brace"
    // Macro for
    // }<enter>
    C_BRACE,
    CAPS_WORD_LOCK,
    // "Opening Bracket-Quote"
    // Macro for
    // ["
    O_BRQOT,
    // "Closing Bracket-Quote"
    // Macro for
    // "]
    C_BRQOT,
    // "QMK Version"
    // Prints the keyboard name, QMK version and build date
    QK_VERS,
    // tmux window navigation
    B_CREAT,
    B_PREV,
    B_NEXT,
    // tmux pane navigation
    B_VERT,
    B_HORIZ,
    B_UP,
    B_LEFT,
    B_DOWN,
    B_RIGHT,
    // tmux copy mode and paste buffer
    B_PASTE,
    B_CPY_M,
    // tmux zoom
    B_ZOOM,
    // tmux close pane
    B_CLOSE,
    // Useful dead keys for French
    //  Dead circumflex
    //  The same as KC_CIRCUMFLEX on US intl but setting it as a separate
    //  keycode helps to exclude it from `post_process_record_user`.
    DED_CIR,
    //  Dead Umlaut
    //  The same as KC_DOUBLE_QUOTE on US intl but setting it as a separate
    //  keycode helps to exclude it from `post_process_record_user`.
    DED_UML,
    // Toggle `base_dead_keys` dynamically at run time.
    BDED_TOG,
    // Right magic key.
    MAGIC_R,
    // Literally just KC_LALT but without all the special handling that OSL &
    // co. do with modifier keys.
    LALT,
    NAV_OV,
    DOWN1,
    DOWN2,
    DOWN3,
    DOWN4,
    DOWN5,
    UP1,
    UP2,
    UP3,
    UP4,
    UP5,
};


bool caps_word_on;

// summoned by magic.
uint16_t last_summoned_keycode;

void process_magic_key_left(uint16_t prev_keycode, uint16_t prev_prev_keycode);
void process_magic_key_right(uint16_t prev_keycode, uint16_t prev_prev_keycode);

#ifdef REPEAT_KEY_ENABLE
#define REPEAT QK_REP
#endif

bool base_dead_keys;
