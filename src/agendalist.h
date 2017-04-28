#ifndef AGENDALIST_H
#define AGENDALIST_H

#include <vector>
#include "agenda.h"

namespace agenda {

class AgendaList {

public:
    AgendaList() = default;
    void addAgenda(Agenda agenda);
    std::vector<std::tuple<Date, Entry, Color::Modifier>> getEntries(Date date_lower, Date date_upper);

    std::vector<Agenda> agendas;

};

}  /* namespace agenda */

#endif

