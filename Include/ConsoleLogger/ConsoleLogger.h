#pragma once

#include "../Logger.h"
#include <memory>

namespace lilo {
	class ConsoleLogger : public Logger {
	public:
						        	ConsoleLogger(LogLevel level = LOG_MESSAGE);
		virtual                     ~ConsoleLogger() override;

	private:
		virtual void                Log(std::string  string, LogLevel level) override;
	};

	std::shared_ptr<Logger> CreateConsoleLogger(LogLevel level = LOG_MESSAGE);
}