#include "WrongAnimal.h"

WrongAnimal::WrongAnimal()
{
	std::cout << GREEN << "WrongAnimal constructor called" << RESET;
	m_Type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << YELLOW << "WrongAnimal copy constructor called" << RESET;
	if (this == &other)
		return ;
	*this = other;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal destructor called" << RESET;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << BLUE << "WrongAnimal assignation operator called" << RESET;
	if (this == &other)
		return (*this);
	m_Type = other.m_Type;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (m_Type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "Random WrongAnimal sounds" << std::endl;
}

