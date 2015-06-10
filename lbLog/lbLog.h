
//====================================================//
// AUTHOR		Samuel Lewis
// LASTE UPDATE	6/06/2015
// PROJECT		LunchBox - Debug Logger
//
// OUTLINE
//		LunchBox logging class, for both run time errors and external logs
//====================================================//

#ifndef LB_LOG_H
#define LB_LOG_H

#include <fstream>
#include <string>
#include <vector>


// Different error levels to be called through the rest of the program
#define FATAL(msg) lbLog::out(__FILE__, __LINE__, "FATAL", lbLog::fatal, (msg))
#define ERROR(msg) lbLog::out(__FILE__, __LINE__, "ERROR", lbLog::error, (msg))
#define WARN(msg) lbLog::out(__FILE__, __LINE__, "WARNING", lbLog::warn, (msg))
#define INFO(msg) lbLog::out(__FILE__, __LINE__, "INFO", lbLog::info, (msg))
#define DEBUG(msg) lbLog::out(__FILE__, __LINE__, "DEBUG", lbLog::debug, (msg))
#define MARK() lbLog::out(__FILE__, __LINE__, "MARK", lbLog::mark, (""))

class lbLog {
public:
	enum sevLevels {
		none = -1,
		all,
		fatal,
		error,
		warn,
		info,
		debug,
		mark
	};

	// Level setters
	static void setLogLevel(int);
	static void setFileLogLevel(int);
	static void setQuitLevel(int);
	static void quickSet(int, int, int);

	// Should only really be called from the macro.
	static void out(const char*, int, std::string, int, std::string);

	// Starts putting logs in to a txt for the duration of the exectuion, or until endLog() is called
	static void startLog();
	static void startLog(std::string, std::string);
	static void endLog();

private:
	// Stop the initialization of a lbLog
	lbLog();

	static int _logLevel;
	static int _fileLogLevel;
	static int _quitLevel;
	static std::ofstream _logFile;

	static bool _validate(int,int);
	static void _writeToLog(std::string);
	static void _createLog(std::string, std::string);
	static std::string _getDateTime(bool);
};

#endif //LB_LOG_H
