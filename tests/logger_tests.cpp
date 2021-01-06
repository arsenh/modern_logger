#include "logger.hpp"
#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include <streambuf>
#include <filesystem>


TEST(logger_tests, debug_message)
{
    namespace fs = std::filesystem;
    
    // arrange
    auto file_path = fs::current_path();
    file_path /= "logger_output.txt";

    std::fstream file{ file_path.string(), std::ios::app };
    assert(file.is_open());

    logger::get().configure(logger::level::trace, file);

    // act
    logger::get().debug("Debug message %", "value");
    
    // assert
    std::ifstream ifile{ file_path };
    std::string file_text{ std::istreambuf_iterator<char>(ifile),
                                std::istreambuf_iterator<char>() };
    fs::remove(file_path.string());
    ASSERT_EQ("DEBUG: Debug message value\n", file_text);
}


TEST(logger_tests, file_removed)
{
   
    namespace fs = std::filesystem;

    // arrange
    auto file_path = fs::current_path();
    file_path /= "logger_output.txt";

    std::fstream file{file_path.string(), std::ios::app};
    assert(file.is_open());

    logger::get().configure(logger::level::trace, file);
    
    // act
    fs::remove(file_path);

    // assert
    try {
        logger::get().debug("Debug message");
    } catch (const std::exception& ex) {
        ASSERT_EQ("Stream source unavailable.", ex.what());
    }
}
