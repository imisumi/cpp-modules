#include <iostream>
#include <fstream>



int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Expected input; filename s1 s2" << std::endl;
		return EXIT_FAILURE;
	}
	const std::string filename = argv[1];
	const std::string s1 = argv[2];
	const std::string s2 = argv[3];

	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Failed to open file" << std::endl;
		return EXIT_FAILURE;
	}
	std::string line;
	while (std::getline(file, line))
	{
		std::cout << line << std::endl;
	}
	
	return EXIT_SUCCESS;
}
