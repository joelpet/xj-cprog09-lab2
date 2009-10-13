#include "gregorian.h"
#include "julian.h"
#include "kattistime.h"
#include <assert.h>
#include <iostream>

int main() {
    using namespace lab2;

    std::cout << "Starting custom tests ..." << std::endl;

    // set up kattistime
    time_t tp;
    time(&tp);    
    set_k_time(tp);

    // set up some test objects 

    std::cout << "set up some test objects" << std::endl;
    Gregorian g1(1900, 1, 1);
    std::cout << ".";
    Gregorian g2(1900, 1, 13);
    std::cout << ".";
    Gregorian g3(1858, 11, 16);
    std::cout << ".";
    Gregorian g4(1858, 11, 17);
    std::cout << ".";
    Gregorian g5(1858, 11, 18);
    Gregorian g6(2000, 9, 1);
    Gregorian g7(2000, 5, 31);
    Gregorian g8(2001, 1, 31);
    std::cout << ".";
    Gregorian gnow;
    std::cout << "." << std::endl << "julian:" << std::endl;

    Julian j1(1899, 12, 20);
    std::cout << ".";
    Julian j2(1900, 1, 1);
    std::cout << ".";
    Julian j3(1858, 11, 4);
    std::cout << ".";
    Julian j4(1858, 11, 5);
    std::cout << ".";
    Julian j5(1858, 11, 6);
    Julian j6(2000, 9, 1);
    Julian j7(2000, 5, 31);
    Julian j8(2001, 1, 31);
    Julian j9(1900, 2, 29);
    std::cout << ".";
    Julian jnow;
    std::cout << ".";


    // operator==
    std::cout << "operator==" << std::endl;
    assert(g1 == g1);
    assert(g4 == g4);
    assert(j1 == j1);
    assert(j4 == j4);
    assert(g1 == j1);
    assert(g2 == j2);
    assert(g3 == j3);
    assert(g4 == j4);
    assert(g5 == j5);
    assert(gnow == jnow);

    // operator!=
    std::cout << "operator!=" << std::endl;
    assert(g1 != g2);
    assert(j1 != j2);
    assert(j3 != g4);
    assert(j4 != j5);

    // operator<
    std::cout << "operator<" << std::endl;
    assert(g3 < j4);
    assert(g4 < j5);
    assert(j3 < g4);
    assert(j4 < g5);

    // operator>
    std::cout << "operator>" << std::endl;
    assert(g4 > j3);
    assert(g5 > j4);
    assert(j4 > g3);
    assert(j5 > g4);

    // operator-
    std::cout << "operator-" << std::endl;
    assert(g5 - j3 == 2);
    assert(j3 - g5 == -2);
    assert(j4 - g4 == 0);

    // operator=
    
    // operator++
    
    // operator--

    // operator+=

    // operator-=

    // year()
    std::cout << "year()" << std::endl;
    assert(g1.year() == 1900);
    assert(g2.year() == 1900);
    assert(g3.year() == 1858);
    assert(g4.year() == 1858);
    assert(g5.year() == 1858);
    assert(gnow.year() == 2009);

    assert(j1.year() == 1899);
    assert(j2.year() == 1900);
    assert(j3.year() == 1858);
    assert(j4.year() == 1858);
    assert(j5.year() == 1858);
    assert(jnow.year() == 2009);

    // month()
    std::cout << "month()" << std::endl;
    assert(g1.month() == 1);
    assert(g2.month() == 1);
    assert(g3.month() == 11);
    assert(g4.month() == 11);
    assert(g5.month() == 11);

    assert(j1.month() == 12);
    assert(j2.month() == 1);
    assert(j3.month() == 11);
    assert(j4.month() == 11);
    assert(j5.month() == 11);

    // day()
    std::cout << "day()" << std::endl;
    assert(g1.day() == 1);
    assert(g2.day() == 13);
    assert(g3.day() == 16);
    assert(g4.day() == 17);
    assert(g5.day() == 18);

    assert(j1.day() == 20);
    assert(j2.day() == 1);
    assert(j3.day() == 4);
    assert(j4.day() == 5);
    assert(j5.day() == 6);



    // mod_julian_day

    // add_day
    
    // add_month
    g3.add_month(1);
    assert(g3 == Gregorian(1858, 12, 16));
    g3.add_month(-1);
    assert(g3 == Gregorian(1858, 11, 16));

    g6.add_month(1);
    assert(g6 == Gregorian(2000, 10, 1));
    g7.add_month(1);
    assert(g7 == Gregorian(2000, 6, 30));
    g8.add_month(1);
    assert(g8 == Gregorian(2001, 3, 1));

    g6.add_month(-1);
    assert(g6 == Gregorian(2000, 9, 1));
    g7.add_month(-1);
    assert(g7 == Gregorian(2000, 5, 31));
    // TODO unsure how to handle this case
    g8.add_month(-1);
    assert(g8 == Gregorian(2001, 2, 1));

    Gregorian g10(2390, 2, 28);
    g10.add_month(-5);
    assert(g10 == Gregorian(2389, 9, 28));
    // add_year


    std::cout << "Custom tests successfully run!" << std::endl;

    return 0;
}
