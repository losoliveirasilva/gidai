#ifndef ENTRY_H
#define ENTRY_H

#include <string>

namespace agenda {

class Entry
{

public:
    Entry(std::string description):
        description{description} {}
    Entry(const Entry&) = default;
    Entry(Entry&&) = default;
    const std::string description;

};

}  /* namespace agenda */

#endif

