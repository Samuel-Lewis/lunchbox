#include <vector>

#include "include/lbLog.h"
#include "include/lbRNG.h"
#include "include/lbString.h"

int main()
{
	// lbLog demo
	// Set debug levels to show all, log all, and quit on fatal
	lbLog::quickSet(lbLog::all, lbLog::all, lbLog::fatal);

	// Start the log in root directory, named 'testlog-[timestamp].log'
	lbLog::startLog("","testlog",true);

	// lbRNG demo
	INFO("A random number between 0 and 10 is " << lbRNG::linear(0,10));
	INFO("A normally distrubuted number mean = 5, std dev = 2:  " << lbRNG::normDist(5,2));

	// lbString demo
	std::string str = "RACE car";
	std::vector<std::string> words = lbString::split(str, " ");

	for (unsigned i = 0; i < words.size(); i++)
	{
		lbString::toLower(words[i]);
		WARN("\t" << words[i]);
		lbString::toUpper(words[i]);
		WARN("\t" << words[i]);
	}

}
