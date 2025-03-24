#include "Item.h"

using std::string;


Item::Item()
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
