// header guard
#ifndef DATE_H
#define DATE_H

#include <ostream>
#include <stdexcept>

namespace lab2 {
    class Date {

        protected:
            /**
             * Full days since January 1, 4713 BC Greenwich noon.
             */
            long jdn;

            long get_jdn() const;

            virtual long ymd_to_jdn(int y, int m, int d) const = 0;
            virtual void jdn_to_ymd(long jdn, int & y, int & m, int & d) const = 0;

        public:
            // Constructors
            Date();
            Date(int y, int m, int d);
            Date(const Date & datum);

            virtual int year() const = 0;
            virtual int month() const = 0;
            virtual int day() const = 0;
            virtual int week_day() const = 0;
            virtual int days_per_week() const = 0;
            virtual int days_this_month() const = 0;
            virtual int months_per_year() const = 0;
            virtual std::string week_day_name() const = 0;
            virtual std::string month_name() const = 0;

            virtual int add_day(int = 1) = 0;
            virtual int add_month(int n = 1) = 0;
            virtual int add_year(int n = 1) = 0; 

            bool operator==(const Date & d) const;
            bool operator!=(const Date & d) const;
            bool operator<(const Date & d) const;
            bool operator<=(const Date & d) const;
            bool operator>(const Date & d) const;
            bool operator>=(const Date & d) const;
            int operator-(const Date & d) const;

            Date & operator=(const Date &);
            Date & operator++();
            Date & operator--();
            Date & operator+=(int);
            Date & operator-=(int);

            int mod_julian_day() const;
    };

    std::ostream & operator<<(std::ostream & os, const Date &);
}

#endif
// end header gard
