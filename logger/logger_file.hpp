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
	std::ostream& destination() noexcept;
	
	virtual ~logger_file();

	// move constructor
	logger_file(logger_file&& o) = default;

	// move assignment operator
	logger_file& operator=(logger_file&& other) = default;

public:

	/// Deleter special member functions.
	// copy constructor
	logger_file(const logger_file& a) = delete;
	
	// copy assigment operator
	logger_file& operator=(const logger_file& other) = delete;
	
};

#endif // __LOGGER_FILE_HPP__