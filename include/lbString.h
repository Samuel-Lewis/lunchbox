//===============================================//
//
//	@Author:	Samuel Lewis
//	@Github:	http://github.com/Samuel-Lewis/lunchbox
//
//	@Project:	Lunchbox Toolset
//
//	@Last Updated:	2015-12-03 14:33:01
//	@Created:		2015-07-14 21:26:08
//
//===============================================//

#ifndef _LB_STRING_H
#define _LB_STRING_H

#include <vector>
#include <string>

namespace lbString {
	std::vector<std::string> split(std::string&, std::string);

	void remove(std::string&, std::string);

	void toUpper(std::string&);
	void toLower(std::string&);

	void getAlpha(std::string&);

	// Trim whitespaces
	void trim(std::string&);
	void trim(std::string&, std::string);

}

#endif //_LB_STRING_H
