#include "ClapTrap.h"

ClapTrap::ClapTrap(const std::string& name)
	: m_Name(name), m_HitPoints(10), m_EnergyPoints(10), m_AttackDamage(0)
{
	std::cout << m_Name << " spawned in" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: m_Name(other.m_Name), m_HitPoints(other.m_HitPoints), m_EnergyPoints(other.m_EnergyPoints), m_AttackDamage(other.m_AttackDamage)
{
	std::cout << m_Name << " is cloned" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << m_Name << " despawned" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	m_Name = other.m_Name;
	m_HitPoints = other.m_HitPoints;
	m_EnergyPoints = other.m_EnergyPoints;
	m_AttackDamage = other.m_AttackDamage;
	std::cout << m_Name << " is assigned" << std::endl;
	return *this;
}

void	ClapTrap::attack(const std::string& target)
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
	std::cout << m_Name << " attacks " << target << " causing " << m_AttackDamage << " points of damage" << std::endl;
	m_EnergyPoints--;
}

void	ClapTrap::takeDamage(uint32_t amount)
{
	if (m_HitPoints == 0)
	{
		std::cout << m_Name << " is already destroyed" << std::endl;
		return ;
	}
	if (m_HitPoints <= amount)
	{
		m_HitPoints = 0;
		std::cout << m_Name << " takes " << amount << " points of damage and is destroyed" << std::endl;
		return ;
	}
	std::cout << m_Name << " takes " << amount << " points of damage" << std::endl;
	m_HitPoints -= amount;
}

void	ClapTrap::beRepaired(uint32_t amount)
{
	if (m_HitPoints == 0 || m_EnergyPoints == 0)
	{
		std::cout << m_Name << " can't be repaired, out of hit points or energy" << std::endl;
		return ;
	
	}
	std::cout << m_Name << " is repaired for " << amount << " points" << std::endl;
}

void	ClapTrap::setAttackDamage(uint32_t amount)
{
	m_AttackDamage = amount;
}

const std::string&	ClapTrap::getName(void) const
{
	return m_Name;
}

void	ClapTrap::printStatus(void) const
{
	std::cout << m_Name << " has " << m_HitPoints << " hit points and " << m_EnergyPoints << " energy points remaining " << std::endl;
}