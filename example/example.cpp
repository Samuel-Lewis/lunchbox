#include <vector>

#include "../include/lbLog.h"
#include "../include/lbRNG.h"
#include "../include/lbString.h"
#include "../include/lbCSV.h"

int main()
{
	// ==== lbLog demo ==== 
	// Set debug levels to show all, log all, and quit on fatal
	lbLog::quickSet(lbLog::all, lbLog::all, lbLog::fatal);

	// Start the log in root directory, named 'testlog-[timestamp].log'
	lbLog::startLog("example/logs/","testlog",true);

	// ==== lbRNG demo ==== 
	INFO("A random number between 0 and 10 is " << lbRNG::linear(0,10));
	INFO("A normally distrubuted number mean = 5, std dev = 2:  " << lbRNG::normDist(5,2));

	// ==== lbString demo ==== 
	std::string str = "RACE car";
	std::vector<std::string> words = lbString::split(str, " ");

	for (unsigned i = 0; i < words.size(); i++)
	{
		lbString::toLower(words[i]);
		WARN(words[i]);
		lbString::toUpper(words[i]);
		WARN(words[i]);
	}

	// ==== lbCSV demo ==== 
	// fakelist.csv doens't exist, will thrown an error
	TABLE fakeList = lbCSV::read("fakelist.csv");
	TABLE list = lbCSV::read("example/list.csv");

	std::string fullLine = "";
	for(auto const &entry : list[0])
	{
		fullLine += entry.first + " ";
	}
	DEBUG(fullLine);

	// Note: these won't display in order due to map storing.
	for (unsigned i = 0; i < list.size(); i++)
	{
		fullLine = "";
		for(auto const &entry : list[i])
		{
			fullLine += entry.second + " ";
		}
		DEBUG(fullLine);
	}

	// Throwing an error that will end the program
	// FATAL("Bye bye");

	// Normal program ending
	lbLog::endLog();

	return 0;

}
