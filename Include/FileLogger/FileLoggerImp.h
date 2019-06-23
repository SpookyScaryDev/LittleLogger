#pragma once

#include "FileLogger.h"

#include "../Logger.h"
#include <string>
#include <fstream>
#include <memory>

namespace lilo {
	inline FileLogger::FileLogger(const char* fileName) :
		Logger(LOG_MESSAGE),
		mFileName(fileName)
	{
		std::fstream mLogFile;
		OpenFile();
	}

	inline FileLogger::FileLogger(LogLevel level, const char* fileName) :
		Logger(level),
		mFileName(fileName)
	{
		std::fstream mLogFile;
		OpenFile();
	}

	inline FileLogger::~FileLogger() {
		CloseFile();
	}

	inline void FileLogger::Log(std::string  string, LogLevel level) {
		// If the log level is bigger than the message level.
		if (mLevel > level || mLevel == level)
			mLogFile << GetTime() << " " << ": " << string << "\r\n";
	}
	
	inline void FileLogger::OpenFile() {
		// Open the file.
		mLogFile.open(mFileName, std::fstream::out | std::fstream::app);

		mLogFile << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\r\n";
		mLogFile << "~Log File created at " << GetTime() << "~\r\n";
		mLogFile << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\r\n";
	}

	inline void FileLogger::CloseFile() {
		mLogFile << "\r\n";

		// Close the file.
		mLogFile.close();
	}

	inline std::shared_ptr<Logger> CreateFileLogger(const char* fileName) {
		return std::make_shared<FileLogger>(fileName);
	}

	inline std::shared_ptr<Logger> CreateFileLogger(LogLevel level, const char* fileName) {
		return std::make_shared<FileLogger>(level, fileName);
	}
}