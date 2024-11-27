
#include <iostream>
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

#include <chrono>

static uint64_t comparison_count = 0;

class ScopeTimer
{
public:
	ScopeTimer(const std::string& name)
		: m_name(name)
	{
		m_start = std::chrono::high_resolution_clock::now();
	}

	~ScopeTimer()
	{
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - m_start);
		std::cout << m_name << " took " << duration.count() << "us" << std::endl;
	}
private:
	std::string m_name;
	std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
};

void sortPair(std::vector<int>& nums, int i, int j)
{
	if (nums[i] > nums[j])
	{
		int tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
}

void sortSequence(std::vector<int>& nums, int i, int j)
{
	int split = i + ((j - i) / 2);
	std::cout << "i: " << i << " j: " << j << " split: " << split << std::endl;

	if (nums[split] > nums[j])
	{
		for (int k = i; k <= split; ++k)
		{
			int tmp = nums[k];
			nums[k] = nums[j + k - split];
			nums[j + k - split] = tmp;
		}
	}
}

void mergeInsertionSort(std::vector<int>& nums, int i, int j)
{
	
}

void mergeInsertionSort(std::vector<int>& nums)
{

}

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

#include <ranges>

void range()
{
	std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
	auto subRange = std::ranges::subrange(v.begin(), v.begin() + 4);
	for (auto num : subRange)
	{
		std::cout << num << " ";
	}
}

void visualizePairs(const std::vector<int>& c, int offset)
{
	int colorOffset = 0;
	for (int i = 0; i < c.size(); i += offset, ++colorOffset)
	{
		bool useYellow = (colorOffset % 2 == 0);
		bool ignore = (i + offset > c.size());
		
		for (int j = 0; j < offset && i + j < c.size(); ++j)
		{
			bool isFirstHalf = (j < offset / 2);
			
			if (ignore) {}
			else if (useYellow)
				std::cout << (isFirstHalf ? BRIGHT_YELLOW : DIM_YELLOW);
			else
				std::cout << (isFirstHalf ? BRIGHT_CYAN : DIM_CYAN);
			
			std::cout << c[i + j] << " ";
		}
		std::cout << RESET;
	}
	std::cout << std::endl;
}

int jacobsthal(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

#include <cmath>
#include <algorithm>

int _jacobsthal_number(long n)
{
	return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

void log_pairs(std::vector<std::pair<std::vector<int>, std::vector<int>>> pairs, std::vector<int> odd_pair, std::vector<int> stray_numbers)
{
	std::cout << "Pairs: " << std::endl;
	int i = 0;
	std::string colors[] = {BRIGHT_YELLOW, DIM_YELLOW, BRIGHT_CYAN, DIM_CYAN};
	for (const auto& pair : pairs)
	{
		// Alternate colors for the first vector of the pair
		// color = (i % 2 == 0) ? BRIGHT_YELLOW : BRIGHT_CYAN;
		for (const auto& num : pair.first)
		{
			std::cout << colors[i % 4] << num << " ";
		}

		// Alternate colors for the second vector of the pair
		// color = (i % 2 == 0) ? BRIGHT_CYAN : BRIGHT_YELLOW;
		for (const auto& num : pair.second)
		{
			// std::cout << color << num << " ";
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
	std::cout << RESET << std::endl; // Reset color to default
}


#include <assert.h>

void log_sequence(const std::vector<std::vector<int>>& s, const std::string& title = "", const std::string& color = "")
{
	// std::cout << titles;
	// for (const auto& num : sequence)
	// {
	// 	std::cout << color << num << " ";
	// }
	// std::cout << RESET << std::endl;

	std::cout << color << title << " " << RESET;
	for (const auto& sequence : s)
	{
		int i = 1;
		for (const auto& num : sequence)
		{
			// if (num == sequence.back())
			if (i % sequence.size() == 0)
				std::cout << CYAN << num << RESET << " ";
			else
				std::cout << num << " ";
			i++;
		}
	}
	std::cout << std::endl;
}
// big thanks to emuminov for the explanation and visualization of the ford-johnson algorithm
// https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91


void testMerge(std::vector<int>& container, int pair_level, int recursionLevel = 1)
{
	// Calculate the number of pairs
	int pair_units_nbr = container.size() / pair_level;
	bool isOdd = pair_units_nbr % 2 == 1;

	// Base case: return if fewer than 2 pairs
	if (pair_units_nbr < 2)
		return;

	int offset = 2 * pair_level;
	int pair_size = pair_level * 2;

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
		// std::cout << "Comparing: " << sequence_one.back() << " " << sequence_two.back() << std::endl;
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
		std::cout << "Stray number: " << *it << std::endl;
	}
	log_pairs(pairs, odd_pair, stray_numbers);

	{
		// I can just use container.size(), but I do this to catch any errors
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

	// Recursive call for further merging
	testMerge(container, pair_level * 2, recursionLevel + 1);
	std::ranges::for_each(container, [](const int& num) { std::cout << num << " "; });
	std::cout << std::endl;





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
		std::cout << "Stray number: " << *it << std::endl;
	}

	//! Bad code repitition











	//? initialize the main and pend vectors
	std::vector<std::vector<int>> main;
	std::vector<std::vector<int>> pend;

	//? push the first two pairs into the main vector
	main.push_back(pairs[0].first);
	main.push_back(pairs[0].second);

	//? push the first pair of the pairs vector into the pend vector and the rest into the main vector
	for (int i = 1; i < pairs.size(); i++)
	{
		pend.push_back(pairs[i].first);
		main.push_back(pairs[i].second);
	}


	// int index = 1;
	std::cout << YELLOW << "initial main: " << RESET;
	for (const auto& sequence : main)
	{
		int i = 1;
		for (const auto& num : sequence)
		{
			// if (num == sequence.back())
			if (i % sequence.size() == 0)
				std::cout << CYAN << num << RESET << " ";
			else
				std::cout << num << " ";
			i++;
		}
	}
	std::cout << std::endl;
	std::cout << CYAN << "initial pend: " << RESET;
	for (const auto& sequence : pend)
	{
		int i = 1;
		for (const auto& num : sequence)
		{
			// if (num == sequence.back())
			if (i % sequence.size() == 0)
				std::cout << CYAN << num << RESET << " ";
			else
				std::cout << num << " ";
			i++;
		}
	}
	std::cout << std::endl;
	{
		std::cout << GREEN << "odd pair: " << RESET;
		int i = 1;
		for (const auto& num : odd_pair)
		{
			if (i == odd_pair.size())
				std::cout << CYAN << num << RESET << " ";
			else
				std::cout << num << " ";
			i++;
		}
		std::cout << std::endl;
	}



	//? insert the pend into the main

	//? start at index 1 because we have already inserted the first pair into the main
	// TODO: implement the jacobsthal number insertion
	int prev_jacobsthal = _jacobsthal_number(1);
	int inserted_numbers = 0;
	for (int i = 2;; i++)
	{
		int current_jacobsthal = _jacobsthal_number(i);
		int jacobsthal_diff = current_jacobsthal - prev_jacobsthal;
		int offser = 0;
		if (jacobsthal_diff > pend.size())
		{
			std::cout << YELLOW << "Jacobsthal diff is greater than pend size, inserting the rest of the pend in sequential order" << RESET << std::endl;
			break ;
		}
		int numbers_to_insert = jacobsthal_diff;
		auto pend_start = pend.begin();
		std::advance(pend_start, jacobsthal_diff - 1); // -1 because pend_start is the first element
		auto main_search_end = main.begin();
		std::advance(main_search_end, current_jacobsthal + inserted_numbers); // we add inserted_numbers because the main vector increases in size as we insert elements
		std::cout << YELLOW << "-- " << "jacobsthall diff / pend start index: " << jacobsthal_diff - 1<< 
		" main end index = jacobshtal number: " << current_jacobsthal << " + inserted numbers: " << inserted_numbers << " == " << current_jacobsthal + inserted_numbers - 1 << RESET << std::endl;
		// " end search index main: (" << current_jacobsthal + inserted_numbers - 1 << " + inserted numbers)" << RESET << std::endl;
		
		// std::cout << "main_search_end: " << main_search_end->back() << std::endl;
		std::cout << "search start: " << main.begin()->back() << " search end: " << (main_search_end - 1)->back() << std::endl;
		while (numbers_to_insert)
		{
			// main_search_end.end() will not be included in the search
			auto insert_pos = std::upper_bound(main.begin(), main_search_end, *pend_start, [](const auto& a, const auto& b) {
				comparison_count++;
				return a.back() < b.back();
			});
			std::cout << "inserting: " << pend_start->back() << std::endl;
			auto inserted = main.insert(insert_pos, *pend_start);
			pend_start = pend.erase(pend_start);
			std::advance(pend_start, -1); // move the pend_start iterator back by one because we have erased the current element


			// if the insert position is the same as the current main_search_end we know for a fact that that the next element will be atleast main_search_end - 1
			offset = (inserted - main.begin()) == current_jacobsthal + inserted_numbers ? 1 : 0;
			main_search_end = main.begin();
			std::advance(main_search_end, current_jacobsthal + inserted_numbers - offset);


			numbers_to_insert--;
		}
		log_sequence(main, "updated main: ", CYAN);
		log_sequence(pend, "updated pend: ", YELLOW);
		prev_jacobsthal = current_jacobsthal;
		inserted_numbers += jacobsthal_diff;
	}







	//? insert the remaing pend into the main
	for (int i = 0; i < pend.size(); i++)
	{
		std::cout << "inserting: " << pend[i].back() << std::endl;

		// we do + i because for every insertion we do, the main vector increases in size
		auto insert_pos = std::upper_bound(main.begin(), main.end() - pend.size() + i, pend[i], [](const auto& a, const auto& b) {
			comparison_count++;
			return a.back() < b.back();
		});
		main.insert(insert_pos, pend[i]);
	}
	pend.clear();



	//? insert the odd pair into the main
	if (odd_pair.size())
	{
		std::cout << YELLOW << "Inserting odd pair into the main" << RESET << std::endl;
		std::cout << "inserting: " << odd_pair.back() << std::endl;
		auto insert_pos = std::upper_bound(main.begin(), main.end(), odd_pair, [](const auto& a, const auto& b) {
			comparison_count++;
			return a.back() < b.back();
		});
		main.insert(insert_pos, odd_pair);
	}
	odd_pair.clear();

	log_sequence(main, "Main: ", CYAN);
	log_sequence(pend, "Pend: ", YELLOW);

	//? insert the stray numbers into the main
	if (stray_numbers.size())
	{
		main.push_back(stray_numbers);
		stray_numbers.clear();
		log_sequence(main, "Main: ", CYAN);
		log_sequence(pend, "Pend: ", YELLOW);
	}




	{
		size_t size = 0;
		for (const auto& sequence : main)
		{
			size += sequence.size();
		}
		size += stray_numbers.size();

		std::cout << "Size: " << size << std::endl;
		assert(size == container.size());
	}
	container.clear();
	for (const auto& sequence : main)
	{
		container.insert(container.end(), sequence.begin(), sequence.end());
	}
	
	std::cout << "----------------------------------------------------------------------------------------------" << std::endl;
}

int main(int argc, char* argv[])
{
	std::vector<int> nums;
	nums.reserve(argc - 1);
	for (int i = 1; i < argc; ++i)
	{
		try
		{
			nums.push_back(std::stoi(argv[i]));
		}
		catch (const std::invalid_argument& e)
		{
			std::cerr << "Invalid argument: " << argv[i] << std::endl;
			return 1;
		}
		catch (const std::out_of_range& e)
		{
			std::cerr << "Out of range: " << argv[i] << std::endl;
			return 1;
		}
	}


	// for (size_t i = 0; i < nums.size(); i += 2)
	// {
	// 	// sortPair(nums, i, i + 1);
	// 	sortSequence(nums, i, i + 1);
	// }

	testMerge(nums, 1);

	std::cout << "Total comparisons: " << comparison_count << std::endl;

	// lambda function to check if nums is sorted
	auto isSorted = [](const std::vector<int>& nums) {
		for (size_t i = 0; i < nums.size() - 1; ++i)
		{
			if (nums[i] > nums[i + 1])
				return false;
		}
		return true;
	};

	std::cout << "Is sorted: " << (isSorted(nums) ? "Yes" : "No") << std::endl;

	// std::ranges::for_each(nums, [](const int& num) { std::cout << num << " "; });
	// std::cout << std::endl;
	return 0;

	// for (size_t group = 2; (group * 2 ) <= nums.size(); group *= 2)
	// {
	// 	// for (size_t i = 0; i < nums.size(); i += group)
	// 	std::cout << "-------------------------------------------------" << group << std::endl;
	// 	for (size_t i = 0; (i + group - 1) < nums.size(); i += group)
	// 	{
	// 		sortSequence(nums, i, i + group - 1);
	// 		// break;
	// 	}
	// 	// break ;
	// 	// if (group == 8)
	// 	// {
	// 	// 	break;
	// 	// }
	// }

	for (auto num : nums)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
}
