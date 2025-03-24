#pragma once

#include <string>
#include <vector>

#include "IDisplayable.h"
#include "Weapon.h"


class Inventory : public IDisplayable
{
public:
	Inventory();
	~Inventory();

	int GetSize() const;

	void AddItem(Item* item);
	Item* GetItem(int index) const;
	Item* GetItem(std::string name) const;
	void RemoveItemByIndex(int index);
	void RemoveItemByName(std::string name);

	std::vector<Weapon*> GetWeapons();

	void Display() const override;

private:
	std::vector<Item*> mItems;

};
