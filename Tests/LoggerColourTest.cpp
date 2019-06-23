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
	printf("Creating ColourLogger - LogLevel Message\n");
	std::shared_ptr<Logger> colourLoggerMessage = CreateColourLogger(LOG_MESSAGE);

	colourLoggerMessage->LogMessage("Message - ColourLogger - LogLevel Message");
	colourLoggerMessage->LogWarning("Warning - ColourLogger - LogLevel Message");
	colourLoggerMessage->LogError("Error - ColourLogger - LogLevel Message");
	printf("\n");

	printf("Creating ColourLogger - LogLevel Warning\n");
	std::shared_ptr<Logger> colourLoggerWarning = CreateColourLogger(LOG_WARNING);

	colourLoggerWarning->LogMessage("Message - ColourLogger - LogLevel Warning");
	colourLoggerWarning->LogWarning("Warning - ColourLogger - LogLevel Warning");
	colourLoggerWarning->LogError("Error - ColourLogger - LogLevel Warning");
	printf("\n");

	printf("Creating ColourLogger Console - LogLevel Error\n");
	std::shared_ptr<Logger> colourLoggerError = CreateColourLogger(LOG_ERROR);

	colourLoggerError->LogMessage("Message - ColourLogger - LogLevel Error");
	colourLoggerError->LogWarning("Warning - ColourLogger - LogLevel Error");
	colourLoggerError->LogError("Error - ColourLogger - LogLevel Error");
	printf("\n");


	// Tests of LogLevel based on SetLevel().
	printf("****************************************\n");
	printf("*Tests of LogLevel based on SetFormat()*\n");
	printf("****************************************\n");
	printf("Creating ColourLogger\n");
	std::shared_ptr<Logger> colourLoggerMessage2 = CreateColourLogger();
	printf("Setting LogLevel to Message\n");
	colourLoggerMessage2->SetLevel(LOG_MESSAGE);

	colourLoggerMessage2->LogMessage("Message - ColourLogger - LogLevel Message");
	colourLoggerMessage2->LogWarning("Warning - ColourLogger - LogLevel Message");
	colourLoggerMessage2->LogError("Error - ColourLogger - LogLevel Message");
	printf("\n");

	printf("Creating ColourLogger\n");
	std::shared_ptr<Logger> colourLoggerWarning2 = CreateColourLogger();
	printf("Setting LogLevel to Warning\n");
	colourLoggerWarning2->SetLevel(LOG_WARNING);

	colourLoggerWarning2->LogMessage("Message - ColourLogger - LogLevel Warning");
	colourLoggerWarning2->LogWarning("Warning - ColourLogger - LogLevel Warning");
	colourLoggerWarning2->LogError("Error - ColourLogger - LogLevel Warning");
	printf("\n");


	printf("Creating ColourLogger\n");
	std::shared_ptr<Logger> colourLoggerError2 = CreateColourLogger();
	printf("Setting LogLevel to Error\n");
	colourLoggerError2->SetLevel(LOG_ERROR);

	colourLoggerError2->LogMessage("Message - ColourLogger - LogLevel Error");
	colourLoggerError2->LogWarning("Warning - ColourLogger - LogLevel Error");
	colourLoggerError2->LogError("Error - ColourLogger - LogLevel Error");
	printf("\n");

	std::cin.get();
	return 0;
}