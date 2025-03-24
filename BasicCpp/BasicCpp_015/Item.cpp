#include "Item.h"

#include <iostream>

using std::cout;
using std::endl;
using std::string;


Item::Item() :
	mName{ "Default" },
	mDescription{ "Default" },
	mRarity{ 0 }
{
}

Item::Item(std::string name, std::string description, int rarity) :
	mName{ name },
	mDescription{ description },
	mRarity{ rarity }
{
}

Item::~Item()
{
}

string Item::GetName() const
{
	return mName;
}

void Item::Display() const
{
	cout << mName << " (" << mRarity << "): " << mDescription << endl;
}
