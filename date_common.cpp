#include "date_common.h"
#include "kattistime.h"

#include <iostream>

namespace lab2 {
    const std::string nameOfDay[] = {"", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
    const std::string nameOfMonth[] = {"", "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};

    const int daysPerMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    /**
     * Constructs a new date. Assumes that the system gives a
     * Gregorian date.
     */
    DateCommon::DateCommon() {
        time_t mytime;
        k_time(&mytime);

        // get local gregorian date
        struct tm * t = gmtime(&mytime);
        int y = t->tm_year + 1900;
        int m = t->tm_mon + 1; // 1-indexed 
        int d = t->tm_mday; // 1-indexed

        init(y, m, d);
    }

    /**
     * Constructs a new date with the specified date data.
     */
    DateCommon::DateCommon(int y, int m, int d) {
        init(y, m, d);
    }
    
    DateCommon::DateCommon(const Date & datum) : Date(datum) {}

    /**
     * Initiates this date by calculating the JDN from the assumed
     * Gregorian date.
     */
    void DateCommon::init(int y, int m, int d) {
        jdn = (long)(d - 32076)
            + 1461L * (y + 4800L + (m - 14) / 12) / 4
            + 367 * (m - 2 - (m - 14) / 12 * 12) / 12
            - 3 * ((y + 4900L + (m - 14) / 12) / 100) / 4
            + 1;            /* correction by rdg */
    }


    /**
     * Returns the year of this date.
     *
     * @return The year
     */
    int DateCommon::year() const {
        int y, m, d;
        jdn_to_ymd(jdn, y, m, d);
        return y;
    }

    /**
     * Returns the month of this date.
     *
     * @return The month
     */
    int DateCommon::month() const {
        int y, m, d;
        jdn_to_ymd(jdn, y, m, d);
        return m;
    }
    /**
     * Returns the day of this date.
     *
     * @retun The day
     */
    int DateCommon::day() const {
        int y, m, d;
        jdn_to_ymd(jdn, y, m, d);
        return d;
    }

    /**
     * Adds the specified number of days to this date.
     *
     * @param n The number of days to add
     * @return The new day
     */
    int DateCommon::add_day(int n) {
        jdn += n;

        return day();
    }


    /**
     * Adds a number of months to our current date and returns the 
     * new month.
     * 
     * @param n The number of months to add to the calendar
     */
    int DateCommon::add_month(int n) {
        // om n == 0, return
        if (n == 0) {
            return month();
        }

        // record current day
        int old_day = day(); 

        if (n > 0) {
            int y, m, d;
            jdn_to_ymd(jdn, y, m, d);

            if (m == 12) {
                m = 1;
                y++;
            }
            else {
                m++;
            }

            if (!is_valid(y,m,d)) {
                add_day(30);
            }
            else {
                jdn = ymd_to_jdn(y, m, d);
            }
            // // add just enough days to wrap month
            // add_day(days_this_month() - day() + 1);
            // // add up to old_day or as high as possible
            // int i = 1;
            // while (old_day - i >= days_this_month()) {
                // i++;
            // }
            // add_day(old_day - i);
        } else {
            int y, m, d;        

            jdn_to_ymd(jdn, y, m, d);

            if (m == 1) {
                m = 12;
                y--;
            }
            else {
                m--;
            }

            if (!is_valid(y, m, d)) {
                add_day(-30);
            }
            else {
                jdn = ymd_to_jdn(y, m, d);
            }
        }

        // rekursera
        n = n < 0 ? n+1 : n-1;
        return add_month(n);
    }

    /**
     * Returns the week day, where 1 means Monday.
     */
    int DateCommon::week_day() const {
        if (jdn < 0)
            return (-jdn) % 7 +1;
        return jdn % 7 + 1;
    }

    /**
     * Check if the current date is valid
     */
    bool DateCommon::is_valid() const {
        return is_valid(year(), month(), day());
    }

    bool DateCommon::is_valid(int year, int month, int day) const {
        if (month < 1 || month > 12 || day < 1) return false;
        if (leap_year(year) && month == 2 && day == 29) return true;
        if (day > daysPerMonth[month]) return false;
        return true;
    }

    /** 
     * Increases the year with n
     */
    int DateCommon::add_year(signed int n ) { 
        int year;
        int month;
        int day;
        jdn_to_ymd(jdn, year, month, day);

        year += n;

        if (!is_valid(year, month, day)) {
            // 29 feb
            day = 28;
        }

        jdn = ymd_to_jdn(year, month, day);

        return year;
    }

    /**
     * There are 7 days per week in both the Gregorian and Julian 
     * calendar.
     */
    int DateCommon::days_per_week() const {
        return 7;
    }

    /**
     * The number of days this month
     */
    int DateCommon::days_this_month() const {
        if (leap_year() && month() == 2) {
            return 29;
        }
        else {
            return daysPerMonth[month()];
        }
    }

    /**
     * There are 12 months per year in both Julian and Gregorian.
     * This method should be moved down to those to in a more generic,
     * approach though, since that may not be the case for all 
     * calendars.
     */
    int DateCommon::months_per_year() const {
        return 12;
    }

    /**
     * Returns the name of the current day
     * as provided by week_day()
     */
    std::string DateCommon::week_day_name() const {
        if (week_day() > 7)
            throw std::out_of_range("week_day > 7");
        return nameOfDay[week_day()];
    }

    /**
     * Returns the name of the current month
     */
    std::string DateCommon::month_name() const {
        int m = month();
        if (m < 0 || m > 12)
            throw std::out_of_range("0 > month() < 12");
        return nameOfMonth[m];
    }

}
