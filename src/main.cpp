#include <iostream>
#include <fstream>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem.hpp>
#include "nmtranpreproc.h"

int main() {
    boost::filesystem::path temp = boost::filesystem::unique_path();
    std::ofstream ostr(temp.native());
    std::string f_name("test_example.ctl");
    std::ifstream istr(f_name);

    nmtranpreproc preproc = nmtranpreproc();
    preproc.preprocess(istr, ostr);
}