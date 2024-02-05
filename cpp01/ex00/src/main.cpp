#include <iostream>

#include "Zombie.h"

int	main(void)
{
	std::cout << "Zombie on the stack" << std::endl;
	Zombie Zombie1("bob");
	Zombie1.announce();

	std::cout << std::endl << "Zombie on the heap" << std::endl;
	Zombie* Zombie2 = newZombie("jim");
	Zombie2->announce();
	delete Zombie2;

	std::cout << std::endl << "Random Zombie on the stack" << std::endl;
	randomChump("joe");

	return (EXIT_SUCCESS);
}