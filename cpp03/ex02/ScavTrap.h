#pragma once
#include "ClapTrap.h"

class ScavTrap : public ClapTrap
{
public:
// constructors
	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap( const ScavTrap& other );

// destructor
	~ScavTrap();

// assignation operator
	ScavTrap&	operator = ( const ScavTrap& other );

	void	guardGate( void );
	void	attack(const std::string& target);

private:
	bool m_GuardGate = false;
};
