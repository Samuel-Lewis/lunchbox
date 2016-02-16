//===============================================//
//
//	@Author:	Samuel Lewis
//	@Github:	http://github.com/Samuel-Lewis/lunchbox
//
//	@Project:	Lunchbox Toolset
//
//	@Last Updated:	2016-02-14 15:37:54
//	@Created:		2016-02-11 16:45:20
//
//===============================================//

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

// OS Specific
#if WINDOWS
	#include <windows.h>
#else
	#include <dirent.h>
	#include <unistd.h>
	#include <sys/stat.h>
	#include <sys/types.h>
#endif

#include "../lunchbox.h"

std::vector<std::string> lbFile::getFileContents(std::string filePath)
{
	LOG("Reading data from file " << filePath);
	std::ifstream file;
	file.open(filePath);

	std::vector<std::string> data = {};
	std::string line = "";

	// Read every line of the file and add it to an array
	if (file.good())
	{
		while(getline(file, line))
		{
			data.push_back(line);
		}
	} else {
		// File not found.
		WARN("Could not find file " << filePath << ". Returning empty vector.");
		return data;
	}

	LOG("Successfully read file");

	return data;
}


// Credit to Andreas Bonini (stackoverflow.com), with some edits.
std::vector<std::string> lbFile::getContentsOfDir(std::string dirPath)
{
	std::vector<std::string> files;
	LOG("Searching for files in '" << dirPath << "'");

	#ifdef WINDOWS
	// If WINDOWS

	HANDLE dir;
	WIN32_FIND_DATA file_data;

	if ((dir = FindFirstFile((dirPath + "/*").c_str(), &file_data)) == INVALID_HANDLE_VALUE)
	{
		LOG("No files found in " << dirPath);
		return files;
	}

	do
	{
		const std::string file_name = file_data.cFileName;
		const std::string full_file_name = dirPath + "/" + file_name;
		const bool is_directory = (file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;

		if (file_name[0] == '.' || is_directoy)
		{
			continue;
		}

		files.push_back(full_file_name);
	} while (FindNextFile(dir, &file_data));

	FindClose(dir);

	#else
	// else if UNIX

	DIR *dir;
	dirent *ent;
	struct stat st;

	dir = opendir(dirPath.c_str());

	// Make sure path is valid
	if (stat(dirPath.c_str(), &st) < 0 || (st.st_mode & S_IFDIR) == 0)
	{
		WARN(dirPath << " is not a valid path, or you don't have permission to it.");
		return files;
	}

	while ((ent = readdir(dir)) != NULL) {
		const std::string file_name = ent->d_name;
		const std::string full_file_name = dirPath + "/" + file_name;

		if (file_name[0] == '.' || stat(full_file_name.c_str(), &st) < 0)
		{
			continue;
		}

		if ((st.st_mode & S_IFDIR) != 0)
		{
			continue;
		}

		files.push_back(full_file_name);
	}

	closedir(dir);
	#endif

	return files;
}


void lbFile::writeToFile(std::string filePath, std::string str)
{
	std::fstream outfile;
	// Make sure we open, and set to append mode
	outfile.open(filePath, std::fstream::out | std::fstream::app);
	outfile << "\n" << str;
	outfile.close();
}
