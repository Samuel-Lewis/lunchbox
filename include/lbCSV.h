//
//	@Author:	Samuel Lewis
//	@Github:	http://github.com/Samuel-Lewis/lunchbox
//
//	@Project:	Lunchbox Toolset
//


#ifndef _LB_CSV_H
#define _LB_CSV_H

#include <string>
#include <map>
#include <vector>

typedef std::vector<std::map<std::string, std::string> > TABLE;

class lbCSV
{
public:
	lbCSV();
	lbCSV(std::string);
	~lbCSV();

	TABLE table;

	void read(std::string);

private:
	std::vector<std::string> _splitLine(std::string);

};

#endif // _LB_CSV_H
