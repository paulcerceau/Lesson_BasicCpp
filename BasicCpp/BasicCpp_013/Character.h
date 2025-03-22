#pragma once
#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;


class Character
{
public:
	Character();
	Character(string name, int maxHealth);
	Character(string name, int maxHealth, vector<string> inventory);
	~Character();

	//v Name =========================================================
	// Set the character's name
	void SetName(string name);
	// Get the character's name
	string GetName() const;

	//v Abilities ====================================================
	// Get the character's abilities
	map<string, int> GetAbilities() const;
	// Display the character's abilities
	void DisplayAbilities() const;

	//v Health =======================================================
	// Set the character's max health
	void SetMaxHealth(int maxHealth);
	// Get the character's max health
	int GetMaxHealth() const;

	// Do damage to the character
	void ReceiveDamage(int damage);
	// Heal the character
	void ReceiveHeal(int heal);

	//v Inventory ====================================================
	// Add an item to the character's inventory
	void AddToInventory(string item);

	// Remove an item from the character's inventory
	void RemoveFromInventory(int index);

	// Display the character's inventory
	void DisplayInventory() const;

	//v Information ==================================================
	// Display the character's info
	void DisplayInfo() const;

protected:
	//v Abilities ====================================================
	// Roll the character's abilities
	void RollAbilities();

private:
	//v Abilities ====================================================
	// Roll an ability following D&D rules
	int RollAbility();

private:
	string m_name;

	map<string, int> m_abilities;

	int m_maxHealth;
	int m_health;

	vector<string> m_inventory;

};
