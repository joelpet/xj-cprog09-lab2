#include "gregorian.h"
#include "julian.h"
#include "kattistime.h"
#include <assert.h>
#include <iostream>

int main() {
    using namespace lab2;

    std::cout << "start custom tests" << std::endl;

    // set up kattistime
    time_t tp;
    time(&tp);    
    set_k_time(tp);

    // set up some test objects 

    Gregorian g1(1900, 1, 1);
    Gregorian g2(1900, 1, 13);
    Gregorian g3(1858, 11, 16);
    Gregorian g4(1858, 11, 17);
    Gregorian g5(1858, 11, 18);
    Gregorian gnow;

    Julian j1(1899, 12, 20);
    Julian j2(1900, 1, 1);
    Julian j3(1858, 11, 4);
    Julian j4(1858, 11, 5);
    Julian j5(1858, 11, 6);
    Julian jnow;

    // operator==
    assert(g1 == g1);
    assert(g4 == g4);
    assert(j1 == j4);
    assert(j4 == j4);
    assert(g1 == j1);
    assert(g2 == j2);
    assert(g3 == j3);
    assert(g4 == j4);
    assert(g5 == j5);
    assert(gnow == jnow);

    // operator!=
    assert(g1 != g2);
    assert(j1 != j2);
    assert(j3 != g4);
    assert(j4 != j5);

    // operator<
    assert(g3 < j4);
    assert(g4 < j5);
    assert(j3 < g4);
    assert(j4 < g5);

    // operator>
    assert(g4 > j3);
    assert(g5 > j4);
    assert(j4 > g3);
    assert(j5 > g4);

    // operator-
    assert(g5 - j3 == 2);
    assert(j3 - g5 == -2);
    assert(j4 - g4 == 0);

    // operator=
    
    // operator++
    
    // operator--

    // operator+=

    // operator-=

    // year()
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





    // mod_julian_day

    // add_day
    
    // add_month

    // add_year


    std::cout << "end custom tests" << std::endl;

    return 0;
}
