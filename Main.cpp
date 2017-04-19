#include <iostream>
#include <iomanip>
#include <numeric>
#include <string>
#include <ctime>
#include "Agenda.h"
//#include "Modifier.h"

int main(int argc, char **argv)
{

    auto a = agenda::Agenda{};
    unsigned short line = 1;
    unsigned short year_;
    unsigned short month_;
    unsigned short day_;
    unsigned short hour_;
    unsigned short minute_;
    std::string description_;
    
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );

    while (line != 0){
        std::cout << "Agenda v1.0 Alpha\n\n"
                  << "0 - Sair\n"
                  << "1 - Adicionar compromisso\n"
                  << "2 - Ver os compromissos do dia\n\n"
                  << "> ";

        std::cin >> line;
        std::cin.ignore();

        if(line == 1){
            std::cout << "Day: ";
            std::cin >> day_;
            std::cin.ignore();
            std::cout << "Month: ";
            std::cin >> month_;
            std::cin.ignore();
            std::cout << "Year: ";
            std::cin >> year_;
            std::cin.ignore();
            std::cout << "Hour: ";
            std::cin >> hour_;
            std::cin.ignore();
            std::cout << "Minute: ";
            std::cin >> minute_;
            std::cin.ignore();
            std::cout << "Description: ";
            std::getline(std::cin, description_);
            a.pushEntry(agenda::Date(year_, month_, day_, hour_, minute_), agenda::Entry(description_));
        } else if(line == 2){
            for(auto v: a.getEntries({(unsigned short)(now->tm_year + 1900), (unsigned char)now->tm_mon, (unsigned char)now->tm_mday, 0, 0}, {year_, (unsigned char)month_, (unsigned char)day_, 23, 60})){
                std::cout << std::setfill('0') << std::setw(2) << (int)v.first.hour << ":" 
                          << std::setfill('0') << std::setw(2) << (int)v.first.minute << " "
                          << std::setfill('0') << std::setw(2) << (int)v.first.day << "/"
                          << std::setfill('0') << std::setw(2) << (int)v.first.month << "/"
                          << std::setfill('0') << std::setw(2) << (int)v.first.year << " - "
                          << v.second.description
                << std::endl;
            }
        } else if(line == 3){
            std::cout << "Day: ";
            std::cin >> day_;
            std::cin.ignore();
            std::cout << "Month: ";
            std::cin >> month_;
            std::cin.ignore();
            std::cout << "Year: ";
            std::cin >> year_;
            std::cin.ignore();

            for(auto v: a.getEntries({year_, (unsigned char)month_, (unsigned char)day_, 0, 0}, {year_, (unsigned char)month_, (unsigned char)day_, 23, 60})){
                std::cout << std::setfill('0') << std::setw(2) << (int)v.first.hour << ":" 
                          << std::setfill('0') << std::setw(2) << (int)v.first.minute << " "
                          << std::setfill('0') << std::setw(2) << (int)v.first.day << "/"
                          << std::setfill('0') << std::setw(2) << (int)v.first.month << "/"
                          << std::setfill('0') << std::setw(2) << (int)v.first.year << " - "
                          << v.second.description
                << std::endl;
            }
        }

        std::cout << std::endl;

    } 

    /*a.pushEntry(agenda::Date(2017, 4, 10, 10, 5), agenda::Entry("teste0"));
    a.pushEntry(agenda::Date(2017, 6, 8, 18, 30), agenda::Entry("teste1"));
    a.pushEntry(agenda::Date(2017, 4, 15, 8, 20), agenda::Entry("teste2"));*/

    for(auto v: a.getEntries({2017, 3, 18, 0, 0}, {2018, 6, 8, 0, 0})){
        std::cout << std::setfill('0') << std::setw(2) << (int)v.first.hour << ":" 
                  << std::setfill('0') << std::setw(2) << (int)v.first.minute << " "
                  << std::setfill('0') << std::setw(2) << (int)v.first.day << "/"
                  << std::setfill('0') << std::setw(2) << (int)v.first.month << "/"
                  << std::setfill('0') << std::setw(2) << (int)v.first.year << " - "
                  << v.second.description
        << std::endl;
    }

    return 0;
}

