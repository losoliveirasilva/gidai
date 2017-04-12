#include "Agenda.h"

namespace agenda {

    void Agenda::pushEntry(Date date, Entry entry){
        entries.emplace(date, entry);
    }

    std::vector<Entry> Agenda::getEntries(Date date){
        auto range = entries.equal_range(date);
        //return std::vector<Entry>(range.first, range.second);
        return {};
    }

} /* namespace agenda */

