#pragma once

#include <string>
#include <vector>

#include "IDisplayable.h"
#include "Item.h"


class Inventory : public IDisplayable
{
public:
	Inventory();
	~Inventory();

	void AddItem(Item item);
	void RemoveItemByIndex(int index);
	void RemoveItemByName(std::string name);

	void Display() const override;

private:
	std::vector<Item> mItems;

};
