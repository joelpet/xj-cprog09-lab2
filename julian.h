#include "date_common.h"

namespace lab2 {

    class Julian : public DateCommon {

        bool leap_year() const;

        virtual long ymd_to_jdn(int y, int m, int d);
        virtual long jdn_to_ymd(long jdn, int & y, int & m, int & d);

        public:
            Julian();
            Julian(int, int, int);
            virtual int mod_julian_day() const; 
    };

}
