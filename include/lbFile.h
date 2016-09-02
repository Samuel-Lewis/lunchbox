//
//	@Author:	Samuel Lewis
//	@Github:	http://github.com/Samuel-Lewis/lunchbox
//
//	@Project:	Lunchbox Toolset
//



#ifndef LB_FILE_H
#define LB_FILE_H

#include <string>
#include <vector>

namespace lbFile
{
	std::string getFileContents(std::string);
	std::vector<std::string> getFileLines(std::string);

	std::vector<std::string> getContentsOfDir(std::string);

	void writeToFile(std::string, std::string);

};

#endif // LB_FILE_H
