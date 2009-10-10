#include "date.h"
#include "kattistime.h"
#include <assert.h>
#include <iostream>

namespace lab2 {
    static const int FIRST_MONTH = 1;
    static const int FIRST_DAY = 1;

    /**
     * Constructs a new empty date, with year, month and day set to 
     * zero.
     */
    // TODO: should use todays date, through kattistime
    Date::Date() : t_year(0), t_month(FIRST_MONTH), t_day(FIRST_DAY) {
    }
    /**
     * Constructs a new date with the specified date data.
     *
     * @param year The year
     * @param month The month
     * @param day The day
     */
    Date::Date(int year, int month, int day) : t_year(year), t_month(month), t_day(day) {
        std::cout << "bajskorv" << std::endl;
    }

    /**
     * Copy constructor for a Date.
     *
     * @param datum the date to copy
     */
    Date::Date(const Date & datum) {
        t_year = datum.year();
        t_month = datum.month();
        t_day = datum.day();
        std::cerr << "Date::Date(const Date & datum)" << std::endl;
    }

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
     * Adds the specified number of years and returns the new year.
     * Then returns the resulting year, which may be handy to have.
     *
     * @param n Number of years to add
     * @return The new year
     */
    int Date::add_year(int n = 1) {
        return t_year += n;
    }

    /**
     * Adds the specified number of months and returns the new month.
     * Then returns the resulting month, which may be handy to have.
     *
     * @param n Number of months to add
     * @return The new month
     */
    // XXX: what happens if day==30 and month lands on februrary?
    // XXX: above scenario is described in lab-pm
    // TODO: this code should probably be moved to each child class
    /*
    int Date::add_month(int n = 1) {
        if (n < months_per_year()) {
            t_month++;
            // TODO: must do more here
        }

        int n_year_wraps = n / months_per_year();
        int month_remainder = n - (n_year_wraps * months_per_year());

        add_year(n_year_wraps);
        return add_month(month_remainder); // recurse
    }
    */

    /**
     * Decreases the specified number of years and returns resulting
     * year.
     *
     * @param n The number of years to decrease by
     * @return The resulting year
     */
    // XXX: are we allowed to have negative years?
    /*
    int Date::decrease_year(int n = 1) {
        return --t_year;
    }
    */

    /**
     * Decreases the the month by the specified number.
     *
     * @param n The number of month to decrease by
     * @return The resulting month
     */
    // TODO: take care of leap years and different # days / month
    /*
    int Date::decrease_month(int n = 1) {
        if (n <= t_month) {
            return t_month - n;
        }

        int n_year_wraps = n / months_per_year();
        int month_remainder = n - (n_year_wraps * months_per_year());

        decrease_year(n_year_wraps);
        return decrease_month(month_remainder); // recurse
    }
    */

    bool Date::operator==(const Date & d) const {
        return d.mod_julian_day() == this->mod_julian_day();
    }
    bool Date::operator!=(const Date & d) const {
        return !(*this == d);
    }
    bool Date::operator<=(const Date & d) const {
        return d - *this <= 0;
    }
    bool Date::operator<(const Date & d) const {
        return d - *this < 0;
    }
    bool Date::operator>(const Date & d) const {
        return d - *this > 0;
    }
    bool Date::operator>=(const Date & d) const {
        return d - *this >= 0;
    }
    /**
     * Returns the number of days between this and the specified date.
     * The integer is positive if the specified date is earlier than 
     * this date.
     *
     * @param d The date to compare with
     * @return The integral difference between the dates
     */
    int Date::operator-(const Date & d) const {
        return this->mod_julian_day() - d.mod_julian_day();
    }

    /**
     * Assigns this date to be what the specified date is.
     *
     * @param d The date to set this date to
     * @return A reference to this date
     */
    Date & Date::operator=(const Date & d) {
        if (this == &d) {
            return *this;
        }

        t_day = d.day();
        t_month = d.month();
        t_year = d.year();

        return *this;
    }

    /** 
     * Increments this date by one day. Makes sure the days wrap and
     * month in that case increase, which in turn will do the same
     * check with year.
     *
     * @return A reference to this date
     */
    Date & Date::operator++() {
        if (++t_day > days_per_week()) {
            add_month(1);
            t_day = 1;
        }

        return *this;
    }

    /**
     * Decreases this date by one day. Makes sure the days wrap and
     * month in that case increase, which in turn will do the same 
     * thing with year.
     *
     * @return A reference to this date
     */
    Date & Date::operator--() {
        if (--t_day < 1) {
            add_month(-1);
            t_day = days_this_month();
        }

        return *this;
    }

    /**
     * Prints a string representation of this date to stdout.
     *
     * @param os An ostream reference
     * @param d The date to print
     */
    std::ostream & operator<<(std::ostream & os, const Date & d) {
        std::cout << d.year() << "-" << d.month() << "-" << d.day() << std::endl;
    }
}

int main() {
    using namespace lab2;
    std::cout << "start" << std::endl;
    
    /*
    Date a(1998, 9, 13);
    Date b(1998, 9, 13);
    Date c(2000, 10, 5);
    Date d(2000, 9, 13);
    Date e(1998, 9, 1);
    */

    // Test compare operators
    /*
    assert(a == b);
    assert(a != c);
    assert(a != d);
    assert(a != e);
    assert(a < c);
    assert(c > a);
    assert(a <= b);
    assert(b >= a);
    assert(c - a > 0);
    assert(e - d < 0); 
    */

    std::cout << "stop" << std::endl;
    return 0;
}
