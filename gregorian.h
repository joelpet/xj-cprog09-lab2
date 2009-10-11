#include "date_common.h"
namespace lab2 {

    class Gregorian : public DateCommon {

        bool leap_year() const;
        public:
            virtual int week_day();
            virtual int days_per_week();
            virtual int days_this_month();
            virtual int months_per_year();
            virtual std::string week_day_name();
            virtual std::string month_name();

            virtual int add_year(int); 
            virtual int add_month(int);
    
            virtual int mod_julian_day() const; // vad är detta?

            // Operator overloads don't get inherited?
    };


}
