#include QMK_KEYBOARD_H
#include "precondition_keymap.h"

/* Magic rules version 1.0 */

/*
 * Percentages are given relative to ngram class in a corpus composed of my
 * keylogs, and shell commands:
 * « 1 » (frequency percentage among all unigrams/monograms)
 * « 12 » (frequency percentage among all bigrams),
 * « 123 » (frequency percentage among all trigrams),
 * « 1_3 » (frequency percentage of « 1 » <something> « 3 » among all skip-1-grams)
 * etc.
 */

void process_magic_key_left(const uint16_t prev_keycodes[]) {
    const uint16_t penultimate_keycode = prev_keycodes[1] == MAGIC_L || prev_keycodes[1] == MAGIC_R ? last_summoned_keycode : prev_keycodes[1];
    switch (prev_keycodes[0]) {

        case KC_A:
        case HOME2_A:
            switch (penultimate_keycode) {
                case KC_C:
                case KC_G:
                    // rationale: avoid SFS.
                    // ngram: « cas » (0.01724%), « gas » (0.00291%)
                    // examples: « case »,  « cas »,  « cassé », « lowercase », « magasin »
                    tap_code(KC_S);
                    last_summoned_keycode = KC_S;
                    break;

                case KC_P:
                case KC_K:
                case KC_T:
                case HOME2_T:
                case KC_B:
                case KC_D:
                case KC_V:
                    // rationale: avoid SFS.
                    // ngram: « dat » (0.07028%), TODO
                    // examples: « data », « date », « update », « stade »
                    tap_code(KC_T);
                    last_summoned_keycode = KC_T;
                    break;

                default:
                    // rationale: avoid SFB.
                    // ngram: « ao » (0.00980%)
                    // examples: « août », « lmao »,  « chaos », « kaomoji »
                    tap_code(KC_O);
                    last_summoned_keycode = KC_O;
                    break;
            }
            break;

        case KC_B:
            // rationale: avoid SFB.
            // ngram: « bd » (0.01193%)
            // examples: « :bd » (buffer delete), « lambda », « kbd »
            tap_code(KC_D);
            last_summoned_keycode = KC_D;
            break;

        case KC_C:
            // rationale: avoid SFB.
            // ngram: « cs » (0.03134%)
            // examples: « trucs », « docs », « csv », « css », « ergonomics »
            tap_code(KC_S);
            last_summoned_keycode = KC_S;
            break;

        case KC_E:
        case HOME2_E:
            // rationale: avoid SFB.
            // ngram: « e<sym> » (0.10403%)
            // examples: TODO
            set_oneshot_layer(_SYM2, ONESHOT_START);
            last_summoned_keycode = OSL(_SYM2);
            break;

        case KC_F:
            // rationale: avoid SFB.
            // ngram: « f" » (TODO%)
            // examples: « f"python interpolated f-string" »
            tap_code16(KC_DOUBLE_QUOTE);
            if (base_dead_keys) {
                tap_code(KC_SPACE);
            }
            last_summoned_keycode = KC_DOUBLE_QUOTE;
            break;

        case KC_G:
            // rationale: reduce typing.
            // ngram: « git␣ » (0.30964%)
            // examples: « git st », « git add », « git commit »
            tap_code(KC_I);
            tap_code(KC_T);
            tap_code(KC_SPACE);
            last_summoned_keycode = KC_SPACE;
            break;

        case KC_I:
        case HOME2_I:
            // rationale: avoid SFB.
            // ngram: « iz » (0.03639%)
            // examples: « size »,  « realize »,  « capitalize »,  « optimized »
            tap_code(KC_Z);
            last_summoned_keycode = KC_Z;
            break;

        case KC_N:
        case HOME2_N:
            // rationale: avoid SFB.
            // ngram: « nl » (0.02438%)
            // examples: « only », « unless », « enlever », « download »
            /*
             * « download » is a very interesting word because half of the
             * letters can be typed with magic keys:
             * KC_D, KC_O, MAGIC_R (w), KC_N, MAGIC_L (l), KC_O, MAGIC_R (a), KC_D
             */
            tap_code(KC_L);
            last_summoned_keycode = KC_L;
            break;

        case KC_O:
            // rationale: avoid SFB.
            // ngram: « oa » (0.05211%)
            // examples: « keyboard », « woah », « approach »
            tap_code(KC_A);
            last_summoned_keycode = KC_A;
            break;

        case KC_P:
            // rationale: avoid SFB.
            // ngram: « pt » (0.06302%)
            // examples: « compte »,  « option »,  « script »,  « ptet »,  « except »
            tap_code(KC_T);
            last_summoned_keycode = KC_T;
            break;

        case KC_Q:
            // rationale: TODO
            // ngram: « q! » (TODO%)
            // examples: « :q!⏎ »
            tap_code16(KC_EXLM);
            last_summoned_keycode = KC_EXLM;
            break;

        case KC_R:
        case HOME2_R:
            // rationale: avoid SFB and SKB.
            // ngram: « rr » (0.09392%)
            // examples: « bizarre », « correct », « erreur », « array »
            tap_code(KC_R);
            last_summoned_keycode = KC_R;
            break;

        case KC_S:
        case HOME2_S:
            // rationale: avoid SFB.
            // ngram: « sc » (0.08298%)
            // examples: « Discord », « script », « screen », « scroll »
            tap_code(KC_C);
            last_summoned_keycode = KC_C;
            break;

        case KC_T:
        case HOME2_T:
            // rationale: avoid SFS.
            // ngram: « ted » (0.04675%)
            // examples: « expected », « dedicated », « accented »
            tap_code(KC_E);
            tap_code(KC_D);
            tap_code(KC_SPACE);
            last_summoned_keycode = KC_SPACE;
            break;

        case KC_V:
            // rationale: avoid SKS.
            // ngram: Ctrl+(Shift+)V⏎
            // examples: TODO
            tap_code(KC_ENTER);
            last_summoned_keycode = KC_ENTER;
            break;

        case KC_W:
            // rationale: avoid lateral stretch.
            // ngram: « wh » (0.07922%)
            // examples: « what », « when », « which », « why », « where »
            tap_code(KC_H);
            last_summoned_keycode = KC_H;
            break;

        case KC_Y:
            // rationale: avoid SFB.
            // ngram: « yi » (TODO%)
            // examples: « annoying␣ »,  « saying␣ »,  « buying␣ »
            /*
             * « yi » is almost always followed by « ng » (« ying » makes up 0.68375%
             * of all tetragrams starting with « yi »). Exceptions include
             * « yikes » (0.04580%), « yield » (0.02181%) and « yank inner » Vim
             * commands (0.24863%) like « yiw ».
             */
            tap_code(KC_I);
            last_summoned_keycode = KC_I;
            break;

        case KC_Z:
            // rationale: avoid SFB.
            // ngram: « zi » (0.00167%)
            // examples: « zip »,  « amazing »,  « fuzzing »,  « magazine », « squeezing »
            /*
             * « izi » as in « realizing » is not applicable because it is
             * typed as KC_I MAGIC_R(z) KC_I.
             */
            tap_code(KC_I);
            last_summoned_keycode = KC_I;
            break;

        case KC_QUOTE:
            // rationale: avoid SFB.
            // ngram: « '⏎ » and « "⏎ » (0.02988%)
            // examples: « git commit -m "msg"⏎ », « vim 'copy\pasted\windows\path'⏎ »
            tap_code16(KC_ENTER);
            last_summoned_keycode = KC_ENTER;
            break;


        case KC_MINUS:
            // rationale: avoid SFS.
            // ngram: « <- » (0.00080%)
            // examples: « <- »,  « <-- », « ANSI<->ISO »
            /*
             * I bet the frequency of « <- » goes way up for R programmers but I
             * am not one.
             */
            tap_code(KC_BACKSPACE);
            tap_code16(KC_LT);
            tap_code16(KC_MINUS);
            last_summoned_keycode = KC_MINUS;
            break;

        case KC_RPRN:
            // rationale: reduce typing.
            // ngram: « ); » (TODO%)
            // examples: TODO
            tap_code(KC_SEMICOLON);
            last_summoned_keycode = KC_SEMICOLON;
            break;

        case KC_LCBR:
            // rationale: avoid SKB.
            // ngram: « {⏎ » (TODO%)
            // examples: TODO
            tap_code(KC_ENTER);
            last_summoned_keycode = KC_ENTER;
            break;

        case KC_COLN:
            // rationale: avoid LSB and SFS.
            // ngram: « :find␣ » (TODO%)
            // examples: TODO
            SEND_STRING("find ");
            last_summoned_keycode = KC_SPACE;
            break;

        case QK_REP:
            // rationale: avoid SFB.
            // ngram: « ↻r » (TODO%)
            // examples: TODO
            tap_code(KC_R);
            last_summoned_keycode = KC_R;
            break;

        case MAGIC_R:
            // rationale: avoid SFB.
            // ngram: « <MAGIC_R>e »
            tap_code(KC_E);
            last_summoned_keycode = KC_E;
            break;

    }
}


void process_magic_key_right(const uint16_t prev_keycodes[]) {
    switch (prev_keycodes[0]) {

        case KC_A:
        case HOME2_A:
            switch (penultimate_keycode) {
                case KC_C:
                case KC_G:
                    // rationale: avoid SFS.
                    // ngram: « cas » (0.01724%), « gas » (0.00291%)
                    // examples: « case »,  « cas »,  « cassé », « lowercase », « magasin »
                    tap_code(KC_S);
                    last_summoned_keycode = KC_S;
                    break;

                case KC_P:
                case KC_K:
                case KC_T:
                case HOME2_T:
                case KC_B:
                case KC_D:
                case KC_V:
                    // rationale: avoid SFS.
                    // ngram: « dat » (0.07028%), TODO
                    // examples: « data », « date », « update », « stade »
                    tap_code(KC_T);
                    last_summoned_keycode = KC_T;
                    break;

                default:
                    // rationale: avoid SFB.
                    // ngram: « ao » (0.00980%)
                    // examples: « août », « lmao »,  « chaos », « kaomoji »
                    tap_code(KC_O);
                    last_summoned_keycode = KC_O;
                    break;
            }
            break;

        case KC_C:
            // rationale: avoid SFS.
            // ngram: « ces » (0.03377%)
            // examples: « ␣ces␣ »,  « access »,  « exercices »,  « process »
            tap_code(KC_E);
            tap_code(KC_S);
            last_summoned_keycode = KC_S;
            break;

        case KC_G:
            // rationale: avoid SFB.
            // ngram: « gs » (0.01907%)
            // examples: « settings », « things », « strings », « mappings »
            if (prev_keycodes[1] == KC_SLASH) {
                // « :%s/re/p/gc »
                tap_code(KC_C);
                last_summoned_keycode = KC_C;
            } else {
                tap_code(KC_S);
                last_summoned_keycode = KC_S;
            }
            break;

        case KC_I:
        case HOME2_I:
            // rationale: avoid SFS.
            // ngram: « ity » (0.05076%)
            // examples: « functionality »,  « ability »,  « community »
            tap_code(KC_T);
            tap_code(KC_Y);
            last_summoned_keycode = KC_Y;
            break;

        case KC_J:
            // rationale: avoid SFS-2.
            // ngram: « jour » (TODO%)
            // examples: « jour », « bonjour », « aujourd'hui », « journey »
            tap_code(KC_O);
            tap_code(KC_U);
            tap_code(KC_R);
            last_summoned_keycode = KC_R;
            break;

        case KC_L:
            // rationale: avoid SFB.
            // ngram: « ln » (TODO%)
            // examples: « println »,  « ln(0) »,  « ulnar »,  « ln -s file symlink »,  « KC_COLN »
            tap_code(KC_N);
            last_summoned_keycode = KC_N;
            break;

        case KC_M:
            // rationale: avoid SFS.
            // ngram: « m␣" » (TODO%)
            // examples: « git commit -m "msg" »
            tap_code(KC_SPACE);
            tap_code16(KC_DOUBLE_QUOTE);
            if (base_dead_keys) {
                tap_code(KC_SPACE);
            }
            last_summoned_keycode = KC_DOUBLE_QUOTE;
            break;

        case KC_N:
        case HOME2_N:
            // rationale: avoid SFS.
            // ngram: « nal » (0.02550%)
            // examples: "final",  "terminal",  "personally",  "original", "national"
            /*
             * Especially important to avoid the double SFS in « onal ».
             */
            tap_code(KC_A);
            tap_code(KC_L);
            last_summoned_keycode = KC_L;
            break;

        case KC_O:
            // rationale: avoid SFB.
            // ngram: « ow » (0.10844%)
            // examples: « how »,  « know »,  « down »,  « now »,  « Windows »
            tap_code(KC_W);
            last_summoned_keycode = KC_W;
            break;

        case KC_P:
            // rationale: avoid SFB.
            // ngram: « pd » (0.01643%)
            // examples: « update »,  « pdf »,  « pdt »,  « dropdown »,  « pd.DataFrame »
            tap_code(KC_D);
            last_summoned_keycode = KC_D;
            break;

        case KC_R:
        case HOME2_R:
            // rationale: avoid SFS.
            // ngram: « ree » (0.02534%)
            // examples: « free »,  « screen »,  « three »,  « freeze »
            /*
             * The most frequent letter preceding « ee » is R but various
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
            // ngram: « sg » (0.00539%)
            // examples: « msg », « disgusted »,  « disguised »
            tap_code(KC_G);
            last_summoned_keycode = KC_G;
            break;

        case KC_T:
        case HOME2_T:
            // rationale: avoid SFB.
            // ngram: « tp » (0.01311%)
            // examples: « output »,  « smartphone »,  « stp » (s'il te plaît)
            tap_code(KC_P);
            last_summoned_keycode = KC_P;
            break;

        case KC_W:
            // rationale: avoid ring-pinky outer row skip and SFS.
            // ngram: « would » (0.07580%)
            // examples: « would »,  « wouldn't »,  « won't »,  « word »
            tap_code(KC_O);
            tap_code(KC_U);
            tap_code(KC_L);
            tap_code(KC_D);
            last_summoned_keycode = KC_D;
            break;

        case KC_U:
            // rationale: avoid SFS.
            // ngram: « put » (0.10564%), « but », (0.03200%), « dut » (0.00250%)
            // examples: « but »,  « put »,  « input »,  « début »,  « computer », « dutch »
            tap_code(KC_T);
            last_summoned_keycode = KC_T;
            break;

        case KC_Y:
            // rationale: avoid SFB.
            // ngram: « ying » (0.00561%)
            // examples: « annoying »,  « saying »,  « buying »
            /*
             * « yi » is almost always followed by « ng » (« ying » makes up 0.68375%
             * of all tetragrams starting with « yi »). Exceptions include
             * « yikes » (0.04580%), « yield » (0.02181%) and « yank inner » Vim
             * commands (0.24863%) like « yiw ».
             */
            tap_code(KC_I);
            tap_code(KC_N);
            tap_code(KC_G);
            last_summoned_keycode = KC_G;
            break;

        case KC_SPACE:
            // rationale: typing reduction.
            // ngram: « ␣the » (0.27805%)
            // examples: « in the », « of the », « with the »,  « and then »
            tap_code(KC_T);
            tap_code(KC_H);
            tap_code(KC_E);
            last_summoned_keycode = KC_E;
            break;

        case KC_MINUS:
            // rationale: avoid SFS.
            // ngram: « -> » (0.00541%)
            // examples: « record->event.pressed »,  « def f(x: int) -> int: »
            tap_code16(KC_GT);
            last_summoned_keycode = KC_GT;
            break;

        case KC_QUOTE:
            // rationale: avoid SFB.
            // ngram: « 'm␣ » (0.01094%)
            // examples: « I'm not »,  « I'm still »,  « I'm trying »
            tap_code(KC_M);
            tap_code(KC_SPACE);
            last_summoned_keycode = KC_SPACE;
            break;

        case QK_REP:
            // rationale: avoid SFS.
            // ngram: « ↻er » (TODO%)
            // examples: « different »,  « better »,  « passer »,  « aller »,  « letter »
            tap_code(KC_E);
            tap_code(KC_R);
            last_summoned_keycode = KC_R;
            break;

        case MAGIC_R:
            // rationale: typing reduction and consistency.
            // ngram: « ␣the » (TODO%)
            // examples: « I'm the », « git commit the », « :find the »,
            switch (last_summoned_keycode) {
                case KC_SPACE:
                    SEND_STRING("the");
                    last_summoned_keycode = KC_SPACE;
                    break;
            }
            break;

        case MAGIC_L:
            // rationale: avoid SFB.
            // ngram: « _<MAGIC_L>␣ », « __<MAGIC_L>␣ »
            /*
             * the main reason why there may seem to be more magic rules on the
             * right hand is that MAGIC_R does not cause SFBs with KC_SPACE
             * whereas MAGIC_L has a nasty tendency to trade a non-thumb SFB or
             * SFS by a left thumb SFB or SFS if the sequence ends with a space
             * (almost) directly after. This magic rule helps to at least
             * alleviate the « <MAGIC_L>␣ » SFB. The « <MAGIC_L>_␣ » SFS cannot be
             * bypassed though.
             */
            switch (last_summoned_keycode) {
                case KC_SPACE:
                    if (prev_keycodes[1] == KC_G) {
                        // Avoid the KC_G MAGIC_L KC_C SFS.
                        SEND_STRING("commit ");
                        last_summoned_keycode = KC_SPACE;
                    } else {
                        // e.g., KC_T MAGIC_L MAGIC_R for "I creaTED THE ".
                        SEND_STRING("the");
                        last_summoned_keycode = KC_E;
                    }
                    break;
                default:
                    tap_code(KC_SPACE);
                    last_summoned_keycode = KC_SPACE;
                    break;
            }
            break;

    }
}
