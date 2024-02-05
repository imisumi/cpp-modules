#include "Zombie.h"

Zombie* newZombie(const std::string& name)
{
	Zombie* newZombie = new Zombie(name);
	return (newZombie);
}
