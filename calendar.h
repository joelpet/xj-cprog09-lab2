// TODO add template <class Date> tjosan hur man nu gör det

namespace lab2 {

    class Calendar {

        public:
            Calendar();
            
            bool set_date(int y, int m, int d);

            bool add_event(std::string event, int y, int m, int d);

            bool remove_event(std::string event, int y, int m, int d);


    
    };

}

