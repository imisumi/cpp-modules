#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cassert>
#include <list>

#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"

#define BRIGHT_CYAN "\033[38;5;51m"
#define DIM_CYAN "\033[38;5;30m"
#define BRIGHT_YELLOW "\033[38;5;11m"
#define DIM_YELLOW "\033[38;5;100m"
#define RESET "\033[0m"

template <typename T>
T fillContainer(char* argv[], int size)
{
	T container;
	if constexpr (std::is_same_v<T, std::vector<typename T::value_type>>)
	{
		container.reserve(size);
	}
	for (int i = 1; i < size; ++i)
	{
		try
		{
			container.emplace_back(std::stoi(argv[i]));
		}
		catch (const std::invalid_argument& e)
		{
			std::cerr << "Invalid argument: " << argv[i] << std::endl;
		}
		catch (const std::out_of_range& e)
		{
			std::cerr << "Out of range: " << argv[i] << std::endl;
		}
	}
	return container;
}

template <typename T>
void logSequence(T container, const std::string& prefix = "default", size_t trimSize = 0)
{
	std::cout << CYAN << prefix << RESET << " ";
	if (container.size() > trimSize)
	{
		for (size_t i = 0; i < trimSize; ++i)
		{
			std::cout << container[i] << " ";
		}
		std::cout << "... ";
		for (size_t i = container.size() - trimSize; i < container.size(); ++i)
		{
			std::cout << container[i] << " ";
		}
	}
	else
	{
		for (const auto& num : container)
		{
			std::cout << num << " ";
		}
	}
	std::cout << std::endl;
}