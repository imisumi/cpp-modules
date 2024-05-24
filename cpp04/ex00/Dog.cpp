#include "Dog.h"

Dog::Dog()
{
	m_Type = "Dog";
	std::cout << GREEN << m_Type << " is born." << RESET;
}

Dog::Dog(const Dog& other)
	: Animal(other)
{
	if (this == &other)
		return ;
	m_Type = other.m_Type;
	std::cout << YELLOW << m_Type << " is born." << RESET;
}

Dog::~Dog()
{
	std::cout << RED << m_Type << " dies." << RESET;
}

Dog& Dog::operator=(const Dog &other)
{
	if (this == &other)
		return (*this);
	m_Type = other.m_Type;
	std::cout << BLUE << m_Type << " is born." << RESET;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof woof" << std::endl;
}