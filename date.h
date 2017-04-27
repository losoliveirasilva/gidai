#ifndef DATE_H
#define DATE_H

namespace agenda {

class Date {

public:
    Date(unsigned short year, unsigned char month, unsigned char day,
         unsigned char hour, unsigned char minute):
                year{year}, month{month}, day{day}, hour{hour}, minute{minute} {}

    unsigned short year;
    unsigned char month;
    unsigned char day;
    unsigned char hour;
    unsigned char minute;

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

        if (hour < rhs.hour){
            return true;
        } else if (hour > rhs.hour){
            return false;
        }

        if (minute < rhs.minute){
            return true;
        } else if (minute > rhs.minute){
            return false;
        }

        return false;

    }

};

}  /* namespace agenda */


#endif

