project(logger_unit_tests)

add_executable(logger_tests logger_tests.cpp)

add_test(NAME logger_tests COMMAND logger_tests)

target_link_libraries(logger_tests logger gtest gtest_main)
