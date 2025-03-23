#pragma once

#include "IDisplayable.h"

#include <map>
#include <string>

using std::map;
using std::string;


enum class AbilityName
{
	Strength,
	Dexterity,
	Constitution,
	Intelligence
};

class Abilities : public IDisplayable
{
public:
	Abilities();
	~Abilities();

	map<AbilityName, int> GetAbilities() const;

	string GetAbilityName(AbilityName ability) const;

	void Display() const override;

protected:
	void RollAbilities();

private:
	int RollAbility();

	map<AbilityName, int> m_abilities;

};
