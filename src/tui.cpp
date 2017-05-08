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
            std::cout << std::setfill(' ') << std::setw(((int)log10(MENU_NUM-1))+1) << i << " - " << menu.menuString(i) << std::endl;
        }

        std::cout << std::endl << "> ";

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

    int Tui::getInt(std::string s){
        int i;
        std::cout << s;
        std::cin >> i;
        std::cin.ignore();

        return i;
    }

    void Tui::printEntriesVector(std::vector<std::tuple<Date, std::string, Color::Modifier>> vector){
        time_t t = time(0);   // get time now
        struct tm * now = localtime( & t );
        agenda::Date today(now->tm_year+1900, now->tm_mon+1, now->tm_mday, (unsigned char)now->tm_hour, (unsigned char)now->tm_min);
        Color::Modifier fg_def(Color::FG_DEFAULT);
        Color::Modifier strike(Color::STRIKE);
        Color::Modifier res_strike(Color::RES_STRIKE);
        for(auto v: vector){
            if(rcColor)
                std::cout << std::get<2>(v);
        
            if(rcStrikethrough){
                if(std::get<0>(v) < today){
                    std::cout << strike;
                } else{
                    std::cout << res_strike;
                }
            }
            std::cout << std::setfill('0') << std::setw(2) << (int)std::get<0>(v).hour << ":" 
                      << std::setfill('0') << std::setw(2) << (int)std::get<0>(v).minute << " "
                      << std::setfill('0') << std::setw(2) << (int)std::get<0>(v).day << "/"
                      << std::setfill('0') << std::setw(2) << (int)std::get<0>(v).month << "/"
                      << std::setfill('0') << std::setw(2) << (int)std::get<0>(v).year << " - "
                      << std::get<1>(v)
            << std::endl;
        }
        std::cout << fg_def;
        std::cout << res_strike;
        std::cout << "\nPressione qualquer tecla para continuar";
        fflush(stdout);
        system("read -n 1");
        std::cout << std::endl;
    }

    void Tui::printAgendaList(std::vector<Agenda> agendas, bool showNum){
        Color::Modifier fg_def(Color::FG_DEFAULT);
        int i = 0;
        if(!agendas.empty()){
            std::cout << std::endl << "Agendas:" << std::endl;
            for(auto v: agendas){
                std::cout << v.fg_color;
                if(showNum)
                    std::cout << i++ << " - ";
                std::cout << v.name << std::endl;
            }
        } else{
            std::cout << "Sem agendas" << std::endl;
        }
        std::cout << fg_def;
        std::cout << std::endl;

    }

    Color::Modifier Tui::getColor(){
        int color;
        Color::Modifier fg_def(Color::FG_DEFAULT);
        Color::Modifier fg_red(Color::FG_RED);
        Color::Modifier fg_green(Color::FG_GREEN);
        Color::Modifier fg_yellow(Color::FG_YELLOW);
        Color::Modifier fg_blue(Color::FG_BLUE);
        Color::Modifier fg_magenta(Color::FG_MAGENTA);
        Color::Modifier fg_cyan(Color::FG_CYAN);
        Color::Modifier fg_lgray(Color::FG_LGRAY);
        Color::Modifier fg_dgray(Color::FG_DGRAY);
        Color::Modifier fg_lred(Color::FG_LRED);
        Color::Modifier fg_lgreen(Color::FG_LGREEN);
        Color::Modifier fg_lyellow(Color::FG_LYELLOW);
        Color::Modifier fg_lblue(Color::FG_LBLUE);
        Color::Modifier fg_lmagenta(Color::FG_LMAGENTA);
        Color::Modifier fg_lcyan(Color::FG_LCYAN);
        Color::Modifier fg_white(Color::FG_WHITE);

        std::cout << std::endl;
        std::cout << fg_red     << "00" << "\t" << fg_green     << "01" << "\t" << fg_yellow << "02" << "\n"
                  << fg_blue    << "03" << "\t" << fg_magenta   << "04" << "\t" << fg_cyan   << "05" << "\n"
                  << fg_lgray   << "06" << "\t" << fg_dgray     << "07" << "\t" << fg_lred   << "08" << "\n"
                  << fg_lgreen  << "09" << "\t" << fg_lyellow   << "10" << "\t" << fg_lblue  << "11" << "\n"
                  << fg_lmagenta<< "12" << "\t" << fg_lcyan     << "13" << "\t" << fg_white  << "14" << "\n";


        std::cout << fg_def;
        std::cout << "\nCor da agenda (número correspondente): ";
        std::cin >> color;
        std::cin.ignore();

        switch(color){
        case 0:
            return fg_red;
        case 1:
            return fg_green;
        case 2:
            return fg_yellow;
        case 3:
            return fg_blue;
        case 4:
            return fg_magenta;
        case 5:
            return fg_cyan;
        case 6:
            return fg_lgray;
        case 7:
            return fg_dgray;
        case 8:
            return fg_lred;
        case 9:
            return fg_lgreen;
        case 10:
            return fg_lyellow;
        case 11:
            return fg_lblue;
        case 12:
            return fg_lmagenta;
        case 13:
            return fg_lcyan;
        case 14:
            return fg_white;
        default:
            return fg_white;
        }
    }

    void Tui::printFinancialVector(std::vector<std::pair<Date, int>> vector){
        Color::Modifier fg_def(Color::FG_DEFAULT);
        Color::Modifier fg_red(Color::FG_RED);
        Color::Modifier fg_green(Color::FG_GREEN);
        int totalBalance = 0;

        if(!vector.empty()){
            std::cout << "\nGastos:\n";
            for(auto v: vector) {
                if(rcColor){
                    if(v.second >= 0){
                        std::cout << fg_green;
                    } else{
                        std::cout << fg_red;
                    }
                }

                std::cout << std::setfill('0') << std::setw(2) << (int)v.first.hour << ":" 
                          << std::setfill('0') << std::setw(2) << (int)v.first.minute << " "
                          << std::setfill('0') << std::setw(2) << (int)v.first.day << "/"
                          << std::setfill('0') << std::setw(2) << (int)v.first.month << "/"
                          << std::setfill('0') << std::setw(2) << (int)v.first.year << "  "
                          << v.second
                << std::endl;
                std::cout << fg_def;
                totalBalance += v.second;
            }

            std::cout << "Balanço total deste período: ";
            if(rcColor){
                if(totalBalance >= 0){
                    std::cout << fg_green;
                } else{
                    std::cout << fg_red;
                }
            }
            std::cout << totalBalance << fg_def << std::endl;
        } else{
            std::cout << "Não houveram gastos neste período: ";
        }

        std::cout << "\nPressione qualquer tecla para continuar";
        fflush(stdout);
        system("read -n 1");
        std::cout << std::endl;
    }

} /* namespace agenda */
