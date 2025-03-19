#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

using std::string;

using std::rand;


int main()
{
	srand(time(NULL));

	//v Presentation =================================================
	string narratorName = "The Almighty";

	cout << "Hello adventurer, I am " << narratorName << ".\nSounds cool right?" << endl;
	cout << "What is your name? " << endl;

	string adventurerName;
	cin >> adventurerName;

	cout << "I am glad to meet you " << adventurerName << "!" << endl;

	string separator = "\n---x---x---x---x---x---x---x---x---\n";

	cout << separator << endl;

	//v Simple rolls for a simple logic ==============================
	cout << "Let's see your abilities now..." << endl;

	int strengthDice = ((rand() % 6) + 1) * 3;
	int dexterityDice = ((rand() % 6) + 1) * 3;
	int constitutionDice = ((rand() % 6) + 1) * 3;
	int intelligenceDice = ((rand() % 6) + 1) * 3;

	cout << "Character abilities:" << endl;
	cout << "\tStrength: " << strengthDice << endl;
	cout << "\tDexterity: " << dexterityDice << endl;
	cout << "\tConstitution: " << constitutionDice << endl;
	cout << "\tIntelligence: " << intelligenceDice << endl;

	cout << separator << endl;

	//v The adventurer's inventory ===================================
	// -- The small bag --
	cout << "I imagine you didn't come empty handed. What did you bring?" << endl;

	string smallBag[5]{ "Pen", "Apple", "Pineapple" }; // <--- string smallBag[5]{ "Pen", "Apple", "Pineapple", "", "" };

	cout << "The first item in your small bag is a " << smallBag[0] << " and the second one is a " << smallBag[1] << ". Okay, interesting!" << endl;

	// Get the last item...
	cout << "But what is the last item?" << endl;

	int lastItemIndex = smallBag->length() - 1;
	cout << "Hun, it's a... " << smallBag[lastItemIndex] << "?" << endl;

	// ...and replace it
	cout << "I shall replace it with something more useful..." << endl;
	smallBag[lastItemIndex] = "Dice";
	cout << "Isn't a " << smallBag[lastItemIndex] << " better?" << endl;

	return 0;
}