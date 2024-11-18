#pragma once

#include <chrono>
#include <string>

#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m\n"

bool isValidFloat(const std::string& str);
bool isValidUint(const std::string& str);
std::chrono::year_month_day validateDate(const std::string& date);
float stringToFloat(const std::string& rate);