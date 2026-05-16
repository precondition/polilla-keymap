#include QMK_KEYBOARD_H
#include "precondition_keymap.h"

/* Magic rules version 0.1 */

/*
 * Percentages are given relative to ngram class in a corpus composed of my
 * keylogs, and shell commands:
 * "1" (frequency percentage among all unigrams/monograms)
 * "12" (frequency percentage among all bigrams),
 * "123" (frequency percentage among all trigrams),
 * "1_3" (frequency percentage of "1" <something> "3" among all skip-1-grams)
 * etc.
 */

void process_magic_key_left(uint16_t prev_keycode, uint8_t prev_mods) {
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
            // ngram: "oce" (0.00915%)
            // examples: "process", "procedure", "ocean"
            tap_code(KC_E);
            last_summoned_keycode = KC_E;
            break;

        case KC_G:
            // rationale: avoid SFS.
            // ngram: "git␣" (0.30964%)
            // examples: "git s", "git add", "git commit"
            tap_code(KC_I);
            tap_code(KC_T);
            tap_code(KC_SPACE);
            last_summoned_keycode = KC_SPACE;
            break;

        case KC_I:
            // rationale: avoid SFS.
            // ngram: "ric" (0.02664%)
            // examples: "America", "strict", "trick", "matrice"
            tap_code(KC_C);
            last_summoned_keycode = KC_C;
            break;

        case KC_L:
            // rationale: avoid SFB.
            // ngram: "lt" (0.04956%)
            // examples: "filter", "default", "result", "multi"
            tap_code(KC_T);
            last_summoned_keycode = KC_T;
            break;

        case KC_M:
            // rationale: avoid SFB.
            // ngram: "ms" (0.19171%)
            // examples: "MS Teams", "seems", "DMs", "params"
            tap_code(KC_E);
            last_summoned_keycode = KC_E;
            break;

        case KC_N:
        case HOME2_N:
            // rationale: avoid SFB.
            // ngram: "nv" (0.04122%)
            // examples: "envie", "envoyer", "convert", "nvm", "nvim"
            tap_code(KC_V);
            last_summoned_keycode = KC_V;
            break;

        case KC_O:
            // rationale: avoid SFB.
            // ngram: "oe" (0.01193%)
            // examples: "does", "goes", "nœud", "whatsoever"
            /*
             * on the left hand because "or␣" (0.07468%) is a lot more frequent than
             * "oe␣" (0.00091%).
             */
            tap_code(KC_E);
            last_summoned_keycode = KC_E;
            break;

        case KC_P:
            // rationale: avoid pinky-ring scissor.
            // ngram: "pr" (0.25307%)
            // examples: "prep", "print", "press", "process", "project"
            tap_code(KC_R);
            last_summoned_keycode = KC_R;
            break;

        case KC_Q:
            // rationale: avoid SFS.
            // ngram: "qui" (0.03750%)
            // examples: "qui␣", "quick", "requires"
            /*
             * this creates an unfortunate left thumb SFB for "qui␣" but this
             * is better than the right ring SFS.  The space SFB could be fixed
             * by putting this on the right magic key but "que␣" (0.05380%) is
             * in fact more frequent than "qui␣" (0.01468%).
             */
            tap_code(KC_U);
            tap_code(KC_I);
            last_summoned_keycode = KC_I;
            break;

        case KC_R:
        case HOME2_R:
            // rationale: avoid SFB.
            // ngram: "rw" (0.00319%)
            // examples: "forward", "otherwise", "afterwards", "overwrite"
            tap_code(KC_W);
            last_summoned_keycode = KC_W;
            break;

        case KC_S:
        case HOME2_S:
            // rationale: avoid SFB.
            // ngram: "sm" (0.02595%)
            // examples: "small", "smartphone", "smart", "smth", "gsm"
            /*
             * the most common patterns are "␣sm" and "sm␣" while "sm_␣" never
             * happens so this can be safely bound to MAGIC_L without creating
             * space SFS.
             */
            tap_code(KC_M);
            last_summoned_keycode = KC_M;
            break;

        case KC_T:
        case HOME2_T:
            // rationale: avoid SFS.
            // ngram: "uta" (0.0130%), "tta" (0.00890%)
            // examples: "gotta", "permutation", "executable", "(je) mettais"
            /*
             * "auta" as in "autant" is excluded because that is typed as
             * KC_A+MAGIC_R+KC_T+KC_A.
             */
            tap_code(KC_A);
            last_summoned_keycode = KC_A;
            break;

        case KC_U:
            // rationale: avoid SFB.
            // ngram: "ua" (0.04527%†)
            // examples: "ouais", "language", "actual", "situation", "visual"
            /*
             * the most frequent usage of "ua" is "qua~" and "~ually" but
             * these ngrams are outside of scope because they are typed as
             * KC_Q+MAGIC_L+KC_A and KC_U+KC_SLASH+MAGIC_L respectively.
             * †: the statistic does not exclude "qua" and "ually".
             */
            tap_code(KC_A);
            last_summoned_keycode = KC_A;
            break;

        case KC_V:
            // rationale: avoid SFB.
            // ngram: "ven" (TODO)
            // examples: "even", "haven't", "souvent", "peuvent", "given"
            tap_code(KC_E);
            tap_code(KC_N);
            last_summoned_keycode = KC_N;
            break;

        case KC_W:
            // rationale: avoid SFB.
            // ngram: "wr" (0.02176%)
            // examples: "write", "wrong", "wrote", "wrapper", "wrists",
            //           "wr␣" (Firefox search keyword for WordReference)
            tap_code(KC_R);
            last_summoned_keycode = KC_R;
            break;

        case KC_X:
            // rationale: avoid SFB.
            // ngram: "xp" (0.02618%)
            // examples: "expect", "experience", "expliquer", Ctrl+X+P (vim autocompletion)
            tap_code(KC_P);
            last_summoned_keycode = KC_P;
            break;

        case KC_DOT:
#ifdef TAP_DANCE_ENABLE
        case TD_DOT:
#endif
            // rationale: avoid SFB.
            // ngram: "../" (0.06328%)
            // examples: "cd ../", "git add ../path/to/file.ext"
            tap_code(KC_DOT);
            tap_code(KC_SLASH);
            last_summoned_keycode = KC_SLASH;
            break;

        case KC_SLASH:
            // rationale: avoid SFS.
            // ngram: "ally" (0.00778%)
            // examples: "really", "actually", "totally", "personally"
            /*
             * all the magic keys for KC_U and KC_A are already occupied
             * with higher-frequency ngrams but something had to be done with
             * "ally" and especially for "ually" as it would require going down
             * the whole index column to type if we assume standard typing
             * rules. The advantage of KC_SLASH is that it is on the same row
             * as KC_U and does not conflict with other keys. One corollary of
             * this choice is that KC_SLASH must not share the same finger as
             * KC_COMMA or else we would get a SFS due to the high frequency of
             * "ally,".
             */
            tap_code(KC_BACKSPACE);
            tap_code(KC_A);
            tap_code(KC_L);
            tap_code(KC_L);
            tap_code(KC_Y);
            last_summoned_keycode = KC_Y;
            break;

    }
}


void process_magic_key_right(uint16_t prev_keycode, uint8_t prev_mods) {
    switch (prev_keycode) {

        case KC_A:
        case HOME2_A:
            // rationale: avoid SFB.
            // ngram: "au" (0.08569%)
            // examples: "␣au␣", "faut", "aussi", "because", "autre"
            tap_code(KC_U);
            last_summoned_keycode = KC_U;
            break;

        case KC_B:
            // rationale: avoid SFB.
            // ngram: "bl" (0.12859%)
            // examples: "problem", "possible", "probably", "semble"
            /*
             * this has to be on the right magic key because the most
             * frequent pattern is ".*bl.␣" so putting it on the left would create
             * a thumb SFS that even MAGIC_L+MAGIC_R=KC_SPACE cannot fix.
             *
             * It might be surprising to see that such a common bigram requires
             * a magic key so you could wonder if it wouldn't be wiser to swap
             * M and L in order to put L on middle finger and keep B on finger.
             * "bl" (0.12859%) is indeed more frequent than "ls" (0.07231%) but
             * you have to realize that it is easier to bypass and work around
             * a SFB thanks to magic keys compared to SFSs. If we compare the
             * stats for "l_s" (0.27081%) and "b_l" (0.04215%), it becomes
             * clear that it is better to optimize for the "l_s" skipgram since
             * it is rather rare for another letter to insert itself between B
             * and L and the "bl" bigram can be easily fixed with a magic key
             * even if it lives in the same column as L.
             */
            tap_code(KC_L);
            last_summoned_keycode = KC_L;
            break;

        case KC_C:
            // rationale: avoid SFB.
            // ngram: "cr" (0.07286%)
            // example: "croire", "écrire", "macro", "script", "create"
            tap_code(KC_R);
            last_summoned_keycode = KC_R;
            break;

        case KC_D:
            // rationale: avoid SFB.
            // ngram: "dl" (0.01219%)
            // examples: "handle", "deadline", "hardly", "regardless"
            tap_code(KC_L);
            last_summoned_keycode = KC_L;
            break;

        case KC_E:
            // rationale: avoid SFS.
            // ngram: "ted" (0.04350%), "led" (0.01054%)
            // examples: "called", "expected", "dedicated", "enabled"
            tap_code(KC_D);
            last_summoned_keycode = KC_D;
            break;

        case KC_F:
            // rationale: avoid SFB.
            // ngram: "fs" (0.01200%)
            // examples: "profs", "négatifs", "pdfs", "dfs"
            /*
             * "offset" and "diffs" are not affected because they are
             * typed as KC_F+REPEAT+KC_S because REPEAT is currently unable to
             * repeat a resolved magic key (TODO: TBD).
             */
            tap_code(KC_S);
            last_summoned_keycode = KC_S;
            break;

        case KC_I:
            // rationale: avoid SFB.
            // ngram: "iq" (0.02928%)
            // examples: "compliqué", "uniquement", "graphique", "technique"
            tap_code(KC_Q);
            last_summoned_keycode = KC_Q;
            break;

        case KC_L:
            // rationale: avoid SFB.
            // ngram: "ld" (0.05422%)
            // examples: "would", "should", "hold", "could", "folder"
            tap_code(KC_D);
            last_summoned_keycode = KC_D;
            break;

        case KC_N:
            // rationale: avoid SFB.
            // ngram: "np" (0.08870%)
            // examples: "input", "npm", "senpai", "np" (no problem)
            tap_code(KC_P);
            last_summoned_keycode = KC_P;
            break;

        case KC_O:
            // rationale: avoid SFS.
            // ngram: "for" (0.09882%), "wor" (0.04498%), "cor" (0.02330%)
            // examples: "for", "encore", "work", "before", "word"
            // note: Unlike for "wor" and "cor", there is no SFS applicable for
            // "for" (F is on lower middle finger key and R is on center ring
            // key) but using the magic key on thumb is more comfortable than
            // doing finger gymnastics with the ring and middle fingers on the
            // same hand.
            tap_code(KC_R);
            last_summoned_keycode = KC_R;
            break;

        case KC_P:
            // rationale: avoid SFS.
            // ngram: "pen" (0.03847%)
            // examples: "penser", "pendant", "open", "happens"
            tap_code(KC_E);
            tap_code(KC_N);
            last_summoned_keycode = KC_N;
            break;

        case KC_Q:
            // rationale: avoid row skip.
            // ngram: "qu" (0.38932%)
            // examples: "que", "quand", "qu'il", "qu'on", "quoi"
            /*
             * "qui" is excluded because already taken in charge by
             * KC_Q+MAGIC_L.
             */
            tap_code(KC_U);
            last_summoned_keycode = KC_U;
            break;

        case KC_R:
        case HOME2_R:
            // rationale: avoid SFB.
            // ngram: "rc" (0.07731%)
            // examples: "arch", "search", "src", "merci", "force", "v3.0.2rc1",
            /*
             * "rw_␣" (0.00000%) never happens but "rc_␣" (0.00018%) does happen so the "rc" bypass
             * must be on MAGIC_R to avoid left thumb SFS with KC_SPACE.
             */
            tap_code(KC_C);
            last_summoned_keycode = KC_C;
            break;

        case KC_T:
            // rationale: avoid SFB.
            // ngram: "tl" (0.03451%)
            // examples: "little", "mostly", "exactly", "currently"
            /*
             * the most common pattern is "tl_␣".
             */
            tap_code(KC_L);
            last_summoned_keycode = KC_L;
            break;

        case KC_U:
            // rationale: avoid SFB.
            // ngram: "ua" (0.06432%)
            // examples: "quand", "ouais", "actually", "language", "actual", "Quand", "manually", "ouais,", "quasi", "quasiment", 
            /*
             * "quand" is excluded.
             */
            tap_code(KC_M);
            last_summoned_keycode = KC_M;
            break;

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

        case MAGIC_L:
            // rationale: avoid SFB.
            // ngram: "_<MAGIC_L>␣" (≈.00040%), "__<MAGIC_L>␣" (≈0.00090%)
            // examples: "defauLT␣", "seeMS␣", "aLT␣", "noMS␣", "probleMS␣"
            // examples: "QUI␣", "goTTA␣", "numeRiC␣", "TaD␣", "symmetRiC␣"
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

