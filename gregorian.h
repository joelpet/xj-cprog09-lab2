#ifndef GREGORIAN_H
#define GREGORIAN_H

#include "date_common.h"

namespace lab2 {

    class Gregorian : public DateCommon {

        virtual bool leap_year() const;
        virtual bool leap_year(int) const;

        virtual long ymd_to_jdn(int y, int m, int d) const;
        virtual void jdn_to_ymd(long jdn, int & y, int & m, int & d) const;

        public:
            Gregorian();
            Gregorian(int, int, int);
            Gregorian(const Date & datum);
    };

}
#endif
