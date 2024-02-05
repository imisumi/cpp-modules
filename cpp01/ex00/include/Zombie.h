#pragma once

#include <iostream>

class Zombie
{
public:
	Zombie(const std::string& name);
	~Zombie();

	void	announce(void) const;

private:
	std::string	m_name;
};


Zombie*	newZombie(const std::string& name);
void	randomChump(const std::string& name);
