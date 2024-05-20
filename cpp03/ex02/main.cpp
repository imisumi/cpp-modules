#include "ScavTrap.h"
#include "FragTrap.h"

void	attack(ClapTrap& attacker, ClapTrap& target, uint32_t damage)
{
	std::cout << std::endl;
	attacker.setAttackDamage(damage);
	attacker.attack(target.getName());
	target.takeDamage(damage);
	attacker.setAttackDamage(0);
	target.printStatus();
	attacker.printStatus();
}

void	attackScav(ScavTrap& attacker, ClapTrap& target, uint32_t damage)
{
	std::cout << std::endl;
	attacker.setAttackDamage(damage);
	attacker.attack(target.getName());
	target.takeDamage(damage);
	attacker.setAttackDamage(0);
	target.printStatus();
	attacker.printStatus();
}

void	PrintName(ClapTrap* a)
{
	std::cout << a->getName() << std::endl;
}

int main( void )
{
	std::cout << std::endl;
	const std::string name = "\e[1mBob\e[0m";
	const std::string name2 = "\e[1mSteve\e[0m";
	const std::string name3 = "\e[1mJohn\e[0m";

	ClapTrap a(name);
	ScavTrap b(name2);
	FragTrap c(name3);

	std::cout << "\n";
	{
		FragTrap a(name);
		a.highFiveGuys();
	}
	std::cout << "\n";

	attack(a, c, 5);
	attackScav(b, c, 3);
	attack(a, c, 4);

	std::cout << std::endl;
	a.beRepaired(5);
	a.printStatus();
	attackScav(b, c, 99);
	attack(c, a, 99);

	
	
	return EXIT_SUCCESS;
}