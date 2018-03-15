//
// Created by Stuart Moodie on 13/03/2018.
//

//#define BOOST_TEST_MODULE ParserTests
#include <iostream>
#include <fstream>
#include "nmtranpreproc.h"
#include <boost/filesystem.hpp>
#include "NmtranParser.h"
#include "NmtranLexer.h"
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE(ParserTest)
{
    boost::filesystem::path temp = boost::filesystem::unique_path();
    std::ofstream ostr(temp.native());
    std::string f_name("test_example.ctl");
    BOOST_REQUIRE_EQUAL(true, boost::filesystem::exists(f_name));
    std::ifstream istr(f_name);
    BOOST_REQUIRE_EQUAL(true, istr.is_open());
    nmtranpreproc testInstance = nmtranpreproc();
    testInstance.preprocess(istr, ostr);
    istr.close();
    ostr.close();

//    compareFiles("expected_processed_nm.ctl", temp.native());
}
