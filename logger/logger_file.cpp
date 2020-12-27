#include "logger_file.hpp"

#include <cassert>
#include <filesystem>
#include <stdexcept>
#include <chrono>
#include <sstream>

std::string logger_file::
generate_file_name() const noexcept
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "d%Y_%m_%d_t%H_%M_%S");
    const std::string& file_name = "logger_" + ss.str() + file_format;
    return file_name;
}

logger_file::
logger_file(const path& p)
    : m_file{}
{
    namespace fs = std::filesystem;
    auto logger_path = p;
    if (! fs::is_directory(logger_path)) {
        throw std::runtime_error("Invalid directory.");
    }
    const auto& file_name = generate_file_name();
    logger_path /= file_name;
    m_file.open(logger_path.string(), std::ios::out | std::ios::app);
    if (! m_file) {
        throw std::runtime_error("Cannot open logger file.");
    }
    if (! fs::is_regular_file(logger_path.string())) {
        throw std::runtime_error("File is not regular file.");
    }
    assert(m_file.is_open());
}

std::ostream& logger_file::
get_source() noexcept
{
    return m_file;
}

logger_file::
~logger_file()
{
    m_file.close();
}
