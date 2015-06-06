#include "lbLog.h"

int main() {
	// Quick set levels to hide all output in run-time, log everything to log file and quit on FATALs
	lbLog::quickSet(0,0,1);

	// Quick check to let me know I reached this line
	MARK();

	// Will not be added to a log file, as none is started
	INFO("Some information");
	WARN("More urgent information!!!");

	// Start the log file
	lbLog::startLog();
	INFO("This should add to the log file now");

	// Set visible log level to warning and above
	lbLog::setLogLevel(lbLog::warn);

	DEBUG("We shouldn't see this!");
	WARN("We'll see this,");
	ERROR("And this");

	// Run into some error hey?
	FATAL("Showing off the fatal quit");

	// Program should terminate before it gets here
	ERROR("We past the fatal quit.");

	return 0;
}
