#pragma once

#include "../Logger.h"
#include <string> 
#include <fstream>
#include <memory>

namespace lilo {
	class FileLogger : public Logger {
	public:
							FileLogger(const char* fileName);
							FileLogger(LogLevel level, const char* fileName = "Log.log.txt");

		virtual             ~FileLogger() override;

	private:
		virtual void        Log(std::string  string, LogLevel level) override;
		void                OpenFile();                                        // Open and close file.
		void                CloseFile();

		std::string         mFileName;	    //Logfile filepath.
		std::fstream        mLogFile; 		//fstream for the log file.
	};

	std::shared_ptr<Logger> CreateFileLogger(const char* fileName = "Log.log.txt");
	std::shared_ptr<Logger> CreateFileLogger(LogLevel level, const char* fileName = "Log.log.txt");
}