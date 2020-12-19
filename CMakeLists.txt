cmake_minimum_required(VERSION 3.8)

project(modern_logger)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/logger)

add_subdirectory(logger)
add_subdirectory(logger_demo)
add_subdirectory(googletest)
add_subdirectory(tests)
