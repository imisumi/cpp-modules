#pragma once
#include <iostream>

#include "Weapon.h"

class HumanA
{
	public:
		HumanA(const std::string& name, Weapon& weapon);
		~HumanA();
		void attack();
	private:
		std::string m_Name;
		Weapon& m_Weapon;
};
