#include <iostream>

#include "Character.h"

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main()
{
	srand(time(NULL));

	Character randomAdventurer;
	randomAdventurer.DisplayInfo();

	string adventurerName;

	cout << "Enter player character's name:" << endl;
	cin >> adventurerName;

	vector<string> playerInventory{ "Pen", "Rotten Apple", "Dice" };

	Character playerCharacter(adventurerName, 30, playerInventory);

	playerCharacter.ReceiveDamage(5);
	playerCharacter.AddToInventory("Fresh Apple");
	playerCharacter.DisplayInventory();
	playerCharacter.RemoveFromInventory(1);

	playerCharacter.DisplayInfo();

	return 0;
}
