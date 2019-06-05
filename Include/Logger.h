#pragma once

#include <string> 
#include <sstream>
#include <fstream>
#include <iostream>    
#include <chrono>
#include <iomanip>
#include <windows.h>

namespace logger {


	enum                    LogFormat { LOG_CONSOLE, LOG_FILE }; 	//Logger format enum.
	enum                    Loglevel { LOG_ERROR, LOG_WARNING, LOG_MESSAGE };    //Logger level enum,

	const int               TEXT_WHITE = 7;    //Console colour consts.
	const int               TEXT_GREEN = 10;
	const int               TEXT_YELLOW = 14;
	const int               TEXT_RED = 12;

	class Logger
	{
	public:

		                    Logger(LogFormat format, Loglevel level, std::string name, std::string path);
		                    ~Logger();

		template <typename ... Args>
		inline void         logMessage(const Args& ... message) {
			setColour(TEXT_GREEN);
			log(argsToString(message...), "[MESSAGE]", LOG_MESSAGE);
		}

		template <typename ... Args>
		inline void         logWarning(const Args& ... warning) {
			setColour(TEXT_YELLOW);
			log(argsToString(warning...), "[WARNING]", LOG_WARNING);
		}

		template <typename ... Args>
		inline void         logError(const Args& ... error) {
			setColour(TEXT_RED);
			log(argsToString(error...), "[ERROR]", LOG_ERROR);
		}

		void                setFormat(LogFormat format);
		void                setFile(std::string name, std::string path);
		void                setLevel(Loglevel level);

	private:

		template <typename ... Args>
		inline std::string  argsToString(const Args& ... args) {
			//Unpack the args onto a stringstream.
			std::ostringstream stream;
			using List = int[];
			(void)List {
				0, ((void)(stream << args), 0) ...
			};

			return stream.str();
		}

		void                initFile(std::string path);	//Creates a file and directory if the specified directory doesn't exist and adds a header.                                                            
		void                log(std::string str, const char sLevel[], Loglevel level);		//Logs to the console or file.
		void                setColour(int colour);		//Sets the colour of the console text.
		void                printTime();	//Prints the time and date to the console or log file.

		#if defined (_WIN32) || defined (_WIN64)
			void*           mHandle;        //Windows STD output handle.
		#endif //_WIN32 || _WIN64

		LogFormat           mFormat;		//Logger output format.
		Loglevel            mLevel;		    //Logger level.
		std::string         mFilePath;	    //Logfile filepath.
		std::fstream        mLogFile; 		//fstream for the log file.


	};

	
	inline Logger::Logger(LogFormat format, Loglevel level, std::string name, std::string path) {

		#if defined (_WIN32) || defined (_WIN64)
			mHandle = GetStdHandle(STD_OUTPUT_HANDLE); 	//Sets output handle.
		#endif //_WIN32 || _WIN64

		mFormat = format;
		mLevel = level;

		std::fstream mLogFile;

		//Generates log file path.
		mFilePath = path + "\\" + name + ".log";

	}

	inline Logger::~Logger() {}

	inline void Logger::setFormat(LogFormat format) {
		mFormat = format;
	}

	inline void Logger::setFile(std::string name, std::string path) {
		mFilePath = path + "\\" + name + ".log";
		if (mFormat == LOG_FILE)
		{
			initFile(path);
		}
	}

	inline void Logger::setLevel(Loglevel level) {
		mLevel = level;
	}

	inline void Logger::initFile(std::string path) {
		//If the directory doesn't exist, create it.
		if (GetFileAttributes(path.c_str()) == INVALID_FILE_ATTRIBUTES) {
			CreateDirectory(path.c_str(), NULL);
		}

		//Open the file.
		mLogFile.open(mFilePath, std::ios::binary | std::ios::in | std::ios::out | std::ios::app);

		//If the file doesn't exist, create it.
		if (!mLogFile) {
			mLogFile.open(mFilePath, std::ios::binary | std::ios::trunc | std::ios::out | std::ios::app);
			mLogFile.close();
			// re-open with original flags
			mLogFile.open(mFilePath, std::ios::binary | std::ios::in | std::ios::out | std::ios::app);
		}
		else {
			//File formatting.
			mLogFile << "\r\n";
		}

		mLogFile << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\r\n";
		mLogFile << "~Log File created at ";
		printTime();
		mLogFile << "~\r\n";
		mLogFile << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\r\n";

		mLogFile.close();
	}

	inline void Logger::log(std::string str, const char sLevel[], Loglevel level) {
		//If the log level is bigger than the message level.
		if (mLevel > level || mLevel == level) {
			//Log to the console.
			if (mFormat == LOG_CONSOLE) {
				printTime();
				std::cout << " " << sLevel << ": " << str << std::endl;
			}
			//Log to a log file.
			else if (mFormat == LOG_FILE) {
				mLogFile.open(mFilePath, std::ios::binary | std::ios::in | std::ios::out | std::ios::app);
				printTime();
				mLogFile << " " << sLevel << ": " << str << "\r\n";
				mLogFile.close();
			}

			setColour(TEXT_WHITE);
		}
	}

	inline void Logger::setColour(int colour) {
		#if defined (_WIN32) || defined (_WIN64)
			SetConsoleTextAttribute(mHandle, colour);
		#endif //_WIN32 || _WIN64
	}

	inline void Logger::printTime() {
		//Get date/time...
		auto n = std::chrono::system_clock::now();
		auto in_time_t = std::chrono::system_clock::to_time_t(n);
		std::tm buf;
		localtime_s(&buf, &in_time_t);
		//...and print it.
		if (mFormat == LOG_CONSOLE) {
			std::cout << std::put_time(&buf, "%Y-%m-%d %X");
		}
		else if (mFormat == LOG_FILE) {
			mLogFile << std::put_time(&buf, "%Y-%m-%d %X");
		}

	}

}