#include "Weapon.h"

#include <iostream>

using std::cout;
using std::endl;


Weapon::Weapon()
{
}

Weapon::Weapon(std::string name, std::string description, int rarity, int damage) :
	Item{ name, description, rarity },
	mDamage{ damage }
{
}

Weapon::~Weapon()
{
}

int Weapon::GetDamage() const
{
	return mDamage;
}

void Weapon::Display() const
{
	cout << mName << " (" << mRarity << "): " << mDescription << " - Damage: " << mDamage << endl;
}
