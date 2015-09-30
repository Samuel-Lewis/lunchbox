	//===============================================//
//
//	@Author:	Samuel Lewis
//	@Github:	http://github.com/Samuel-Lewis/lunchbox
//
//	@Project:	Lunchbox Toolset
//
//	@Last Updated:	2015-09-30 13:47:14
//	@Created:		2015-07-14 21:26:08
//
//===============================================//

#ifndef _LB_LOG_H
#define _LB_LOG_H

#include <fstream>
#include <string>
#include <sstream>

// Different error levels to be called through the rest of the program
#define FATAL(msg) { std::stringstream o; o << msg; lbLog::out(__FILE__, __LINE__, "FATAL", lbLog::info, o.str().c_str()); }
#define ERROR(msg) { std::stringstream o; o << msg; lbLog::out(__FILE__, __LINE__, "ERROR", lbLog::info, o.str().c_str()); }
#define WARN(msg) { std::stringstream o; o << msg; lbLog::out(__FILE__, __LINE__, "WARNING", lbLog::info, o.str().c_str()); }
#define INFO(msg) { std::stringstream o; o << msg; lbLog::out(__FILE__, __LINE__, "INFO", lbLog::info, o.str().c_str()); }
#define DEBUG(msg) { std::stringstream o; o << msg; lbLog::out(__FILE__, __LINE__, "DEBUG", lbLog::info, o.str().c_str()); }
#define MARK() { lbLog::out(__FILE__, __LINE__, "MARK", lbLog::info, ""); }

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
	static void startLog(std::string, std::string, bool);
	static void endLog();

private:
	// Stop the initialization of a lbLog
	lbLog();
	~lbLog();

	static int _logLevel;
	static int _fileLogLevel;
	static int _quitLevel;
	static std::ofstream _logFile;

	static bool _validate(int,int);
	static void _writeToLog(std::string);
	static void _createLog(std::string, std::string);
	static std::string _getDateTime(bool);
};

#endif //_LB_LOG_H
