#include "Cat.h"

Cat::Cat()
{
	m_Type = "Cat";
	std::cout << GREEN << m_Type << " is born." << RESET;
}

Cat::Cat(const Cat& other)
	: Animal(other)
{
	if (this == &other)
		return ;
	m_Type = other.m_Type;
	std::cout << YELLOW << m_Type << " is born." << RESET;
}

Cat::~Cat()
{
	std::cout << RED << m_Type << " dies." << RESET;
}

Cat& Cat::operator=(const Cat &other)
{
	if (this == &other)
		return (*this);
	m_Type = other.m_Type;
	std::cout << BLUE << m_Type << " is born." << RESET;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}