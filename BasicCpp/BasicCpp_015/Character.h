#pragma once

#include <string>
#include <vector>
#include <map>

#include "Abilities.h"
#include "Inventory.h"
#include "Weapon.h"

using std::string;
using std::map;


class Character
{
public:
	Character();
	Character(string name, int maxHealth);
	Character(string name, int maxHealth, Inventory inventory);
	~Character();

	//v Name =========================================================
	// Set the character's name
	void SetName(string name);
	// Get the character's name
	string GetName() const;

	//v Health =======================================================
	// Get the character's health
	int GetHealth() const;

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

	//v Attack =======================================================
	// Attack another character
	void Attack(Character& target);

	//v Inventory ====================================================
	// Get the character's inventory
	Inventory GetInventory() const;

	// Add an item to the character's inventory
	void AddItemToInventory(Item* item);

	// Remove an item to the character's inventory using its index
	void RemoveItemByIndexFromInventory(int index);

	// Add an item to the character's inventory using its name
	void RemoveItemByNameFromInventory(std::string name);

	// Display the character's inventory
	void DisplayInventory() const;

	// Equip the character's weapon
	void EquipWeapon();

	//v Information ==================================================
	// Display the character's info
	void DisplayInfo() const;

public: 
	static int currentlyLiving;

private:
	string mName;

	int mMaxHealth;
	int mHealth;

	Abilities mAbilities;
	Inventory mInventory;
	Weapon* mpEquippedWeapon;

};
