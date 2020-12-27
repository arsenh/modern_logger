#ifndef __LOGGER_FILE_HPP__
#define __LOGGER_FILE_HPP__

#include <fstream>
#include <string>
#include <filesystem>

class logger_file
{
	using path = std::filesystem::path;
private:
	static constexpr char* file_format = ".log";
	std::fstream m_file;

private:

	std::string generate_file_name() const noexcept;

public:
	explicit logger_file(const path& p);
	std::ostream& get_source() noexcept;
	
	virtual ~logger_file();
};

#endif // __LOGGER_FILE_HPP__