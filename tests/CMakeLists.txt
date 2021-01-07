project(logger_unit_tests)

add_executable(logger_messages_tests logger_messages_tests.cpp)
add_test(NAME logger_messages_tests COMMAND logger_messages_tests)
target_link_libraries(logger_messages_tests logger gtest gtest_main)


add_executable(logger_data_types_tests logger_data_types_tests.cpp)
add_test(NAME logger_data_types_tests COMMAND logger_data_types_tests)
target_link_libraries(logger_data_types_tests logger gtest gtest_main)


add_executable(logger_levels_tests logger_levels_tests.cpp)
add_test(NAME logger_levels_tests COMMAND logger_levels_tests)
target_link_libraries(logger_levels_tests logger gtest gtest_main)


add_executable(logger_corner_cases_tests logger_corner_cases_tests.cpp)
add_test(NAME logger_corner_cases_tests COMMAND logger_corner_cases_tests)
target_link_libraries(logger_corner_cases_tests logger gtest gtest_main)
