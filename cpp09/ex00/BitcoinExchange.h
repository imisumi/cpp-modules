#pragma once

#include <iostream>
#include <utility>

#include <map>
#include <chrono>
#include <filesystem>

class BitcoinExchange
{
public:
	// Default constructor
	BitcoinExchange() = default;

	// Copy constructor
	BitcoinExchange(const BitcoinExchange&) = default;

	// Copy assignment operator
	BitcoinExchange& operator=(const BitcoinExchange&) = default;

	// Move constructor
	BitcoinExchange(BitcoinExchange&&) noexcept = default;

	// Move assignment operator
	BitcoinExchange& operator=(BitcoinExchange&&) noexcept = default;

	// Destructor
	~BitcoinExchange() = default;

	bool loadData(const std::filesystem::path& filename);
	void logData() const;

	float getExchangeRate(const std::chrono::year_month_day& date) const;

private:
	const std::chrono::year_month_day m_MinDate = std::chrono::year_month_day{ std::chrono::year{ 2009 }, std::chrono::month{ 1 }, std::chrono::day{ 3 } };
	const std::chrono::year_month_day m_MaxDate = std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now());
	// max date is today

	constexpr static float m_MinExchangeRate = 0.0f;
	constexpr static float m_MaxExchangeRate = 1000.0f;
	std::map<std::chrono::year_month_day, float> m_ExchangeMap;
};
