#ifndef FINANCIAL_H
#define FINANCIAL_H

#include <map>
#include <vector>
#include <algorithm>
#include "date.h"

namespace agenda {

namespace {

bool compare(const std::pair<Date, int>& lhs, Date rhs){
    return lhs.first < rhs;
}

}

class Financial {

public:
    Financial() = default;

    void pushEntry(Date date, int value){
        entries.emplace(date, value);
    }

    std::vector<std::pair<Date, int>> getEntries(Date date_lower, Date date_upper){
        auto first = std::lower_bound(entries.begin(), entries.end(), date_lower, compare);
        auto last = std::lower_bound(first, entries.end(), date_upper, compare);
        auto c = std::vector<std::pair<Date, int>>{};
        for (auto it = first; it != last; ++it) { 
            c.push_back(*it);
        }
        sort(c.begin(), c.end());
        return c;
    }

    int getBalance(std::vector<std::pair<Date, int>> vector){
        int balance;
        for(auto v: vector){
            balance += v.second;
        }
        return balance;
    }

private:
    std::multimap<Date, int> entries;

};

}  /* namespace agenda */

#endif

