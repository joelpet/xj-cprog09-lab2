#include "gregorian.h"
#include <iostream>
#include <assert.h>
int main() {
    using namespace lab2;
    std::cout << "start" << std::endl;

    Gregorian a(1998, 9, 13);
    Gregorian b(1998, 9, 13);
    Gregorian c(2000, 10, 5);
    Gregorian d(2000, 9, 13);
    Gregorian e(1998, 9, 1);
    Gregorian f(1998, 8, 31);
    Gregorian g(1998, 8, 1);

    // Test compare operators
    assert(a == b);
    assert(a != c);
    assert(a != d);
    assert(a != e);
    assert(c - a > 0);
    assert(a - c < 0);
    assert(e - d < 0); 
    assert(a < c);
    assert(c > a);
    assert(a <= b);
    assert(b >= a);



    g.add_month(1);
    assert(g == e);

    // std::cout << g << std::endl;
    g.add_month(15);
    // std::cout << g << std::endl;
    g.add_month(-16);
    // std::cout << g << std::endl;
    // std::cout << e << std::endl;
    assert(g == e);

    --e;
    // std::cout << e << std::endl;
    assert(e == f);

    --e;
    ++e;
    assert(e == f);

    e = Gregorian(1998,9,1);

    e += 12;
    assert(e == a);
    c -= 22;
    assert(c == d); // Osäker på att jag räknat rätt, dubbelkolla om det blir fel här



    std::cout << "stop" << std::endl;
    return 0;
}
