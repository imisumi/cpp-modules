#include <iostream>


int	main(void)
{
	const std::string str = "HI THIS IS BRAIN";
	const std::string* ptr = &str;
	const std::string& ref = str;

	std::cout << "str: " << &str << std::endl;
	std::cout << "ptr: " << ptr << std::endl;
	std::cout << "ref: " << &ref << std::endl;

	std::cout << std::endl;

	std::cout << "str: " << str << std::endl;
	std::cout << "ptr: " << *ptr << std::endl;
	std::cout << "ref: " << ref << std::endl;
	return (EXIT_SUCCESS);
}