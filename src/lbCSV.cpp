//===============================================//
//
//	@Author:	Samuel Lewis
//	@Github:	http://github.com/Samuel-Lewis/lunchbox
//
//	@Project:	Lunchbox Toolset
//
//	@Last Updated:	2015-09-30 13:43:43
//	@Created:		2015-09-30 13:34:43
//
//===============================================//

#include <string>
#include <map>
#include <vector>
#include <fstream>

#include "../include/lbCSV.h"

#include "../include/lbLog.h"


lbCSV::lbCSV() {}
lbCSV::~lbCSV() {}

// TABLE = vector<map <string, string> >
// File name should include path
TABLE lbCSV::read(std::string fileName)
{
	TABLE table;
	INFO("Attempting to load CSV file: " << fileName);

	std::ifstream file(fileName);

	std::string line = "";	

	// Catergories
	std::vector<std::string> keys;
	std::vector<std::string> values;
	std::map<std::string, std::string> inter;

	if (file.good())
	{
		INFO("CSV file is good.");
		
		// Get template line, ignoring any comments
		while (keys.size() == 0)
		{
			getline(file, line);
			keys = splitLine(line);
		}

		// Used just to output message
		std::string debugKeys = "";
		for (unsigned i = 0; i < keys.size(); i++)
		{
			debugKeys += keys[i] + ", ";
		}
		DEBUG("Loaded CSV keys: " << debugKeys);

		// Get all the other lines
		while (getline (file, line))
		{
			values = splitLine(line);
			// Make sure it's not an empty line
			if (values.size() > 0)
			{
				if (values.size() != keys.size())
				{
					ERROR("Number of values in line does not equal number of keys: #keys=" << keys.size() << ", #vals=" << values.size());
					break;
				}
				for (unsigned i = 0; i < values.size(); i++)
				{
					inter[keys[i]] = values[i];
				}

				// Add line to the full list
				table.push_back(inter);
				inter.clear();
			}
		}

		// always remember to close your files kids
		file.close();
	} else {
		ERROR("Could not open CSV file: " << fileName);
	}

	return table;
}

std::vector<std::string> lbCSV::splitLine(std::string line)
{
	std::vector<std::string> values;
	std::string value = "";

	bool escaped = false;
	if (line != "")
	{
		for (unsigned i = 0; i < line.length()-1; i++)
		{
			if (line[i] == '"')
			{
			// Everything within quotes (" ") is escaped 
				escaped = !escaped;
			} else if (line[i] == '#' && !escaped) {
			// Everything after the comment sign is ignored
				values.push_back(value);
				break;
			} else if (line[i] == ',' && !escaped) {
			// Split by the comma (if not escaped)
				values.push_back(value);
				value = "";
			} else {
				value += line[i];
			}
		}
	}

	// Add the last value
	values.push_back(value);

	bool allEmpty = true;
	// Used just to output debug message
	std::string debugVals = "";
	for (unsigned i = 0; i < values.size(); i++)
	{
		if (values[i] != "")
		{
			allEmpty = false;
		}
		debugVals += values[i] + ", ";
	}

	DEBUG("Read line: " << debugVals);

	// Make it an empty line if all empty
	if (allEmpty)
	{
		values.clear();
	}

	return values;

}
