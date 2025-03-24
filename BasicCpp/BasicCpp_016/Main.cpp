#include <iostream>
#include <fstream>

#include "Character.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string; 


int main()
{
	string separator = "\n---x---x---x---x---x---x---x---x---\n";

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

	//v Attacking a character ========================================
	Character enemy("Enemy", 15);

	player.Attack(enemy);

	enemy.DisplayInfo();

	
	//v Write a file =================================================
	ofstream myFileWrite;

	myFileWrite.open("CharacterInfo.txt");

	if (myFileWrite.is_open())
	{
		// Write file content
		myFileWrite << "Character's name: " << player.GetName() << endl;
		myFileWrite << "Character's health: " << player.GetHealth() << "/" << player.GetMaxHealth() << endl;
		myFileWrite << "Character's inventory: " << endl;

		Inventory playerInventory = player.GetInventory();
		for (size_t i = 0; i < playerInventory.GetSize(); i++)
		{
			myFileWrite << "\t" << playerInventory.GetItem(i)->GetName() << endl;
		}

		myFileWrite.close();		
	}
	else
	{
		cout << "Unable to open file." << endl;
	}

	//v Read a file ==================================================
	cout << "Getting character's info from file:" << endl;

	ifstream myFileRead;

	myFileRead.open("CharacterInfo.txt");

	if (myFileRead.is_open())
	{
		string line;
		while (getline(myFileRead, line))
		{
			cout << line << endl;
		}
		myFileRead.close();
	}
	else
	{
		cout << "Unable to open file." << endl;
	}

	return 0;
}
