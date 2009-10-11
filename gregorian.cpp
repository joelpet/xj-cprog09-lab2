#include "gregorian.h"
namespace lab2 {

    const int daysPerMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const std::string nameOfDay[] = {"", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
    const std::string nameOfMonth[] = {"", "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};

    /**
     * Returns the current day of the week
     */
    int Gregorian::week_day()  const {
        // http://en.wikipedia.org/wiki/Calculating_the_day_of_the_week
        int months[]        = {0,0,3,3,6,1,4,6,2,5,0,3,5};
        int leap_months[]   = {0,6,2,3,6,1,4,6,2,5,0,3,5};

        int century = (int)(t_year/100); // two first digits of the year
        int year = t_year - century*100; // two last digits of the year
        int c = 2*(3 - (century % 4)); 
        int y = (int)(year / 4);
        int month;
        if (leap_year()) {
            month = leap_months[t_month];
        }
        else {
            month = months[t_month];
        }
        return (c + year + y + months[t_month] + t_day)%7;
    }
    
    
    /**
     * There is 7 days per week in the gregorian calendar
     */
    int Gregorian::days_per_week() const {
        return 7;
    }

    /**
     * The number of days this month
     */
    int Gregorian::days_this_month() const {
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
    int Gregorian::months_per_year() const {
        return 12;
    }

    /**
     * Returns the name of the current day
     * as provided by week_day()
     */
    std::string Gregorian::week_day_name() const {
        return nameOfDay[week_day()];
    }

    /**
     * Returns the name of the current month
     */
    std::string Gregorian::month_name() const {
        return nameOfMonth[t_month];
    }

    /** 
     * Increases the year with n
     */
    int Gregorian::add_year(signed int n) { 
        t_year += n;
        return t_year;
    }

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
     * Adds the specified number of days to this date.
     *
     * @param n The number of days to add
     * @return The new day
     */
    int Gregorian::add_day(int n) {
        for (int i = 0; i < n; i++) {
            (*this)++;
        }

        return t_day;
    }

    /**
     * TODO
     */
    int Gregorian::mod_julian_day() const { // vad är detta?
        return 0;
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
