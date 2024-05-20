#pragma once

#include "ClapTrap.h"

class FragTrap: public ClapTrap
{
public:
// Constructors
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap &copy);

// Deconstructor
	virtual ~FragTrap();

// assignation operator
	FragTrap &operator=(const FragTrap &src);

// Public Methods
	void highFiveGuys(void);

private:
};
