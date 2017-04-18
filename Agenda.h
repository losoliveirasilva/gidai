#ifndef AGENDA_H
#define AGENDA_H

#include <map>
#include <vector>
#include <algorithm>
#include "Date.h"
#include "Entry.h"

namespace agenda {

class Agenda {

public:
    Agenda() = default;
    void pushEntry(Date date, Entry entry);
    std::vector<Entry> getEntries(Date date);
    std::vector<Entry> getEntries(Date date_lower, Date date_upper);

private:
    std::multimap<Date, Entry> entries;

};

}  /* namespace agenda */

#endif

