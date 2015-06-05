
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

#include "Debug.h"

// Default no logs in run time
int Debug::_logLevel;

// Default all logs to text file
int Debug::_fileLogLevel;

// Default quit level at FATAL
int Debug::_quitLevel;

std::ofstream Debug::_logFile;


// Start logging to file, with standard name and root location
void Debug::startLog() {
	_createLog("",(_getDateTime(false)+".log").c_str());
}	

// Start logging to file, with standard name and custom location
void Debug::startLog(std::string path) {
	_createLog(path,(_getDateTime(false)+".log").c_str());
}	

// Start logging to file, with custom name and custom location
void Debug::startLog(std::string path, std::string name) {
	_createLog(path,(name+".log").c_str());
}	

// Close the file, to stop corruption and loose ends
void Debug::endLog() {
	if (_logFile.is_open()) {
		INFO(" === FILE CLOSED ===");
		_logFile.close();
	}
}

// Create the file. *For now*, only one file at a time.
void Debug::_createLog(std::string path, std::string name) {
	if (!_logFile.is_open()) {
		_logFile.open((path+name).c_str());
		INFO(" === CREATED LOG FILE ===" );
	} else {
		WARN("Already an active log file. Close the active one before beginning another!");
	}
}

// Add next line to file
void Debug::_writeToLog(std::string newLine) {
	if (_logFile.is_open()) {
		_logFile << newLine;
	}
}

// Set the logging level viewable from within the program. Required
void Debug::setLogLevel(int newLevel) {
	if (newLevel < -1) {
		// Stop humans from going too low
		newLevel = -1;
	}
	_logLevel = newLevel;
}

// Set the loggling level to go to the text file
void Debug::setFileLogLevel(int newLevel) {
	if (newLevel < -1) {
		// Stop humans from going too low
		newLevel = -1;
	}
	_fileLogLevel = newLevel;
}

// Set the threshold for the program to quit
void Debug::setQuitLevel(int newLevel) {
	if (newLevel < 1) {
		// -1 and 0 are reserved. So default to 1 (FATAL)
		newLevel = 1;
	}
	_quitLevel = newLevel;
}


// Gets date and time to be used for file names
std::string Debug::_getDateTime(bool justTime) {
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
bool Debug::_validate(int sentLevel, int levelThresh) {

	// Exception for -1, HIDE ALL debug messages
	if (levelThresh == -1) {
		return false;

	//Exception for 0, SHOW ALL debug messages
	} else if (levelThresh == 0) {
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

// Print out if logging level is met
void Debug::out(const char* file, int line, std::string levelTag, int sentLevel, std::string msg) {

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
