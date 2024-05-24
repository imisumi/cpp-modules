#include "WrongCat.h"

WrongCat::WrongCat()
{
	m_Type = "WrongCat";
	std::cout << GREEN << m_Type << " is born." << RESET;
}

WrongCat::WrongCat(const WrongCat& other)
	: WrongAnimal(other)
{
	if (this == &other)
		return ;
	m_Type = other.m_Type;
	std::cout << YELLOW << m_Type << " is born." << RESET;
}

WrongCat::~WrongCat()
{
	std::cout << RED << m_Type << " dies." << RESET;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	if (this == &other)
		return (*this);
	m_Type = other.m_Type;
	std::cout << BLUE << m_Type << " is born." << RESET;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}