#include "Brain.h"

Brain::Brain()
{
	std::cout << GREEN << "Brain default constructor called" << RESET;
	for (int i = 0; i < MAX_IDEAS; i++)
		m_Ideas[i] = "Empty " + std::to_string(i);
}

Brain::Brain(const Brain &other)
{
	std::cout << YELLOW << "Brain copy constructor called" << RESET;
	if (this == &other)
	{
		for (int i = 0; i < MAX_IDEAS; i++)
			m_Ideas[i] = "Empty " + std::to_string(i);
		return ;
	}
	for (int i = 0; i < MAX_IDEAS; i++)
		m_Ideas[i] = other.m_Ideas[i];
}

Brain::~Brain()
{
	std::cout << RED << "Brain destructor called" << RESET;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << BLUE << "Brain assignation operator called" << RESET;
	if (this == &other)
		return (*this);
	for (int i = 0; i < MAX_IDEAS; i++)
		m_Ideas[i] = other.m_Ideas[i];
	return (*this);
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index < 0 || index >= MAX_IDEAS)
	{
		std::cout << "Brain::setIdea: Invalid index " << index << "\n";
		return ;
	}
	m_Ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= MAX_IDEAS)
	{
		std::cout << "Brain::getIdea: Invalid index " << index << "\n";
		return ("");
	}
	return (m_Ideas[index]);
}
