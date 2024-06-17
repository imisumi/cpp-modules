#include "Cat.h"

Cat::Cat()
{
	m_Type = "Cat";
	m_Brain = new Brain();
	std::cout << GREEN << m_Type << " is born." << RESET;
}

Cat::Cat(const Cat& other)
	: Animal(other)
{
	std::cout << YELLOW << "Cat is born." << RESET;
	if (this == &other)
	{
		m_Type = "Cat";
		m_Brain = new Brain();
		return ;
	}
	m_Type = other.m_Type;
	m_Brain = new Brain(*other.m_Brain);
}

Cat::~Cat()
{
	delete m_Brain;
	std::cout << RED << m_Type << " dies." << RESET;
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout << BLUE << other.m_Type << " is cloned." << RESET;
	if (this == &other)
		return (*this);
	m_Type = other.m_Type;
	delete m_Brain;
	m_Brain = new Brain(*other.m_Brain);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}

Brain* Cat::getBrain() const
{
	return (m_Brain);
}

void Cat::setIdea(int index, const std::string& idea)
{
	m_Brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	return (m_Brain->getIdea(index));
}