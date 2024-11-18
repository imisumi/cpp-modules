#include "BitcoinExchange.h"
#include <fstream>
#include <regex>
#include <iostream>

#include "Utils.h"

float BitcoinExchange::validateExchangeRate(const std::string& rate)
{
	if (!isValidFloat(rate))
	{
		return -1.0f;
	}
	float val;
	try
	{
		val = std::stof(rate);
	}
	catch (const std::exception& e)
	{
		return -1.0f;
	}
	//TODO: change to only < 0.0f
	if (val < m_MinExchangeRate || val > m_MaxExchangeRate)
	{
		return -1.0f;
	}
	return val;
}

float BitcoinExchange::getExchangeRate(const std::chrono::year_month_day &date) const
{
	auto it = m_ExchangeMap.lower_bound(date);  // Find the first date >= input date

	if (it == m_ExchangeMap.begin()) {
		// No valid date found that is lower, so return -1.0f (or handle as needed)
		return -1.0f;
	}

	if (it == m_ExchangeMap.end() || it->first != date) {
		// Step back to the previous date, which will be the closest valid date before the input date
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
		if (line.empty())
			continue;
		// std::cout << CYAN << "Line: " << line << RESET;

		const std::string date = line.substr(0, line.find(','));
		const std::string value = line.substr(line.find(',') + 1);

		std::chrono::year_month_day ymd = validateDate(date);
		if (!ymd.ok())
		{
			std::cerr << "Ignoring invalid date of: " << date <<  ", on line: " << lineNum << "\n";
			continue;
		}

		// const float val = validateExchangeRate(value);
		const float val = stringToFloat(value);
		if (val < 0.0f)
		{
			std::cerr << "Ignoring invalid exchange rate of: " << value << ", on line: " << lineNum << "\n";
			continue;
		}

		if (m_ExchangeMap.find(ymd) != m_ExchangeMap.end())
		{
			std::cerr << "Error: Duplicate date found on line: " << lineNum << "\n";
			continue;
		}
		m_ExchangeMap[ymd] = val;

	}
	file.close();

	return true;
}

void BitcoinExchange::log() const
{
	for (const auto& [date, rate] : m_ExchangeMap)
	{
		// std::cout << date << ": " << rate << "\n";
		std::cout << "Date: " << int(date.year()) << "-" << unsigned(date.month()) << "-" << unsigned(date.day()) << " Rate: " << rate << "\n";
	}
	// std::cout << "Date: " << int(m_MaxDate.year()) << "-" << unsigned(m_MaxDate.month()) << "-" << unsigned(m_MaxDate.day()) << "\n";

}
