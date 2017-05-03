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
    int auxInt = 0;

    agenda::RCFile rcfile(".gidairc");

    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    todaydate << std::setfill('0') << std::setw(2) << (now->tm_mday) << '/'
              << std::setfill('0') << std::setw(2) << (now->tm_mon + 1) << '/'
              << (now->tm_year + 1900);
    todaymonth << std::setfill('0') << std::setw(2) << (now->tm_mon + 1) << '/'
               << (now->tm_year + 1900);

    al.agendas.at(0).pushEntry(agenda::Date(2017, 5, 2, 10, 5), agenda::Entry("Dentista"));
    al.agendas.at(0).pushEntry(agenda::Date(2017, 5, 3, 13, 5), agenda::Entry("Oftalmo"));
    al.agendas.at(0).pushEntry(agenda::Date(2017, 5, 4, 15, 5), agenda::Entry("Dermato"));
    al.agendas.at(0).pushEntry(agenda::Date(2017, 6, 27, 20, 30), agenda::Entry("Viagem para Lages"));

    al.agendas.at(1).pushEntry(agenda::Date(2017, 5, 2, 11, 5), agenda::Entry("Prova I - Redes I"));
    al.agendas.at(1).pushEntry(agenda::Date(2017, 5, 3, 14, 5), agenda::Entry("Trabalho prático II - Redes I"));
    al.agendas.at(1).pushEntry(agenda::Date(2017, 5, 4, 15, 5), agenda::Entry("Prova II - Cálculo B"));
    al.agendas.at(1).pushEntry(agenda::Date(2017, 6, 10, 10, 10), agenda::Entry("Prova III - Cálculo B"));

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
            tui.printAgendaList(al.agendas, true);
            auxInt = tui.getInt("Número da agenda: ");
            if(auxInt >= (int)al.agendas.size()){
                std::cout << "Agenda inválida\n";
            } else{
                al.agendas.at(auxInt).pushEntry(tui.getTimeDate(), agenda::Entry(tui.getText("Descrição: ")));
            }
            break;

        case agenda::CREATE_AGENDA:
            al.addAgenda(agenda::Agenda(tui.getText("Nome da agenda: "), tui.getColor()));
            break;

        case agenda::VIEW_TODAY_ENTRIES:
            tui.printAgendaList(al.agendas, false);
            std::cout << "Comprimissos do dia " << todaydate.str() << "\n";
            tui.printEntriesVector(al.getEntries({(unsigned short)(now->tm_year + 1900), (unsigned char)(now->tm_mon+1), (unsigned char)now->tm_mday, 0, 0}, {(unsigned short)(now->tm_year + 1900), (unsigned char)(now->tm_mon+1), (unsigned char)(now->tm_mday+1), 0, 0}));
            break;

        case agenda::VIEW_MONTH_ENTRIES:
            tui.printAgendaList(al.agendas, false);
            std::cout << "Comprimissos do mês " << todaymonth.str() << "\n";
            tui.printEntriesVector(al.getEntries({(unsigned short)(now->tm_year + 1900), (unsigned char)(now->tm_mon+1), (unsigned char)1, 0, 0}, {(unsigned short)(now->tm_year + 1900), (unsigned char)(now->tm_mon+1), (unsigned char)32, 0, 0}));
            break;

        case agenda::VIEW_SPECIFIC_DAY:
            tui.printAgendaList(al.agendas, false);
            dateAux = tui.getDate();
            tui.printEntriesVector(al.getEntries(dateAux, {dateAux.year, dateAux.month, (unsigned char)(dateAux.day+1), 0,0}));
            break;

        case agenda::VIEW_SPECIFIC_MONTH:
            tui.printAgendaList(al.agendas, false);
            dateAux = tui.getMonth();
            tui.printEntriesVector(al.getEntries({dateAux.year, dateAux.month, 1, 0, 0}, {dateAux.year, dateAux.month, 32, 0,0}));
            break;

        default:
            std::cout << "\n\nOpção inválida\n\n" << std::endl;
        }

        std::cout << std::endl;

    } 

    return 0;
}

