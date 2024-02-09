#include "Harl.h"

// intput  filename s1 s2
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <log level>" << std::endl;
		return EXIT_FAILURE;
	}
	Harl level;
	
	level.complain(argv[1]);
	return EXIT_SUCCESS;
}
