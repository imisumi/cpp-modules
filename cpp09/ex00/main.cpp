#include <iostream>

#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m\n"

#include <iostream>
#include <chrono>
#include <ctime>

#include <map>

enum class Month : int
{
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include <iostream>
#include <string>
#include <regex>

// bool isValidUint(const std::string& str)
// {
// 	// Regex for an unsigned integer
// 	std::regex uintRegex(R"(^\d+$)");  // Only digits allowed, no sign
// 	return std::regex_match(str, uintRegex);
// }

#include "BitcoinExchange.h"
#include "Utils.h"






void exchangeData(const std::filesystem::path path, const BitcoinExchange& exchange)
{
	std::ifstream file(path);
	if (!file.is_open())
	{
		std::cerr << "Error: Could not open file: " << path << "\n";
		return;
	}

	std::string line;
	uint32_t lineNum = 0;
	while (std::getline(file, line))
	{
		lineNum++;
		if (line.empty() || line[0] == '#')
			continue;
		if (line.find(" | ") == std::string::npos)
		{
			std::cerr << RED << "Error: Invalid line format on line: " << lineNum << RESET;
			continue;
		}

		size_t splitPos = line.find(" | ");
		std::string date = line.substr(0, splitPos);
		std::string value = line.substr(splitPos + 3);


		std::chrono::year_month_day ymd = validateDate(date);
		if (!ymd.ok())
		{
			std::cerr << RED << "Error: Invalid date on line: " << lineNum << RESET;
			continue;
		}

		float val = stringToFloat(value);
		if (val < 0.0f || val > 1000.0f)
		{
			std::cerr << RED << "Error: Invalid btc ammount on line: " << lineNum << RESET;
			continue;
		}

		// std::cout << "Date: " << date << " Value: " << value << "\n";
		const float rate = exchange.getExchangeRate(ymd);
		if (rate == -1.0f)
		{
			std::cerr << RED << "Error: No exchange rate found for date: " << date << RESET;
			continue;
		}
		std::cout << date << " => " << value << " = " << val * rate << "\n";

		// float f = 1;

		

	}
	file.close();
}



int main(int argc, char *argv[])
{
	BitcoinExchange exchange;

	if (!exchange.loadData("data.csv"))
	{
		std::cout << "Error: Could not load data from file.\n";
		return EXIT_FAILURE;
	}
	// exchange.log();

	exchangeData("input.txt", exchange);

	return 0;
}