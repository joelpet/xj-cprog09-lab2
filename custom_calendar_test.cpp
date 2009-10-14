#include "julian.h"
#include "gregorian.h"
#include "calendar.h"
#include "kattistime.h"
#include <assert.h>
#include <iostream>

int main() {
    using namespace lab2;

    // set up kattistime
    time_t tp;
    time(&tp);    
    set_k_time(tp);


    std::cout << "Starting custom tests" << std::endl;
    // set up kattistime
    time_t tp;
    time(&tp);    
    set_k_time(tp);



    std::cout << "----------------------------------------" << std::endl;
    Calendar<Gregorian> cal;
    cal.set_date(2000, 12, 2);
    cal.add_event("Basketträning", 4, 12, 2000);
    cal.add_event("Basketträning", 11, 12, 2000);
    cal.add_event("Nyårsfrukost", 1, 1, 2001);
    cal.add_event("Första advent", 1); // år = 2000, månad = 12
    cal.add_event("Vårdagjämning", 20, 3); // år = 2000
    cal.add_event("Julafton", 24, 12);
    cal.add_event("Kalle Anka hälsar god jul", 24); // också på julafton
    cal.add_event("Julafton", 24);  // En likadan händelse samma datum ska
                                    // ignoreras och inte sättas in i kalendern
    cal.add_event("Min första cykel", 20, 12, 2000);
    cal.remove_event("Basketträning", 4);
    std::cout << cal;   // OBS! Vårdagjämning och första advent är
                        // före nuvarande datum och skrivs inte ut
    std::cout << "----------------------------------------" << std::endl;
    cal.remove_event("Vårdagjämning", 20, 3, 2000);
    cal.remove_event("Kalle Anka hälsar god jul", 24, 12, 2000);
    cal.set_date(2000, 11, 2);
    if (! cal.remove_event("Julafton", 24)) {
        std::cout << " cal.remove_event(\"Julafton\", 24) tar inte"<< std::endl
            << " bort något eftersom aktuell månad är november" << std::endl;
    }
    std::cout << "----------------------------------------" << std::endl;
    std::cout << cal;

    // set up some test objects 
    std::cout << "Setting up test objects ";

    // operator==
    std::cout << "operator==" << std::endl;

    // operator!=
    std::cout << "operator!=" << std::endl;
 
    // operator<
    std::cout << "operator<" << std::endl;
    
    // operator>
    std::cout << "operator>" << std::endl;
    //
    // operator-
    std::cout << "operator-" << std::endl;
   
    // operator=
    
    // operator++
    
    // operator--

    // operator+=

    // operator-=

    // add_event

    Calendar<Gregorian> g1;
    assert(g1.add_event("nhpsCSY", 14, 9, 2100) == true);

    // remove_event

    g1.set_date(2100, 2, 6);
    g1.add_event("JXLkblP",  22, 9);
    assert(g1.remove_event("JXLkblP", 22, 9, 2100) == true);

    std::cout << "Custom tests successfully run!" << std::endl;

    return 0;
}
