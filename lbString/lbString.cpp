
//====================================================//
// AUTHOR		Samuel Lewis
// LASTE UPDATE	10/06/2015
// PROJECT		Lunch Box - String Tools
//
// OUTLINE
//		LunchBox string mainpulation and search tools
//====================================================//

#include <string>
#include <vector>
#include <ctype.h>

#include "lbString.h"

// Split a string up by at least one delimeter string. Return it all in a vector of substrings
std::vector<std::string> lbString::split (std::string& sentString, std::string delim)
{
	// The vector to return with the sub strings
	std::vector<std::string> newStrings;

	// Store the sent string into a working string, so as not to mutate users string.
	std::string workingString = sentString;

	// Find the first delim
	std::size_t nextPos = workingString.find(delim);
	while(nextPos != std::string::npos)
	{
		// Get up to the found delim, and add to vector of sub strings
		newStrings.push_back(workingString.substr(0,nextPos));

		// Erase that phrase, so as to allow checking for next delim
		// This is why we have a workinString, so we don't erase users' sent string
		workingString.erase(0,nextPos+delim.size());

		nextPos = workingString.find(delim);
	}
	
	// Add the last value, where there are no more delims
	newStrings.push_back(workingString);

	return newStrings;
}


// Removes a given string from another given string.
void lbString::remove(std::string& sentString, std::string item)
{
	std::size_t nextPos = sentString.find(item);
	while(nextPos != std::string::npos)
	{
		// Keep removing the substring until it no longer exsists
		sentString.erase(nextPos,item.size());
		nextPos = sentString.find(item);
	}

}

// Make all chars in string upper case
void lbString::toUpper(std::string& sentString)
{
	for (int i = 0; i < sentString.size(); i++)
	{
		sentString[i] = toupper(sentString[i]);
	}
}

// Make all chars in string lower case
void lbString::toLower(std::string& sentString)
{
	for (int i = 0; i < sentString.size(); i++)
	{
		sentString[i] = tolower(sentString[i]);
	}
}
