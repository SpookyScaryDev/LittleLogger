#pragma once

#include "../Logger.h"
#include <string> 
#include <Windows.h>
#include <memory>

namespace lilo {
	class ColourLogger : public Logger {
	public:
						        	ColourLogger(LogLevel level = LOG_MESSAGE);
		virtual                     ~ColourLogger() override;

	private:
		enum TextColour {                   // Console colour consts.
			TEXT_WHITE = 7,
			TEXT_GREEN = 10,
			TEXT_YELLOW = 14,
			TEXT_RED = 12
		};

		virtual void                Log(std::string  string, LogLevel level) override; // Logs to the console or file.
		void                        SetColour(TextColour colour) const;	               // Sets the colour of the console text.

		HANDLE                      mWindowsOutputHandleHandle;            //Windows STD output handle.
	};

	std::shared_ptr<Logger> CreateColourLogger(LogLevel level = LOG_MESSAGE);
}