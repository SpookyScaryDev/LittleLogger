#pragma once

#include "ColourLogger.h"

#include "../Logger.h"
#include <iostream>
#include <Windows.h>
#include <memory>

namespace lilo {
	inline ColourLogger::ColourLogger(LogLevel level) :
		Logger(level)
	{
		mWindowsOutputHandleHandle = GetStdHandle(STD_OUTPUT_HANDLE); 	//Sets output handle.
	}

	inline ColourLogger::~ColourLogger() {}

	inline void ColourLogger::Log(std::string  string, LogLevel level) {
		// Set the colour based on the log level.
		switch (level) {
			case LOG_MESSAGE: SetColour(TEXT_GREEN);  break;
			case LOG_WARNING: SetColour(TEXT_YELLOW); break;
			case LOG_ERROR:   SetColour(TEXT_RED);    break;
		}

		//If the log level is bigger than the message level.
		if (mLevel > level || mLevel == level)
			std::cout << GetTime() << string << std::endl;

		// Set the text colour back to white incase anything
		// else gets printed.
		SetColour(TEXT_WHITE);
	}

	inline void ColourLogger::SetColour(TextColour colour) const {
		SetConsoleTextAttribute(mWindowsOutputHandleHandle, colour);
	}

	inline std::shared_ptr<Logger> CreateColourLogger(LogLevel level) {
		return std::make_shared<ColourLogger>(level);
	}
}