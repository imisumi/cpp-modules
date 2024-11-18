#include "BitcoinExchange.h"
#include <fstream>
#include <regex>
#include <iostream>

#include "Utils.h"

float BitcoinExchange::getExchangeRate(const std::chrono::year_month_day &date) const
{
	auto it = m_ExchangeMap.lower_bound(date);

	if (it == m_ExchangeMap.begin() && it->first != date)
	{
		return -1.0f;
	}

	if (it == m_ExchangeMap.end() || it->first != date)
	{
		--it;
	}

	return it->second;
}

bool BitcoinExchange::loadData(const std::filesystem::path &filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		return false;
	}

	std::string line;
	uint32_t lineNum = 0;
	while (std::getline(file, line))
	{
		lineNum++;
		if (line.empty() || line[0] == '#' || line == "date,exchange_rate")
			continue;

		const std::string date = line.substr(0, line.find(','));
		const std::string value = line.substr(line.find(',') + 1);

		std::chrono::year_month_day ymd = validateDate(date);
		if (!ymd.ok() || ymd < m_MinDate || ymd > m_MaxDate)
		{
			std::cerr << RED << "Dataset error, ignoring invalid date of: " << date <<  ", on line: " << lineNum << RESET;
			continue;
		}

		const float val = stringToFloat(value);
		if (val < 0.0f)
		{
			std::cerr << RED << "Dataset error, ignoring invalid exchange rate of: " << value << ", on line: " << lineNum << RESET;
			continue;
		}

		if (m_ExchangeMap.find(ymd) != m_ExchangeMap.end())
		{
			std::cerr << RED << "Dataset error,  Duplicate date found on line: " << lineNum << RESET;
			continue;
		}
		m_ExchangeMap[ymd] = val;

	}
	file.close();

	return true;
}

void BitcoinExchange::logData() const
{
	for (const auto& [date, rate] : m_ExchangeMap)
	{
		std::cout << "Date: " << int(date.year()) << "-" << unsigned(date.month()) << "-" << unsigned(date.day()) << " Rate: " << rate << "\n";
	}
}
