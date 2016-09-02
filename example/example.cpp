//
//	@Author:	Samuel Lewis
//	@Github:	http://github.com/Samuel-Lewis/lunchbox
//
//	@Project:	Lunchbox Toolset
//

// #define _LB_EXAMPLE
#ifdef _LB_EXAMPLE

#include <vector>

#include "../lunchbox.h"

int main()
{
	// ==== lbLog demo ==== //
	// Set debug levels to show all, log all, and quit on fatal
	lbLog::quickSet(lbLog::info, lbLog::all, lbLog::fatal);

	// Start the log in example/logs directory, named 'testlog-[timestamp].log'
	lbLog::startLog("logs/","testlog",true);

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
	list.read("list.csv");
	INFO(list.table[2]["First names"]);
	// Check out the log, or set the log level to show INFO if you want to see the read results

	// // ==== lbConfig demo ==== //
	INFO("Phrase: " << lbConfig::file("config.txt").get("phrase"));
	INFO("XP Gain: " << lbConfig::file("config.txt").get<float>("xp_gain"));
	INFO("Tile width: " << lbConfig::file("config.txt").get<int>("tile_width"));

	// If you're concerend your loading in too much, you can clear cache
	lbConfig::clearCache();

	// ==== lbFile demo ==== //
	INFO("My file contents:\n" << lbFile::getFileContents("config.txt"));
	lbFile::writeToFile("config.txt", "death_msg = Arrgghhh...");

	// ==== lbTest demo ==== //
	lbTest::TEST_GROUP("SampleTests 1");
	// lbTest::TEST(expected,actual);
	lbTest::TEST(3,3);
	lbTest::TEST(2,2);
	lbTest::TEST(1.2567,1.2567);

	lbTest::TEST_GROUP("SampleTests 2");
	lbTest::TEST((std::string)"expected",(std::string)"actual");
	lbTest::TEST(std::vector<int>{3,6,2},std::vector<int>{3,6,2});
	lbTest::TEST(std::vector<int>{1,6,2},std::vector<int>{3,6,2});

	lbTest::TEST_END();

	// ==== lbLog demo ==== //
	// Throwing an error that will end the program
	FATAL("Bye bye");

	INFO("You should not be able to see this info message!");

	// Normal program ending
	lbLog::endLog();

	return 0;

}

#endif // _LB_EXAMPLE
