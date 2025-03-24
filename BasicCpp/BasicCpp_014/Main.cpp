#include <iostream>

#include "Character.h"

using std::cout;
using std::endl;




int main()
{
	Character player("Player", 100);

	Inventory playerInventory = player.GetInventory();
	
	Item apple{ "Apple" };

	playerInventory.AddItem(apple);
	playerInventory.AddItem(apple);
	playerInventory.AddItem(apple);

	player.DisplayInfo(); // <--- Player's inventory is still empty

	player.AddItemToInventory(apple);
	player.AddItemToInventory(apple);
	player.AddItemToInventory(apple);

	player.DisplayInfo();

	cout << "Currently living characters: " << Character::currentlyLiving << endl;

	Character merchant("Merchant", 50);
	Character soldier("Soldier", 50);

	cout << "Currently living characters: " << Character::currentlyLiving << endl;

	return 0;
}