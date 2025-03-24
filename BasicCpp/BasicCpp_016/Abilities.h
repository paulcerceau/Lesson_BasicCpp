#pragma once

#include "IDisplayable.h"
#include "AbilityName.h"

#include <map>
#include <string>

using std::map;
using std::string;


class Abilities : public IDisplayable
{
public:
	Abilities();
	~Abilities();

	//v Utilities ====================================================
	map<AbilityName, int> GetAbilities() const;
	string GetAbilityName(AbilityName ability) const;

	void Display() const override;

	//v Combat =======================================================
	// Calculate a damage input from abilities
	int GetAbilitiesDamage() const;

protected:
	void RollAbilities();

private:
	int RollAbility();

	map<AbilityName, int> m_abilities;

};
