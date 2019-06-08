#include "../Include/Logger.h"
#include <stdio.h>

using namespace logger;

int main() {
	// Tests of LogLevel based on initialisation.
	printf("*******************************************\n");
	printf("*Tests of LogLevel based on initialisation*\n");
	printf("*******************************************\n");
	printf("Creating Logger - LogFormat File - LogLevel Message\n");
	Logger consoleLoggerMessage(LOG_FILE, LOG_MESSAGE, "LoggerFileTest", "LoggerFileTest");
	consoleLoggerMessage.setFile("LoggerFileTest", "LoggerFileTest"); // Emr...

	consoleLoggerMessage.logMessage("Message");
	consoleLoggerMessage.logWarning("Warning");
	consoleLoggerMessage.logError("Error");
	printf("\n");

	printf("Creating Logger - LogFormat File - LogLevel Warning\n");
	Logger consoleLoggerWarning(LOG_FILE, LOG_WARNING, "LoggerFileTest", "LoggerFileTest");
	consoleLoggerWarning.setFile("LoggerFileTest", "LoggerFileTest"); // Emr...

	consoleLoggerWarning.logMessage("Message");
	consoleLoggerWarning.logWarning("Warning");
	consoleLoggerWarning.logError("Error");
	printf("\n");


	printf("Creating Logger - LogFormat File - LogLevel Error\n");
	Logger consoleLoggerError(LOG_FILE, LOG_ERROR, "LoggerFileTest", "LoggerFileTest");
	consoleLoggerError.setFile("LoggerFileTest", "LoggerFileTest"); // Emr...

	consoleLoggerError.logMessage("Message");
	consoleLoggerError.logWarning("Warning");
	consoleLoggerError.logError("Error");
	printf("\n");


	// Tests of LogLevel based on SetFormat().
	printf("****************************************\n");
	printf("*Tests of LogLevel based on SetFormat()*\n");
	printf("****************************************\n");
	printf("Creating Logger - LogFormat File - LogLevel Message\n");
	Logger consoleLoggerMessage2(LOG_FILE, LOG_MESSAGE, "LoggerFileTest", "LoggerFileTest");
	consoleLoggerMessage2.setFile("LoggerFileTest", "LoggerFileTest"); // Emr...
	printf("Setting LogLevel to Message\n");
	consoleLoggerMessage2.setLevel(LOG_MESSAGE);


	consoleLoggerMessage.logMessage("Message");
	consoleLoggerMessage.logWarning("Warning");
	consoleLoggerMessage.logError("Error");
	printf("\n");

	printf("Creating Logger - LogFormat File - LogLevel Message\n");
	Logger consoleLoggerWarning2(LOG_FILE, LOG_MESSAGE, "LoggerFileTest", "LoggerFileTest");
	consoleLoggerWarning2.setFile("LoggerFileTest", "LoggerFileTest"); // Emr...
	printf("Setting LogLevel to Warning\n");
	consoleLoggerWarning2.setLevel(LOG_WARNING);

	consoleLoggerWarning.logMessage("Message");
	consoleLoggerWarning.logWarning("Warning");
	consoleLoggerWarning.logError("Error");
	printf("\n");


	printf("Creating Logger - LogFormat File - LogLevel Message\n");
	Logger consoleLoggerError2(LOG_FILE, LOG_MESSAGE, "LoggerFileTest", "LoggerFileTest");
	consoleLoggerError2.setFile("LoggerFileTest", "LoggerFileTest"); // Emr...
	printf("Setting LogLevel to Error\n");
	consoleLoggerError2.setLevel(LOG_ERROR);

	consoleLoggerError.logMessage("Message");
	consoleLoggerError.logWarning("Warning");
	consoleLoggerError.logError("Error");
	printf("\n");

	std::cin.get();
	return 0;
}