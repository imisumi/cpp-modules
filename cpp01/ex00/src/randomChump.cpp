#include "Zombie.h"

void	randomChump(const std::string& name)
{
	Zombie Zombie(name);
	Zombie.announce();
}
