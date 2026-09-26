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
