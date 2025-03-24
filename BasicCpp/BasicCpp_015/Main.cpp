#include <iostream>

#include "Character.h"

using std::cout;
using std::endl;


int main()
{
	Character player("Player", 100);

	Inventory playerInventory = player.GetInventory();
	
	Item apple{ "Apple", "A simple apple", 1 };
	Weapon woodenSword{ "Wooden Sword", "A wooden sword. Good enough for training.", 2, 1 };
	Weapon ironSword{ "Iron sword", "An iron sword. Mandatory to leave the town.", 3, 3 };

	player.AddItemToInventory(&apple);
	player.AddItemToInventory(&woodenSword);
	player.AddItemToInventory(&ironSword);

	player.DisplayInfo();

	player.EquipWeapon();

	cout << endl;

	Character enemy("Enemy", 15);

	player.Attack(enemy);

	enemy.DisplayInfo();

	return 0;
}
