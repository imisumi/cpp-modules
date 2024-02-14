#include "ClapTrap.h"

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

int main( void )
{
	const std::string name = "\e[1mBob\e[0m";
	const std::string name2 = "\e[1mSteve\e[0m";
	ClapTrap	a(name);
	ClapTrap	b(name2);
	// ClapTrap	b(a);

	std::cout << std::endl;
	attack(a, b, 5);
	attack(b, a, 3);
	attack(a, b, 4);

	std::cout << std::endl;
	a.beRepaired(5);
	a.printStatus();

	attack(b, a, 99);
	attack(b, a, 99);

	std::cout << std::endl;
	a.beRepaired(5);

	std::cout << std::endl;
	return EXIT_SUCCESS;
}