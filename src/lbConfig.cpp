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

#include "../lunchbox.h"

// Static var pre decleration
lbConfig* lbConfig::_inst;
std::string lbConfig::_defaultDir = "";

lbConfig::lbConfig()
{}

lbConfig::~lbConfig()
{}

lbConfig::CfgFile& lbConfig::file(std::string filePath)
{
	// If there is no instance of itself, make one. Making this a singleton
	if (_inst == nullptr)
	{
		INFO("Initializing lbConfig");
		_inst = new lbConfig();
	}

	filePath = _defaultDir + filePath;

	// Check if file has been loaded yet
	if(!(_inst->_files.count(filePath)))
	{
		INFO(filePath << " config not loaded.");
		_inst->loadFile(filePath);
	}

	return *(_inst->_files[filePath]);
}


void lbConfig::loadFile(std::string filePath)
{
	INFO("Loading config file " << filePath << "...");

	// Read the contents of the file
	std::vector<std::string> lines = lbFile::getFileContents(filePath);

	if (lines.size() == 0)
	{
		WARN("No configs loaded from file " << filePath <<". Please check the path or the files contents.");
		return;
	}

	_files[filePath] = new CfgFile();

	for (int i = 0; i < (int)lines.size(); i++)
	{
		std::string line = lines[i];

		// Ignore blank lines, or lines with '#' (comment lines)
		if (line.size() == 0 || line.find_first_not_of(" \t") == '#')
		{
			continue;
		}

		// Split key and data at the *FIRST* equals sign.
		// Technically, I guess you could have an equal in the data then
		std::string key = line.substr(0, line.find_first_of("="));
		std::string data = line.substr(line.find_first_of("=")+1, line.size());

		// Trim white space
		lbString::trim(key);
		lbString::trim(data);

		// Only possible because friend class :D
		_files[filePath]->set(key, data);

	}
}

void lbConfig::defaultDir(std::string path)
{
	_defaultDir = path;
}

void lbConfig::CfgFile::set(std::string key, std::string val)
{
	if (_itemData.count(key))
	{
		WARN("Overwriting key '" << key << "' from '" << _itemData[key] << "' to '" << val << "'.");
	}

	_itemData[key] = val;
}

void lbConfig::clearCache()
{
	for (auto const& entry : _inst->_files)
	{
		delete _inst->_files[entry.first];
	}

	_inst->_files.clear();
}
