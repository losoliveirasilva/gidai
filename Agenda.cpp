#include "Agenda.h"

namespace agenda {

namespace {

bool compare(const std::pair<Date, Entry>& lhs, Date rhs){
    return lhs.first < rhs;
}

}

    Agenda::Agenda(Color::Modifier fg_color):
        fg_color{fg_color}
    {}

    void Agenda::pushEntry(Date date, Entry entry){
        entries.emplace(date, entry);
    }

    std::vector<std::pair<Date, Entry>> Agenda::getEntries(Date date_lower, Date date_upper){
        auto first = std::lower_bound(entries.begin(), entries.end(), date_lower, compare);
        auto last = std::lower_bound(first, entries.end(), date_upper, compare);
        auto c = std::vector<std::pair<Date, Entry>>{};
        for (auto it = first; it != last; ++it) { 
            c.push_back(*it);
        }
        return c;
    }

} /* namespace agenda */
