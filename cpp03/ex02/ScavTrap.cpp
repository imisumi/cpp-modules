#include "ScavTrap.h"

ScavTrap::ScavTrap()
	: ClapTrap()
{
	m_HitPoints = 100;
	m_EnergyPoints = 50;
	m_AttackDamage = 20;
	std::cout << GREEN << "ScavTrap constructor called" << RESET;
}

ScavTrap::ScavTrap(const std::string& name)
	: ClapTrap(name)
{
	m_HitPoints = 100;
	m_EnergyPoints = 50;
	m_AttackDamage = 20;
	std::cout << GREEN << "ScavTrap constructor called" << RESET;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << RED << "ScavTrap destructor called" << RESET;
}

ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other.m_Name)
{
	*this = other;
	std::cout << "ScavTrap copy constructor called" << RESET;
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

void	ScavTrap::guardGate( void )
{
	if (m_GuardGate)
	{
		std::cout << "ScavTrap " << m_Name << " is already in Gate keeper mode" << std::endl;
		return ;
	}
	m_GuardGate = true;
	std::cout << "ScavTrap " << m_Name << " has entered in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (m_EnergyPoints == 0)
	{
		std::cout << m_Name << " can't attack, out of energy" << std::endl;
		return ;
	}
	if (m_HitPoints == 0)
	{
		std::cout << m_Name << " can't attack, out of hit points" << std::endl;
		return ;
	}
	std::cout << "ST: " << m_Name << " attacks " << target << " causing " << m_AttackDamage << " points of damage" << std::endl;
	m_EnergyPoints--;
}