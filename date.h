#include <ostream>

namespace lab2 {
    class Date {

        int t_year;
        int t_month;
        int t_day;

        public:
            // Konstruktorer
            Date(); // Skapar med dagens datum
            Date(int year, int month, int day); // Skapar ett datum med specade args
            // Kanske en med kattistime?
            Date(const Date & datum);

            int year() const;
            int month() const;
            int day() const;
            virtual int week_day() = 0;
            virtual int days_per_week() = 0;
            virtual int days_this_month() = 0;
            virtual int months_per_year() = 0;
            virtual std::string week_day_name() = 0;
            virtual std::string month_name() = 0;


            Date & operator--();
            void operator+=(int);
            void operator-=(int);

            void add_year(int n = 1); // Returtyp? varför?
            void add_month(int n = 1);  // returtyp? varför?

            bool operator==(const Date & d) const;
            bool operator!=(const Date & d) const;
            bool operator<(const Date & d) const;
            bool operator<=(const Date & d) const;
            bool operator>(const Date & d) const;
            bool operator>=(const Date & d) const;
            int operator-(const Date & d) const;

            virtual int mod_julian_day() const = 0; // vad är detta?

            //std::ostream & operator<<(std::ostream & os);
            // år-månad-dag

            /*
             * Operatorerna ska vara virtuella där så behövs. Låt de funktinoer som
             * inte kan definieras i basklassen vara strikt virtuella (pure
             * virtual).
             */

            /*
             * Vilka funktioner är const? Vilka argument/returtyper är const? Vid
             * redovisningen ska du övertyga handledaren att du kan använda const
             * och virtual.
             */


    };

    std::ostream & operator<<(std::ostream & os, const Date &);
    // år-månad-dag
}
