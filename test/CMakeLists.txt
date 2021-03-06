# Copyright (c) 2018 Eight Pillars Ltd.
#
# This file is part of the NMTRAN Parser.
# The NMTRAN Parser is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# The NMTRAN Parser Library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with The NMTRAN Parser.  If not, see <http://www.gnu.org/licenses/>.

find_package (Boost COMPONENTS system filesystem unit_test_framework REQUIRED)


#LIST( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )
#
## set variable pointing to the antlr tool that supports C++
#set(ANTLR4CPP_JAR_LOCATION ${PROJECT_SOURCE_DIR}/thirdparty/antlr/antlr-4.7.1-complete.jar)
## add external build for antlrcpp
#include( ExternalAntlr4Cpp )

include_directories( ${ANTLR4CPP_INCLUDE_DIRS} )
link_directories( ${ANTLR4CPP_LIBS} )

include_directories (
        ${CMAKE_SOURCE_DIR}/src
        ${Boost_INCLUDE_DIRS}
        )
include_directories(${CMAKE_SOURCE_DIR}/antlr4cpp_generated_src/nmtranparserns)

set(CMAKE_DEBUG_TARGET_PROPERTIES
        INCLUDE_DIRECTORIES
        COMPILE_DEFINITIONS
        POSITION_INDEPENDENT_CODE
        CONTAINER_SIZE_REQUIRED
        LIB_VERSION
        )

add_definitions (-DBOOST_TEST_DYN_LINK)

add_executable (Test module.cpp nmtranpreproctest.cpp nmtranparsertest.cpp module.cpp)

target_link_libraries (Test
        nmtranparserlib
        antlr4-runtime
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

configure_file(test_example.ctl ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(expected_processed_nm.ctl ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)