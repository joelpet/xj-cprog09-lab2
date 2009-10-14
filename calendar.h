#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>
#include <map>
#include <stdexcept>
#include "date.h"

namespace lab2 {

    template <class T>
        class Calendar {

            public:
                std::multimap<T, std::string> cal;
                T date;
                /**
                 * Should be set to the current day
                 */
                Calendar() {
                    date = T();
                }

                /**
                 * Should work no matter the type of Date
                 */
                template <class Q>
                    Calendar(const Calendar<Q> & c) {
                        this->date = c.date;
                        typename std::multimap<Q,std::string>::const_iterator it;

                        for (it = c.cal.begin(); it != c.cal.end(); ++it) {
                            cal.insert(std::pair<T, std::string>(T(it->first), it->second));
                        }

                    }

                /**
                 * @return false if the date is invalid
                 */
                bool set_date(int y, int m, int d) {
                    try {
                        date = T(y,m,d);
                    }
                    catch (std::out_of_range & e) {
                        return false;
                    }
                    return true;
                }

                /**
                 * Use the current date
                 */
                bool add_event(std::string str) {
                    return add_event(str, date);
                }

                bool add_event(std::string event, int d) {
                    try {
                        return add_event(event, T(date.year(), date.month(), d));
                    }
                    catch (std::out_of_range & e) {
                        return false;
                    }
                    return true;
                }

                bool add_event(std::string event, int d, int m) {
                    try {
                        return add_event(event, T(date.year(), m, d));
                    }
                    catch (std::out_of_range & e) {
                        return false;
                    }
                    return true;
                }

                /**
                 * if the date is invalid, return false
                 * if event already exists on the date, return false, nothing
                 * should be added
                 */
                bool add_event(std::string event, int d, int m, int y) {
                    try {
                        return add_event(event, T(y,m,d));
                    }
                    catch (std::out_of_range &e) {
                        std::cerr << "out of range" << std::endl;
                        return false;
                    }
                }

                bool add_event(std::string event, T date) {
                    typename std::multimap<T,std::string>::iterator it;
                    std::pair<typename std::multimap<T, std::string>::iterator, typename std::multimap<T, std::string>::iterator> ret;

                    ret = cal.equal_range(date);
                    for (it = ret.first; it != ret.second; ++it) {
                        if (event == (*it).second) {
                            std::cerr << "already exists" << std::endl;
                            return false;
                        }
                    }
                    // We didnt find it
                    cal.insert(std::pair<T, std::string>(date, event));
                    return true;
                }

                /**
                 * Use the current date
                 */
                bool remove_event(std::string event) {
                    return remove_event(event, date);
                }

                /**
                 * Same as add_event
                 * If unable to remove, return false
                 */
                bool remove_event(std::string event, int d, int m = 0, int y = 0) {
                    if (m == 0) m = date.month();
                    if (y == 0) y = date.year();

                    try {
                        return remove_event(event, T(y, m, d));
                    }
                    catch (std::out_of_range &e ) {
                        return false;
                    }
                }

                bool remove_event(std::string event, T date) {
                    typename std::multimap<T,std::string>::iterator it;
                    std::pair<typename std::multimap<T, std::string>::iterator, typename std::multimap<T, std::string>::iterator> ret;

                    ret = cal.equal_range(date);
                    for (it = ret.first; it != ret.second; ++it) {
                        if (event == it->second) {
                            cal.erase(it);
                            return true;
                        }
                    }
                }

        };
    /**
     * should only print events after the current date (on the current date?)
     * should be sorted by date primarily and secondarily on insertion order
     * format:
     * datum : händelse\n
     *
     * ----------------------------------------
     *  2000-12-11 : Basketträning
     *  2000-12-20 : Min första cykel
     *  2000-12-24 : Julafton
     *  2000-12-24 : Kalle Anka hälsar god jul
     *  2001-01-01 : Nyårsfrukost
     *  ----------------------------------------
     *  cal.remove_event("Julafton", 24) tar inte
     *  bort något eftersom aktuell månad är november
     *  ----------------------------------------
     *  2000-12-01 : Första advent
     *  2000-12-11 : Basketträning
     *  2000-12-20 : Min första cykel
     *  2000-12-24 : Julafton
     *  2001-01-01 : Nyårsfrukost
     */
    template <typename T>
        std::ostream & operator<<(std::ostream & os, const Calendar<T> & c) {
            typename std::multimap<T, std::string>::const_iterator it;
            typename std::multimap<T, std::string> cal = c.cal;

            for (it = cal.begin(); it != cal.end(); it++) {
                if (it->first > c.date) {
                    std::cout << it->first << " : " << it->second << std::endl;
                }
            }
        }

}

#endif
