#include <iostream>
#include <string>
#include <vector>

#include "../include/lbString.h"

int main() {
	// Some sample string
	std::string str = "A good book praises itself";
	std::cout << str << std::endl;

	// Split the string into seperate words
	// Note that str is still preserved
	std::vector<std::string> words = lbString::split(str, " ");

	// Extended output to show each word
	for (int i = 0; i < words.size(); i++)
	{
		std::cout << words[i] << std::endl;
	}

	// Send all to upper case
	lbString::toUpper(str);
	std::cout << str << std::endl;


	// Send all to lower
	lbString::toLower(str);
	std::cout << str << std::endl;


	// Remove all instancs of "oo"
	lbString::remove(str,"oo");
	std::cout << str << std::endl;

	// Remove all instances of "e"
	lbString::remove(str,"e");
	std::cout << str << std::endl;

	return 0;
}
