#include "Array.h"
#include <iostream>
#include <array>

int main(void)
{
	std::cout << "Array of ints" << std::endl;
	Array<int> a(5);
	for (auto &i : a)
	{
		i = 42;
	}
	for (auto &i : a)
	{
		std::cout << i << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Copy constructor" << std::endl;
	Array<int> b = a;
	for (auto &i : b)
	{
		std::cout << i << std::endl;
	}
	b = b;

	std::cout << std::endl;
	std::cout << "Copy assignment operator" << std::endl;
	Array<int> c(b);
	for (auto &i : c)
	{
		std::cout << i << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Array of arrays" << std::endl;

	Array<Array<int>> d(5);
	for (uint32_t i = 0; i < d.size(); i++)
	{
		d[i] = Array<int>(i);
		for (auto &j : d[i])
		{
			j = i;
		}
	}

	for (auto &i : d)
	{
		for (auto &j : i)
		{
			std::cout << j;
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Move semantics" << std::endl;

	for (auto &i: b)
	{
		std::cout << i << std::endl;
	}
	Array<int> e = std::move(b);
	std::cout << b.size() << std::endl;
	for (auto &i: e)
	{
		std::cout << i << std::endl;
	}


	std::cout << std::endl;
	std::cout << "Out of range" << std::endl;
	Array<int> f(5);
	try
	{
		f[5] = 42;
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Array of strings" << std::endl;
	Array<std::string> g(5);
	for (auto &i : g)
	{
		i = "hello";
	}
	for (auto &i : g)
	{
		std::cout << i << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Early deconstruction" << std::endl;
	Array<int> h(5);
	h.~Array();

	return 0;
}