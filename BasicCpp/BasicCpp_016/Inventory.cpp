#include "Inventory.h"

#include <iostream>

using std::cout;
using std::endl;


Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

int Inventory::GetSize() const
{
	return mItems.size();
}

void Inventory::AddItem(Item* item)
{
	mItems.push_back(item);
}

Item* Inventory::GetItem(int index) const
{
	return mItems[index];
}

Item* Inventory::GetItem(std::string name) const
{
	for (Item* item : mItems)
	{
		if (item->GetName() == name)
		{
			return item;
		}
	}
	
	return nullptr;
}

void Inventory::RemoveItemByIndex(int index)
{
	if (index < 0 || index >= mItems.size())
	{
		cout << "Invalid index" << endl;
		return;
	}

	mItems.erase(mItems.begin() + index);
}

void Inventory::RemoveItemByName(std::string name)
{
	for (size_t i = 0; i < mItems.size(); i++)
	{
		if (mItems[i]->GetName() == name)
		{
			mItems.erase(mItems.begin() + i);
			return;
		}
	}

	cout << "Item not found" << endl;
}

std::vector<Weapon*> Inventory::GetWeapons()
{
	std::vector<Weapon*> weapons;

	for (Item* item : mItems)
	{
		if (Weapon* weapon = dynamic_cast<Weapon*>(item))
		{
			weapons.push_back(weapon);
		}
	}

	return weapons;
}

void Inventory::Display() const
{
	if (mItems.empty())
	{
		cout << "Inventory is empty" << endl;
		return;
	}
	int itemIndex = 0;
	cout << "Inventory:" << endl;
	for (const Item* item : mItems)
	{
		cout << "\t" << itemIndex << "- " << item->GetName() << endl;
		itemIndex++;
	}
}
