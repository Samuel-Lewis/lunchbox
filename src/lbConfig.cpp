//===============================================//
//
//	@Author:	Samuel Lewis
//	@Github:	http://github.com/Samuel-Lewis/lunchbox
//
//	@Project:	Lunchbox Toolset
//
//	@Last Updated:	2016-02-11 16:59:54
//	@Created:		2015-12-03 14:31:04
//
//===============================================//


#include <string>
#include <vector>
#include <algorithm>

#include "../include/lbConfig.h"
#include "../include/lbLog.h"
#include "../include/lbFile.h"


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
	// Load file using lbFile
	std::vector<std::string> fileData = lbFile::getFileContents(fileName);

	for (int i = 0; i < (int)fileData.size(); i++)
	{
		std::string line = fileData[i];
		
		if (line.length() > 0 && line[0] != '#')
		{
			// Get everything up to the =
			std::string key = line.substr(0, line.find_first_of("="));

				// line is now the value, everything after the equals
			line.erase(0, line.find_first_of("=")+1);

			trim(key);
			trim(line);

			_data[key] = line;
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
