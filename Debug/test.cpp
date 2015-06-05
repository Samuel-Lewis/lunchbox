#include "Debug.h"

int main()
{
	Debug::setQuitLevel(1);
	Debug::setLogLevel(0);
	Debug::setFileLogLevel(0);

	Debug::startLog();
	WARN("Don't know where I live... Help");
	INFO("I might know");
	Debug::startLog("ads");

	Debug::endLog();

	Debug::startLog("","panic one");
	FATAL("DEATH TO THE PROGRAM");

	return 0;
}
