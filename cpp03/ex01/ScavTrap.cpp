#include "ScavTrap.h"

ScavTrap::ScavTrap(const std::string& name)
	: ClapTrap(name)
{
	m_HitPoints = 100;
	m_EnergyPoints = 50;
	m_AttackDamage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other.m_Name)
{
	*this = other;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	m_Name = other.m_Name;
	m_HitPoints = other.m_HitPoints;
	m_EnergyPoints = other.m_EnergyPoints;
	m_AttackDamage = other.m_AttackDamage;
	std::cout << "ScavTrap assignation operator called" << std::endl;
	return *this;
}

void	ScavTrap::guardGate( void ) const
{
	std::cout << "ScavTrap " << m_Name << " has entered in Gate keeper mode" << std::endl;
}