#include <iostream>

#include "Zombie.h"

int	main(void)
{
	Zombie* horde = zombieHorde(5, "Zombie");
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete[] horde;
	std::cout << std::endl;

	horde = zombieHorde(0, "Zombie");
	if (horde == nullptr)
		std::cout << "zombieHorde(0, \"Zombie\") returned nullptr" << std::endl;
	return (EXIT_SUCCESS);
}