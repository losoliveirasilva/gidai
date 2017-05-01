#include "tui.h"

namespace agenda {

    Tui::Tui(bool rcColor, bool rcStrikethrough):
        rcColor{rcColor}, rcStrikethrough{rcStrikethrough}
    {}

    void Tui::showHeader(){
        std::cout << "gidai v0.1 Alpha\n\n";
    }

    int Tui::showMenu(){
        auto menu = agenda::Features();
        unsigned short line;

        for(int i = 0; i < MENU_NUM; ++i){
            std::cout << i << " - " << menu.menuString(i) << std::endl;
        }

        std::cout << std::endl << "> ";

        /*std::cout << "0 - Sair\n"
                  << "1 - Adicionar compromisso\n"
                  << "2 - Ver os compromissos de hoje\n"
                  << "3 - Ver os compromissos desse mês\n"
                  << "4 - Ver os compromissos de um dia específico\n"
                  << "5 - Ver os compromissos de um mês específico\n"
                  << "\n> ";*/
        
        std::cin >> line;
        std::cin.ignore();
        return line;
    }

    agenda::Date Tui::getTimeDate(){
        unsigned short year_;
        unsigned short month_;
        unsigned short day_;
        unsigned short hour_;
        unsigned short minute_;
        char slash_dummy;

        std::cout << "Hora (HH:MM): ";
        std::cin >> hour_ >> slash_dummy >> minute_;
        std::cout << "Data (dd/mm/aaaa): ";
        std::cin >> day_ >> slash_dummy >> month_ >> slash_dummy >> year_;
        std::cin.ignore();

        return agenda::Date(year_, month_, day_, hour_, minute_);
    }

    agenda::Date Tui::getDate(){
        unsigned short year_;
        unsigned short month_;
        unsigned short day_;
        char slash_dummy;

        std::cout << "Data (dd/mm/aaaa): ";
        std::cin >> day_ >> slash_dummy >> month_ >> slash_dummy >> year_;
        std::cin.ignore();

        return agenda::Date(year_, month_, day_, 0, 0);
    }

    agenda::Date Tui::getMonth(){
        unsigned short year_;
        unsigned short month_;
        char slash_dummy;

        std::cout << "Data (mm/aaaa): ";
        std::cin >> month_ >> slash_dummy >> year_;

        return agenda::Date(year_, month_, 1, 0, 0);
    }

    std::string Tui::getText(std::string s){
        std::string description_;
        std::cout << s;
        std::getline(std::cin, description_);

        return description_;
    }

    void Tui::printEntriesVector(std::vector<std::tuple<Date, Entry, Color::Modifier>> vector){
        Color::Modifier fg_def(Color::FG_DEFAULT);
        for(auto v: vector){
            if(rcColor)
                std::cout << std::get<2>(v);
            std::cout << std::setfill('0') << std::setw(2) << (int)std::get<0>(v).hour << ":" 
                      << std::setfill('0') << std::setw(2) << (int)std::get<0>(v).minute << " "
                      << std::setfill('0') << std::setw(2) << (int)std::get<0>(v).day << "/"
                      << std::setfill('0') << std::setw(2) << (int)std::get<0>(v).month << "/"
                      << std::setfill('0') << std::setw(2) << (int)std::get<0>(v).year << " - "
                      << std::get<1>(v).description
            << std::endl;
        }
        std::cout << fg_def;
        std::cout << "\nPressione qualquer tecla para continuar";
        fflush(stdout);
        system("read -n 1");
        std::cout << std::endl;
    }

    void Tui::printAgendaList(std::vector<Agenda> agendas){
        Color::Modifier fg_def(Color::FG_DEFAULT);
        int i = 0;
        if(!agendas.empty()){
            std::cout << std::endl << "Agendas:" << std::endl;
            for(auto v: agendas){
                std::cout << v.fg_color;
                std::cout << i++ << " - ";
                std::cout << v.name << std::endl;
            }
        } else{
            std::cout << "Sem agendas" << std::endl;
        }
        std::cout << fg_def;
        std::cout << std::endl;

    }

} /* namespace agenda */
