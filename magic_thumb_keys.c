#include QMK_KEYBOARD_H
#include "precondition_keymap.h"

/* Magic rules version 1.0 */

/*
 * Percentages are given relative to ngram class in a corpus composed of my
 * keylogs, and shell commands:
 * "1" (frequency percentage among all unigrams/monograms)
 * "12" (frequency percentage among all bigrams),
 * "123" (frequency percentage among all trigrams),
 * "1_3" (frequency percentage of "1" <something> "3" among all skip-1-grams)
 * etc.
 */

void process_magic_key_left(uint16_t prev_keycode) {
    switch (prev_keycode) {

        case KC_A:
        case HOME2_A:
            // rationale: avoid SFS.
            // ngram: "dat" (0.07028%), "tad" (0.00412%)
            // examples: "data", "date", "update", "stade"
            tap_code(KC_T);
            last_summoned_keycode = KC_T;
            break;

        case KC_B:
            // rationale: avoid SFB.
            // ngram: "bd" (0.01193%)
            // examples: ":bd" (buffer delete), "lambda", "kbd"
            tap_code(KC_D);
            last_summoned_keycode = KC_D;
            break;

        case KC_C:
            // rationale: avoid SFS.
            // ngram: "oca" (0.01074%)
            // examples: "local", "vocal", "vocab", "allocates"
            /*
             * "oca" typically occurs in the middle of a word so it is unlikely
             * to cause a left thumb space SFB → good fit for MAGIC_L.
             */
            tap_code(KC_A);
            last_summoned_keycode = KC_A;
            break;

        case KC_G:
            // rationale: reduce typing.
            // ngram: "git␣" (0.30964%)
            // examples: "git s", "git add", "git commit"
            tap_code(KC_I);
            tap_code(KC_T);
            tap_code(KC_SPACE);
            last_summoned_keycode = KC_SPACE;
            break;

        case KC_N:
        case HOME2_N:
            // rationale: avoid SFB.
            // ngram: "nl" (0.02438%)
            // examples: "only", "unless", "enlever", "download"
            /*
             * "download" is a very interesting word because half of the
             * letters can be typed with magic keys:
             * KC_D, KC_O, MAGIC_R (w), KC_N, MAGIC_L (l), KC_O, MAGIC_R (a), KC_D
             */
            tap_code(KC_L);
            last_summoned_keycode = KC_L;
            break;

        case KC_O:
            // rationale: avoid SFB.
            // ngram: "oa" (0.05211%)
            // examples: "keyboard", "woah", "approach"
            tap_code(KC_A);
            last_summoned_keycode = KC_A;
            break;

        case KC_P:
            // rationale: avoid SFB.
            // ngram: "pt" (0.06302%)
            // examples: "compte",  "option",  "script",  "ptet",  "except"
            tap_code(KC_T);
            last_summoned_keycode = KC_T;
            break;

        case KC_R:
        case HOME2_R:
            // rationale: avoid SFB and SKB.
            // ngram: "rr" (0.09392%)
            // examples: "bizarre", "correct", "erreur", "array"
            tap_code(KC_R);
            last_summoned_keycode = KC_R;
            break;

        case KC_S:
        case HOME2_S:
            // rationale: avoid SFB.
            // ngram: "sc" (0.08298%)
            // examples: "Discord", "script", "screen", "scroll"
            tap_code(KC_C);
            last_summoned_keycode = KC_C;
            break;

        case KC_T:
        case HOME2_T:
            // rationale: avoid SFS.
            // ngram: "ted" (0.04675%)
            // examples: "expected", "dedicated", "accented"
            tap_code(KC_E);
            tap_code(KC_D);
            tap_code(KC_SPACE);
            last_summoned_keycode = KC_SPACE;
            break;

        case KC_W:
            // rationale: avoid lateral stretch.
            // ngram: "wh" (0.07922%)
            // examples: "what", "when", "which", "why", "where"
            tap_code(KC_H);
            last_summoned_keycode = KC_H;
            break;

        case KC_QUOTE:
            // rationale: avoid SFB.
            // ngram: "'m␣" (0.01094%)
            // examples: "I'm not",  "I'm still",  "I'm trying"
            tap_code(KC_M);
            tap_code(KC_SPACE);
            last_summoned_keycode = KC_SPACE;
            break;

        case KC_MINUS:
            // rationale: avoid SFS.
            // ngram: "<-" (0.00080%)
            // examples: "<-",  "<--", "ANSI<->ISO"
            /*
             * I bet the frequency of "<-" goes way up for R programmers but I
             * am not one.
             */
            tap_code(KC_BACKSPACE);
            tap_code16(KC_LT);
            tap_code16(KC_MINUS);
            last_summoned_keycode = KC_MINUS;
            break;

        default:
            // Report the unsupported leading key by typing out its key code in
            // decimal format.
            const char *prev_keycode_str = get_u16_str(prev_keycode, ' ');
            // Skip padding spaces
            while (*prev_keycode_str == ' ') {
                prev_keycode_str++;
            }
            send_string(prev_keycode_str);
            tap_code16(KC_QUESTION);
            last_summoned_keycode = KC_QUESTION;
            break;
    }
}


void process_magic_key_right(uint16_t prev_keycode) {
    switch (prev_keycode) {

        case KC_C:
            // rationale: avoid SFB.
            // ngram: "cs" (0.03134%)
            // examples: "trucs", "docs", "csv", "css", "ergonomics"
            tap_code(KC_S);
            last_summoned_keycode = KC_S;
            break;

        case KC_G:
            // rationale: avoid SFB.
            // ngram: "gs" (0.01907%)
            // examples: "settings", "things", "strings", "mappings"
            tap_code(KC_S);
            last_summoned_keycode = KC_S;
            break;

        case KC_O:
            // rationale: avoid SFB.
            // ngram: "ow" (0.10844%)
            // examples: "how",  "know",  "down",  "now",  "Windows"
            tap_code(KC_W);
            last_summoned_keycode = KC_W;
            break;

        case KC_R:
        case HOME2_R:
            // rationale: avoid SFS.
            // ngram: "ree" (0.02534%)
            // examples: "free",  "screen",  "three",  "freeze"
            /*
             * The most frequent letter preceding "ee" is R but various
             * constraints and design choices led R to occupy the same finger
             * as ↻. This magic rules fixes the deficiency.
             */
            tap_code(KC_E);
            tap_code(KC_E);
            last_summoned_keycode = KC_E;
            break;

        case KC_S:
        case HOME2_S:
            // rationale: avoid SFB.
            // ngram: "sg" (0.00539%)
            // examples: "msg", "disgusted",  "disguised"
            tap_code(KC_G);
            last_summoned_keycode = KC_G;
            break;


        case KC_Y:
            // rationale: avoid SFB.
            // ngram: "ying"
            // examples: "annoying",  "saying",  "buying"
            /*
             * "yi" is almost always followed by "ng" ("ying" makes up 0.68375%
             * of all tetragrams starting with "yi"). Exceptions include
             * "yikes" (0.04580%), "yield" (0.02181%) and "yank inner" Vim
             * commands (0.24863%) like "yiw".
             */
            tap_code(KC_I);
            tap_code(KC_N);
            tap_code(KC_G);
            last_summoned_keycode = KC_G;
            break;

        /*
        case KC_SPACE:
            // rationale: typing reduction.
            // ngram: "␣the␣" (0.28211%)
            // examples: "at the end", "on the right", "of the keyboard", "in the same"
            tap_code(KC_T);
            tap_code(KC_H);
            tap_code(KC_E);
            tap_code(KC_SPACE);
            last_summoned_keycode = KC_SPACE;
            break;
        */

        case KC_SPACE:
            // rationale: typing reduction.
            // ngram: "␣the" (0.27805%)
            // examples: "in the", "of the", "with the",  "and then"
            tap_code(KC_T);
            tap_code(KC_H);
            tap_code(KC_E);
            last_summoned_keycode = KC_E;
            break;

        case KC_MINUS:
            // rationale: avoid SFS.
            // ngram: "->" (0.00541%)
            // examples: "record->event.pressed",  "def f(x: int) -> int:"
            tap_code16(KC_GT);
            last_summoned_keycode = KC_GT;
            break;


        case MAGIC_L:
            // rationale: avoid SFB.
            // ngram: "_<MAGIC_L>␣", "__<MAGIC_L>␣"
            /*
             * the main reason why there may seem to be more magic rules on the
             * right hand is that MAGIC_R does not cause SFBs with KC_SPACE
             * whereas MAGIC_L has a nasty tendency to trade a non-thumb SFB or
             * SFS by a left thumb SFB or SFS if the sequence ends with a space
             * (almost) directly after. This magic rule helps to at least
             * alleviate the "<MAGIC_L>␣" SFB. The "<MAGIC_L>_␣" SFS cannot be
             * bypassed though.
             */
            tap_code(KC_SPACE);
            last_summoned_keycode = KC_SPACE;
            break;

    }
}
