#pragma once

#include "ConsoleLogger.h"

#include "../Logger.h"
#include <iostream>
#include <memory>

namespace lilo {
	inline ConsoleLogger::ConsoleLogger(LogLevel level) :
		Logger(level) {}

	inline ConsoleLogger::~ConsoleLogger() {}

	inline void ConsoleLogger::Log(std::string  string, LogLevel level) {
		//If the log level is bigger than the message level.
		if (mLevel > level || mLevel == level)
			std::cout << GetTime() << " " << ": " << string << std::endl;
	}

	inline std::shared_ptr<Logger> CreateConsoleLogger(LogLevel level) {
		return std::make_shared<ConsoleLogger>(level);
	}
}