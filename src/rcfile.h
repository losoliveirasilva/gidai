#ifndef RC_H
#define RC_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

namespace agenda {

class RCFile {

public:
    RCFile(std::string filepath);

    bool useStrikethrough;
    bool useColor;
    bool sortEntries;
    std::string language;

private:
    void storeLine(std::string key, std::string value);

};

}  /* namespace agenda */

#endif
