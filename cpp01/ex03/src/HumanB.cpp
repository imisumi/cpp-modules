#include "HumanB.h"

HumanB::HumanB(const std::string &name)
	: m_Name(name), m_Weapon(nullptr)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack() const
{
	if (m_Weapon == nullptr)
	{
		std::cout << m_Name << " has no weapon to attack with" << std::endl;
		return;
	}
	std::cout << m_Name << " attacks with their " << m_Weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	m_Weapon = &weapon;
}