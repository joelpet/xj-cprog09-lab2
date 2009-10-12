#include "julian.h"

#include <iostream>

namespace lab2 {

    Julian::Julian() {
        // todays gregorian date
        int & y = t_year;
        int & m = t_month;
        int & d = t_day;

        int current_jd = 367*y-(7*(y+5001+(m-9)/7))/4+(275*m)/9+d+1729777;

        // reset to jd == 0
        y = -4713;
        m = 1;
        d = 1;

        // add days
        add_days(current_jd);
    }

    Julian::Julian(int y, int m, int d) : DateCommon(y,m,d) {
    }

    /**
     * Returns the year of this date.
     *
     * @return The year
     */
    int Julian::year() const {
        return 0; // TODO
    }

    /**
     * Returns the Julian day number, which is the interval of time in days
     * since January 1, 4713 BC Greenwich noon.
     *
     * This method is valid for all Julian calendar dates after November 23,
     * which indeed covers all years from 1858 to 2558.
     *
     * http://en.wikipedia.org/wiki/Julian_day
     * #Converting_between_Julian_calendar_date_and_Julian_Day_Number
     */
    int Julian::mod_julian_day() const { 
        return 367*year()-(7*(year()+5001+(month()-9)/7))/4+(275*month())/9+day()+1729777;
    }

    /** 
     * Returns true if the current year is a leap year. That is, if
     * the year is evenly divisible by four.
     */
    bool Julian::leap_year() const { 
        return year() % 4 == 0;
    }

}

