#ifndef _LB_CSV_H
#define _LB_CSV_H

#include <string>
#include <map>
#include <vector>

typedef std::vector<std::map<std::string, std::string> > TABLE;

class lbCSV
{
public:
	static TABLE read(std::string);

private:
	lbCSV();
	~lbCSV();

	static std::vector<std::string> splitLine(std::string);

};

#endif // _LB_CSV_H
