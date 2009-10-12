#include "date_common.h"

namespace lab2 {
    const std::string nameOfDay[] = {"", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
    const std::string nameOfMonth[] = {"", "january", "februrary", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};

    const int daysPerMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    DateCommon::DateCommon() {}

    DateCommon::DateCommon(int y, int m, int d) : Date(y,m,d) {}


    /**
     * Returns the year of this date.
     *
     * @return The year
     */
    int Date::year() const {
        return t_year;
    }
    /**
     * Resturns the month of this date.
     *
     * @return The month
     */
    int Date::month() const {
        return t_month;
    }
    /**
     * Returns the day of this date.
     *
     * @retun The day
     */
    int Date::day() const {
        return t_day;
    }

    /**
     * Adds the specified number of days to this date.
     *
     * @param n The number of days to add
     * @return The new day
     */
    int DateCommon::add_day(int n) {
        if (n > 0) {
            for (int i = 0; i < n; i++) {
                ++(*this);
            }
        }
        else {
            for (; n < 0; n++) {
                --(*this);
            }
        }

        return t_day;
    }

    /**
     * Adds a number of months to our current date
     * 
     * @param n Add this number of months to the calendar
     */
    // TODO probably broken
    int DateCommon::add_month(signed int n = 1) {
        bool pos;
        if (n > 0)
            pos = true;
        else {
            pos = false;
        }

        int addMonths = n + t_month;

        int addYear, newMonth;

        addYear = (int)(addMonths/12);
        newMonth = addMonths - addYear*12;

        if (!is_valid(t_year + addYear, newMonth, t_day)) {
            addMonths--;
            add_day(30);

            addYear = (int)(addMonths/12);
            newMonth = addMonths - addYear*12;

        }
        t_year += addYear;
        t_month = newMonth;
    }

    bool DateCommon::is_valid(int year, int month, int day) const {
        if (day > daysPerMonth[month]) return false;
        if (leap_year() && month == 2 && day > daysPerMonth[month]+1) return false;
    }

    /** 
     * Increases the year with n
     */
    int DateCommon::add_year(signed int n = 1) { 
        t_year += n;
        if (!is_valid(t_year, t_month, t_day)) {
            // 29 feb
            t_day = 28;
        }
        return t_year;
    }

    /**
     * Returns the day of the week.
     */
    int DateCommon::week_day() const {
        return mod_julian_day() % days_per_week() + 1;
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
        if (leap_year() && t_month == 2) {
            return 29;
        }
        else {
            return daysPerMonth[t_month];
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
        return nameOfDay[week_day()];
    }

    /**
     * Returns the name of the current month
     */
    std::string DateCommon::month_name() const {
        return nameOfMonth[t_month];
    }

}
