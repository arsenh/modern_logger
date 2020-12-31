#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include <functional>
#include <iostream>
#include <optional>
#include <string>

class logger
{
private:

	using str_levels = std::array<const char*, 9>;
	using o_stream = std::reference_wrapper<std::ostream>;

public:

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

public:

	static logger& get() noexcept;

	void configure(level l, const o_stream& os);

	void string_builder(std::string& format) noexcept;

	template <typename T, typename... Args>
	void string_builder(std::string& format, T t, Args... args) noexcept;

	template <typename... Args>
	void fatal(const std::string& format, Args... args) noexcept;

	template <typename... Args>
	void critical(const std::string& format, Args... args) noexcept;

	template <typename... Args>
	void error(const std::string& format, Args... args) noexcept;
	
	template <typename... Args>
	void warning(const std::string& format, Args... args) noexcept;
	
	template <typename... Args>
	void notice(const std::string& format, Args... args) noexcept;
	
	template <typename... Args>
	void information(const std::string& format, Args... args) noexcept;
	
	template <typename... Args>
	void debug(const std::string& format, Args... args) noexcept;
	
	template <typename... Args>
	void trace(const std::string& format, Args... args) noexcept;
	
	virtual ~logger() = default;

private:

	logger();
};

#include "logger.icpp"

#endif // __LOGGER_HPP__


