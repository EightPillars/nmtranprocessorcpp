find_package (Boost COMPONENTS system filesystem REQUIRED)

#LIST( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )

## compiler must be 11 or 14
#SET (CMAKE_CXX_STANDARD 11)

## set variable pointing to the antlr tool that supports C++
#set(ANTLR4CPP_JAR_LOCATION ${PROJECT_SOURCE_DIR}/thirdparty/antlr/antlr-4.7.1-complete.jar)
## add external build for antlrcpp
#include( ExternalAntlr4Cpp )

# add antrl4cpp artifacts to project environment
include_directories( ${ANTLR4CPP_INCLUDE_DIRS} )
link_directories( ${ANTLR4CPP_LIBS} )
message(STATUS "Found antlr4cpp libs: ${ANTLR4CPP_LIBS} and includes: ${ANTLR4CPP_INCLUDE_DIRS} ")

message(STATUS "Inclide dir: ${antlr4cpp_include_dirs_nmtranparser}")

set(CMAKE_DEBUG_TARGET_PROPERTIES
        INCLUDE_DIRECTORIES
        COMPILE_DEFINITIONS
        POSITION_INDEPENDENT_CODE
        CONTAINER_SIZE_REQUIRED
        LIB_VERSION
        )

# Call macro to add lexer and grammar to your build dependencies.
antlr4cpp_process_grammar(nmtranparser nmtranparserns
        ${CMAKE_SOURCE_DIR}/grammar/NmtranLexer.g4
        ${CMAKE_SOURCE_DIR}/grammar/NmtranParser.g4)
# include generated files in project environment
include_directories(${antlr4cpp_include_dirs_nmtranparserns})

include_directories (
        ${Boost_INCLUDE_DIRS}
        )

add_definitions (-DBOOST_TEST_DYN_LINK)

set(SOURCE_FILES main.cpp nmtranpreproc.cpp nmtranpreproc.h)

add_library (nmtranparserlib ${SOURCE_FILES} ${antlr4cpp_src_files_nmtranparserns})

add_executable (nmtranparser ${SOURCE_FILES} ${antlr4cpp_src_files_nmtranparserns})

add_dependencies(nmtranparser nmtranparser antlr4cpp_generation_nmtranparserns)

target_link_libraries (nmtranparser
        antlr4-runtime
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        )

