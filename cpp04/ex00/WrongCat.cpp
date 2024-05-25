#include "WrongCat.h"

WrongCat::WrongCat()
{
	m_Type = "WrongCat";
	std::cout << GREEN << m_Type << " is born." << RESET;
}

WrongCat::WrongCat(const WrongCat& other)
	: WrongAnimal(other)
{
	std::cout << YELLOW << "WrongCat is born." << RESET;
	if (this == &other)
	{
		m_Type = "WrongCat";
		return ;
	}
	m_Type = other.m_Type;
}

WrongCat::~WrongCat()
{
	std::cout << RED << m_Type << " dies." << RESET;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	std::cout << BLUE << other.m_Type << " is Cloned." << RESET;
	if (this == &other)
		return (*this);
	m_Type = other.m_Type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong meow meow" << std::endl;
}