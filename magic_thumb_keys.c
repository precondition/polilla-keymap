#include QMK_KEYBOARD_H
#include "precondition_keymap.h"

/* Magic rules version 2.0 */

/*
 * "Magic key" is AKL jargon (https://layouts.wiki/reference/terminology/magic/).
 * Not to be confused with QMK magic keycodes (https://docs.qmk.fm/keycodes_magic)
 */

/*
 * Percentages are given relative to ngram class in a corpus composed of my
 * keylogs, and shell commands:
 * « 1 » (frequency percentage among all unigrams/monograms)
 * « 12 » (frequency percentage among all bigrams),
 * « 123 » (frequency percentage among all trigrams),
 * « 1_3 » (frequency percentage of « 1 » <something> « 3 » among all skip-1-grams)
 * etc.
 */

static keypos_t get_closest_home_keypos(const keypos_t keypos) {
    /*  Matrix for polilla:
     *              ┌──┐┌──┐┌──┐              ┌──┐┌──┐┌──┐
     *  ┌──┐┌──┐┌──┐│03││04││05│              │06││07││08│┌──┐┌──┐┌──┐
     *  │00││01││02│└──┘└──┘└──┘              └──┘└──┘└──┘│09││0A││0B│
     *  └──┘└──┘└──┘┌──┐┌──┐┌──┐              ┌──┐┌──┐┌──┐└──┘└──┘└──┘
     *  ┌──┐┌──┐┌──┐│13││14││15│              │16││17││18│┌──┐┌──┐┌──┐
     *  │10││11││12│└──┘└──┘└──┘              └──┘└──┘└──┘│19││1A││1B│
     *  └──┘└──┘└──┘┌──┐┌──┐┌──┐              ┌──┐┌──┐┌──┐└──┘└──┘└──┘
     *  ┌──┐┌──┐┌──┐│23││24││25│              │26││27││28│┌──┐┌──┐┌──┐
     *  │20││21││22│└──┘└──┘└──┘              └──┘└──┘└──┘│29││2A││2B│
     *  └──┘└──┘└──┘┌──┐┌──┐┌──┐┌──┐      ┌──┐┌──┐┌──┐┌──┐└──┘└──┘└──┘
     *  ┌──┐┌──┐┌──┐│33││34││35││45│      │46││36││37││38│┌──┐┌──┐┌──┐
     *  │30││31││32│└──┘└──┘└──┘└──┘      └──┘└──┘└──┘└──┘│39││3A││3B│
     *  └──┘└──┘└──┘┌──┐┌──┐┌──┐┌──┐      ┌──┐┌──┐┌──┐┌──┐└──┘└──┘└──┘
     *          ┌──┐│41││42││43││44│      │47││48││49││4A│┌──┐
     *          │40│└──┘└──┘└──┘│  │      │  │└──┘└──┘└──┘│4B│
     *          └──┘            │  │      │  │            └──┘
     *                          └──┘      └──┘
     *
     * ⚠️ The layout produced by the `qmk info -kb polilla --matrix` command and
     * the reality do not match!
     */
    #define HOME_ROW 2

    const bool is_left_thumb_keypos = (4 == keypos.row && 0 <= keypos.col && keypos.col <= 4);
    const bool is_right_thumb_keypos =  (4 == keypos.row && 7 <= keypos.col && keypos.col <= 11);

    if (is_left_thumb_keypos) {
        return (keypos_t){.row = keypos.row, .col = 3};
    }

    if (is_right_thumb_keypos) {
        return (keypos_t){.row = keypos.row, .col = 8};
    }

    const bool is_4F_key_pos = 4 == keypos.row && 5 == keypos.col;
    const bool is_left_outer_col = 0 == keypos.col || 6 == keypos.col;
    if (is_left_outer_col || is_4F_key_pos) {
        return (keypos_t){.row = HOME_ROW, .col = keypos.col + 1};
    }

    const bool is_right_outer_col = 5 == keypos.col || 11 == keypos.col;
    if (is_right_outer_col) {
        return (keypos_t){.row = HOME_ROW, .col = keypos.col - 1};
    }

    // Deviate a bit from the reported function name.
    // This must go after the outer col logic to avoid catching the non-resting
    // key positions on home row.
    const bool is_home_row = HOME_ROW == keypos.row;
    if (is_home_row) {
        return (keypos_t){.row = keypos.row - 1, .col = keypos.col};
    }

    return (keypos_t){.row = HOME_ROW, .col = keypos.col};
}

void summon_same_finger_home_key(const keypos_t keypos) {
    const keypos_t home_keypos = get_closest_home_keypos(keypos);
    const uint16_t home_keycode = keymap_key_to_keycode(layer_switch_get_layer(home_keypos), home_keypos);
    if (QK_MOD_TAP <= home_keycode && home_keycode <= QK_MOD_TAP_MAX) {
        tap_code(GET_TAP_KC(home_keycode));
        last_summoned_keycode = GET_TAP_KC(home_keycode);
    } else {
        tap_code16(home_keycode);
        last_summoned_keycode = home_keycode;
    }
}

void process_magic_key_left(const uint16_t prev_keycodes[], const keypos_t prev_keypos[]) {
    const uint16_t penultimate_keycode = prev_keycodes[1] == MAGIC_L || prev_keycodes[1] == MAGIC_R ? last_summoned_keycode : prev_keycodes[1];
    switch (prev_keycodes[0]) {

        case KC_A:
        case HOME2_A:
            switch (penultimate_keycode) {
                case KC_SPACE:
                case KC_L:
                case KC_M:
                case KC_F:
                case KC_H:
                case KC_QUOTE:
                case KC_K:
                    // rationale: avoid SFB.
                    // ngram: « ao » (0.00980%)
                    // examples: « août », « lmao »,  « chaos », « kaomoji »
                    tap_code(KC_O);
                    last_summoned_keycode = KC_O;
                    break;

                default:
                    summon_same_finger_home_key(prev_keypos[1]);
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

        case KC_E:
        case HOME2_E:
            // rationale: avoid SFB.
            // ngram: « e<sym> » (0.10403%)
            // examples: TODO
            set_oneshot_layer(_SYM2, ONESHOT_START);
            last_summoned_keycode = OSL(_SYM);
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

        case KC_U:
            summon_same_finger_home_key(prev_keypos[1]);
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

        case MAGIC_R:
            // rationale: avoid SFB.
            // ngram: « <MAGIC_R>e »
            tap_code(KC_E);
            last_summoned_keycode = KC_E;
            break;

        default:
            summon_same_finger_home_key(prev_keypos[0]);
            break;

    }
}


void process_magic_key_right(const uint16_t prev_keycodes[], const keypos_t prev_keypos[]) {
    const uint16_t penultimate_keycode = prev_keycodes[1] == MAGIC_L || prev_keycodes[1] == MAGIC_R ? last_summoned_keycode : prev_keycodes[1];
    switch (prev_keycodes[0]) {

        case KC_A:
        case HOME2_A:
            switch (penultimate_keycode) {
                case KC_SPACE:
                case KC_L:
                case KC_M:
                case KC_F:
                case KC_H:
                case KC_QUOTE:
                case KC_K:
                    // rationale: avoid SFB.
                    // ngram: « ao » (0.00980%)
                    // examples: « août », « lmao »,  « chaos », « kaomoji »
                    tap_code(KC_O);
                    last_summoned_keycode = KC_O;
                    break;

                default:
                    summon_same_finger_home_key(prev_keypos[1]);
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

        case KC_D:
            // rationale: avoid SFS.
            // ngram: « dev » (TODO%)
            // examples: « devoir »,  « devrait »,  « develop »,  « devant », « device »
            tap_code(KC_E);
            tap_code(KC_V);
            last_summoned_keycode = KC_V;
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
            if (penultimate_keycode == KC_U) {
                // Make typing « update » and « updating » more comfortable.
                tap_code(KC_A);
                tap_code(KC_T);
                last_summoned_keycode = KC_T;
            }
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
            const bool is_preceded_by_the = prev_keycodes[1] == MAGIC_R && prev_keycodes[2] == KC_SPACE;
            // to make it easier to type « there » without SFS.
            tap_code(KC_E);
            if (!is_preceded_by_the) {
                tap_code(KC_E);
            }
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
            summon_same_finger_home_key(prev_keypos[1]);
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

        default:
            summon_same_finger_home_key(prev_keypos[0]);
            break;

    }
}
