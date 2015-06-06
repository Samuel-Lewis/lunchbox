LUNCHBOX
Debug Logging

“Lunch Box logging class, for both run time errors and external logs”



void lbLog::startLog():
	Start logging to an external file. Not needed to produce run-time logs.
	Default file is a .log in the same directory, named with a timestamp.

void lbLog::startLog(std::string path, string fileName):
	Same as startLog(), except with a specified path and fileName.
	path must include a trailing forward slash ‘/‘.
	fileName does not need a file extension (will become a .log).
