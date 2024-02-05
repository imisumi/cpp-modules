#include "Weapon.h"

Weapon::Weapon(const std::string& type)
	: m_Type(type)
{
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType() const
{
	return m_Type;
}

void Weapon::setType(const std::string& type)
{
	m_Type = type;
}