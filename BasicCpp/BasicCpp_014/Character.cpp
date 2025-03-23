#include "Character.h"

#include <iostream>

using std::cout;
using std::endl;
using std::pair;
using std::rand;


Character::Character() :
	m_name("John Doe"),
	m_maxHealth(20)
{
	m_health = m_maxHealth;
}

Character::Character(string name, int maxHealth) :
	m_name(name),
	m_maxHealth(maxHealth),
	m_health(maxHealth)
{
}

Character::Character(string name, int maxHealth, vector<Item> inventory) :
	m_name(name),
	m_maxHealth(maxHealth),
	m_health(maxHealth),
	m_inventory(inventory)
{
}

Character::~Character()
{
}

Abilities Character::GetAbilities() const
{
	return m_abilities;
}

void Character::DisplayAbilities() const
{
	cout << "Abilities:" << endl;

	for (const std::pair<string, int>& ability : m_abilities)
	{
		cout << "\t- " << ability.first << ": " << ability.second << endl;
	}
}

void Character::SetName(string name)
{
	m_name = name;
}

string Character::GetName() const
{
	return m_name;
}

int Character::GetMaxHealth() const
{
	return m_maxHealth;
}

void Character::SetMaxHealth(int maxHealth)
{
	m_maxHealth = maxHealth;
}

void Character::ReceiveDamage(int damage)
{
	m_health -= damage;
}

void Character::ReceiveHeal(int heal)
{
	// The following line is a ternary operator. It is a short way to write an if-else statement
	m_health = m_health + heal > m_maxHealth ? m_maxHealth : m_health + heal;

	// This is the same as:
	/*
	if (m_health + heal > m_maxHealth)
	{
		m_health = m_maxHealth;
	}
	else
	{
		m_health += heal;
	}
	*/
}

void Character::AddToInventory(string item)
{
	m_inventory.push_back(item);
}

void Character::RemoveFromInventory(int index)
{
	if (index < 0 || index >= m_inventory.size())
	{
		cout << "Invalid index" << endl;
		return;
	}

	m_inventory.erase(m_inventory.begin() + index);
}

Inventory Character::GetInventory() const
{
	return m_inventory;
}

void Character::DisplayInventory() const
{
	if (m_inventory.empty())
	{
		cout << "Inventory is empty" << endl;
		return;
	}

	int itemIndex = 0;

	cout << "Inventory:" << endl;
	for (const string& item : m_inventory)
	{
		cout << "\t" << itemIndex << "- " << item << endl;
		itemIndex++;
	}
}

void Character::DisplayInfo() const
{
	cout << "\n---x---x---x---x---x---x---x---x---\n" << endl;

	cout << m_name << "'s info:" << endl;
	cout << "Health: " << m_health << "/" << m_maxHealth << endl;
	DisplayAbilities();
	DisplayInventory();

	cout << "\n---x---x---x---x---x---x---x---x---\n" << endl;
}
