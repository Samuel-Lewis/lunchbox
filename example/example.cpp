//===============================================//
//
//	@Author:	Samuel Lewis
//	@Github:	http://github.com/Samuel-Lewis/lunchbox
//
//	@Project:	Lunchbox Toolset
//
//	@Last Updated:	2016-02-12 13:04:37
//	@Created:		2015-09-30 13:45:13
//
//===============================================//

#define _LB_EXAMPLE
#ifdef _LB_EXAMPLE

#include <vector>

#include "../lunchbox.h"

int main()
{
	// ==== lbLog demo ==== //
	// Set debug levels to show all, log all, and quit on fatal
	lbLog::quickSet(lbLog::info, lbLog::all, lbLog::fatal);

	// Start the log in example/logs directory, named 'testlog-[timestamp].log'
	lbLog::startLog("example/logs/","testlog",true);

	// ==== lbRNG demo ==== //
	// INFO(lbRNG::generateSeed("custom seed string"));
	INFO("A random number between 0 and 10 is " << lbRNG::linear(0,10));
	INFO("A random number between 0 and 10 is " << lbRNG::linear(0,10));
	INFO("A normally distributed N(5,2)" << lbRNG::normDist(5,2));

	INFO("Seed: " << lbRNG::getSeed())

	// ==== lbString demo ==== //
	std::string str = "     RACE car    ";
	lbString::trim(str);
	std::vector<std::string> words = lbString::split(str, " ");

	for (unsigned i = 0; i < words.size(); i++)
	{
		lbString::toLower(words[i]);
		WARN(words[i]);
		lbString::toUpper(words[i]);
		WARN(words[i]);
	}

	// ==== lbCSV demo ==== //
	// fakelist.csv doens't exist, will throw an error
	lbCSV list("fakelist.csv");
	list.read("example/list.csv");
	INFO(list.table[2]["First names"]);
	// Check out the log, or set the log level to show INFO if you want to see the read results

	// // ==== lbConfig demo ==== //
	INFO("Phrase: " << lbConfig::file("example/config.txt").get("phrase"));
	INFO("XP Gain: " << lbConfig::file("example/config.txt").get<float>("xp_gain"));

	// If writing the full path is too tedious, you can set default directory
	lbConfig::defaultDir("example/");

	INFO("Tile width: " << lbConfig::file("config.txt").get<int>("tile_width"));

	// ==== lbFile demo ==== //
	std::vector<std::string> localFiles = lbFile::getContentsOfDir("example");
	for (int i = 0; i < (int)localFiles.size(); i++)
	{
		INFO(localFiles[i]);
	}

	lbFile::writeToFile("example/config.txt", "death_msg = Arrgghhh...");


	// Throwing an error that will end the program
	FATAL("Bye bye");

	INFO("You should not be able to see this info message!");

	// Normal program ending
	lbLog::endLog();

	return 0;

}

#endif // _LB_EXAMPLE
