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

