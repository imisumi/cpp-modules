#include "HumanA.h"

HumanA::HumanA(const std::string& name, Weapon& weapon)
	: m_Name(name), m_Weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	std::cout << m_Name << " attacks with their " << m_Weapon.getType() << std::endl;
}
