//
//	@Author:	Samuel Lewis
//	@Github:	http://github.com/Samuel-Lewis/lunchbox
//
//	@Project:	Lunchbox Toolset
//


#ifndef _LB_RNG_H
#define _LB_RNG_H

#include <string>
#include <random>

class lbRNG
{
private:
	lbRNG();
	~lbRNG();

	static std::string _seedStr;
	static std::default_random_engine _eng;

public:

	// SEED SETTERS / GETTERS
	static std::string generateSeed(std::string seedStr)
	{

		_seedStr = seedStr;
		std::seed_seq seed(seedStr.begin(), seedStr.end());
		_eng.seed(seed);

		INFO("Generated seed from '" << seedStr << "'");

		return _seedStr;
	}

	static std::string generateSeed()
	{
		// Random number to string, to use as seed
		std::random_device rd;
		return generateSeed(std::to_string(rd()));
	}

	static std::string getSeed()
	{
		if (_seedStr == "")
		{
			generateSeed();
		}

		return _seedStr;
	}

	// RAW NUMBER GENERATORS
	template<typename T>
	static T linear(T lower, T upper)
	{
		getSeed();
		std::uniform_real_distribution<> dist(lower, upper);
		return dist(_eng);
	}

	template <typename T>
	static T normDist(T mean, T stdDev)
	{
		getSeed();
		std::normal_distribution<> dist(mean, stdDev);
		return dist(_eng);
	}

	// DEPENDANT CHANCES
	static bool decision(float weight)
	{
		return linear(0.0,1.0) < weight;
	}
};

#endif // _LB_RNG_H
