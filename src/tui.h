#ifndef TUI_H
#define TUI_H

#include "features.h"
#include "date.h"
#include <string>
#include <vector>
#include <iomanip>
#include "entry.h"
#include "modifier.h"
#include "agenda.h"
#include <ctime>

namespace agenda {

class Tui {

public:
    Tui(bool rcColor, bool rcStrikethrough);
    void showHeader();
    int showMenu();
    agenda::Date getTimeDate();
    agenda::Date getDate();
    agenda::Date getMonth();
    std::string getText(std::string s);
    int getInt(std::string s);
    void printEntriesVector(std::vector<std::tuple<Date, Entry, Color::Modifier>> vector);
    void printAgendaList(std::vector<Agenda> agendas, bool showNum);
    Color::Modifier getColor();


private:

    bool rcColor;
    bool rcStrikethrough;

};

}  /* namespace agenda */

#endif
