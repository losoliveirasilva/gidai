#ifndef DATE_H
#define DATE_H

#include <sstream>
#include <iomanip>

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

	std::string dateString(){
		std::stringstream ss;
		ss 	<< (int)year << "-"
			<< std::setfill('0') << std::setw(2) << (int)month 	<< "-"
			<< std::setfill('0') << std::setw(2) << (int)day 	<< " "
			<< std::setfill('0') << std::setw(2) << (int)hour 	<< ":"
			<< std::setfill('0') << std::setw(2) << (int)minute << ":"
			<< std::setfill('0') << std::setw(2) << 0;
		return ss.str();
	}

};

}  /* namespace agenda */


#endif

