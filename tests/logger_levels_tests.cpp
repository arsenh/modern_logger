#include "logger.hpp"
#include <gtest/gtest.h>

#include <filesystem>
#include <fstream>

TEST(logger_levels_tests, none_level)
{
    namespace fs = std::filesystem;

    // arrange
    const std::string file_name = "logger_output.txt";
    std::ofstream logger_file{ file_name, std::ios::trunc };
    assert(logger_file.is_open());

    logger::get().configure(logger::level::none, logger_file);

    // act
    logger::get().fatal("fatal message.");
    logger::get().critical("critical message.");
    logger::get().error("error message.");
    logger::get().warning("warning message.");
    logger::get().notice("notice message.");
    logger::get().information("information message.");
    logger::get().debug("debug message.");
    logger::get().trace("trace message.");
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

TEST(logger_levels_tests, fatal_level)
{
    namespace fs = std::filesystem;

    // arrange
    const std::string file_name = "logger_output.txt";
    std::ofstream logger_file{ file_name, std::ios::trunc };
    assert(logger_file.is_open());

    logger::get().configure(logger::level::fatal, logger_file);

    // act
    logger::get().fatal("fatal message.");
    logger::get().critical("critical message.");
    logger::get().error("error message.");
    logger::get().warning("warning message.");
    logger::get().notice("notice message.");
    logger::get().information("information message.");
    logger::get().debug("debug message.");
    logger::get().trace("trace message.");
    logger_file.close();

    // assert
    std::ifstream ifile{ file_name };
    ifile.is_open();

    const std::string file_text{ std::istreambuf_iterator<char>(ifile),
                                    std::istreambuf_iterator<char>() };
    ifile.close();
    fs::remove(file_name);

    ASSERT_EQ(file_text, "FATAL: fatal message.\n");
}

TEST(logger_levels_tests, critical_level)
{
    namespace fs = std::filesystem;

    // arrange
    const std::string file_name = "logger_output.txt";
    std::ofstream logger_file{ file_name, std::ios::trunc };
    assert(logger_file.is_open());

    logger::get().configure(logger::level::critical, logger_file);

    const std::string golden = std::string("FATAL: fatal message.\n") 
                        + std::string("CRITICAL: critical message.\n");

    // act
    logger::get().fatal("fatal message.");
    logger::get().critical("critical message.");
    logger::get().error("error message.");
    logger::get().warning("warning message.");
    logger::get().notice("notice message.");
    logger::get().information("information message.");
    logger::get().debug("debug message.");
    logger::get().trace("trace message.");
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

TEST(logger_levels_tests, error_level)
{
    namespace fs = std::filesystem;

    // arrange
    const std::string file_name = "logger_output.txt";
    std::ofstream logger_file{ file_name, std::ios::trunc };
    assert(logger_file.is_open());

    logger::get().configure(logger::level::error, logger_file);

    const std::string golden = std::string("FATAL: fatal message.\n")
        + std::string("CRITICAL: critical message.\n")
        + std::string("ERROR: error message.\n");

    // act
    logger::get().fatal("fatal message.");
    logger::get().critical("critical message.");
    logger::get().error("error message.");
    logger::get().warning("warning message.");
    logger::get().notice("notice message.");
    logger::get().information("information message.");
    logger::get().debug("debug message.");
    logger::get().trace("trace message.");
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

TEST(logger_levels_tests, warning_level)
{
    namespace fs = std::filesystem;

    // arrange
    const std::string file_name = "logger_output.txt";
    std::ofstream logger_file{ file_name, std::ios::trunc };
    assert(logger_file.is_open());

    logger::get().configure(logger::level::warning, logger_file);

    const std::string golden = std::string("FATAL: fatal message.\n")
        + std::string("CRITICAL: critical message.\n")
        + std::string("ERROR: error message.\n")
        + std::string("WARNING: warning message.\n");

    // act
    logger::get().fatal("fatal message.");
    logger::get().critical("critical message.");
    logger::get().error("error message.");
    logger::get().warning("warning message.");
    logger::get().notice("notice message.");
    logger::get().information("information message.");
    logger::get().debug("debug message.");
    logger::get().trace("trace message.");
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

TEST(logger_levels_tests, notice_level)
{
    namespace fs = std::filesystem;

    // arrange
    const std::string file_name = "logger_output.txt";
    std::ofstream logger_file{ file_name, std::ios::trunc };
    assert(logger_file.is_open());

    logger::get().configure(logger::level::notice, logger_file);

    const std::string golden = std::string("FATAL: fatal message.\n")
        + std::string("CRITICAL: critical message.\n")
        + std::string("ERROR: error message.\n")
        + std::string("WARNING: warning message.\n")
        + std::string("NOTICE: notice message.\n");

        // act
        logger::get().fatal("fatal message.");
    logger::get().critical("critical message.");
    logger::get().error("error message.");
    logger::get().warning("warning message.");
    logger::get().notice("notice message.");
    logger::get().information("information message.");
    logger::get().debug("debug message.");
    logger::get().trace("trace message.");
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

TEST(logger_levels_tests, information_level)
{
    namespace fs = std::filesystem;

    // arrange
    const std::string file_name = "logger_output.txt";
    std::ofstream logger_file{ file_name, std::ios::trunc };
    assert(logger_file.is_open());

    logger::get().configure(logger::level::information, logger_file);

    const std::string golden = std::string("FATAL: fatal message.\n")
        + std::string("CRITICAL: critical message.\n")
        + std::string("ERROR: error message.\n")
        + std::string("WARNING: warning message.\n")
        + std::string("NOTICE: notice message.\n")
        + std::string("INFORMATION: information message.\n");

    // act
    logger::get().fatal("fatal message.");
    logger::get().critical("critical message.");
    logger::get().error("error message.");
    logger::get().warning("warning message.");
    logger::get().notice("notice message.");
    logger::get().information("information message.");
    logger::get().debug("debug message.");
    logger::get().trace("trace message.");
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

TEST(logger_levels_tests, debug_level)
{
    namespace fs = std::filesystem;

    // arrange
    const std::string file_name = "logger_output.txt";
    std::ofstream logger_file{ file_name, std::ios::trunc };
    assert(logger_file.is_open());

    logger::get().configure(logger::level::debug, logger_file);

    const std::string golden = std::string("FATAL: fatal message.\n")
        + std::string("CRITICAL: critical message.\n")
        + std::string("ERROR: error message.\n")
        + std::string("WARNING: warning message.\n")
        + std::string("NOTICE: notice message.\n")
        + std::string("INFORMATION: information message.\n")
        + std::string("DEBUG: debug message.\n");

    // act
    logger::get().fatal("fatal message.");
    logger::get().critical("critical message.");
    logger::get().error("error message.");
    logger::get().warning("warning message.");
    logger::get().notice("notice message.");
    logger::get().information("information message.");
    logger::get().debug("debug message.");
    logger::get().trace("trace message.");
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

TEST(logger_levels_tests, trace_level)
{
    namespace fs = std::filesystem;

    // arrange
    const std::string file_name = "logger_output.txt";
    std::ofstream logger_file{ file_name, std::ios::trunc };
    assert(logger_file.is_open());

    logger::get().configure(logger::level::trace, logger_file);

    const std::string golden = std::string("FATAL: fatal message.\n")
        + std::string("CRITICAL: critical message.\n")
        + std::string("ERROR: error message.\n")
        + std::string("WARNING: warning message.\n")
        + std::string("NOTICE: notice message.\n")
        + std::string("INFORMATION: information message.\n")
        + std::string("DEBUG: debug message.\n")
        + std::string("TRACE: trace message.\n");

    // act
    logger::get().fatal("fatal message.");
    logger::get().critical("critical message.");
    logger::get().error("error message.");
    logger::get().warning("warning message.");
    logger::get().notice("notice message.");
    logger::get().information("information message.");
    logger::get().debug("debug message.");
    logger::get().trace("trace message.");
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