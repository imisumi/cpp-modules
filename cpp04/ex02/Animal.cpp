#include "Animal.h"

Animal::Animal()
{
	std::cout << GREEN << "Animal constructor called" << RESET;
	m_Type = "Animal";
}

Animal::Animal(const Animal &other)
{
	std::cout << YELLOW << "Animal copy constructor called" << RESET;
	if (this == &other)
		return ;
	m_Type = other.m_Type;
}

Animal::~Animal()
{
	std::cout << RED << "Animal destructor called" << RESET;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << BLUE << "Animal assignation operator called" << RESET;
	if (this == &other)
		return (*this);
	m_Type = other.m_Type;
	return (*this);
}

std::string Animal::getType() const
{
	return (m_Type);
}
