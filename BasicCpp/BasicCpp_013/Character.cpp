#include "Character.h"

#include <iostream>

using std::cout;
using std::endl;
using std::pair;
using std::rand;


Character::Character() :
	mName("John Doe"),
	mMaxHealth(20)
{
	mHealth = mMaxHealth;

	RollAbilities();
}

Character::Character(string name, int maxHealth) :
	mName{ name },
	mMaxHealth{ maxHealth },
	mHealth{ maxHealth }
{
	RollAbilities();
}

Character::Character(string name, int maxHealth, vector<string> inventory) :
	mName{ name },
	mMaxHealth{ maxHealth },
	mHealth{ maxHealth },
	mInventory{ inventory }
{
	RollAbilities();
}

Character::~Character()
{
}

map<string, int> Character::GetAbilities() const
{
	return mAbilities;
}

void Character::DisplayAbilities() const
{
	cout << "Abilities:" << endl;

	for (const std::pair<string, int>& ability : mAbilities)
	{
		cout << "\t- " << ability.first << ": " << ability.second << endl;
	}
}

void Character::RollAbilities()
{
	mAbilities["Strength"] = RollAbility();
	mAbilities["Dexterity"] = RollAbility();
	mAbilities["Constitution"] = RollAbility();
	mAbilities["Intelligence"] = RollAbility();
}

int Character::RollAbility()
{
	const int abilityRollsCount = 4;
	int rolls[abilityRollsCount]{ 0 };

	int minimumRoll = 6;
	int minimumRollIndex = 0;

	// Roll all dices
	for (int i = 0; i < abilityRollsCount; i++)
	{
		rolls[i] = (rand() % 6) + 1;

		// Keep track of the minimum roll
		if (rolls[i] < minimumRoll)
		{
			minimumRoll = rolls[i];
			minimumRollIndex = i;
		}
	}

	// Remove the minimum roll
	rolls[minimumRollIndex] = 0;

	// Sum the highest 3 rolls
	int sum = 0;
	for (int i = 0; i < abilityRollsCount; i++)
	{
		sum += rolls[i];
	}

	return sum;
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
}

void Character::ReceiveHeal(int heal)
{
	// The following line is a ternary operator. It is a short way to write an if-else statement
	mHealth = mHealth + heal > mMaxHealth ? mMaxHealth : mHealth + heal;

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
	mInventory.push_back(item);
}

void Character::RemoveFromInventory(int index)
{
	if (index < 0 || index >= mInventory.size())
	{
		cout << "Invalid index" << endl;
		return;
	}

	mInventory.erase(mInventory.begin() + index);
}

void Character::DisplayInventory() const
{
	if (mInventory.empty())
	{
		cout << "Inventory is empty" << endl;
		return;
	}

	int itemIndex = 0;

	cout << "Inventory:" << endl;
	for (const string& item : mInventory)
	{
		cout << "\t" << itemIndex << "- " << item << endl;
		itemIndex++;
	}
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
