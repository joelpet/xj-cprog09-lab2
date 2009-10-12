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
    long Julian::ymd_to_jdn(int y, int m, int d) {
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
    long Julian::jdn_to_ymd(long jdn, int & y, int & m, int & d) {
        // TODO implement
    }

    /*
     * Returns the year of this date.
     *
     * @return The year
     */
    int Julian::year() const {
        return 0; // TODO
    }


}

