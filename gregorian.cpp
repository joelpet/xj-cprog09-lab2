#include "gregorian.h"
namespace lab2 {

    /** 
     * Increases the month with n
     */
    int Gregorian::add_month(signed int n) {
        if (n > 0) {
            t_year += (int)(n + t_month/12);
            t_month += (n + t_month)%12;
            return t_month;
        }
        else {
            // Might be broken, didnt think it through thurrowly (spelling?)
            t_year -= (int)(n - t_month/12);
            t_month -= (n - t_month)%12;
            return t_month;
        }
    }
    
    /**
     * TODO
     */
    int Gregorian::add_day(int n) {
        return 0;
    }

    /**
     * http://en.wikipedia.org/wiki/Julian_day#Converting_between_Gregorian_calendar_date_and_Julian_Day_Number
     */
    int Gregorian::mod_julian_day() const { // vad är detta?
        return (1461 * (t_year + 4800 + (t_month - 14)/12))/4 +(367 * (t_month - 2 - 12 * ((t_month - 14)/12)))/12 - (3 * ((t_year + 4900 + (t_month - 14)/12)/100))/4 + t_day - 32075;
    }


    /**
     * Returns true if the current year is a leap year
     * 
     * "    Every year that is exactly divisible by four is a leap year, except for years that are exactly divisible by 100; the centurial years that are exactly divisible by 400 are still leap years. For example, the year 1900 is not a leap year; the year 2000 is a leap year. "
     */
    bool Gregorian::leap_year() const {
        if (t_year % 400)
            return true;
        if (t_year % 100)
            return false;
        if (t_year % 4)
            return true;
        return false;
    }

}
