//===============================================//
//
//	@Author:	Samuel Lewis
//	@Project:	https://github.com/Samuel-Lewis/lunchbox
//			
//
//	@Last Updated: 2015-07-30 21:32:29
//	@Created:      2015-07-14 21:26:08
//
//===============================================//

#include <iostream>
#include <cmath>
#include <map>
#include <fstream>


#include "../include/lbRNG.h"

int main() {
	// std::cout << "Linear() int[1,10]: " << lbRNG::linear<int>(1,10) << std::endl;
	// std::cout << "Linear() float[0,2]: " << lbRNG::linear<float>(0.0,2.0) << std::endl;
	// std::cout << "Linear() double[30,100]: " << lbRNG::linear<double>(30,100) << std::endl;

	// std::cout << std::endl;

	// std::cout << "normDist() int[0,1]: " << lbRNG::normDist<int>(0,1) << std::endl;
	// std::cout << "normDist() float[3.0,3.0]: " << lbRNG::normDist<float>(3.0,3.0) << std::endl;
	// std::cout << "normDist() double[100,30]: " << lbRNG::normDist<double>(100,30) << std::endl;

	// std::cout << std::endl;

	// std::cout << "expD() float[0,2,1,1]: " << lbRNG::expD<float>(0,2,1,1) << std::endl;
	// std::cout << "expD() float[4,10,10,1]: " << lbRNG::expD<float>(4,10,10,1) << std::endl;

	
	// std::map<int,int> cheese;
	// for (int i = 0; i < 2; i++)
	// {
	// 	cheese[i] = 0;
	// }

	// for (int j = 0; j < 300; j++)
	// {
	// 	cheese[floor(lbRNG::quadratic<float>(0,2,2))]++;
	// }

	// for (const auto &p : cheese)
	// {
	// 	std::cout << p.first << ": ";
	// 	for (int l = 0; l < p.second; l++)
	// 	{
	// 		std::cout << "*";
	// 	}
	// 	std::cout << std::endl;
	// }

	std::ofstream file;
	file.open("results.txt");

	for (int i = 0; i < 1000; i++)
	{
		file << lbRNG::quadratic<float>(0,2,2);
		file << "\n";
	}


	return 0;
}
