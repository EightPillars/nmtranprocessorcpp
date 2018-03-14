find_package (Boost COMPONENTS system filesystem unit_test_framework REQUIRED)
include_directories (${TEST_SOURCE_DIR}/src
        ${Boost_INCLUDE_DIRS}
        ../src
        )

add_definitions (-DBOOST_TEST_DYN_LINK)

add_executable (Test nmtranpreproctest.cpp)

target_link_libraries (Test
        Sqr
        ${Boost_FILESYSTEM_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

configure_file(test_example.ctl ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(expected_processed_nm.ctl ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)