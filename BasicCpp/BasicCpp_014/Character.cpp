#include "Character.h"

#include <iostream>

using std::cout;
using std::endl;
using std::pair;
using std::rand;
using std::string;


int Character::currentlyLiving = 0;

Character::Character() :
	mName{ "John Doe" },
	mMaxHealth{ 20 }
{
	mHealth = mMaxHealth;

	currentlyLiving++;
} 

Character::Character(string name, int maxHealth) :
	mName{ name },
	mMaxHealth{ maxHealth },
	mHealth{ maxHealth }
{
	currentlyLiving++;
}

Character::Character(string name, int maxHealth, Inventory inventory) :
	mName{ name },
	mMaxHealth{ maxHealth },
	mHealth{ maxHealth },
	mInventory{ inventory }
{
	currentlyLiving++;
}

Character::~Character()
{
	currentlyLiving--;
}

Abilities Character::GetAbilities() const
{
	return mAbilities;
}

void Character::DisplayAbilities() const
{
	mAbilities.Display();
}

void Character::SetName(string name)
{
	mName = name;
}

string Character::GetName() const
{
	return mName;
}

int Character::GetMaxHealth() const
{
	return mMaxHealth;
}

void Character::SetMaxHealth(int maxHealth)
{
	mMaxHealth = maxHealth;
}

void Character::ReceiveDamage(int damage)
{
	mHealth -= damage;
}

void Character::ReceiveHeal(int heal)
{
	// The following line is a ternary operator. It is a short way to write an if-else statement
	mHealth = mHealth + heal > mMaxHealth ? mMaxHealth : mHealth + heal;
}

Inventory Character::GetInventory() const
{
	return mInventory;
}

void Character::AddItemToInventory(Item item)
{
	mInventory.AddItem(item);
}

void Character::RemoveItemByIndexFromInventory(int index)
{
	mInventory.RemoveItemByIndex(index);
}

void Character::RemoveItemByNameFromInventory(string name)
{
	mInventory.RemoveItemByName(name);
}

void Character::DisplayInventory() const
{
	mInventory.Display();
}

void Character::DisplayInfo() const
{
	cout << "\n---x---x---x---x---x---x---x---x---\n" << endl;

	cout << mName << "'s info:" << endl;
	cout << "Health: " << mHealth << "/" << mMaxHealth << endl;
	DisplayAbilities();
	DisplayInventory();

	cout << "\n---x---x---x---x---x---x---x---x---\n" << endl;
}
