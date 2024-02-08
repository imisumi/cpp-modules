#include <iostream>
#include <fstream>


void	replace(std::string &line, const std::string &s1, const std::string &s2, std::size_t pos)
{
	std::size_t found = line.find(s1, pos);
	if (found != std::string::npos)
	{
		line.insert(found + s1.size(), s2);
		line.erase(found, s1.size());
		replace(line, s1, s2, found + s2.size());
	}
}

// intput  filename s1 s2
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
		replace(line, s1, s2, 0);
		std::cout << line << std::endl;
	}

	return EXIT_SUCCESS;
}
