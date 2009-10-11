#include "gregorian.h"
#include <iostream>
int main() {
    using namespace lab2;
    std::cout << "start" << std::endl;

       Gregorian a(1998, 9, 13);
       Gregorian b(1998, 9, 13);
       Gregorian c(2000, 10, 5);
       Gregorian d(2000, 9, 13);
       Gregorian e(1998, 9, 1);

    // Test compare operators
    /*
       assert(a == b);
       assert(a != c);
       assert(a != d);
       assert(a != e);
       assert(a < c);
       assert(c > a);
       assert(a <= b);
       assert(b >= a);
       assert(c - a > 0);
       assert(e - d < 0); 

        e += 12;
        assert(e == a);
        c -= 22;
        assert(c == d); // Osäker på att jag räknat rätt, dubbelkolla om det blir fel här

        
       */

    std::cout << "stop" << std::endl;
    return 0;
}
