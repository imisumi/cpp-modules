#include <iostream>
#include <limits>
#include <random>

#include "Span.h"

#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m\n"

std::vector<int> generateRandomNumbers(size_t N, int min, int max)
{
	std::vector<int> numbers;
	numbers.reserve(N);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(min, max);

	for (size_t i = 0; i < N; ++i)
	{
		numbers.emplace_back(dis(gen));
	}

	return numbers;
}

int main()
{
	{
		constexpr int N = 10;
		constexpr int min = 0;
		constexpr int max = N;
		std::vector<int> numbers = generateRandomNumbers(N, min, max);
		Span span(N);
		span.addNumber(numbers.begin(), numbers.end());
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;
	}
	{
		Span span(0);
		try
		{
			span.addNumber(42);
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET;
		}
	}
}
