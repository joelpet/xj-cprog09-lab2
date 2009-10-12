// header guard
#ifndef DATE_H
#define DATE_H

#include <ostream>

namespace lab2 {
    class Date {

        protected:
            /**
             * Number of full days since January 1, 
             * 4713 BC Greenwich noon.
             */
            int jdn;

        public:
            // Constructors
            Date();
            Date(int year, int month, int day);
            Date(const Date & datum);

            int year() const;
            int month() const;
            int day() const;
            virtual int week_day() const = 0;
            virtual int days_per_week() const = 0;
            virtual int days_this_month() const = 0;
            virtual int months_per_year() const = 0;
            virtual std::string week_day_name() const = 0;
            virtual std::string month_name() const = 0;

            virtual int add_day(int = 1) = 0;
            virtual int add_year(int = 1) = 0; 
            virtual int add_month(int = 1) = 0;

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

            virtual int mod_julian_day() const = 0;
            virtual long ymd_to_jdn(int y, int m, int d, bool julian) = 0;
            virtual long jdn_to_ymd(long jdn, int & y, int & m, int & d, bool julian) = 0;
    };

    std::ostream & operator<<(std::ostream & os, const Date &);
}

#endif
// end header gard
