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
                enum format { list, cal, iCal };
            // private: 
                format current_format;
            // public:
                std::multimap<T, std::string> calendar;
                T date;
                /**
                 * Should be set to the current day
                 */
                Calendar() : current_format(list) {
                    date = T();
                }

                /**
                 * Should work no matter the type of Date
                 */
                template <class Q>
                    Calendar(const Calendar<Q> & c) : current_format(list) {
                        this->date = c.date;
                        typename std::multimap<Q,std::string>::const_iterator it;

                        for (it = c.calendar.begin(); it != c.calendar.end(); ++it) {
                            calendar.insert(std::pair<T, std::string>(T(it->first), it->second));
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

                    ret = calendar.equal_range(date);
                    for (it = ret.first; it != ret.second; ++it) {
                        if (event == (*it).second) {
                            std::cerr << "already exists" << std::endl;
                            return false;
                        }
                    }
                    // We didnt find it
                    calendar.insert(std::pair<T, std::string>(date, event));
                    return true;
                }

                bool remove_event(std::string event) {
                    return remove_event(event, date);
                }

                bool remove_event(std::string event, int d) {
                    return remove_event(event, d, date.month());
                }

                bool remove_event(std::string event, int d, int m) {
                    return remove_event(event, d, m, date.year());
                }

                /**
                 * Same as add_event
                 * If unable to remove, return false
                 */
                bool remove_event(std::string event, int d, int m, int y) {
                    try {
                        return remove_event(event, T(y, m, d));
                    }
                    catch (std::out_of_range &e ) {
                        return false;
                    }
                }


                bool remove_event(const std::string event, T date) {
                    typename std::multimap<T,std::string>::iterator it;
                    std::pair<typename std::multimap<T, std::string>::iterator, typename std::multimap<T, std::string>::iterator> ret;

                    ret = calendar.equal_range(date);
                    for (it = ret.first; it != ret.second; ++it) {
                        if (event == it->second) {
                            calendar.erase(it);
                            return true;
                        }
                    }
                    return false;
                }

                void set_format(format f) {
                    current_format = f;
                }

                format get_format() {
                    return current_format;
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
            typename std::multimap<T, std::string> calendar = c.calendar;

            if (c.current_format == Calendar<T>::list) {

                for (it = calendar.begin(); it != calendar.end(); it++) {
                    if (it->first > c.date) {
                        std::cout << it->first << " : " << it->second << std::endl;
                    }
                }
            }
            else if (c.current_format == Calendar<T>::cal) {
                T first_day(c.date.year(), c.date.month(), 1); // first day this month
                T today(first_day);
                
                std::cout << "      " << first_day.month_name() << " " << first_day.year()<< std::endl;
                std::cout << "må  ti  on  to  fr  lö  sö" << std::endl;

                for (int i = 0; i < first_day.week_day(); i++) {
                    std::cout << "    ";
                }

                it = calendar.begin();
                while (it->first <= c.date)
                    ++it;

                for (int i = 1; i <= first_day.days_this_month(); ++i) {
                    std::string append;
                    if (i < 10)
                        append.resize(1, ' ');

                    std::cout << append << i;
                    if (it->first == today) {
                        std::cout << "* ";
                        it++;
                    }
                    else {
                        std::cout << "  ";
                    }
                    if (today.week_day() == 6)
                        std::cout << std::endl;
                    ++today;
                }

                std::cout << std::endl << std::endl;;


                for (it = calendar.begin(); it != calendar.end(); it++) {
                    if (it->first > c.date) {
                        std::cout << " "<< it->first << ": " << it->second << std::endl;
                    }
                }
            }
            else if (c.current_format == Calendar<T>::iCal) {
                std::cout << "BEGIN:VCALENDAR" << std::endl;
                std::cout << "VERSION:2.0" << std::endl;
                std::cout << "PRODID: lolbollarna :)" << std::endl;
                for (it = calendar.begin(); it != calendar.end(); it++) {
                    if (it->first > c.date) {
                        std::cout << "BEGIN:VEVENT" << std::endl;
                        std::cout << "DTSTART:" << it->first.year();
                        if (it->first.month() < 10)
                            std::cout << "0" << it->first.month();
                        else
                            std::cout << it->first.month();
                        if (it->first.day() < 10)
                            std::cout << "0" << it->first.day();
                        else
                            std::cout << it->first.day();
                        std::cout << "T080000" << std::endl;
                        std::cout << "DTEND:" << it->first.year();
                        if (it->first.month() < 10)
                            std::cout << "0" << it->first.month();
                        else
                            std::cout << it->first.month();
                        if (it->first.day() < 10)
                            std::cout << "0" << it->first.day();
                        else
                            std::cout << it->first.day();
                        std::cout << "T090000" << std::endl;

                        // std::cout << it->first << " : " << it->second << std::endl;
                        std::cout << "SUMMARY:" << it->second << std::endl;
                        std::cout << "END:VEVENT" << std::endl;
                    }
                }
                std::cout << "END:VCALENDAR" << std::endl;
            }
        }

}

#endif
