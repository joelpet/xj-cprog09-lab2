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
     */
    long ymd_to_jdn(int y, int m, int d) {
        // TODO implement
    }

    /**
     * Writes the Julian date's year, month and day to the given
     * integers from the specified JDN.
     */
    long jdn_to_ymd(long jdn, int & y, int & m, int & d) {
        // TODO implement
    }

}

