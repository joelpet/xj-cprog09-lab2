#include "date_common.h"

namespace lab2 {

    class Gregorian : public DateCommon {

        bool leap_year() const;

        public:
            Gregorian();
            Gregorian(int, int, int);
            virtual int mod_julian_day() const; 
    };

}
