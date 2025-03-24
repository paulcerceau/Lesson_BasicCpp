#pragma once

#include <string>


class Item
{
public:
	Item();
	Item(std::string name, std::string description, int rarity);
	~Item();

	std::string GetName() const;

private:
	std::string mName;
	std::string mDescription;
	int mRarity;

};
