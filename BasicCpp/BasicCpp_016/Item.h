#pragma once

#include <string>

#include "IDisplayable.h"

class Item : public IDisplayable
{
public:
	Item();
	Item(std::string name, std::string description, int rarity);
	~Item();

	std::string GetName() const;

	void Display() const override;

protected: // <--- replace private with protected
	std::string mName;
	std::string mDescription;
	int mRarity;

};
