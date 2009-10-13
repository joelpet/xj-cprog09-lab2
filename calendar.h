// TODO add template <class Date> tjosan hur man nu gör det

namespace lab2 {

    class Calendar {

        public:
            /**
             * Should be set to the current day
             */
            Calendar();
            
            /**
             * Should work no matter the type of Date
             */
            Calendar(const Calendar & cal);

            /**
             * @return false if the date is invalid
             */
            bool set_date(int y, int m, int d);

            /**
             * Use the current date
             */
            bool add_event(std::string);

            /**
             * if the date is invalid, return false
             * if event already exists on the date, return false, nothing
             * should be added
             */
            bool add_event(std::string event, int y, int m, int d);

            /**
             * Use the current date
             */
            bool remove_event(std::string event);

            /**
             * Same as add_event
             * If unable to remove, return false
             */
            bool remove_event(std::string event, int y, int m, int d);



    
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
    std::ostream & operator<<(std::ostream & os, const Calendar &);

}

