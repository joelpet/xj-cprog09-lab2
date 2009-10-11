#include "date_common.h"

namespace lab2 {
    const std::string nameOfDay[] = {"", "Måndag", "Tisdag", "Onsdag", "Torsdag", "Fredag", "Lördag", "Söndag"};
    const std::string nameOfMonth[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    const int daysPerMonth[13] = {0,31,28,31,30,31,30,31, 31, 30, 31, 30, 31};
    
    /**
     * Adds a number of months to our current date
     * 
     * @param n Add this number of months to the calendar
     */
    int DateCommon::add_month(signed int n) {
        t_year += int(n/12);
        n = n%12;
        t_month += n;
        return t_month;
    }

    /**
     * Return the day of the week
     */
    int DateCommon::week_day() const {
        return mod_julian_day()%7+1;
    }

    /**
     * There is 7 days per week in the gregorian calendar
     */
    int DateCommon::days_per_week() const {
        return 7;
    }

    /**
     * The number of days this month
     */
    int DateCommon::days_this_month() const {
        if (leap_year() && t_month == 2) {
            return 29;
        }
        else {
            return daysPerMonth[t_month];
        }
    }

    /**
     * There are always 12 months per year
     */
    int DateCommon::months_per_year() const {
        return 12;
    }
    
    /**
     * Returns the name of the current day
     * as provided by week_day()
     */
    std::string DateCommon::week_day_name() const {
        return nameOfDay[week_day()];
    }

    /**
     * Returns the name of the current month
     */
    std::string DateCommon::month_name() const {
        return nameOfMonth[t_month];
    }

    /** 
     * Increases the year with n
     */
    int DateCommon::add_year(signed int n) { 
        t_year += n;
        return t_year;
    }


}
