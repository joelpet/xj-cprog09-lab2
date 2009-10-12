#include "julian.h"

#include <iostream>

namespace lab2 {

    Julian::Julian() {}

    Julian::Julian(int y, int m, int d) : DateCommon(y,m,d) {}

    /** 
     * Returns true if the current year is a leap year. That is, if
     * the year is evenly divisible by four.
     */
    bool Julian::leap_year() const { 
        return year() % 4 == 0;
    }

    /**
     * Returns the JDN for the specified Julian date.
     *
     * @link http://www.cs.umu.se/~isak/Snippets/jdn.c
     */
    long Julian::ymd_to_jdn(int y, int m, int d) const {
        long jdn;

        if (y < 0)              /* adjust BC year */
            y++;

        jdn = 367L * y - 7 * (y + 5001L + (m - 9) / 7) / 4
            + 275 * m / 9 + d + 1729777L;

        return jdn;
    }

    /**
     * Writes the Julian date's year, month and day to the given
     * integers from the specified JDN.
     *
     * @link http://www.cs.umu.se/~isak/Snippets/jdn.c
     */
    void Julian::jdn_to_ymd(long jdn, int & yy, int & mm, int & dd) const {
        long x, z, m, d, y;
        long daysPer400Years = 146097L;
        long fudgedDaysPer4000Years = 1460970L + 31;

        x = jdn + 68569L;

        x += 38;
        daysPer400Years = 146100L;
        fudgedDaysPer4000Years = 1461000L + 1;

        z = 4 * x / daysPer400Years;
        x = x - (daysPer400Years * z + 3) / 4;
        y = 4000 * (x + 1) / fudgedDaysPer4000Years;
        x = x - 1461 * y / 4 + 31;
        m = 80 * x / 2447;
        d = x - 2447 * m / 80;
        x = m / 11;
        m = m + 2 - 12 * x;
        y = 100 * (z - 49) + y + x;

        yy = (int)y;
        mm = (int)m;
        dd = (int)d;

        if (yy <= 0)                   /* adjust BC years */
            (yy)--;
    }

}

