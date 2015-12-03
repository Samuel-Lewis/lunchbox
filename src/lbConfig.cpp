//===============================================//
//
//	@Author:	Samuel Lewis
//	@Github:	http://github.com/Samuel-Lewis/lunchbox
//
//	@Project:	Lunchbox Toolset
//
//	@Last Updated:	2015-12-03 14:31:18
//	@Created:		2015-12-03 14:31:04
//
//===============================================//


#include <string>
#include <fstream>
#include <algorithm>

#include "../include/lbConfig.h"

lbConfig::lbConfig()
{}

lbConfig::lbConfig(std::string fileName)
{
	read(fileName);
}

lbConfig::~lbConfig()
{}

// Warning, will overwrite any existing values in _data
void lbConfig::read(std::string fileName)
{
	std::ifstream file;
	file.open(fileName);

	std::string line = "";
	std::string key = "";

	if(file.good())
	{
		while (getline(file, line))
		{
			// Removes lead and tail whitespace
			trim(line);

			// Make sure there is content in the string, and that it's not a comment
			if (line.length() > 0 && line[0] != '#')
			{
				// Get everything up to the =
				key = line.substr(0, line.find_first_of("="));

				// line is now the value, everything after the equals
				line.erase(0, line.find_first_of("=")+1);

				trim(key);
				trim(line);

				_data[key] = line;
			}
		}
	}
}

// Shortcut to get strings
std::string lbConfig::get(std::string key)
{
	return _data[key];
}

std::string lbConfig::operator[](std::string keyName)
{
	return get(keyName);
}


// Utility
void lbConfig::trim(std::string& str)
{
	// Trim leading whitespace or tabs
	str.erase(0, str.find_first_not_of(" \t"));

	// Trimp trailing whitespace or tabs
	std::reverse(str.begin(), str.end());
	str.erase(0, str.find_first_not_of(" \t"));
	std::reverse(str.begin(), str.end());
}
