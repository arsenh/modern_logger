#include "logger.hpp"
#include <gtest/gtest.h>

#include <filesystem>
#include <fstream>

TEST(logger_data_types_tests, integer_number)
{
    namespace fs = std::filesystem;

    // arrange
    const std::string file_name = "logger_output.txt";
    std::ofstream logger_file{ file_name, std::ios::trunc };
    assert(logger_file.is_open());
    const std::string text = "Integer = %";
    const int value = -123;
    const std::string golden = "DEBUG: Integer = -123\n";

    logger::get().configure(logger::level::debug, logger_file);

    // act
    logger::get().debug(text, value);
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

TEST(logger_data_types_tests, float_number)
{
    namespace fs = std::filesystem;

    // arrange
    const std::string file_name = "logger_output.txt";
    std::ofstream logger_file{ file_name, std::ios::trunc };
    assert(logger_file.is_open());
    const std::string text = "Float = %";
    const float value = 9.87654f;
    const std::string golden = "DEBUG: Float = 9.87654\n";

    logger::get().configure(logger::level::debug, logger_file);

    // act
    logger::get().debug(text, value);
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

TEST(logger_data_types_tests, single_char)
{
    namespace fs = std::filesystem;

    // arrange
    const std::string file_name = "logger_output.txt";
    std::ofstream logger_file{ file_name, std::ios::trunc };
    assert(logger_file.is_open());
    const std::string text = "Char = %";
    const char value = 'E';
    const std::string golden = "DEBUG: Char = E\n";

    logger::get().configure(logger::level::debug, logger_file);

    // act
    logger::get().debug(text, value);
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

TEST(logger_data_types_tests, bool_value)
{
    namespace fs = std::filesystem;

    // arrange
    const std::string file_name = "logger_output.txt";
    std::ofstream logger_file{ file_name, std::ios::trunc };
    assert(logger_file.is_open());
    const std::string text = "Bool = %";
    const bool value = true;
    const std::string golden = "DEBUG: Bool = 1\n";

    logger::get().configure(logger::level::debug, logger_file);

    // act
    logger::get().debug(text, value);
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

class Complex
{
private:
    int m_r;
    int m_i;
public:
    explicit Complex(int r, int i = 0)
        : m_r{r}
        , m_i{i}
    {

    }
    friend std::ostream& operator<<(std::ostream& os, const Complex& num)
    {
        // for example (1,3)
        os << "(" << num.m_r << "," << num.m_i << ")";
        return os;
    }
};

TEST(logger_data_types_tests, cutom_data_type)
{
    namespace fs = std::filesystem;

    // arrange
    const std::string file_name = "logger_output.txt";
    std::ofstream logger_file{ file_name, std::ios::trunc };
    assert(logger_file.is_open());
    const std::string text = "Complex = %";
    const Complex value{3, 6};
    const std::string golden = "DEBUG: Complex = (3,6)\n";

    logger::get().configure(logger::level::debug, logger_file);

    // act
    logger::get().debug(text, value);
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