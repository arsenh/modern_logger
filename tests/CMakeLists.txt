project(logger_tests)

add_executable(logger_corner_cases_tests logger_corner_cases_tests.cpp)

add_test(NAME logger_corner_cases_tests COMMAND logger_corner_cases_tests)

target_link_libraries(logger_corner_cases_tests logger gtest gtest_main)
