//
//	@Author:	Samuel Lewis
//	@Github:	http://github.com/Samuel-Lewis/lunchbox
//
//	@Project:	Lunchbox Toolset
//

#include <string>
#include <map>
#include <vector>
#include <fstream>

#include "../lunchbox.h"

lbCSV::lbCSV() {}
lbCSV::lbCSV(std::string fileName)
{
	read(fileName);
}
lbCSV::~lbCSV() {}

// TABLE = vector<map <string, string> >
// File name should include path
void lbCSV::read(std::string fileName)
{
	INFO("Loading CSV file '" << fileName << "'");

	std::ifstream file(fileName);

	std::string line = "";

	// Catergories
	std::vector<std::string> keys;
	std::vector<std::string> data;
	std::map<std::string, std::string> inter;

	if (file.good())
	{
		// Get template line, ignoring any comments
		while (keys.size() == 0)
		{
			getline(file, line);
			keys = _splitLine(line);
		}

		// Used just to output message
		std::string debugKeys = "";
		for (unsigned i = 0; i < keys.size(); i++)
		{
			debugKeys += keys[i] + ", ";
		}
		INFO("Loaded CSV keys: " << debugKeys);

		// Get all the other lines
		while (getline (file, line))
		{
			data = _splitLine(line);
			// Make sure it's not an empty line
			if (data.size() > 0)
			{
				if (data.size() != keys.size())
				{
					WARN("Number of data in line does not equal number of keys: #keys=" << keys.size() << ", #vals=" << data.size());
					break;
				}
				for (unsigned i = 0; i < data.size(); i++)
				{
					inter[keys[i]] = data[i];
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

	INFO("Loaded " << table.size() << "cols.");
}

std::vector<std::string> lbCSV::_splitLine(std::string line)
{
	std::vector<std::string> data;
	std::string value = "";

	bool escaped = false;
	if (line == "")
	{
		return data;
	}

	for (unsigned i = 0; i < line.length()+1; i++)
	{
		if (line[i] == '"')
		{
			// Everything within quotes (" ") is escaped
			escaped = !escaped;
		} else if (line[i] == '#' && !escaped) {
			// Everything after the comment sign is ignored
			data.push_back(value);
			break;
		} else if (line[i] == ',' && !escaped) {
			// Split by the comma (if not escaped)
			data.push_back(value);
			value = "";
		} else {
			value += line[i];
		}
	}

	// Add the last value
	data.push_back(value);

	bool allEmpty = true;
	// Used just to output debug message
	std::string debugVals = "";
	for (unsigned i = 0; i < data.size(); i++)
	{
		if (data[i] != "")
		{
			allEmpty = false;
		}

		debugVals += data[i] + ", ";
	}

	// Make it an empty line if all empty
	if (allEmpty)
	{
		data.clear();
	}

	return data;

}
