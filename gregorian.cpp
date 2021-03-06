#include "gregorian.h"

namespace lab2 {

    Gregorian::Gregorian() {
    }

    Gregorian::Gregorian(int y, int m, int d) : DateCommon(y, m, d) {
        if (!is_valid(y, m, d)) {
            throw std::out_of_range("Invalid date");
        }
        jdn = ymd_to_jdn(y, m, d);
    }

    Gregorian::Gregorian(const Date & datum) : DateCommon(datum) {
    }

    /** 
     * Returns true if the current year is a leap year
     * 
     * Every year that is exactly divisible by four is a leap year, except for
     * years that are exactly divisible by 100; the centurial years that are
     * exactly divisible by 400 are still leap years. For example, the year
     * 1900 is not a leap year; the year 2000 is a leap year.
     */
    bool Gregorian::leap_year(int year) const { 
        if (year % 400 == 0) return true; 
        if (year % 100 == 0) return false; 
        if (year % 4 == 0) return true; 
        return false;
    }

    bool Gregorian::leap_year() const {
        return leap_year(year());
    }

    /**
     * Returns the JDN for the specified Gregorian date.
     *
     * @link http://www.cs.umu.se/~isak/Snippets/jdn.c
     */
    long Gregorian::ymd_to_jdn(int y, int m, int d) const {
        long jdn;

        if (y < 0)              /* adjust BC year */
            y++;

        jdn = (long)(d - 32076)
            + 1461L * (y + 4800L + (m - 14) / 12) / 4
            + 367 * (m - 2 - (m - 14) / 12 * 12) / 12
            - 3 * ((y + 4900L + (m - 14) / 12) / 100) / 4
            + 1;            /* correction by rdg */

        return jdn;
    }

    /**
     * Writes the Gregorian date's year, month and day to the given
     * integers from the specified JDN.
     *
     * @link http://www.cs.umu.se/~isak/Snippets/jdn.c
     */
    void Gregorian::jdn_to_ymd(long jdn, int & yy, int & mm, int & dd) const {
        long x, z, m, d, y;
        long daysPer400Years = 146097L;
        long fudgedDaysPer4000Years = 1460970L + 31;

        x = jdn + 68569L;

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
