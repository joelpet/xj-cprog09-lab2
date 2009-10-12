#include "gregorian.h"

namespace lab2 {

    Gregorian::Gregorian() {}

    Gregorian::Gregorian(int y, int m, int d) : DateCommon(y,m,d) {}

    /** 
     * Returns true if the current year is a leap year
     * 
     * Every year that is exactly divisible by four is a leap year, except for
     * years that are exactly divisible by 100; the centurial years that are
     * exactly divisible by 400 are still leap years. For example, the year
     * 1900 is not a leap year; the year 2000 is a leap year.
     */
    bool Gregorian::leap_year() const { 
        if (year() % 400) return true; 
        if (year() % 100) return false; 
        if (year() % 4) return true; 
        return false;
    }

    /**
     * Returns the JDN for the specified Gregorian date.
     */
    long ymd_to_jdn(int y, int m, int d) {
        // TODO implement
    }

    /**
     * Writes the Gregorian date's year, month and day to the given
     * integers from the specified JDN.
     */
    long jdn_to_ymd(long jdn, int & y, int & m, int & d) {
        // TODO implement
    }

}
