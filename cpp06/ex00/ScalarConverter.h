#pragma once

#include <iostream>
#include <utility>

class ScalarConverter
{
public:
	// Default constructor
	ScalarConverter() = delete;

	// Copy constructor
	ScalarConverter(const ScalarConverter&) = delete;

	// Copy assignment operator
	ScalarConverter& operator=(const ScalarConverter&) = delete;

	// Move constructor
	ScalarConverter(ScalarConverter&&) noexcept = delete;

	// Move assignment operator
	ScalarConverter& operator=(ScalarConverter&&) noexcept = delete;

	// Destructor
	~ScalarConverter() = delete;

	static void convert(const std::string& str);

private:
	enum class FPType : uint8_t
	{
		OK,
		NAN,
		INF,
	};

	static void detectTypeAndPrint(const std::string& str);

	static bool isChar(const std::string& str);
	static bool isInt(const std::string& str);
	static bool isFloat(const std::string& str, FPType& type);
	static bool isDouble(const std::string &str, FPType& type);

	static void convertChar(const std::string& str);
	static void convertInt(const std::string& str);
	static void convertFloat(const std::string& str, FPType type);
	static void convertDouble(const std::string& str, FPType type);

	static void printUnkownType();
	static void printImpossibleType();
};
