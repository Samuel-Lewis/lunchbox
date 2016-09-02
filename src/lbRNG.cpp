//
//	@Author:	Samuel Lewis
//	@Github:	http://github.com/Samuel-Lewis/lunchbox
//
//	@Project:	Lunchbox Toolset
//

#include "../lunchbox.h"

/*
* I am sorry I have to do this. It's butt ugly I know.
* However, you can't initialize these in the header, as a new instance would be created for every template type variation.
* Hence you get mad duplicates of them. So they go here for now. As gross global variables.
*/

// Static vars
std::string lbRNG::_seedStr = "";
std::default_random_engine lbRNG::_eng;
