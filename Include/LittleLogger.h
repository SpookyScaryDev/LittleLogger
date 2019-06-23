#pragma once

#include "Logger.h"
#include "LoggerImp.h"

#include "ConsoleLogger/ConsoleLogger.h"	 
#include "ConsoleLogger/ConsoleLoggerImp.h"

#include "FileLogger/FileLogger.h"
#include "FileLogger/FileLoggerImp.h"

#if defined (_WIN32) || defined (_WIN64)
#include "ColourLogger/ColourLogger.h"
#include "ColourLogger/ColourLoggerImp.h"
#endif //_WIN32 || _WIN64