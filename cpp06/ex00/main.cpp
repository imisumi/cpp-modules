#include "ScalarConverter.h"

auto main(int argc, char* argv[]) -> int
{
	if (argc != 2)
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return EXIT_FAILURE;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}