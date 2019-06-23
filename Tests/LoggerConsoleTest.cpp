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
	printf("Creating ConsoleLogger - LogLevel Message\n");
	std::shared_ptr<Logger> consoleLoggerMessage = CreateConsoleLogger(LOG_MESSAGE);

	consoleLoggerMessage->LogMessage("Message - ConsoleLogger - LogLevel Message");
	consoleLoggerMessage->LogWarning("Warning - ConsoleLogger - LogLevel Message");
	consoleLoggerMessage->LogError("Error - ConsoleLogger - LogLevel Message");
	printf("\n");

	printf("Creating ConsoleLogger - LogLevel Warning\n");
	std::shared_ptr<Logger> consoleLoggerWarning = CreateConsoleLogger(LOG_WARNING);

	consoleLoggerWarning->LogMessage("Message - ConsoleLogger - LogLevel Warning");
	consoleLoggerWarning->LogWarning("Warning - ConsoleLogger - LogLevel Warning");
	consoleLoggerWarning->LogError("Error - ConsoleLogger - LogLevel Warning");
	printf("\n");


	printf("Creating ConsoleLogger Console - LogLevel Error\n");
	std::shared_ptr<Logger> consoleLoggerError = CreateConsoleLogger(LOG_ERROR);

	consoleLoggerError->LogMessage("Message - ConsoleLogger - LogLevel Error");
	consoleLoggerError->LogWarning("Warning - ConsoleLogger - LogLevel Error");
	consoleLoggerError->LogError("Error - ConsoleLogger - LogLevel Error");
	printf("\n");


	// Tests of LogLevel based on SetLevel().
	printf("****************************************\n");
	printf("*Tests of LogLevel based on SetLevel()*\n");
	printf("****************************************\n");
	printf("Creating ConsoleLogger\n");
	std::shared_ptr<Logger> consoleLoggerMessage2 = CreateConsoleLogger();
	printf("Setting LogLevel to Message\n");
	consoleLoggerMessage2->SetLevel(LOG_MESSAGE);

	consoleLoggerMessage2->LogMessage("Message - ConsoleLogger - LogLevel Message");
	consoleLoggerMessage2->LogWarning("Warning - ConsoleLogger - LogLevel Message");
	consoleLoggerMessage2->LogError("Error - ConsoleLogger - LogLevel Message");
	printf("\n");

	printf("Creating ConsoleLogger\n");
	std::shared_ptr<Logger> consoleLoggerWarning2 = CreateConsoleLogger();
	printf("Setting LogLevel to Warning\n");
	consoleLoggerWarning2->SetLevel(LOG_WARNING);

	consoleLoggerWarning2->LogMessage("Message - ConsoleLogger - LogLevel Warning");
	consoleLoggerWarning2->LogWarning("Warning - ConsoleLogger - LogLevel Warning");
	consoleLoggerWarning2->LogError("Error - ConsoleLogger - LogLevel Warning");
	printf("\n");


	printf("Creating ConsoleLogger\n");
	std::shared_ptr<Logger> consoleLoggerError2 = CreateConsoleLogger();
	printf("Setting LogLevel to Error\n");
	consoleLoggerError2->SetLevel(LOG_ERROR);

	consoleLoggerError2->LogMessage("Message - ConsoleLogger - LogLevel Error");
	consoleLoggerError2->LogWarning("Warning - ConsoleLogger - LogLevel Error");
	consoleLoggerError2->LogError("Error - ConsoleLogger - LogLevel Error");
	printf("\n");

	std::cin.get();
	return 0;
}