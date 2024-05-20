#pragma once
#include <iostream>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define RESET "\033[0m\n"

class ClapTrap
{
	public:
		ClapTrap();
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

	private:
		std::string	m_Name;
		uint32_t	m_HitPoints = 10;
		uint32_t	m_EnergyPoints = 10;
		uint32_t	m_AttackDamage = 0;
};
