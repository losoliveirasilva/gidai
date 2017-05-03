#include "agendalist.h"

namespace agenda {

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
        //sort(c.begin(), c.end());
        return c;
    }

    /*bool operator<(const std::tuple<Date, Entry, Color::Modifier>& lhs, const std::tuple<Date, Entry, Color::Modifier>& rhs){
        return std::get<0>(lhs) < std::get<0>(rhs);
    }*/


} /* namespace agenda */
