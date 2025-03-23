#include "Abilities.h"

#include <iostream>

using std::cout;
using std::endl;
using std::rand;


Abilities::Abilities()
{
	RollAbilities();
}

Abilities::~Abilities()
{
}

map<AbilityName, int> Abilities::GetAbilities() const
{
	return m_abilities;
}

string Abilities::GetAbilityName(AbilityName ability) const
{
	switch (ability)
	{
	case AbilityName::Strength:
		return "Strength";
	case AbilityName::Dexterity:
		return "Dexterity";
	case AbilityName::Constitution:
		return "Constitution";
	case AbilityName::Intelligence:
		return "Intelligence";
	default:
		return "Unknown";
	}
}

void Abilities::Display() const
{
	cout << "Abilities:" << endl;

	for (const std::pair<AbilityName, int>& ability : m_abilities)
	{
		cout << "\t- " << GetAbilityName(ability.first) << ": " << ability.second << endl;
	}
}

void Abilities::RollAbilities()
{
	m_abilities[AbilityName::Strength] = RollAbility();
	m_abilities[AbilityName::Dexterity] = RollAbility();
	m_abilities[AbilityName::Constitution] = RollAbility();
	m_abilities[AbilityName::Intelligence] = RollAbility();
}

int Abilities::RollAbility()
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
