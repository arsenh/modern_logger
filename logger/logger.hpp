#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <array>
#include <functional>
#include <iostream>
#include <string_view>

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
	
	static constexpr str_levels levels{ "NONE", "FATAL", "CRITICAL",
					    "ERROR", "WARNING", "NOTICE",
					    "INFORMATION", "DEBUG", "TRACE" };

	level m_level;
	o_stream m_out_stream;

private:

	std::ostream& stream() const noexcept;

public:

	static logger& get() noexcept;

	void configure(const o_stream& os, level l);

	void message(const std::string_view str) noexcept;

public:

	logger();
};

#include "logger.icpp"

#endif // __LOGGER_H__
