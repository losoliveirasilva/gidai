#include <iostream>
#include <iomanip>
#include <numeric>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include "Agenda.h"

enum Menu
{
    EXIT,
    ADD_ENTRY,
    VIEW_TODAY_ENTRIES,
    VIEW_MONTH_ENTRIES,
    VIEW_SPECIFIC_DAY,
    VIEW_SPECIFIC_MONTH,
    MENU_NUM
};

int main(int argc, char **argv)
{
    Color::Modifier fg_red(Color::FG_RED);
    Color::Modifier fg_blue(Color::FG_BLUE);
    Color::Modifier fg_def(Color::FG_DEFAULT);
    auto a = agenda::Agenda(fg_blue);
    unsigned short line = 1;
    unsigned short year_;
    unsigned short month_;
    unsigned short day_;
    unsigned short hour_;
    unsigned short minute_;
    std::string description_;
    std::stringstream todaydate;
    std::stringstream todaymonth;

    char slash_dummy;

    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    todaydate << std::setfill('0') << std::setw(2) << (now->tm_mday) << '/'
              << std::setfill('0') << std::setw(2) << (now->tm_mon + 1) << '/'
              << (now->tm_year + 1900);
    todaymonth << std::setfill('0') << std::setw(2) << (now->tm_mon + 1) << '/'
               << (now->tm_year + 1900);

    a.pushEntry(agenda::Date(2017, 4, 20, 10, 5), agenda::Entry("teste0"));
    a.pushEntry(agenda::Date(2017, 4, 21, 10, 5), agenda::Entry("teste1"));
    a.pushEntry(agenda::Date(2017, 4, 22, 10, 5), agenda::Entry("teste2"));

    while (line != EXIT){
        std::cout << "gidai v0.1 Alpha\n\n"
                  << "0 - Sair\n"
                  << "1 - Adicionar compromisso\n"
                  << "2 - Ver os compromissos de hoje\n"
                  << "3 - Ver os compromissos desse mês\n"
                  << "4 - Ver os compromissos de um dia específico\n"
                  << "5 - Ver os compromissos de um mês específico\n"
                  << "\n> ";

        std::cin >> line;
        std::cin.ignore();

        switch(line){
        case EXIT:
            std::cout << "\n\nAté logo!! :)\n" << std::endl;
            break;
        case ADD_ENTRY:
            std::cout << "Hora (HH:MM): ";
            std::cin >> hour_ >> slash_dummy >> minute_;
            std::cout << "Data (dd/mm/aaaa): ";
            std::cin >> day_ >> slash_dummy >> month_ >> slash_dummy >> year_;
            std::cin.ignore();
            std::cout << "Description: ";
            std::getline(std::cin, description_);
            a.pushEntry(agenda::Date(year_, month_, day_, hour_, minute_), agenda::Entry(description_));
            break;

        case VIEW_TODAY_ENTRIES:
            std::cout << "\nComprimissos do dia " << todaydate.str() << "\n";
            std::cout << a.fg_color;
            for(auto v: a.getEntries({(unsigned short)(now->tm_year + 1900), (unsigned char)(now->tm_mon+1), (unsigned char)now->tm_mday, 0, 0}, {(unsigned short)(now->tm_year + 1900), (unsigned char)(now->tm_mon+1), (unsigned char)(now->tm_mday+1), 0, 0})){
                std::cout << std::setfill('0') << std::setw(2) << (int)v.first.hour << ":" 
                          << std::setfill('0') << std::setw(2) << (int)v.first.minute << " - "
                          << v.second.description
                << std::endl;
            }
            std::cout << fg_def;
            break;

        case VIEW_MONTH_ENTRIES:
            std::cout << "\nComprimissos do mês " << todaymonth.str() << "\n";
            std::cout << a.fg_color;
            for(auto v: a.getEntries({(unsigned short)(now->tm_year + 1900), (unsigned char)(now->tm_mon+1), (unsigned char)1, 0, 0}, {(unsigned short)(now->tm_year + 1900), (unsigned char)(now->tm_mon+1), (unsigned char)32, 0, 0})){
                std::cout << std::setfill('0') << std::setw(2) << (int)v.first.hour << ":" 
                          << std::setfill('0') << std::setw(2) << (int)v.first.minute << " "
                          << std::setfill('0') << std::setw(2) << (int)v.first.day << "/"
                          << std::setfill('0') << std::setw(2) << (int)v.first.month << "/"
                          << std::setfill('0') << std::setw(2) << (int)v.first.year << " - "
                          << v.second.description
                << std::endl;
            }
            std::cout << fg_def;
            break;

            break;
        case VIEW_SPECIFIC_DAY:
            std::cout << "Data (dd/mm/aaaa): ";
            std::cin >> day_ >> slash_dummy >> month_ >> slash_dummy >> year_;
            for(auto v: a.getEntries({year_, (unsigned char)month_, (unsigned char)day_, 0, 0}, {year_, (unsigned char)month_, (unsigned char)(day_+1), 0, 0})){
                std::cout << std::setfill('0') << std::setw(2) << (int)v.first.hour << ":" 
                          << std::setfill('0') << std::setw(2) << (int)v.first.minute << " "
                          << std::setfill('0') << std::setw(2) << (int)v.first.day << "/"
                          << std::setfill('0') << std::setw(2) << (int)v.first.month << "/"
                          << std::setfill('0') << std::setw(2) << (int)v.first.year << " - "
                          << v.second.description
                << std::endl;
            }
            break;

        case VIEW_SPECIFIC_MONTH:
            std::cout << "Data (mm/aaaa): ";
            std::cin >> month_ >> slash_dummy >> year_;

            for(auto v: a.getEntries({year_, (unsigned char)month_, (unsigned char)1, 0, 0}, {year_, (unsigned char)month_, (unsigned char)32, 0, 0})){
                std::cout << std::setfill('0') << std::setw(2) << (int)v.first.hour << ":" 
                          << std::setfill('0') << std::setw(2) << (int)v.first.minute << " "
                          << std::setfill('0') << std::setw(2) << (int)v.first.day << "/"
                          << std::setfill('0') << std::setw(2) << (int)v.first.month << "/"
                          << std::setfill('0') << std::setw(2) << (int)v.first.year << " - "
                          << v.second.description
                << std::endl;
            }
            break;

        default:
            std::cout << "\n\nOpção inválida\n\n" << std::endl;
        }

        std::cout << std::endl;

    } 

    return 0;
}

