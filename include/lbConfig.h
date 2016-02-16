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

#include "../lunchbox.h"

class lbConfig
{
private:

	// Indiviual files data, are stored in CfgFile with a key and value
	class CfgFile
	{
	public:
		CfgFile() {};
		~CfgFile() {};

		template <typename T>
		T get(std::string key)
		{
			std::stringstream ss(_itemData[key]);
			T retType;
			ss >> retType;
			LOG("Found config '" << key << "'. Returned '" << _itemData[key] << "'.");
			return retType;
		}

		std::string get(std::string key) { return get<std::string>(key); }

		void set(std::string, std::string);

	private:
		std::map<std::string, std::string> _itemData;
	};

public:
	static CfgFile& file(std::string);

	static void defaultDir(std::string);

	static void clearCache();

private:
	lbConfig();
	~lbConfig();
	static lbConfig* _inst;
	static std::string _defaultDir;

	std::map<std::string, CfgFile*> _files;

	void loadFile(std::string);

};

#endif // LB_CONFIG_H
