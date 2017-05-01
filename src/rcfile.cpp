#include "rcfile.h"

namespace agenda {

    RCFile::RCFile(std::string filepath){
        std::ifstream infile(filepath);
        if((infile.rdstate() & std::ifstream::failbit) != 0)
            std::cerr << "Error opening '" << filepath << "'" << std::endl;

        useStrikethrough = true;
        useColor = true;
        language = "pt_BR";

        std::string line;
        while(std::getline(infile, line)){
            if(line.at(0) != '\"'){
                std::istringstream is_line(line);
                std::string key;
                if(std::getline(is_line, key, '=')){
                    std::string value;
                    if(std::getline(is_line, value)){
                        storeLine(key, value);
                    }
                }
            }
        }
    }

    void RCFile::storeLine(std::string key, std::string value){
        if(key.compare("useStrikethrough") == 0){
            useStrikethrough = (value.compare("false") == 0) ? false : true;
        } else if(key.compare("useColor") == 0){
            useColor = (value.compare("false") == 0) ? false : true;
        } else if(value.compare("language") == 0){
            language = value;
        }
    }

} /* namespace agenda */
