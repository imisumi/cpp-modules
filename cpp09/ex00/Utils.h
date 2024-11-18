#pragma once

#include <chrono>
#include <string>

bool isValidFloat(const std::string& str);
bool isValidUint(const std::string& str);
std::chrono::year_month_day validateDate(const std::string& date);
float stringToFloat(const std::string& rate);