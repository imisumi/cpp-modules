#include "PmergeMe.h"


#include <cmath>
#include <algorithm>
#include <ranges>


static uint64_t comparison_count = 0;

int PmergeMe::mergeInsertionSort(std::vector<int>& v)
{
	comparison_count = 0;
	mergeInsertionSort(v, 1);
	return comparison_count;
}

int PmergeMe::mergeInsertionSort(std::list<int>& v)
{
	comparison_count = 0;
	mergeInsertionSort(v, 1);
	return comparison_count;
}

int PmergeMe::jacobsthalNumber(long n)
{
	return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

// big thanks to emuminov for the explanation and visualization of the ford-johnson algorithm
// https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91
void PmergeMe::mergeInsertionSort(std::vector<int>& container, int pair_level)
{
	// Calculate the number of pairs
	int pair_units_nbr = container.size() / pair_level;

	if (pair_units_nbr < 2)
		return ;

	bool isOdd = pair_units_nbr % 2 == 1;
	size_t offset = 2 * pair_level;

	std::vector<std::pair<std::vector<int>, std::vector<int>>> pairs;
	std::vector<int> odd_pair;
	std::vector<int> stray_numbers;

	auto start = container.begin();
	auto end = start + pair_level * pair_units_nbr - (isOdd ? pair_level : 0);

	int i = 0;
	auto it = start;
	for (; it < end; std::advance(it, offset), i++)
	{
		auto currentPairEnd = it + pair_level - 1;   // Last element of the current pair
		auto nextPairEnd = it + 2 * pair_level - 1;  // Last element of the next pair
		std::vector<int> sequence_one = std::vector<int>(it, currentPairEnd + 1);
		std::vector<int> sequence_two = std::vector<int>(it + pair_level, nextPairEnd + 1);
		if (sequence_one.back() > sequence_two.back())
		{
			comparison_count++;
			std::swap(sequence_one, sequence_two);
		}

		pairs.push_back({sequence_one, sequence_two});
	}
	for (;isOdd && it < container.end(); std::advance(it, 1))
	{
		if ((offset / 2) == odd_pair.size())
		{
			break;
		}
		odd_pair.push_back(*it);
	}
	for (; it < container.end(); std::advance(it, 1))
	{
		stray_numbers.push_back(*it);
	}

#if DEBUG_LOG
	log_pairs(pairs, odd_pair, stray_numbers);
#endif

	{
		size_t size = pairs.size() * (pairs[0].first.size() * 2) + odd_pair.size() + stray_numbers.size();
		assert(size == container.size());
	}

	container.clear();
	for (const auto& pair : pairs)
	{
		container.insert(container.end(), pair.first.begin(), pair.first.end());
		container.insert(container.end(), pair.second.begin(), pair.second.end());
	}
	container.insert(container.end(), odd_pair.begin(), odd_pair.end());
	container.insert(container.end(), stray_numbers.begin(), stray_numbers.end());

	//? Recursive call for further merging
	mergeInsertionSort(container, pair_level * 2);
#if DEBUG_LOG
	std::ranges::for_each(container, [](const int& num) { std::cout << num << " "; });
	std::cout << std::endl;
#endif

	//! Bad code repitition
	pairs.clear();
	odd_pair.clear();
	stray_numbers.clear();

	start = container.begin();
	end = start + pair_level * pair_units_nbr - (isOdd ? pair_level : 0);

	i = 0;
	it = start;
	for (; it < end; std::advance(it, offset), i++)
	{
		auto currentPairEnd = it + pair_level - 1;   // Last element of the current pair
		auto nextPairEnd = it + 2 * pair_level - 1;  // Last element of the next pair
		std::vector<int> sequence_one = std::vector<int>(it, currentPairEnd + 1);
		std::vector<int> sequence_two = std::vector<int>(it + pair_level, nextPairEnd + 1);
		pairs.push_back({sequence_one, sequence_two});
	}
	for (;isOdd && it < container.end(); std::advance(it, 1))
	{
		if ((offset / 2) == odd_pair.size())
		{
			break;
		}
		odd_pair.push_back(*it);
	}
	for (; it < container.end(); std::advance(it, 1))
	{
		stray_numbers.push_back(*it);
	}
	//! Bad code repitition

	//? initialize the main and pend vectors
	std::vector<std::vector<int>> main;
	std::vector<std::vector<int>> pend;

	//? push the first two pairs into the main vector
	main.push_back(pairs[0].first);
	main.push_back(pairs[0].second);

	//? push the first pair of the pairs vector into the pend vector and the rest into the main vector
	for (size_t i = 1; i < pairs.size(); i++)
	{
		pend.push_back(pairs[i].first);
		main.push_back(pairs[i].second);
	}

#if DEBUG_LOG
	log_sequence(main, "initial main:", YELLOW);
	log_sequence(pend, "initial pend:", CYAN);
	log_sequence(odd_pair, "odd pair:", GREEN);
#endif

	//? insert the pend into the main
	size_t prev_jacobsthal = jacobsthalNumber(1);
	size_t inserted_numbers = 0;
	//? we start from 2 because we have already inserted the first pair into the main vector
	for (size_t i = 2;; i++)
	{
		size_t current_jacobsthal = jacobsthalNumber(i);
		size_t jacobsthal_diff = current_jacobsthal - prev_jacobsthal;
		size_t offset = 0;
		if (jacobsthal_diff > pend.size())
		{
		#if DEBUG_LOG
			std::cout << YELLOW << "Jacobsthal diff is greater than pend size, inserting the rest of the pend in sequential order" << RESET << std::endl;
		#endif
			break ;
		}
		size_t numbers_to_insert = jacobsthal_diff;
		auto pend_start = pend.begin();
		std::advance(pend_start, jacobsthal_diff - 1); // -1 because pend_start is the first element
		auto main_search_end = main.begin();
		std::advance(main_search_end, current_jacobsthal + inserted_numbers); // we add inserted_numbers because the main vector increases in size as we insert elements
	#if DEBUG_LOG
		std::cout << YELLOW << "-- " << "jacobsthall diff / pend start index: " << jacobsthal_diff - 1<< 
		" main end index = jacobshtal number: " << current_jacobsthal << " + inserted numbers: " << inserted_numbers << " == " << current_jacobsthal + inserted_numbers - 1 << RESET << std::endl;
		std::cout << "search start: " << main.begin()->back() << " search end: " << (main_search_end - 1)->back() << std::endl;
	#endif
		while (numbers_to_insert)
		{
			//? main_search_end.end() will not be included in the search
			auto insert_pos = std::upper_bound(
				main.begin(), 
				main_search_end, 
				*pend_start, 
				[](const auto& a, const auto& b) {
					comparison_count++;
					return a.back() < b.back();
				}
			);
		#if DEBUG_LOG
			std::cout << "inserting: " << pend_start->back() << std::endl;
		#endif
			auto inserted = main.insert(insert_pos, *pend_start);
			pend_start = pend.erase(pend_start);
			std::advance(pend_start, -1); // move the pend_start iterator back by one because we have erased the current element

			//? if the insert position is the same as the current main_search_end we know for a fact that that the next element will be atleast main_search_end - 1
			offset = static_cast<std::size_t>(inserted - main.begin()) == current_jacobsthal + inserted_numbers ? 1 : 0;

			main_search_end = main.begin();
			std::advance(main_search_end, current_jacobsthal + inserted_numbers - offset);

			numbers_to_insert--;
		}
	#if DEBUG_LOG
		log_sequence(main, "updated main: ", CYAN);
		log_sequence(pend, "updated pend: ", YELLOW);
	#endif
		prev_jacobsthal = current_jacobsthal;
		inserted_numbers += jacobsthal_diff;
	}

	//? insert the remaing pend into the main
	for (size_t i = 0; i < pend.size(); i++)
	{
	#if DEBUG_LOG
		std::cout << "inserting: " << pend[i].back() << std::endl;
	#endif


		//? we do + i because for every insertion we do, the main vector increases in size
		auto insert_pos = std::upper_bound
		(main.begin(), 
		main.end() - pend.size() + i, 
		pend[i], 
		[](const auto& a, const auto& b) {
			comparison_count++;
			return a.back() < b.back();
			}
		);
		main.insert(insert_pos, pend[i]);
	}
	pend.clear();

	//? insert the odd pair into the main
	if (odd_pair.size())
	{
	#if DEBUG_LOG
		std::cout << YELLOW << "Inserting odd pair into the main" << RESET << std::endl;
		std::cout << "inserting: " << odd_pair.back() << std::endl;
	#endif
		auto insert_pos = std::upper_bound(main.begin(), main.end(), odd_pair, [](const auto& a, const auto& b) {
			comparison_count++;
			return a.back() < b.back();
		});
		main.insert(insert_pos, odd_pair);
	}

#if DEBUG_LOG
	log_sequence(main, "Main: ", CYAN);
	log_sequence(pend, "Pend: ", YELLOW);
#endif

	//? insert the stray numbers into the main
	if (stray_numbers.size())
	{
		main.push_back(stray_numbers);
		stray_numbers.clear();
	#if DEBUG_LOG
		log_sequence(main, "Main: ", CYAN);
		log_sequence(pend, "Pend: ", YELLOW);
	#endif
	}

	{
		size_t size = 0;
		for (const auto& sequence : main)
		{
			size += sequence.size();
		}
		size += stray_numbers.size();

	#if DEBUG_LOG
		std::cout << "Size: " << size << std::endl;
	#endif
		assert(size == container.size());
	}
	container.clear();
	for (const auto& sequence : main)
	{
		container.insert(container.end(), sequence.begin(), sequence.end());
	}

#if DEBUG_LOG
	std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
#endif
}

void PmergeMe::mergeInsertionSort(std::list<int>& container, int pair_level)
{
	// Calculate the number of pairs
	int pair_units_nbr = container.size() / pair_level;

	if (pair_units_nbr < 2)
		return ;

	bool isOdd = pair_units_nbr % 2 == 1;
	size_t offset = 2 * pair_level;

	std::list<std::pair<std::list<int>, std::list<int>>> pairs;
	std::list<int> odd_pair;
	std::list<int> stray_numbers;

	auto start = container.begin();
	// auto end = start;
	auto end = std::next(start, pair_level * pair_units_nbr - (isOdd ? pair_level : 0));
	// std::advance(end, pair_level * pair_units_nbr - (isOdd ? pair_level : 0));

	int i = 0;
	auto it = start;
	for (; it != end; std::advance(it, offset), i++)
	{
		auto currentPairEnd = std::next(it, pair_level - 1);   // Last element of the current pair
		auto nextPairEnd = std::next(it, 2 * pair_level - 1);  // Last element of the next pair
		std::list<int> sequence_one = std::list<int>(it, std::next(currentPairEnd, 1));
		std::list<int> sequence_two = std::list<int>(std::next(it, pair_level), std::next(nextPairEnd, 1));
		if (sequence_one.back() > sequence_two.back())
		{
			comparison_count++;
			std::swap(sequence_one, sequence_two);
		}

		pairs.push_back({sequence_one, sequence_two});
	}
	for (;isOdd && it != container.end(); std::advance(it, 1))
	{
		if ((offset / 2) == odd_pair.size())
		{
			break;
		}
		odd_pair.push_back(*it);
	}
	for (; it != container.end(); std::advance(it, 1))
	{
		stray_numbers.push_back(*it);
	}

	{
		// size_t size = pairs.size() * (pairs[0].first.size() * 2) + odd_pair.size() + stray_numbers.size();
		size_t size = pairs.size() * (pairs.begin()->first.size() * 2) + odd_pair.size() + stray_numbers.size();
		assert(size == container.size());
	}

	container.clear();
	for (const auto& pair : pairs)
	{
		container.insert(container.end(), pair.first.begin(), pair.first.end());
		container.insert(container.end(), pair.second.begin(), pair.second.end());
	}
	container.insert(container.end(), odd_pair.begin(), odd_pair.end());
	container.insert(container.end(), stray_numbers.begin(), stray_numbers.end());

	//? Recursive call for further merging
	mergeInsertionSort(container, pair_level * 2);

	//! Bad code repitition
	pairs.clear();
	odd_pair.clear();
	stray_numbers.clear();

	start = container.begin();
	end = std::next(start, pair_level * pair_units_nbr - (isOdd ? pair_level : 0));

	i = 0;
	it = start;
	for (; it != end; std::advance(it, offset), i++)
	{
		auto currentPairEnd = std::next(it, pair_level - 1);   // Last element of the current pair
		auto nextPairEnd = std::next(it, 2 * pair_level - 1);  // Last element of the next pair
		std::list<int> sequence_one = std::list<int>(it, std::next(currentPairEnd, 1));
		std::list<int> sequence_two = std::list<int>(std::next(it, pair_level), std::next(nextPairEnd, 1));
		pairs.push_back({sequence_one, sequence_two});
	}
	for (;isOdd && it != container.end(); std::advance(it, 1))
	{
		if ((offset / 2) == odd_pair.size())
		{
			break;
		}
		odd_pair.push_back(*it);
	}
	for (; it != container.end(); std::advance(it, 1))
	{
		stray_numbers.push_back(*it);
	}
	//! Bad code repitition

	//? initialize the main and pend vectors
	std::list<std::list<int>> main;
	std::list<std::list<int>> pend;

	//? push the first two pairs into the main vector
	main.push_back(std::move(pairs.begin()->first));
	main.push_back(std::move(pairs.begin()->second));

	//? push the first pair of the pairs vector into the pend vector and the rest into the main vector
	for (size_t i = 1; i < pairs.size(); i++)
	{
		pend.push_back(std::move(std::next(pairs.begin(), i)->first));
		main.push_back(std::move(std::next(pairs.begin(), i)->second));
	}

	//? insert the pend into the main
	size_t prev_jacobsthal = jacobsthalNumber(1);
	size_t inserted_numbers = 0;
	//? we start from 2 because we have already inserted the first pair into the main vector
	for (size_t i = 2;; i++)
	{
		size_t current_jacobsthal = jacobsthalNumber(i);
		size_t jacobsthal_diff = current_jacobsthal - prev_jacobsthal;
		size_t offset = 0;
		if (jacobsthal_diff > pend.size())
		{
			break ;
		}
		size_t numbers_to_insert = jacobsthal_diff;
		auto pend_start = pend.begin();
		std::advance(pend_start, jacobsthal_diff - 1); // -1 because pend_start is the first element
		auto main_search_end = main.begin();
		std::advance(main_search_end, current_jacobsthal + inserted_numbers); // we add inserted_numbers because the main vector increases in size as we insert elements

		while (numbers_to_insert)
		{
			//? main_search_end.end() will not be included in the search
			auto insert_pos = std::upper_bound(
				main.begin(), 
				main_search_end, 
				*pend_start, 
				[](const auto& a, const auto& b) {
					comparison_count++;
					return a.back() < b.back();
				}
			);

			auto inserted = main.insert(insert_pos, *pend_start);
			pend_start = pend.erase(pend_start);
			std::advance(pend_start, -1); // move the pend_start iterator back by one because we have erased the current element

			//? if the insert position is the same as the current main_search_end we know for a fact that that the next element will be atleast main_search_end - 1
			offset = static_cast<std::size_t>(std::distance(main.begin(), inserted)) == current_jacobsthal + inserted_numbers ? 1 : 0;

			main_search_end = main.begin();
			std::advance(main_search_end, current_jacobsthal + inserted_numbers - offset);

			numbers_to_insert--;
		}

		prev_jacobsthal = current_jacobsthal;
		inserted_numbers += jacobsthal_diff;
	}

	//? insert the remaing pend into the main
	for (size_t i = 0; i < pend.size(); i++)
	{
		//? we do + i because for every insertion we do, the main vector increases in size
		auto insert_pos = std::upper_bound(
			main.begin(), 
			std::prev(main.end(), pend.size() - i),  // Adjust this to reflect the range in the list
			*std::next(pend.begin(), i),  // Access the i-th element in pend
			[](const auto& a, const auto& b) {
				comparison_count++;
				return a.back() < b.back();
			}
		);
		main.insert(insert_pos, *std::next(pend.begin(), i));
	}
	pend.clear();

	//? insert the odd pair into the main
	if (odd_pair.size())
	{
		auto insert_pos = std::upper_bound(
			main.begin(), 
			main.end(), 
			odd_pair, 
			[](const auto& a, const auto& b) {
				comparison_count++;
				return a.back() < b.back();
			});
		main.insert(insert_pos, odd_pair);
	}
	odd_pair.clear();

	//? insert the stray numbers into the main
	if (stray_numbers.size())
	{
		main.push_back(stray_numbers);
		stray_numbers.clear();
	}

	{
		size_t size = 0;
		for (const auto& sequence : main)
		{
			size += sequence.size();
		}
		size += stray_numbers.size();

		assert(size == container.size());
	}
	container.clear();
	for (const auto& sequence : main)
	{
		container.insert(container.end(), sequence.begin(), sequence.end());
	}
}

void PmergeMe::log_pairs(std::vector<std::pair<std::vector<int>, std::vector<int>>> pairs, std::vector<int> odd_pair, std::vector<int> stray_numbers)
{
	std::cout << "Pairs: " << std::endl;
	int i = 0;
	std::string colors[] = {BRIGHT_YELLOW, DIM_YELLOW, BRIGHT_CYAN, DIM_CYAN};
	for (const auto& pair : pairs)
	{
		for (const auto& num : pair.first)
		{
			std::cout << colors[i % 4] << num << " ";
		}
		for (const auto& num : pair.second)
		{
			std::cout << colors[(i + 1) % 4] << num << " ";
		}
		i+=2;
	}
	for (const auto& num : odd_pair)
	{
		std::cout << RED << num << " ";
	}
	for (const auto& num : stray_numbers)
	{
		std::cout << RESET << num << " ";
	}
	std::cout << RESET << std::endl;
}

void PmergeMe::log_sequence(const std::vector<std::vector<int>>& s, const std::string& title, const std::string& color)
{
	std::cout << color << title << " " << RESET;
	for (const auto& sequence : s)
	{
		int i = 1;
		for (const auto& num : sequence)
		{
			if (i % sequence.size() == 0)
				std::cout << CYAN << num << RESET << " ";
			else
				std::cout << num << " ";
			i++;
		}
	}
	std::cout << std::endl;
}

void PmergeMe::log_sequence(const std::vector<int>& s, const std::string& title, const std::string& color)
{
	std::cout << color << title << " " << RESET;
	int i = 1;
	for (const auto& num : s)
	{
		if (i % s.size() == 0)
			std::cout << CYAN << num << RESET << " ";
		else
			std::cout << num << " ";
		i++;
	}
	std::cout << std::endl;
}


//? Timer

Timer::Timer()
{
	Reset();
}

void Timer::Reset()
{
	m_Start = std::chrono::high_resolution_clock::now();
}

float Timer::Elapsed() const
{
	return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - m_Start).count() * 0.001f * 0.001f;
}

float Timer::ElapsedMillis() const
{
	return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - m_Start).count() * 0.001f;
}

