#include "Utils.h"
#include <regex>
#include <iostream>

bool isValidFloat(const std::string& str)
{
	std::regex floatRegex(R"(^[+-]?\d*\.?\d+([eE][+-]?\d+)?$)");
	return std::regex_match(str, floatRegex);
}

std::chrono::year_month_day validateDate(const std::string& date)
{
	int year;
	uint32_t month, day;

	if (std::count(date.begin(), date.end(), '-') != 2)
	{
		return {};
	}

	try
	{
		size_t firstDashPos = date.find('-');
		size_t secondDashPos = date.find('-', firstDashPos + 1);

		year = std::stoi(date.substr(0, firstDashPos));
		month = std::stoi(date.substr(firstDashPos + 1, secondDashPos - firstDashPos - 1));
		day = std::stoi(date.substr(secondDashPos + 1));

		std::chrono::year_month_day ymd{std::chrono::year{year}, std::chrono::month{month}, std::chrono::day{day}};
		return ymd;
	}
	catch (const std::exception& e)
	{
		return {};
	}
}

/*
** stringToFloat: Converts a string to a float >= 0.0f
** returns: -1.0f if the string is not a valid float
*/
float stringToFloat(const std::string& rate)
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
	return val;
}
