#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

using std::string;

using std::rand;


int main()
{
	//srand(time(NULL)); // <--- Huuum... I wonder what it does

	//v Presentation =================================================
	string narratorName = "The Almighty";

	cout << "Hello adventurer, I am " << narratorName << ".\nSounds cool right?" << endl;
	cout << "What is your name? " << endl;

	string adventurerName;
	cin >> adventurerName;

	cout << "I am glad to meet you " << adventurerName << "!" << endl;

	string separator = "\n---x---x---x---x---x---x---x---x---\n";

	cout << separator << endl; 

	cout << "Let's see your abilities now..." << endl;

	//v Simple rolls for a simple logic ==============================
	int strengthDice = ((rand() % 6) + 1) * 3;
	int dexterityDice = ((rand() % 6) + 1) * 3;
	int constitutionDice = ((rand() % 6) + 1) * 3;
	int intelligenceDice = ((rand() % 6) + 1) * 3;

	cout << "Character abilities:" << endl;
	cout << "\tStrength: " << strengthDice << endl;
	cout << "\tDexterity: " << dexterityDice << endl;
	cout << "\tConstitution: " << constitutionDice << endl;
	cout << "\tIntelligence: " << intelligenceDice << endl;

	return 0;
}