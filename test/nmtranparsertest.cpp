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
// Created by Stuart Moodie on 13/03/2018.
//

//#define BOOST_TEST_MODULE ParserTests
#include <iostream>
#include <fstream>
#include "nmtranpreproc.h"
#include <boost/filesystem.hpp>
#include "antlr4-runtime.h"
#include "NmtranParser.h"
#include "NmtranLexer.h"
#include <boost/test/unit_test.hpp>
#include <NmtranParserBaseListener.h>


class MyParserListener : public nmtranparserns::NmtranParserBaseListener {
private:
    std::string number{};

public:
    virtual void exitRealLiteral(nmtranparserns::NmtranParser::RealLiteralContext * ctx) override {
        if(ctx ->REAL() != nullptr) {
//            std::cout << ctx->REAL()->toString() << std::endl;
            number = ctx->REAL()->toString();
        }
        else if(ctx ->INT() != nullptr) {
//            std::cout << ctx->INT()->toString() << std::endl;
            number = ctx->INT()->toString();
        }
        else if(ctx -> SCIENTIFIC() != nullptr){
//            std::cout << ctx->SCIENTIFIC()->toString() << std::endl;
            number = ctx->SCIENTIFIC()->toString();
        }
    }

    const std::string &getNumber() const {
        return number;
    }


};

BOOST_AUTO_TEST_CASE(ParserTest)
{
//    boost::filesystem::path temp = boost::filesystem::unique_path();
//    std::ofstream ostr(temp.native());
    std::string f_name{"expected_processed_nm.ctl"};
    BOOST_REQUIRE_EQUAL(true, boost::filesystem::exists(f_name));
    std::ifstream istr{f_name};
    BOOST_REQUIRE_EQUAL(true, istr.is_open());
    antlr4::ANTLRInputStream input(istr);
    nmtranparserns::NmtranLexer lexer(&input);
    antlr4::CommonTokenStream charStream(&lexer);
    nmtranparserns::NmtranParser parser{&charStream};
    std::unique_ptr<MyParserListener> lsnr(new MyParserListener());
    parser.addParseListener(lsnr.get());
    auto tree = parser.nmModel();
    istr.close();
    auto lastNum = lsnr->getNumber();
    BOOST_CHECK_EQUAL("1.0", lastNum);

//    std::cout << tree->toStringTree(&parser) << std::endl << std::endl;

//    ostr.close();

//    compareFiles("expected_processed_nm.ctl", temp.native());
}

BOOST_AUTO_TEST_CASE(TmplTest)
{
//    boost::filesystem::path temp = boost::filesystem::unique_path();
//    std::ofstream ostr(temp.native());
    std::string f_name{"expected_processed_nm.ctl"};
    BOOST_REQUIRE_EQUAL(true, boost::filesystem::exists(f_name));
    std::ifstream istr{f_name};
    BOOST_REQUIRE_EQUAL(true, istr.is_open());
    antlr4::ANTLRInputStream input(istr);
    nmtranparserns::NmtranLexer lexer(&input);
    antlr4::CommonTokenStream charStream(&lexer);
    nmtranparserns::NmtranParser parser{&charStream};
    std::unique_ptr<MyParserListener> lsnr(new MyParserListener());
    parser.addParseListener(lsnr.get());
    auto tree = parser.nmModel();
    istr.close();
    auto lastNum = lsnr->getNumber();
    BOOST_CHECK_EQUAL("1.0", lastNum);

//    std::cout << tree->toStringTree(&parser) << std::endl << std::endl;

//    ostr.close();

//    compareFiles("expected_processed_nm.ctl", temp.native());
}
