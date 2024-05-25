#include "Dog.h"

Dog::Dog()
{
	m_Type = "Dog";
	std::cout << GREEN << m_Type << " is born." << RESET;
}

Dog::Dog(const Dog& other)
	: Animal(other)
{
	std::cout << YELLOW << "Dog is born." << RESET;
	if (this == &other)
	{
		m_Type = "Dog";
		return ;
	}
	m_Type = other.m_Type;
}

Dog::~Dog()
{
	std::cout << RED << m_Type << " dies." << RESET;
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << BLUE << other.m_Type << " is cloned." << RESET;
	if (this == &other)
		return (*this);
	m_Type = other.m_Type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof woof" << std::endl;
}