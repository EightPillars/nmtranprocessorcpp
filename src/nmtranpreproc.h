//
// Created by Stuart Moodie on 14/03/2018.
//

#ifndef NMTRANPREPROC_NMTRANPREPROC_H
#define NMTRANPREPROC_NMTRANPREPROC_H


#include <ostream>
#include <regex>

class nmtranpreproc {
    const std::regex option_pattern;
    const std::regex problem_pattern;
    const std::regex data_pattern;


    static std::string buildPattern(std::string prefix, std::vector<std::string> &nameList, std::string suffix);

public:
    nmtranpreproc();
    void preprocess(std::istream& bin, std::ostream& bout);

    std::string processLine(std::string line, std::regex pat, std::string replacementStr);
};


#endif //NMTRANPREPROC_NMTRANPREPROC_H
