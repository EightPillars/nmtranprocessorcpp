//
// Created by Stuart Moodie on 14/03/2018.
//

#include <sstream>
#include <string>
#include <iostream>

#include "nmtranpreproc.h"

using namespace std;

static vector<string> OPTION_KWDS = {
        "FILE", "IGNORE", "GRD", "MSFO", "FORMAT", "METHOD"
};
static vector<string> DATA_LIKE_BLOCKS = {
        "DAT\\w*", "MSF\\w*"
};



nmtranpreproc::nmtranpreproc() : option_pattern(buildPattern("((?:", OPTION_KWDS, ")\\s*=\\s*)(\\S+)")),
                                problem_pattern("(\\$PRO\\w*\\s+)(.+\\b)(\\s*)$"),
                                data_pattern(buildPattern("(\\$(?:", DATA_LIKE_BLOCKS, ")\\s+)\"?([^\" \\t\\n\\r]+)\"?"))
{

}

void nmtranpreproc::preprocess(std::istream& infile, std::ostream& bout){
    std::string line;
    while (std::getline(infile, line))
    {
        std::string result = processLine(processLine(processLine(line, option_pattern, "$1\"$2\""),
                                                     problem_pattern, "$1\"$2\"$3"),
                                                    data_pattern, "$1\"$2\"");
        bout << result << std::endl;
//        std::cout << result << std::endl;
    }
}


string nmtranpreproc::buildPattern(string prefix, vector<string>& nameList, string suffix){
    string buf(prefix);
    for(int i = 0; i < nameList.size(); i++){
        buf.append(nameList[i]);
        if(i < nameList.size() - 1){
            buf.append("|");
        }
    }
    buf.append(suffix);
    return buf;
}

string nmtranpreproc::processLine(string line, regex pat, string replacementStr) {
    if(std::regex_search(line, pat)){
        std::string retval = std::regex_replace(line, pat, replacementStr, std::regex_constants::match_any);
//        std:cout << "Matched: " << retval << std::endl;
        return retval;
    }
    else{
        return line;
    }
}
