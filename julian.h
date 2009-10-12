#include "date_common.h"

namespace lab2 {

    class Julian : public DateCommon {

        bool leap_year() const;

        public:
            Julian();
            Julian(int, int, int);
            virtual int mod_julian_day() const; 
    };

}
