#include "date_common.h"
namespace lab2 {

    class Gregorian : public DateCommon {

        bool leap_year() const;
        public:

            virtual int add_day(int);
            virtual int add_month(int);
    
            virtual int mod_julian_day() const; // vad är detta?

            // Operator overloads don't get inherited?
    };


}
