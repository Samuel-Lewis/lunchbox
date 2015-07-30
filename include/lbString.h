//===============================================//
//
//	@Author:	Samuel Lewis
//	@Project:	https://github.com/Samuel-Lewis/lunchbox
//			
//
//	@Last Updated: 2015-07-30 21:34:41
//	@Created:      2015-07-14 21:26:08
//
//===============================================//

#ifndef LB_STRING_H
#define LB_STRING_H

#include <vector>
#include <string>

class lbString {
public:
	static std::vector<std::string> split(std::string&, std::string);

	static void remove(std::string&, std::string);

	static void toUpper(std::string&);
	static void toLower(std::string&);

	static void getAlpha(std::string&);
	

private:
	// Stop the initialization of a lbString
	lbString();

};

#endif //LB_STRING_H
