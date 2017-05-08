#ifndef AGENDALIST_H
#define AGENDALIST_H

#include <vector>
#include "agenda.h"

namespace agenda {

class AgendaList {

public:
    AgendaList(bool sortEntries);
    void addAgenda(Agenda agenda);
    std::vector<std::tuple<Date, std::string, Color::Modifier>> getEntries(Date date_lower, Date date_upper);

    std::vector<Agenda> agendas;

private:
    bool sortEntries;

};

}  /* namespace agenda */

#endif

