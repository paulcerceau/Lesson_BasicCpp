#include "Character.h"

#include <iostream>

using std::endl;
using std::cin;
using std::cout;
using std::pair;
using std::rand;
using std::string;
using std::vector;


int Character::currentlyLiving = 0;

Character::Character() :
	mName{ "John Doe" },
	mMaxHealth{ 20 },
	mpEquippedWeapon{ nullptr }
{
	mHealth = mMaxHealth;

	currentlyLiving++;
} 

Character::Character(string name, int maxHealth) :
	mName{ name },
	mMaxHealth{ maxHealth },
	mHealth{ maxHealth },
	mpEquippedWeapon{ nullptr }
{
	currentlyLiving++;
}

Character::Character(string name, int maxHealth, Inventory inventory) :
	mName{ name },
	mMaxHealth{ maxHealth },
	mHealth{ maxHealth },
	mInventory{ inventory },
	mpEquippedWeapon{ nullptr }
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

void Character::Attack(Character& target)
{
	int totalDamage = mAbilities.GetAbilitiesDamage() + mpEquippedWeapon->GetDamage();

	cout << mName << " attacks " << target.GetName() << " for " << totalDamage << " damage." << endl;

	target.ReceiveDamage(totalDamage);
}

void Character::SetName(string name)
{
	mName = name;
}

string Character::GetName() const
{
	return mName;
}

int Character::GetHealth() const
{
	return mHealth;
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

	if (mHealth <= 0)
	{
		mHealth = 0;
		cout << mName << " died." << endl;
	}
	else
	{
		cout << mName << " took " << damage << " damage." << endl;
	}
}

void Character::ReceiveHeal(int heal)
{
	// The following line is a ternary operator. It is a short way to write an if-else statement
	mHealth = mHealth + heal > mMaxHealth ? mMaxHealth : mHealth + heal;

	cout << mName << " healed for " << heal << " health." << endl;
}

Inventory Character::GetInventory() const
{
	return mInventory;
}

void Character::AddItemToInventory(Item* item)
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

void Character::EquipWeapon()
{
	// Search for a weapon in the inventory
	vector<Weapon*> weapons = mInventory.GetWeapons();

	// If no weapon is found, return
	if (weapons.empty())
	{
		cout << "No weapon found" << endl;
		return;
	}

	// If a single weapon is found, equip it
	if (weapons.size() == 1)
	{
		mpEquippedWeapon = weapons[0];
		cout << mName << " equipped " << mpEquippedWeapon->GetName() << endl;
		return;
	}
	
	// If there are multiple weapons, ask the user to choose one
	cout << "Choose a weapon to equip:" << endl;

	for (size_t i = 0; i < weapons.size(); i++)
	{
		cout << "\t" << i << "- "; 
		weapons[i]->Display();
	}

	int userChoice;

	do
	{
		cout << "Enter the number of the weapon you want to equip:" << endl;
		cin >> userChoice;
	} while (userChoice < 0 || userChoice >= weapons.size());

	mpEquippedWeapon = weapons[userChoice];
	cout << mName << " equipped " << mpEquippedWeapon->GetName() << endl;
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
