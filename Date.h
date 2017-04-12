#ifndef DATE_H
#define DATE_H

namespace agenda {

class Date {

public:
    Date(unsigned short year, unsigned char month, unsigned char day):
        year{year}, month{month}, day{day} {}
    const unsigned short year;
    const unsigned char month;
    const unsigned char day;

    bool operator<(const agenda::Date& rhs) const {
        if (year < rhs.year){
            return true;
        } else if (year > rhs.year){
            return false;
        }

        if (month < rhs.month){
            return true;
        } else if (month > rhs.month){
            return false;
        }

        if (day < rhs.day){
            return true;
        } else if (day > rhs.day){
            return false;
        }

        return false;

    }
};

}  /* namespace agenda */


#endif

