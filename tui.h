#ifndef TUI_H
#define TUI_H

#include "features.h"
#include "date.h"
#include <string>
#include <vector>
#include <iomanip>
#include "entry.h"
#include "modifier.h"

namespace agenda {

class Tui {

public:
    Tui() = default;
    void showHeader();
    int showMenu();
    void showGoodbye();
    agenda::Date getTimeDate();
    agenda::Date getDate();
    agenda::Date getMonth();
    std::string getText(std::string s);
    void printEntriesVector(std::vector<std::tuple<Date, Entry, Color::Modifier>> vector);


private:

};

}  /* namespace agenda */

#endif

