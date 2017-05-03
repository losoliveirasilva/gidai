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
    std::string description;

    Entry& operator=(const Entry& rhs) {
        description = rhs.description;
        return *this;
    }

};

}  /* namespace agenda */

#endif

