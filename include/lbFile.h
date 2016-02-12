//===============================================//
//
//	@Author:	Samuel Lewis
//	@Github:	http://github.com/Samuel-Lewis/lunchbox
//
//	@Project:	Lunchbox Toolset
//
//	@Last Updated:	2016-02-12 10:00:19
//	@Created:		2016-02-11 16:44:03
//
//===============================================//


#ifndef LB_FILE_H
#define LB_FILE_H

#include <string>
#include <vector>

namespace lbFile
{
	std::vector<std::string> getFileContents(std::string);

	std::vector<std::string> getContentsOfDir(std::string);

	void writeToFile(std::string, std::string);

};

#endif // LB_FILE_H
