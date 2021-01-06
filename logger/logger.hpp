#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include <iostream>
#include <string>

/**
 * Logger class.
 * 
 * Class implementation based on variadic templates.
 * 
 * For adding variables in format need to insert special
 * symbol % on position, which is must include given variable.
 * 
 * Usage: logger().get().debug("This is a simple %", "message!");
 * 
 * Output: DEBUG: This is a simple message!
 * 
 * Logger support all data types which implements operator<<() for output streams.
 * 
 * Destination of output must be a class derived from std::ostream.
 *  For example standard output, file, etc.
 */
class logger
{
private:

	using str_levels = std::array<const char*, 9>;
	using o_stream = std::reference_wrapper<std::ostream>;

public:
	
	/**
	 * Logger levels.
	 */
	enum class level : int {
		none, fatal, critical,
		error, warning, notice,
		information, debug, trace
	};

private:
	
	level m_level;
	o_stream m_out_stream;
	const char m_logger_sym = '%';

private:

	std::ostream& stream() const noexcept;
	void check_stream() const;

private:

	/**
	 * Base case of string builder variadic template function.
	 * Add end line on format.
	 * 
	 * \param format - generated format string.
	 */
	void string_builder(std::string& format) noexcept;

	/**
	 * Variadic template function for generating logger
	 * format string base on arguments list.
	 *
	 * \param format - format string.
	 * \param args - arguments list.
	 */
	template <typename T, typename... Args>
	void string_builder(std::string& format, T t, Args... args) noexcept;

public:

	/**
	 * Returns logger singleton object.
	 * 
	 * \return logger object reference.
	 */
	static logger& get() noexcept;

	/**
	 * Function configures the logger functionality.
	 * 
	 * \param l level of logging.
	 * \param os destination of output.
	 */
	void configure(level l, const o_stream& os);

	/**
	 * Add fatal message in output.
	 * 
	 * \param format message format.
	 * \param args message format arguments list.
	 */
	template <typename... Args>
	void fatal(const std::string& format, Args... args) noexcept;

	/**
	 * Add critical message in output.
	 *
	 * \param format message format.
	 * \param args message format arguments list.
	 */
	template <typename... Args>
	void critical(const std::string& format, Args... args) noexcept;
	
	/**
	 * Add error message in output.
	 *
	 * \param format message format.
	 * \param args message format arguments list.
	 */
	template <typename... Args>
	void error(const std::string& format, Args... args) noexcept;
	
	/**
	 * Add warning message in output.
	 *
	 * \param format message format.
	 * \param args message format arguments list.
	 */
	template <typename... Args>
	void warning(const std::string& format, Args... args) noexcept;
	
	/**
	 * Add notice message in output.
	 *
	 * \param format message format.
	 * \param args message format arguments list.
	 */
	template <typename... Args>
	void notice(const std::string& format, Args... args) noexcept;
	
	/**
	 * Add information message in output.
	 *
	 * \param format message format.
	 * \param args message format arguments list.
	 */
	template <typename... Args>
	void information(const std::string& format, Args... args) noexcept;
	
	/**
	 * Add debug message in output.
	 *
	 * \param format message format.
	 * \param args message format arguments list.
	 */
	template <typename... Args>
	void debug(const std::string& format, Args... args) noexcept;
	
	/**
	 * Add trace message in output.
	 *
	 * \param format message format.
	 * \param args message format arguments list.
	 */
	template <typename... Args>
	void trace(const std::string& format, Args... args) noexcept;
	
	/**
	 * Default constructor.
	 */
	virtual ~logger() = default;

private:

	logger();

public:

	/**
	 * Deleted copy constructor.
	 */
	logger(const logger& a) = delete;
	
	/**
	 * Deleted copy assignment operator.
	 */
	logger& operator=(const logger& other) = delete;
	
	/**
	 * Deleted move constructor.
	 */
	logger(logger&& o) = delete;
	
	/**
	 * Deleted move assignment operator.
	 */
	logger& operator=(logger&& other) = delete;
};

#include "logger.icpp"

#endif // __LOGGER_HPP__


