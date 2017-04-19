#include <iostream>
#include <iomanip>
#include <numeric>
#include "Agenda.h"
//#include "Modifier.h"

int main(int argc, char **argv)
{
    auto a = agenda::Agenda{};
    a.pushEntry(agenda::Date(2017, 4, 10, 10, 5), agenda::Entry("teste0"));
    a.pushEntry(agenda::Date(2017, 6, 8, 18, 30), agenda::Entry("teste1"));
    a.pushEntry(agenda::Date(2017, 4, 15, 8, 20), agenda::Entry("teste2"));

    for(auto v: a.getEntries({2017, 3, 18, 0, 0}, {2018, 6, 8, 0, 0})){
        std::cout << v.description << std::endl;
    }

    return 0;
}

