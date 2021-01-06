#ifndef __LOGGER_FILE_HPP__
#define __LOGGER_FILE_HPP__

#include <filesystem>
#include <fstream>

/**
 * Class represents the logger file.
 */
class logger_file
{
	using path = std::filesystem::path;
private:
	static constexpr const char* file_format = ".log";
	std::fstream m_file;

private:

	/**
	 * Generates the file name, based on current date.
	 * 
	 * \return genetared file name.
	 */
	std::string generate_file_name() const noexcept;

public:
	
	/**
	 * Logger file constructor.
	 * Generates the logger file in given directory.
	 * 
	 * \param p - logger file directory.
	 */
	explicit logger_file(const path& p);

	/**
	 * Returns the output destionation.
	 * 
	 * \return - ostream object.
	 */
	std::ostream& destination() noexcept;
	
	/**
	 * Destructor.
	 * 
	 * Closes the opened file.
	 */
	virtual ~logger_file();

	/**
	 * Default move constructor.
	 * 
	 * \param o - logger file object.
	 */
	logger_file(logger_file&& o) = default;
	
	/**
	 * Default assignment operator.
	 *
	 * \param o - logger file object.
	 */
	logger_file& operator=(logger_file&& other) = default;

public:

	/**
	 * Deleted copy constructor.
	 */
	logger_file(const logger_file& a) = delete;
	
	/**
	 * Deleted copy assignment operator.
	 */
	logger_file& operator=(const logger_file& other) = delete;
	
};

#endif // __LOGGER_FILE_HPP__
