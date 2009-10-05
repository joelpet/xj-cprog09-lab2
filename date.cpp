#include "date.h"
#include "kattistime.h"
#include <iostream>

namespace lab2 {
    Date::Date() : t_year(0), t_month(0), t_day(0) {

    }
    Date::Date(int year, int month, int day) : t_year(year), t_month(month), t_day(day) {
        std::cout << "bajskorv" << std::endl;
    }
    Date::Date(const Date & datum) {
        // if (datum == this)
        // return;
        t_year = datum.t_year;
        t_month = datum.t_month;
        t_day = datum.t_day;
        std::cout << "kopiera" << std::endl;
    }


    int Date::year() const {
        return t_year;
    }
    int Date::month() const {
        return t_month;
    }
    int Date::day() const {
        return t_day;
    }

    bool Date::operator==(const Date & d) const {
        return d.mod_julian_day() == this->mod_julian_day();
    }
    bool Date::operator!=(const Date & d) const {
        return d.mod_julian_day() != this->mod_julian_day();
    }
    bool Date::operator<=(const Date & d) const {
        return d.mod_julian_day() <= this->mod_julian_day();
    }
    bool Date::operator<(const Date & d) const {
        return d.mod_julian_day() < this->mod_julian_day();
    }
    bool Date::operator>(const Date & d) const {
        return d.mod_julian_day() > this->mod_julian_day();
    }
    bool Date::operator>=(const Date & d) const {
        return d.mod_julian_day() >= this->mod_julian_day();
    }

    int Date::operator-(const Date & d) const {
        return d.mod_julian_day() - this->mod_julian_day();
    }

    std::ostream & operator<<(std::ostream & os, const Date & d) {
        std::cout << d.year() << "-" << d.month() << "-" << d.day() << std::endl;
    }
}

int main() {
    using namespace lab2;
    std::cout << "start" << std::endl;
    //Date a;
    //Date d(1998, 9, 13);
    std::cout << "stop" << std::endl;
    return 0;
}
