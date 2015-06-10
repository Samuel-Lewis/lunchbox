
//====================================================//
// AUTHOR		Samuel Lewis
// LASTE UPDATE	10/06/2015
// PROJECT		Lunch Box - String Tools
//
// OUTLINE
//		LunchBox string mainpulation and search tools
//====================================================//

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
	

private:
	// Stop the initialization of a lbString
	lbString();

};

#endif //LB_STRING_H
