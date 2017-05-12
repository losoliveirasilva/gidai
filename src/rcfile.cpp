#include "rcfile.h"

namespace agenda {

    RCFile::RCFile(std::string filepath){
        std::ifstream infile(filepath);

        useStrikethrough = true;
        useColor = true;
        sortEntries = true;
        language = "pt_BR";

        if ((infile.rdstate() & std::ifstream::failbit) != 0){
            std::cerr << "Error opening '" << filepath << "'" << std::endl;
        } else{
            std::string line;
            while (std::getline(infile, line)){
                if (line.at(0) != '\"'){
                    std::istringstream is_line(line);
                    std::string key;
                    if (std::getline(is_line, key, '=')){
                        std::string value;
                        if (std::getline(is_line, value)){
                            try {
                                storeLine(key, value);
                            } catch (const std::logic_error& e) {
                                std::cout << e.what() << std::endl;
                            }
                        }
                    }
                }
            }
        }
    }

    bool parseBool(std::string value) {
        std::transform(value.begin(), value.end(), value.begin(), ::tolower);
        if (value == "false")
            return false;
        else if (value == "true")
            return true;
        
        std::ostringstream ss;
        ss << "Error parsing value " << value << ".";
        throw std::logic_error(ss.str());

    }

    void RCFile::storeLine(std::string key, std::string value){
        if (key.compare("useStrikethrough") == 0){
            useStrikethrough = parseBool(value);
        } else if (key.compare("useColor") == 0){
            useColor = parseBool(value);
        } else if (value.compare("language") == 0){
            language = value;
        } else if (key.compare("sortEntries") == 0){
            sortEntries = parseBool(value);
        }
    }

} /* namespace agenda */
