#include <iostream>
#include <iomanip>
#include <numeric>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>
#include "tui.h"
#include "agendalist.h"
#include "rcfile.h"
#include "features.h"

int main(/*int argc, char **argv*/)
{
    Color::Modifier fg_red(Color::FG_RED);
    Color::Modifier fg_blue(Color::FG_BLUE);
    Color::Modifier fg_def(Color::FG_DEFAULT);
    auto al = agenda::AgendaList();
    al.addAgenda(agenda::Agenda("Pessoal", fg_red));
    al.addAgenda(agenda::Agenda("Aula", fg_blue));
    unsigned short line = 1;
    std::stringstream todaydate;
    std::stringstream todaymonth;

    agenda::RCFile rcfile(".gidairc");

    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    todaydate << std::setfill('0') << std::setw(2) << (now->tm_mday) << '/'
              << std::setfill('0') << std::setw(2) << (now->tm_mon + 1) << '/'
              << (now->tm_year + 1900);
    todaymonth << std::setfill('0') << std::setw(2) << (now->tm_mon + 1) << '/'
               << (now->tm_year + 1900);

    al.agendas.at(0).pushEntry(agenda::Date(2017, 4, 27, 10, 5), agenda::Entry("teste0"));
    al.agendas.at(0).pushEntry(agenda::Date(2017, 4, 27, 12, 5), agenda::Entry("teste2"));
    al.agendas.at(0).pushEntry(agenda::Date(2017, 4, 27, 14, 5), agenda::Entry("teste4"));

    al.agendas.at(1).pushEntry(agenda::Date(2017, 4, 27, 11, 5), agenda::Entry("teste1"));
    al.agendas.at(1).pushEntry(agenda::Date(2017, 4, 27, 13, 5), agenda::Entry("teste3"));
    al.agendas.at(1).pushEntry(agenda::Date(2017, 4, 28, 15, 5), agenda::Entry("teste5"));

    agenda::Date dateAux = agenda::Date(0,0,0,0,0);
    std::string stringAux;
    auto tui = agenda::Tui(rcfile.useColor, rcfile.useStrikethrough);
    tui.showHeader();

    while (line != agenda::EXIT){
        line = (unsigned short)tui.showMenu();

        switch(line){
        case agenda::EXIT:
            break;
        case agenda::ADD_ENTRY:
            tui.printAgendaList(al.agendas);
            al.agendas.at(0).pushEntry(tui.getTimeDate(), agenda::Entry(tui.getText("Descrição: ")));
            break;

        case agenda::CREATE_AGENDA:
            al.addAgenda(agenda::Agenda(tui.getText("\nNome da agenda: "), fg_red));
            break;

        case agenda::VIEW_TODAY_ENTRIES:
            std::cout << "\nComprimissos do dia " << todaydate.str() << "\n";
            tui.printEntriesVector(al.getEntries({(unsigned short)(now->tm_year + 1900), (unsigned char)(now->tm_mon+1), (unsigned char)now->tm_mday, 0, 0}, {(unsigned short)(now->tm_year + 1900), (unsigned char)(now->tm_mon+1), (unsigned char)(now->tm_mday+1), 0, 0}));
            break;

        case agenda::VIEW_MONTH_ENTRIES:
            std::cout << "\nComprimissos do mês " << todaymonth.str() << "\n";
            tui.printEntriesVector(al.getEntries({(unsigned short)(now->tm_year + 1900), (unsigned char)(now->tm_mon+1), (unsigned char)1, 0, 0}, {(unsigned short)(now->tm_year + 1900), (unsigned char)(now->tm_mon+1), (unsigned char)32, 0, 0}));
            break;

            break;
        case agenda::VIEW_SPECIFIC_DAY:
            dateAux = tui.getDate();

            //tui.printEntriesVector(al.agendas.at(0).getEntries({dateAux.year, dateAux.month, dateAux.day, 0, 0}, {dateAux.year, dateAux.month, (unsigned char)(dateAux.day+1), 0, 0}));
            break;

        case agenda::VIEW_SPECIFIC_MONTH:
            dateAux = tui.getMonth();

            //tui.printEntriesVector(a.getEntries({dateAux.year, dateAux.month, 1, 0, 0}, {dateAux.year, dateAux.month, 32, 0, 0}));
            break;

        default:
            std::cout << "\n\nOpção inválida\n\n" << std::endl;
        }

        std::cout << std::endl;

    } 

    return 0;
}

