#ifndef AGENDA_H
#define AGENDA_H

#include <map>
#include <vector>
#include <algorithm>
#include "date.h"
#include "entry.h"
#include "modifier.h"

namespace agenda {

class Agenda {

public:
    Agenda() = default;
    Agenda(Color::Modifier fg_color);
    void pushEntry(Date date, Entry entry);
    std::vector<std::pair<Date, Entry>> getEntries(Date date_lower, Date date_upper);
    Color::Modifier fg_color;

private:
    std::multimap<Date, Entry> entries;

};

}  /* namespace agenda */

#endif

