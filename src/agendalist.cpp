#include "agendalist.h"

namespace agenda {

    AgendaList::AgendaList(bool sortEntries):
        sortEntries{sortEntries}
    {}

    void AgendaList::addAgenda(Agenda agenda){
        agendas.push_back(agenda);
    }

    std::vector<std::tuple<Date, Entry, Color::Modifier>> AgendaList::getEntries(Date date_lower, Date date_upper){
        auto c = std::vector<std::tuple<Date, Entry, Color::Modifier>>{};
        for(auto as: agendas){
            for(auto a: as.getEntries(date_lower, date_upper)){
                c.push_back(std::make_tuple(a.first, a.second, as.fg_color));
            }
        }

        if(sortEntries)
            sort(c.begin(), c.end(),
                [](std::tuple<Date, Entry, Color::Modifier> const &t1, std::tuple<Date, Entry, Color::Modifier> const &t2) {
                    return std::get<0>(t1) < std::get<0>(t2);
                }
            );

        return c;
    }

} /* namespace agenda */
