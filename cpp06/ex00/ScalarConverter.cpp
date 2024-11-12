#include "ScalarConverter.h"

#include <iomanip> // for std::fixed and std::setprecision
#include <limits> // for std::numeric_limits

constexpr char charTemplate[]   = "\033[36mchar:   \033[0m";
constexpr char intTemplate[]    = "\033[36mint:    \033[0m";
constexpr char floatTemplate[]  = "\033[36mfloat:  \033[0m";
constexpr char doubleTemplate[] = "\033[36mdouble: \033[0m";

void ScalarConverter::convert(const std::string &str)
{
	detectTypeAndPrint(str);
}

void ScalarConverter::detectTypeAndPrint(const std::string &str)
{
	FPType type = FPType::OK;
	if (str.empty())
	{
		printUnkownType();
		return;
	}
	if (isChar(str))
	{
		std::cout << "isChar" << std::endl;
		convertChar(str);
		return;
	}
	else if (isInt(str))
	{
		std::cout << "isInt" << std::endl;
		convertInt(str);
		return;
	}
	else if (isFloat(str, type))
	{
		std::cout << "isFloat" << std::endl;
		convertFloat(str, type);
		return;
	}
	else if (isDouble(str, type))
	{
		std::cout << "isDouble" << std::endl;
		convertDouble(str, type);
		return;
	}
	printUnkownType();
}

bool ScalarConverter::isChar(const std::string &str)
{
	if (str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]))
		return true;
	return false;
}

bool ScalarConverter::isInt(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			continue;
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string &str, FPType& type)
{
	if (str[str.length() - 1] != 'f')
		return false;
	if (str == "nanf" || str == "inff" || str == "-inff")
	{
		if (str == "nanf")
			type = FPType::NAN;
		else
			type = FPType::INF;
		return true;
	}
	if (str.find('.') == std::string::npos)
		return false;
	if (str.find_first_not_of("0123456789e+-.f") != std::string::npos)
		return false;
	return true;
}

bool ScalarConverter::isDouble(const std::string &str, FPType& type)
{
	if (str == "nan" || str == "inf" || str == "-inf")
	{
		if (str == "nan")
			type = FPType::NAN;
		else
			type = FPType::INF;
		return true;
	}
	if (str.find('.') == std::string::npos)
		return false;
	if (str.find_first_not_of("0123456789e+-.") != std::string::npos)
		return false;
	return true;
}

void ScalarConverter::convertChar(const std::string &str)
{
	char c = str[0];
	std::cout << charTemplate << "\"" << c << "\"" << std::endl;
	std::cout << intTemplate << static_cast<int>(c) << std::endl;
	std::cout << floatTemplate << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << doubleTemplate << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertInt(const std::string &str)
{
	int i = 0;
	try
	{
		i = std::stoi(str);
	}
	catch (std::exception &e)
	{
		printImpossibleType();
		return ;
	}
	std::cout << charTemplate;
	if (i >= 0 && i <= 255 && std::isprint(i))
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << intTemplate << i << std::endl;
	std::cout << floatTemplate << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
	std::cout << doubleTemplate << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

void ScalarConverter::convertFloat(const std::string &str, FPType type)
{
	float f;
	try
	{
		f = std::stof(str);
	}
	catch (std::exception &e)
	{
		printImpossibleType();
		return ;
	}
	if (type != FPType::OK)
	{
		std::cout << charTemplate << "impossible" << std::endl;
		std::cout << intTemplate << "impossible" << std::endl;
	}
	else
	{
		int i = static_cast<int>(f);
		std::cout << charTemplate;
		if (i >= 0 && i <= 255 && std::isprint(i))
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << intTemplate << i << std::endl;
	}
	std::cout << floatTemplate << f << "f" << std::endl;
	std::cout << doubleTemplate << static_cast<double>(f) << std::endl;
}

void ScalarConverter::convertDouble(const std::string &str, FPType type)
{
	double d;
	try
	{
		d = std::stod(str);
	}
	catch (std::exception &e)
	{
		printImpossibleType();
		return ;
	}
	if (type != FPType::OK)
	{
		std::cout << charTemplate << "impossible" << std::endl;
		std::cout << intTemplate << "impossible" << std::endl;
	}
	else
	{
		int i = static_cast<int>(d);
		std::cout << charTemplate;
		if (i >= 0 && i <= 255 && std::isprint(i))
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << intTemplate << i << std::endl;
	}
	std::cout << floatTemplate << static_cast<float>(d) << "f" << std::endl;
	std::cout << doubleTemplate << d << std::endl;
}

void ScalarConverter::printUnkownType()
{
	std::cout << charTemplate << "impossible" << std::endl;
	std::cout << intTemplate << "impossible" << std::endl;
	std::cout << floatTemplate << "nanf" << std::endl;
	std::cout << doubleTemplate << "nan" << std::endl;
}

void ScalarConverter::printImpossibleType()
{
	std::cout << charTemplate << "impossible" << std::endl;
	std::cout << intTemplate << "impossible" << std::endl;
	std::cout << floatTemplate << "impossible" << std::endl;
	std::cout << doubleTemplate << "impossible" << std::endl;
}
