#include "Agenda.h"

namespace agenda {

    void Agenda::pushEntry(Date date, Entry entry){
        entries.emplace(date, entry);
    }

    std::vector<Entry> Agenda::getEntries(Date date){
        auto c = std::vector<Entry>{};
        auto range = entries.equal_range(date);
        for (auto it = range.first; it != range.second; ++it) { 
            c.push_back(it->second);
        }
        return c;
    }

} /* namespace agenda */

