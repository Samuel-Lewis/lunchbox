
//====================================================//
// AUTHOR		Sam Lewis
// LASTE UPDATE	5/06/2015
// PROJECT		Utility Debug
//
// OUTLINE
//		Debug file to be used throughout the programs to log things.
//====================================================//

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>

#include "lbLog.h"

// Default no logs in run time
int lbLog::_logLevel;

// Default all logs to text file
int lbLog::_fileLogLevel;

// Default quit level at FATAL
int lbLog::_quitLevel;

std::ofstream lbLog::_logFile;


// Start logging to file, with standard name and root location
void lbLog::startLog() {
	_createLog("",(_getDateTime(false)+".log").c_str());
}	

// Start logging to file, with custom fileName and custom location
void lbLog::startLog(std::string path, std::string fileName) {
	_createLog(path,(fileName+".log").c_str());
}	

// Close the file, to stop corruption and loose ends
void lbLog::endLog() {
	if (_logFile.is_open()) {
		INFO(" === FILE CLOSED ===");
		_logFile.close();
	}
}

// Create the file. *For now*, only one file at a time.
void lbLog::_createLog(std::string path, std::string fileName) {
	if (!_logFile.is_open()) {
		_logFile.open((path+fileName).c_str());
		INFO(" === CREATED LOG FILE ===" );
	} else {
		WARN("Already an active log file. Close the active one before beginning another!");
	}
}

// Add next line to file
void lbLog::_writeToLog(std::string newLine) {
	if (_logFile.is_open()) {
		_logFile << newLine;
	}
}

// Set the logging level viewable from within the program. Required
void lbLog::setLogLevel(int newLevel) {
	if (newLevel < none) {
		// Stop humans from going too low
		newLevel = none;
	}
	_logLevel = newLevel;
}

// Set the loggling level to go to the text file
void lbLog::setFileLogLevel(int newLevel) {
	if (newLevel < none) {
		// Stop humans from going too low
		newLevel = none;
	}
	_fileLogLevel = newLevel;
}

// Set the threshold for the program to quit
void lbLog::setQuitLevel(int newLevel) {
	if (newLevel < none) {
		// none and 0 are reserved. So default to 1 (FATAL)
		newLevel = none;
	}
	_quitLevel = newLevel;
}

void lbLog::quickSet(int newLogLevel, int newFileLogLevel, int newQuitLevel) {
	if (newLogLevel < none) {
		newLogLevel = none;
	}
	
	if (newFileLogLevel < none) {
		newFileLogLevel = none;
	}
	
	if (newQuitLevel < none) {
		newQuitLevel = none;
	}

	_logLevel = newLogLevel;
	_fileLogLevel = newFileLogLevel;
	_quitLevel = newQuitLevel;
}


// Gets date and time to be used for file names
std::string lbLog::_getDateTime(bool justTime) {
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);

	if (justTime) {
		// Only return the time. Used for prefixing logs
		strftime(buf, sizeof(buf), "%X", &tstruct);
	} else {
		strftime(buf, sizeof(buf), "%Y.%m.%d-%X", &tstruct);
	}

	return buf;
}

// Check the level of debug asked for
bool lbLog::_validate(int sentLevel, int levelThresh) {

	// Exception for none, HIDE ALL debug messages
	if (levelThresh == none) {
		return false;

	//Exception for 0, SHOW ALL debug messages
	} else if (levelThresh == all) {
		return true;
	} else {
		// Otherwise, only output at designated _logLevel + all higher
		if (sentLevel <= levelThresh) {
			return true;
		} else {
			return false;
		}
	}
}

// Print out if logging level is met. Should always be called from a macro
void lbLog::out(const char* file, int line, std::string levelTag, int sentLevel, std::string msg) {

	std::string toLog = "["+_getDateTime(true)+"][" + levelTag+"]:"+file+":"+std::to_string(line)+": "+msg;

	// The panic button. Quit after outputting the problem to everything.
	if (sentLevel > 0 && sentLevel <= _quitLevel) {
		// Always output quitLevel logs
		std::cout << toLog << std::endl;
		toLog+= "\n";
		_writeToLog(toLog);

		endLog();
		std::exit(1);
	}

	// Check debug level for user viewing
	if (_validate(sentLevel, _logLevel)) {
		std::cout << toLog << std::endl;		
	}

	// Check debug level for file logging
	if (_validate(sentLevel, _fileLogLevel)) {
		toLog+= "\n";
		_writeToLog(toLog);
	}
}
