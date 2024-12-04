#include "PmergeMe.h"

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Please provide a list of numbers to sort" << std::endl;
		return EXIT_FAILURE;
	}

	constexpr int trimSize = 3;

	//? std::vector
	try
	{
		Timer timer;
		std::vector<int> v = PmergeMe::fillContainer<std::vector<int>>(argv, argc);
		float initilizeTime = timer.ElapsedMillis();
		std::cout << CYAN << "std::vector " << RESET << "initializing took: " << CYAN << initilizeTime << "ms" << RESET << std::endl;

		PmergeMe::logSequence(v, "Before:", trimSize);

		timer.Reset();
		uint32_t comparisons = PmergeMe::mergeInsertionSort(v);
		float mergeTime = timer.ElapsedMillis();

		PmergeMe::logSequence(v, "After: ", trimSize);

		std::cout << "Is the list sorted: " << CYAN << (PmergeMe::isSorted(v) ? "Yes" : "No") << RESET << std::endl;

		std::cout << "Time to process a range of " << CYAN << argc - 1 << RESET \
		<< " elements with " << CYAN << "std::vector " << RESET \
		<< "took: " << CYAN << mergeTime << "ms" << RESET \
		<< " with: " << CYAN << comparisons << " comparisons" << std::endl;
	}
	catch(const std::exception& e)
	{
		return EXIT_FAILURE;
	}
	std::cout << GREEN << "---------------------------------------------------------------------------------------------------" << RESET << std::endl;
	//? std::list
	try
	{
		Timer timer;
		std::list<int> l = PmergeMe::fillContainer<std::list<int>>(argv, argc);
		float initilizeTime = timer.ElapsedMillis();
		std::cout << CYAN << "std::list " << RESET << "initializing took: " << CYAN << initilizeTime << "ms" << RESET << std::endl;

		PmergeMe::logSequence(l, "Before:", trimSize);

		timer.Reset();
		uint32_t comparisons = PmergeMe::mergeInsertionSort(l);
		float mergeTime = timer.ElapsedMillis();

		PmergeMe::logSequence(l, "After: ", trimSize);
		
		std::cout << "Is the list sorted: " << CYAN << (PmergeMe::isSorted(l) ? "Yes" : "No") << RESET << std::endl;

		std::cout << "Time to process a range of " << CYAN << argc - 1 << RESET \
		<< " elements with " << CYAN << "std::list " << RESET \
		<< "took: " << CYAN << mergeTime << "ms" << RESET \
		<< " with: " << CYAN << comparisons << " comparisons" << std::endl;

	}
	catch(const std::exception& e)
	{
		return EXIT_FAILURE;
	}
	return 0;
}
