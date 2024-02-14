#pragma once
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap() = delete;
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& other);
		~ClapTrap();
		ClapTrap&	operator=(const ClapTrap& other);

		void	attack(const std::string& target);
		void	takeDamage(uint32_t amount);
		void	beRepaired(uint32_t amount);
		void	setAttackDamage(uint32_t amount);

		const std::string&	getName(void) const;
		void	printStatus(void) const;

	protected:
		std::string	m_Name;
		uint32_t	m_HitPoints;
		uint32_t	m_EnergyPoints;
		uint32_t	m_AttackDamage;
};
