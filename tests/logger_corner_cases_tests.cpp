#include "logger.hpp"
#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include <streambuf>
#include <filesystem>

TEST(logger_corner_cases_test, logger_text) {
   
    namespace fs = std::filesystem;

    // arrange

    auto file_path = fs::current_path();
    file_path /= "logger_output.txt";

    std::fstream file{file_path.string(), std::ios::app};
    assert(file.is_open());

    logger::get().configure(logger::level::trace, file);
    std::string logger_text{ "Test message!" };
    
    // act
    logger::get().debug(logger_text);
    file.close();

    std::ifstream ifile{ file_path };
    std::string file_text{ std::istreambuf_iterator<char>(ifile),
                                std::istreambuf_iterator<char>() };
    fs::remove(file_path.string());
    
    // assert
    ASSERT_EQ("DEBUG: " + logger_text + "\n", file_text);
}
