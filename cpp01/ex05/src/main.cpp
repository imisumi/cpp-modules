#include "Harl.h"

// intput  filename s1 s2
int main(void)
{
	Harl level;
	
	level.complain("DEBUG");
	level.complain("INFO");
	level.complain("WARNING");
	level.complain("ERROR");
	level.complain("INVALID");
	return EXIT_SUCCESS;
}
