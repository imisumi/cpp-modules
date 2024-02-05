#include "Zombie.h"

// Constructor
Zombie::Zombie()
{
	m_name = "default";
}

Zombie::Zombie(const std::string& name)
{
	m_name = name;
}

// destructor
Zombie::~Zombie()
{
	 std::cout << "\""<< m_name << "\""<< " is exterminated" << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(const std::string& name)
{
	m_name = name;
}
