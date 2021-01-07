#include "logger.hpp"
#include <gtest/gtest.h>
#include <string>
#include <fstream>
#include <streambuf>
#include <filesystem>
#include <cassert>

TEST(logger_messages_tests, none_message)
{
    namespace fs = std::filesystem;

    // arrange
    const std::string file_name = "logger_output.txt";
    std::ofstream logger_file{ file_name, std::ios::trunc };
    assert(logger_file.is_open());
    const std::string text = "This is a % message.";

    logger::get().configure(logger::level::none, logger_file);

    // act
    logger::get().fatal(text, "fatal");
    logger_file.close();

    // assert
    std::ifstream ifile{ file_name };
    ifile.is_open();

    const std::string file_text{ std::istreambuf_iterator<char>(ifile),
                                    std::istreambuf_iterator<char>() };
    ifile.close();
    fs::remove(file_name);

    ASSERT_EQ(file_text, "");
}

TEST(logger_messages_tests, fatal_message)
{
    namespace fs = std::filesystem;

    // arrange
    const std::string file_name = "logger_output.txt";
    std::ofstream logger_file{ file_name, std::ios::trunc };
    assert(logger_file.is_open());
    const std::string text = "This is a % message.";
    const std::string golden = "FATAL: This is a fatal message.\n";
        
    logger::get().configure(logger::level::fatal, logger_file);

    // act
    logger::get().fatal(text, "fatal");
    logger_file.close();

    // assert
    std::ifstream ifile{ file_name };
    ifile.is_open();

    const std::string file_text{ std::istreambuf_iterator<char>(ifile),
                                    std::istreambuf_iterator<char>() };
    ifile.close();
    fs::remove(file_name);

    ASSERT_EQ(file_text, golden);
}

TEST(logger_messages_tests, critical_message)
{
    namespace fs = std::filesystem;

    // arrange
    const std::string file_name = "logger_output.txt";
    std::ofstream logger_file{ file_name, std::ios::trunc };
    assert(logger_file.is_open());
    const std::string text = "This is a % message.";
    const std::string golden = "CRITICAL: This is a critical message.\n";

    logger::get().configure(logger::level::critical, logger_file);

    // act
    logger::get().critical(text, "critical");
    logger_file.close();

    // assert
    std::ifstream ifile{ file_name };
    ifile.is_open();

    const std::string file_text{ std::istreambuf_iterator<char>(ifile),
                                    std::istreambuf_iterator<char>() };
    ifile.close();
    fs::remove(file_name);

    ASSERT_EQ(file_text, golden);
}

TEST(logger_messages_tests, error_message)
{
    namespace fs = std::filesystem;

    // arrange
    const std::string file_name = "logger_output.txt";
    std::ofstream logger_file{ file_name, std::ios::trunc };
    assert(logger_file.is_open());
    const std::string text = "This is a % message.";
    const std::string golden = "ERROR: This is a error message.\n";

    logger::get().configure(logger::level::error, logger_file);

    // act
    logger::get().error(text, "error");
    logger_file.close();

    // assert
    std::ifstream ifile{ file_name };
    ifile.is_open();

    const std::string file_text{ std::istreambuf_iterator<char>(ifile),
                                    std::istreambuf_iterator<char>() };
    ifile.close();
    fs::remove(file_name);

    ASSERT_EQ(file_text, golden);
}

TEST(logger_messages_tests, warning_message)
{
    namespace fs = std::filesystem;

    // arrange
    const std::string file_name = "logger_output.txt";
    std::ofstream logger_file{ file_name, std::ios::trunc };
    assert(logger_file.is_open());
    const std::string text = "This is a % message.";
    const std::string golden = "WARNING: This is a warning message.\n";

    logger::get().configure(logger::level::warning, logger_file);

    // act
    logger::get().warning(text, "warning");
    logger_file.close();

    // assert
    std::ifstream ifile{ file_name };
    ifile.is_open();

    const std::string file_text{ std::istreambuf_iterator<char>(ifile),
                                    std::istreambuf_iterator<char>() };
    ifile.close();
    fs::remove(file_name);

    ASSERT_EQ(file_text, golden);
}

TEST(logger_messages_tests, notice_message)
{
    namespace fs = std::filesystem;

    // arrange
    const std::string file_name = "logger_output.txt";
    std::ofstream logger_file{ file_name, std::ios::trunc };
    assert(logger_file.is_open());
    const std::string text = "This is a % message.";
    const std::string golden = "NOTICE: This is a notice message.\n";

    logger::get().configure(logger::level::notice, logger_file);

    // act
    logger::get().notice(text, "notice");
    logger_file.close();

    // assert
    std::ifstream ifile{ file_name };
    ifile.is_open();

    const std::string file_text{ std::istreambuf_iterator<char>(ifile),
                                    std::istreambuf_iterator<char>() };
    ifile.close();
    fs::remove(file_name);

    ASSERT_EQ(file_text, golden);
}

TEST(logger_messages_tests, information_message)
{
    namespace fs = std::filesystem;

    // arrange
    const std::string file_name = "logger_output.txt";
    std::ofstream logger_file{ file_name, std::ios::trunc };
    assert(logger_file.is_open());
    const std::string text = "This is a % message.";
    const std::string golden = "INFORMATION: This is a information message.\n";

    logger::get().configure(logger::level::information, logger_file);

    // act
    logger::get().information(text, "information");
    logger_file.close();

    // assert
    std::ifstream ifile{ file_name };
    ifile.is_open();

    const std::string file_text{ std::istreambuf_iterator<char>(ifile),
                                    std::istreambuf_iterator<char>() };
    ifile.close();
    fs::remove(file_name);

    ASSERT_EQ(file_text, golden);
}

TEST(logger_messages_tests, debug_message)
{
    namespace fs = std::filesystem;

    // arrange
    const std::string file_name = "logger_output.txt";
    std::ofstream logger_file{ file_name, std::ios::trunc };
    assert(logger_file.is_open());
    const std::string text = "This is a % message.";
    const std::string golden = "DEBUG: This is a debug message.\n";

    logger::get().configure(logger::level::debug, logger_file);
    
    // act
    logger::get().debug(text, "debug");
    logger_file.close();

    // assert
    std::ifstream ifile{ file_name };
    ifile.is_open();

    const std::string file_text{ std::istreambuf_iterator<char>(ifile),
                                    std::istreambuf_iterator<char>() };
    ifile.close();
    fs::remove(file_name);

    ASSERT_EQ(file_text, golden);
}

TEST(logger_messages_tests, trace_message)
{
    namespace fs = std::filesystem;

    // arrange
    const std::string file_name = "logger_output.txt";
    std::ofstream logger_file{ file_name, std::ios::trunc };
    assert(logger_file.is_open());
    const std::string text = "This is a % message.";
    const std::string golden = "TRACE: This is a trace message.\n";

    logger::get().configure(logger::level::trace, logger_file);

    // act
    logger::get().trace(text, "trace");
    logger_file.close();

    // assert
    std::ifstream ifile{ file_name };
    ifile.is_open();

    const std::string file_text{ std::istreambuf_iterator<char>(ifile),
                                    std::istreambuf_iterator<char>() };
    ifile.close();
    fs::remove(file_name);

    ASSERT_EQ(file_text, golden);
}

/*
TEST(logger_tests, logger_level)
{
    ASSERT_EQ(1, 1);
}

TEST(logger_tests, custom_object)
{
    ASSERT_EQ(1, 1);
}
*/