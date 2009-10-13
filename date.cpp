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
        if (this == &datum) {
            return;
        }
        jdn = datum.get_jdn();
        std::cerr << "Date::Date(const Date & datum)" << std::endl;
    }

    long Date::get_jdn() const {
        return jdn;
    }

    bool Date::operator==(const Date & d) const {
        return d.get_jdn() == this->get_jdn();
    }
    bool Date::operator!=(const Date & d) const {
        return d.get_jdn() != this->get_jdn();
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
        return this->get_jdn() - d.get_jdn();
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

        jdn = d.get_jdn();

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
     * Increments this date by one day.
     *
     * @return A reference to this date
     */
    Date & Date::operator++() {
        jdn++;

        return *this;
    }

    /**
     * Decreases this date by one day.
     *
     * @return A reference to this date
     */
    Date & Date::operator--() {
        jdn--;
        return *this;
    }

    /**
     * Returns the modified julian day of this date. That is the number 
     * of days since the Gregorian date November 17, 1858.
     *
     * @return The modified julian day
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
        
        std::cout << d.year() << "-" << month.str() << "-" << day.str();
        return os;
    }

}
