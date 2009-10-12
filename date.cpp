//#define NDEBUG

#include "date.h"

#include <assert.h>
#include <iostream>
#include <sstream>

namespace lab2 {
    static const int FIRST_MONTH = 1;
    static const int FIRST_DAY = 1;
    // XXX This might be wrong! Make sure to test. 
    // Should perhaps be 2400000
    // http://tycho.usno.navy.mil/mjd.html
    static const long JDN_17_NOV_1858 = 2400001;

    /**
     * Constructs a new date.
     */
    Date::Date() {}

    /**
     * Constructs a new date with the specified date data.
     */
    Date::Date(int y, int m, int d) {}

    /**
     * Date copy constructor.
     *
     * @param datum the date to copy
     */
    Date::Date(const Date & datum) {
        jdn = datum.mod_julian_day();
        std::cerr << "Date::Date(const Date & datum)" << std::endl;
    }

    /**
     * Adds the specified number of years and returns the new year.
     * Then returns the resulting year, which may be handy to have.
     *
     * @param n Number of years to add
     * @return The new year
     */
    // int Date::add_year(int n = 1) {
        // return t_year += n;
    // }

    bool Date::operator==(const Date & d) const {
        return d.mod_julian_day() == this->mod_julian_day();
    }
    bool Date::operator!=(const Date & d) const {
        return !(*this == d);
    }
    bool Date::operator<=(const Date & d) const {
        return *this - d <= 0;
    }
    bool Date::operator<(const Date & d) const {
        return *this - d  < 0;
    }
    bool Date::operator>(const Date & d) const {
        return *this - d > 0;
    }
    bool Date::operator>=(const Date & d) const {
        return  *this - d >= 0;
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

        jdn = d.mod_julian_day();

        assert(*this - d == 0);

        return *this;
    }

    /**
     * Increments this date by the specified number of days.
     *
     * @param n The number of days to add
     * @return A reference to this date
     */
    Date & Date::operator+=(int n) {
        add_day(n);
        return *this;
    }

    /**
     * Decreases this date by the specified number of days.
     *
     * @param n The number of days to subtract
     * @return A reference to this date
     */
    Date & Date::operator-=(int n) {
        add_day(-n);
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
        jdn++;

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
        jdn--;
        return *this;
    }

    /**
     * Returns the modified julian day. That is the number of days
     * since the Gregorian date November 17, 1858.
     */
    int Date::mod_julian_day() const { 
        return jdn - JDN_17_NOV_1858;
    }

    /**
     * Prints a string representation of this date to stdout.
     *
     * @param os An ostream reference
     * @param d The date to print
     */
    std::ostream & operator<<(std::ostream & os, const Date & d) {
        std::stringstream month(std::stringstream::in | std::stringstream::out);
        month.width(2);
        month.fill('0');
        month << d.month();

        std::stringstream day(std::stringstream::in | std::stringstream::out);
        day.width(2);
        day.fill('0');
        day << d.day();
        
        std::cout << d.year() << "-" << month.str() << "-" << day.str() << std::endl;
        return os;
    }

}
