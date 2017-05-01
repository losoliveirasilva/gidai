#ifndef FEATURES_H
#define FEATURES_H

#include <string>
#include <iostream>

namespace agenda {

enum Menu
{
    EXIT,
    ADD_ENTRY,
    CREATE_AGENDA,
    VIEW_TODAY_ENTRIES,
    VIEW_MONTH_ENTRIES,
    VIEW_SPECIFIC_DAY,
    VIEW_SPECIFIC_MONTH,
    MENU_NUM
};

class Features {

 public:
    std::string menuString(int menu){
        switch(menu){
            case EXIT:
                return "Sair";
            case ADD_ENTRY:
                return "Adicionar compromisso";
            case CREATE_AGENDA:
                return "Criar agenda";
            case VIEW_TODAY_ENTRIES:
                return "Ver os compromissos de hoje";
            case VIEW_MONTH_ENTRIES:
                return "Ver os compromissos desse mês";
            case VIEW_SPECIFIC_DAY:
                return "Ver os compromissos de um dia específico";
            case VIEW_SPECIFIC_MONTH:
                return "Ver os compromissos de um mês específico";
            default:
                return "ERROR";
        }
    }

};

}  /* namespace agenda */

#endif

