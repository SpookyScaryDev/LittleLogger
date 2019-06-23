#pragma once

#include "Logger.h"

#include <string>
#include <sstream>
#include <iomanip>

namespace lilo {
	inline Logger::Logger(LogLevel level) :
		mLevel(level) {}

	inline void Logger::SetLevel(LogLevel level) {
		mLevel = level;
	}

	inline std::string Logger::GetTime() const {
		// Get date/time as string.
		time_t time = std::time(nullptr);
		tm dateTime;
		localtime_s(&dateTime, &time);

		std::ostringstream oStringStream;
		oStringStream << std::put_time(&dateTime, "%d-%m-%Y %X");
		return oStringStream.str();
	}
}