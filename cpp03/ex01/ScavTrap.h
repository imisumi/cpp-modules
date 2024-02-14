#pragma once
#include "ClapTrap.h"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap( void ) = delete;
	ScavTrap(const std::string& name);
	ScavTrap( const ScavTrap& other );
	~ScavTrap( void );

	ScavTrap&	operator = ( const ScavTrap& other );

	void	guardGate( void ) const;
};
