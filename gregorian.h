#include "date_common.h"
namespace lab2 {

    class Gregorian : public DateCommon {

        bool leap_year() const;

        public:
            virtual int week_day() const;
            virtual int days_per_week() const;
            virtual int days_this_month() const;
            virtual int months_per_year() const;
            virtual std::string week_day_name() const;
            virtual std::string month_name() const;

            virtual int add_day(int);
            virtual int add_year(int); 
            virtual int add_month(int);
    
            virtual int mod_julian_day() const; // vad är detta?

            // Operator overloads don't get inherited?
    };


}
