//
// Created by Stuart Moodie on 13/03/2018.
//

#define BOOST_TEST_MODULE SqrTests
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <fstream>
#include <nmtranpreproc.h>
#include <boost/filesystem.hpp>
#include <boost/filesystem.hpp>


#include "sqr.h"

void compareFiles(std::string expected, std::string actual){
    std::ifstream file1(expected);
    std::ifstream file2(actual);
    std::string string1;
    std::string string2;
    int j =0;
    int mismatches = 0;
    while(!file1.eof())
    {
        std::getline(file1, string1);
        std::getline(file2, string2);
        j++;
        if(string1 != string2){
//            std::string msg();
            BOOST_TEST(string1 == string2, "Mismatch at line: " + std::to_string(j));
            mismatches++;
            std::cout << "Expect: " << string1 << std::endl;
            std::cout << "Actual: " << string2 << std::endl;
        }
    }
    BOOST_TEST(0 == mismatches, "File comparison");
}


BOOST_AUTO_TEST_CASE(FailTest)
{
    sqr s(2);
    BOOST_CHECK_NE(5, s.get());
}

BOOST_AUTO_TEST_CASE(PassTest)
{
    sqr s(2);
    BOOST_CHECK_EQUAL(4, s.get());
}

BOOST_AUTO_TEST_CASE(PreprocTest)
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

//    std::ifstream tmpStr(temp.native());
//    std::cout<< "tempfile=" << boost::filesystem::temp_directory_path() / temp.native()<<std::endl;
//    std::ifstream xpxt_st("expected_processed_nm.ctl");
//    BOOST_REQUIRE_EQUAL(true, xpxt_st.is_open());
//    BOOST_REQUIRE_EQUAL(true, tmpStr.is_open());
//    std::istream_iterator<char> b1(xpxt_st), e1;
//    std::istream_iterator<char> b2(tmpStr), e2;
    compareFiles("expected_processed_nm.ctl", temp.native());
//    BOOST_CHECK_EQUAL_COLLECTIONS(b1, e1, b2, e2);
}
