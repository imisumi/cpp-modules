#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cassert>
#include <list>
#include <type_traits>
#include <chrono>

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

class PmergeMe
{
public:
	template <typename T>
	static T fillContainer(char* argv[], int size)
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
				int value = std::stoi(argv[i]);
				container.emplace_back(value);
			}
			catch (const std::invalid_argument& e)
			{
				std::cerr << "Error: Argument '" << argv[i] << "' is not a valid integer." << std::endl;
				throw;
			}
			catch (const std::out_of_range& e)
			{
				// Handle out-of-range error (value too large or small)
				std::cerr << "Error: Argument '" << argv[i] << "' is out of range for an integer." << std::endl;
				throw;
			}
		}
		return container;
	}

	template <typename T>
	static void logSequence(const T& c, const std::string& prefix = "default", size_t trimSize = 0)
	{
		std::cout << CYAN << prefix << RESET << " ";
		
		if (trimSize && c.size() > trimSize * 2)
		{
			auto it = c.begin();
			
			for (size_t i = 0; i < trimSize; ++i)
			{
				std::cout << *it << " ";
				std::advance(it, 1);
			}
			std::cout << "... "; 
			auto itEnd = c.end();
			std::advance(itEnd, -trimSize);
			for (auto lastIt = itEnd; lastIt != c.end(); ++lastIt)
			{
				std::cout << *lastIt << " ";
			}
		}
		else
		{
			for (const auto& num : c)
			{
				std::cout << num << " ";
			}
		}
		std::cout << std::endl;
	}

	template <typename T>
	static bool isSorted(const T& container)
	{
		auto it = container.begin();
		auto prev = it;
		std::advance(it, 1);
		for (; it != container.end(); std::advance(it, 1), std::advance(prev, 1))
		{
			if (*prev > *it)
			{
				return false;
			}
		}
		return true;
	}
	static int mergeInsertionSort(std::vector<int>& v);
	static int mergeInsertionSort(std::list<int>& v);
private:
	static void mergeInsertionSort(std::vector<int>& container, int pair_level);
	static void mergeInsertionSort(std::list<int>& container, int pair_level);
	static void log_pairs(std::vector<std::pair<std::vector<int>, std::vector<int>>> pairs, std::vector<int> odd_pair, std::vector<int> stray_numbers);
	static void log_sequence(const std::vector<std::vector<int>>& s, const std::string& title = "", const std::string& color = "");
	static void log_sequence(const std::vector<int>& s, const std::string& title = "", const std::string& color = "");
	static int jacobsthalNumber(long n);
};

class Timer
{
public:
	Timer();
	Timer(const Timer&) = delete;
	Timer& operator=(const Timer&) = delete;
	~Timer() = default;

	void Reset();
	float Elapsed() const;
	float ElapsedMillis() const;
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_Start;
};