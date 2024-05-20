#include "FragTrap.h"

FragTrap::FragTrap()
	: ClapTrap()
{
	m_HitPoints = 100;
	m_EnergyPoints = 100;
	m_AttackDamage = 30;
	std::cout << GREEN << "FragTrap constructor called" << RESET;
}

FragTrap::FragTrap(const std::string& name)
	: ClapTrap(name)
{
	m_HitPoints = 100;
	m_EnergyPoints = 100;
	m_AttackDamage = 30;
	std::cout << GREEN << "FragTrap constructor called" << RESET;
}

FragTrap::FragTrap(const FragTrap &copy)
	: ClapTrap(copy)
{
	*this = copy;
	std::cout << "FragTrap copy constructor called" << RESET;
}

FragTrap::~FragTrap( void )
{
	std::cout << RED << "FragTrap destructor called" << RESET;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	m_Name = src.m_Name;
	m_HitPoints = src.m_HitPoints;
	m_EnergyPoints = src.m_EnergyPoints;
	m_AttackDamage = src.m_AttackDamage;
	std::cout << "FragTrap assignation operator called" << std::endl;
	return *this;
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << m_Name << " High five guys!" << std::endl;
}