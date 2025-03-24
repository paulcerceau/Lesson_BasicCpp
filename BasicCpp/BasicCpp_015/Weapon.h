#pragma once

#include "Item.h"

class Weapon : public Item
{
public:
	Weapon();
	Weapon(std::string name, std::string description, int rarity, int damage);
	~Weapon();

	int GetDamage() const;

	void Display() const override;

private:
	int mDamage;

};
