project(logger_unit_tests)

if (WIN32)
    add_definitions(-DFILE_DISPOSITION_FLAG_POSIX_SEMANTICS -DFILE_DISPOSITION_FLAG_DELETE)
endif(WIN32)

add_executable(logger_tests logger_tests.cpp)

add_test(NAME logger_tests COMMAND logger_tests)

target_link_libraries(logger_tests logger gtest gtest_main)
