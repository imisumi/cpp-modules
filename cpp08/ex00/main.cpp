#include <iostream>

#include <algorithm>
#include <deque>
#include <list>
#include <array>
#include <vector>

#include "easyfind.h"

#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m\n"

// Function to test easyfind on a container with valid and invalid values
template <typename Container>
void testEasyFind(Container &container, int value)
{
	auto it = easyfind(container, value);
	if (it != container.end())
		std::cout << GREEN << "	Found: " << *it << RESET;
	else
		std::cout << RED << "	Not found: " << value << RESET;
}

int main()
{
	std::cout << CYAN << "std::array" << RESET;
	std::array<int, 5> arr = {1, 2, 3, 4, 5};
	testEasyFind(arr, 1);
	testEasyFind(arr, 11);

	std::cout << CYAN << "std::vector" << RESET;
	std::vector<int> vec = {1, 2, 3, 4, 5};
	testEasyFind(vec, 1);
	testEasyFind(vec, 11);

	std::cout << CYAN << "std::deque" << RESET;
	std::deque<int> deq = {1, 2, 3, 4, 5};
	testEasyFind(deq, 1);
	testEasyFind(deq, 11);

	std::cout << CYAN << "std::list" << RESET;
	std::list<int> lst = {1, 2, 3, 4, 5};
	testEasyFind(lst, 1);
	testEasyFind(lst, 11);

	return 0;
}
