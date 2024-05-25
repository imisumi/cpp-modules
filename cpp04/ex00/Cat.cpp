#include "Cat.h"

Cat::Cat()
{
	m_Type = "Cat";
	std::cout << GREEN << m_Type << " is born." << RESET;
}

Cat::Cat(const Cat& other)
	: Animal(other)
{
	std::cout << YELLOW << "Cat is born." << RESET;
	if (this == &other)
	{
		m_Type = "Cat";
		return ;
	}
	m_Type = other.m_Type;
}

Cat::~Cat()
{
	std::cout << RED << m_Type << " dies." << RESET;
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout << BLUE << other.m_Type << " is cloned." << RESET;
	if (this == &other)
		return (*this);
	m_Type = other.m_Type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}