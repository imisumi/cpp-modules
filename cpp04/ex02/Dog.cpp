#include "Dog.h"

Dog::Dog()
{
	m_Type = "Dog";
	m_Brain = new Brain();
	std::cout << GREEN << m_Type << " is born." << RESET;
}

Dog::Dog(const Dog& other)
	: Animal(other)
{
	std::cout << YELLOW << "Dog is born." << RESET;
	if (this == &other)
	{
		m_Type = "Dog";
		m_Brain = new Brain();
		return ;
	}
	m_Type = other.m_Type;
	m_Brain = new Brain(*other.m_Brain);
}

Dog::~Dog()
{
	delete m_Brain;
	std::cout << RED << m_Type << " dies." << RESET;
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << BLUE << other.m_Type << " is cloned." << RESET;
	if (this == &other)
		return (*this);
	m_Type = other.m_Type;
	delete m_Brain;
	m_Brain = new Brain(*other.m_Brain);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof woof" << std::endl;
}

Brain* Dog::getBrain() const
{
	return (m_Brain);
}

void Dog::setIdea(int index, const std::string& idea)
{
	m_Brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	return (m_Brain->getIdea(index));
}