#include <iostream>
#include <iomanip>
#include <numeric>
#include "Agenda.h"
//#include "Modifier.h"

int main(int argc, char **argv)
{
    auto a = agenda::Agenda{};
    auto date1 = agenda::Date(2017, 4, 18);
    auto entry1 = agenda::Entry("teste");
    auto entry2 = agenda::Entry("teste2");
    a.pushEntry(date1, entry1);
    a.pushEntry(date1, entry2);
    std::cout << a.getEntries({2017, 4, 18})[0].description << std::endl;
    std::cout << a.getEntries({2017, 4, 18})[1].description << std::endl;
    return 0;
}

