/*******************************************************************************
 * Copyright (c) 2018 Eight Pillars Ltd.
 *
 * This file is part of the NMTRAN Parser.
 *
 * The NMTRAN Parser is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * The NMTRAN Parser Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with The NMTRAN Parser.  If not, see <http://www.gnu.org/licenses/>.
 *******************************************************************************/
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
