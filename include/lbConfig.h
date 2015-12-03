//===============================================//
//
//	@Author:	Samuel Lewis
//	@Github:	http://github.com/Samuel-Lewis/lunchbox
//
//	@Project:	Lunchbox Toolset
//
//	@Last Updated:	2015-12-03 14:31:09
//	@Created:		2015-12-03 14:31:04
//
//===============================================//


#ifndef LB_CONFIG_H
#define LB_CONFIG_H

#include <string>
#include <sstream>
#include <map>

class lbConfig
{
public:
	lbConfig();
	lbConfig(std::string);
	~lbConfig();

	void read(std::string);
	
	// Get and convert to type
	template<typename T>
	T get(std::string key)
	{
		// Use a stringstream to try and convert
		std::stringstream ss(_data[key]);

		T retType;
		ss >> retType;

		return retType;
	}

	std::string operator[](std::string);
	std::string get(std::string);

private:

	std::map<std::string, std::string> _data;

	void trim(std::string&);

};

#endif // LB_CONFIG_H
