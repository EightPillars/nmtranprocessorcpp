cmake_minimum_required(VERSION 3.9)
project(nmtranpreproc)

set(CMAKE_CXX_STANDARD 14)

LIST( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )

# set variable pointing to the antlr tool that supports C++
set(ANTLR4CPP_JAR_LOCATION ${PROJECT_SOURCE_DIR}/thirdparty/antlr/antlr-4.7.1-complete.jar)
# add external build for antlrcpp
include( ExternalAntlr4Cpp )


add_subdirectory(src)
add_subdirectory(test)

enable_testing()
add_test (NAME MyTest COMMAND Test)

