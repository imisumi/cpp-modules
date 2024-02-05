#pragma once

#include <iostream>
#

class Zombie
{
public:
	Zombie();
	Zombie(const std::string& name);
	~Zombie();

	void	announce(void) const;
	void	setName(const std::string& name);

private:
	std::string	m_name;
};


Zombie* zombieHorde(int N, std::string name);
