#pragma once
#include <iostream>

#include "Weapon.h"

class HumanB
{
	public:
		HumanB(const std::string& name);
		~HumanB();
		void attack() const;
		void setWeapon(Weapon& weapon);
	private:
		std::string m_Name;
		Weapon* m_Weapon;
};
