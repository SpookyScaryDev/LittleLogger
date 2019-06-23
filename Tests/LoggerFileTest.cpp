#include "../Include/LittleLogger.h"
#include <stdio.h>
#include <iostream>
#include <memory>

using namespace lilo;

int main() {
	// Tests of LogLevel based on initialisation.
	printf("*******************************************\n");
	printf("*Tests of LogLevel based on initialisation*\n");
	printf("*******************************************\n");
	printf("Creating FileLogger - LogLevel Message\n");
	std::shared_ptr<Logger> fileLoggerMessage = CreateFileLogger(LOG_MESSAGE, "LogFileTest.log.txt");

	fileLoggerMessage->LogMessage("Message - FileLogger - LogLevel Message");
	fileLoggerMessage->LogWarning("Warning - FileLogger - LogLevel Message");
	fileLoggerMessage->LogError("Error - FileLogger - LogLevel Message");
	printf("\n");

	fileLoggerMessage.reset();

	printf("Creating FileLogger - LogLevel Warning\n");
	std::shared_ptr<Logger> fileLoggerWarning = CreateFileLogger(LOG_WARNING, "LogFileTest.log.txt");

	fileLoggerWarning->LogMessage("Message - FileLogger - LogLevel Warning");
	fileLoggerWarning->LogWarning("Warning - FileLogger - LogLevel Warning");
	fileLoggerWarning->LogError("Error - FileLogger - LogLevel Warning");
	printf("\n");

	fileLoggerWarning.reset();

	printf("Creating FileLogger Console - LogLevel Error\n");
	std::shared_ptr<Logger> fileLoggerError = CreateFileLogger(LOG_ERROR, "LogFileTest.log.txt");

	fileLoggerError->LogMessage("Message - FileLogger - LogLevel Error");
	fileLoggerError->LogWarning("Warning - FileLogger - LogLevel Error");
	fileLoggerError->LogError("Error - FileLogger - LogLevel Error");
	printf("\n");

	fileLoggerError.reset();

	// Tests of LogLevel based on SetLevel().
	printf("****************************************\n");
	printf("*Tests of LogLevel based on SetLevel()*\n");
	printf("****************************************\n");
	printf("Creating FileLogger\n");
	std::shared_ptr<Logger> fileLoggerMessage2 = CreateFileLogger("LogFileTest.log.txt");
	printf("Setting LogLevel to Message\n");
	fileLoggerMessage2->SetLevel(LOG_MESSAGE);

	fileLoggerMessage2->LogMessage("Message - FileLogger - LogLevel Message");
	fileLoggerMessage2->LogWarning("Warning - FileLogger - LogLevel Message");
	fileLoggerMessage2->LogError("Error - FileLogger - LogLevel Message");
	printf("\n");

	fileLoggerMessage2.reset();

	printf("Creating FileLogger\n");
	std::shared_ptr<Logger> fileLoggerWarning2 = CreateFileLogger("LogFileTest.log.txt");
	printf("Setting LogLevel to Warning\n");
	fileLoggerWarning2->SetLevel(LOG_WARNING);

	fileLoggerWarning2->LogMessage("Message - FileLogger - LogLevel Warning");
	fileLoggerWarning2->LogWarning("Warning - FileLogger - LogLevel Warning");
	fileLoggerWarning2->LogError("Error - FileLogger - LogLevel Warning");
	printf("\n");

	fileLoggerWarning2.reset();

	printf("Creating FileLogger\n");
	std::shared_ptr<Logger> fileLoggerError2 = CreateFileLogger("LogFileTest.log.txt");
	printf("Setting LogLevel to Error\n");
	fileLoggerError2->SetLevel(LOG_ERROR);

	fileLoggerError2->LogMessage("Message - FileLogger - LogLevel Error");
	fileLoggerError2->LogWarning("Warning - FileLogger - LogLevel Error");
	fileLoggerError2->LogError("Error - FileLogger - LogLevel Error");
	printf("\n");

	fileLoggerError2.reset();

	std::cin.get();
	return 0;
}