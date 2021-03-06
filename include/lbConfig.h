//
//	@Author:	Samuel Lewis
//	@Github:	http://github.com/Samuel-Lewis/lunchbox
//
//	@Project:	Lunchbox Toolset
//


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
			INFO("Found config '" << key << "'. Returned '" << _itemData[key] << "'.");
			return retType;
		}

		std::string get(std::string key) { return get<std::string>(key); }

		void set(std::string, std::string);
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
