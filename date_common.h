// header guard
#ifndef DATE_COMMON_H
#define DATE_COMMON_H

#include "date.h"
#include <stdexcept>

namespace lab2 {

    /* A note on 'public' before 'Date' below:
     * The public access specifier may be replaced by
     * any one of the other access specifiers
     * protected and private. This access specifier
     * limits the most accessible level for the
     * members inherited from the base class: The
     * members with a more accessible level are
     * inherited with this level instead, while the
     * members with an equal or more restrictive
     * access level keep their restrictive level in
     * the derived class. 
     */

    /**
     * DateCommon offers an extra layer between any class that
     * implements Date and the Date class itself. This is so that 
     * code that may be common to two or more implementing classes 
     * but does not fit in base class Date do not have to be
     * duplicated.
     *
     * We assume for the sake of simplicity that only Gregorian and
     * Julian dates will inherit from DateCommon, which is why things
     * like days_per_week() are placed inside here.
     */
    class DateCommon : public Date {
        public:
            DateCommon();
            DateCommon(int, int, int);
            virtual int year() const = 0;
            virtual int month() const;
            virtual int day() const;
            virtual int add_day(int);
            virtual int add_month(int);
            virtual int add_year(int); 
            virtual int week_day() const;
            virtual int days_per_week() const;
            virtual int days_this_month() const;
            virtual int months_per_year() const;
            virtual std::string week_day_name() const;
            virtual std::string month_name() const;
        protected:
            virtual bool leap_year() const = 0;
            virtual bool is_valid(int, int, int) const;
    };

}

#endif
// end header guard
