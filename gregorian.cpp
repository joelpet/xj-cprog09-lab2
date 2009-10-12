#include "gregorian.h"

namespace lab2 {

    Gregorian::Gregorian() {

    }
    Gregorian::Gregorian(int y, int m, int d) : DateCommon(y,m,d) {
    }

    /**
     * Returns the Julian day number, which is the interval of time in days
     * since January 1, 4713 BC Greenwich noon.
     *
     * This method is valid for all Gregorian calendar dates after November 23,
     * which indeed covers all years from 1858 to 2558.
     *
     * http://en.wikipedia.org/wiki/Julian_day
     * #Converting_between_Gregorian_calendar_date_and_Julian_Day_Number
     */
    int Gregorian::mod_julian_day() const { 
        // return (1461 * (t_year + 4800 + (t_month - 14)/12))/4 +(367 * (t_month - 2 - 12 * ((t_month - 14)/12)))/12 - (3 * ((t_year + 4900 + (t_month - 14)/12)/100))/4 + t_day - 32075;
        // TODO
        return 0;
    }


    /** 
     * Returns true if the current year is a leap year
     * 
     * Every year that is exactly divisible by four is a leap year, except for
     * years that are exactly divisible by 100; the centurial years that are
     * exactly divisible by 400 are still leap years. For example, the year
     * 1900 is not a leap year; the year 2000 is a leap year.
     */
    bool Gregorian::leap_year() const { 
        int year = this->year();
        if (year % 400) return true; 
        if (year % 100) return false; 
        if (year % 4) return true; 
        return false;
    }

    /**
     * Returns the year of this date.
     *
     * @return The year
     * TODO
     */
    int Gregorian::year() const {
        return 0;
    }
}
