#pragma once

#include <string>
#include <sstream>

namespace lilo {
	enum LogLevel {
		LOG_ERROR,
		LOG_WARNING,
		LOG_MESSAGE
	};

	class Logger {
	public:
		                    Logger(LogLevel level);
		virtual             ~Logger() {};

		void                SetLevel(LogLevel level);

		template <typename ... Args>
		inline void         LogMessage(const Args& ... message){
			Log(ArgeToString(" [MESSAGE]: ", message...), LOG_MESSAGE);
		}

		template <typename ... Args>
		inline void         LogWarning(const Args& ... warning) {
			Log(ArgeToString(" [WARNING]: ", warning...), LOG_WARNING);
		}

		template <typename ... Args>
		inline void         LogError(const Args& ... error) {
			Log(ArgeToString(" [ERROR]: ", error...), LOG_ERROR);
		}

	protected:
		virtual void        Log(std::string  string, LogLevel level) = 0; // Logs to the console or file.
		std::string         GetTime() const;      	                      // Returns the time/date.

		LogLevel            mLevel;		    // Logger level.

	private:
		template <typename ... Args>
		inline std::string  ArgeToString(const Args& ... args) const {
			// Unpack the args onto a stringstream.
			std::stringstream stream;
			(stream << ... << args);
			return stream.str();
		}
	};
}