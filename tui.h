#ifndef TUI_H
#define TUI_H

#include "features.h"

namespace agenda {

class Tui {

public:
    Tui() = default;
    void showHeader();
    void showMenu();
    Menu getOption();


private:

};

}  /* namespace agenda */

#endif

