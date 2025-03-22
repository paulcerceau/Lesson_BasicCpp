#pragma once
#include <string>
#include <vector>
#include <map>

#include "Abilities.h"
#include "Inventory.h"
#include "Item.h"

using std::string;
using std::vector;
using std::map;


class Character
{
public:
	Character();
	Character(string name, int maxHealth);
	Character(string name, int maxHealth, vector<Item> inventory);
	~Character();

	//v Name =========================================================
	// Set the character's name
	void SetName(string name);
	// Get the character's name
	string GetName() const;

	//v Health =======================================================
	// Set the character's max health
	void SetMaxHealth(int maxHealth);
	// Get the character's max health
	int GetMaxHealth() const;

	// Do damage to the character
	void ReceiveDamage(int damage);
	// Heal the character
	void ReceiveHeal(int heal);

	//v Abilities ====================================================
	// Get the character's abilities
	Abilities GetAbilities() const;

	// Display the character's abilities
	void DisplayAbilities() const;

	//v Inventory ====================================================
	// Get the character's inventory
	Inventory GetInventory() const;

	// Display the character's inventory
	void DisplayInventory() const;

	//v Information ==================================================
	// Display the character's info
	void DisplayInfo() const;

private:
	string m_name;

	int m_maxHealth;
	int m_health;

	Abilities m_abilities;
	Inventory m_inventory;

};
