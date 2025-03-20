
#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::cout;
using std::endl;
using std::cin;

using std::string;

using std::rand;

using std::vector;

using std::map;
using std::pair;


// Jump a line in the console
void JumpLine()
{
	cout << endl;
}

// Write a custom separator in the console
void DrawCustomSeparator(string separator)
{
	cout << separator << endl;
}

// Return an ability roll, following the classic D&D rule: roll 4d6 and keep the highest 3
int AbilitiesRoll()
{
	const int abilityRollsCount = 4;
	int rolls[abilityRollsCount]{0};

	int minimumRoll = 6;
	int minimumRollIndex = 0;

	// Roll all dices
	for (int i = 0; i < abilityRollsCount; i++)
	{
		rolls[i] = (rand() % 6) + 1;

		// Keep track of the minimum roll
		if (rolls[i] < minimumRoll)
		{
			minimumRoll = rolls[i];
			minimumRollIndex = i;
		}
	}

	// Remove the minimum roll
	rolls[minimumRollIndex] = 0;

	// Sum the highest 3 rolls
	int sum = 0;
	for (int i = 0; i < abilityRollsCount; i++)
	{
		sum += rolls[i];
	}

	return sum;
}

int main()
{
	srand(time(NULL));

	//v Presentation =================================================
	string narratorName = "The Almighty";

	cout << "Hello adventurer, I am " << narratorName << ".\nSounds cool right?" << endl;
	cout << "What is your name? " << endl;

	string adventurerName;
	cin >> adventurerName;

	JumpLine();

	cout << "I am glad to meet you " << adventurerName << "!" << endl;

	string separator = "\n---x---x---x---x---x---x---x---x---\n";

	DrawCustomSeparator(separator);

	//v Simple rolls with a map and for loop ==========================
	// Create the abilities map
	map<string, int> abilities{
		{ "Strength", 0 },
		{ "Dexterity", 0 },
		{ "Constitution", 0 },
		{ "Intelligence", 0 }
	};

	for (std::pair<const string, int>& ability : abilities) 
	{
		ability.second = AbilitiesRoll();

		cout << ability.first << ": " << ability.second << ". ";

		if (ability.second > 15)
		{
			cout << "You are really good at " << ability.first << "!" << endl;
		}
		else if (ability.second < 10)
		{
			cout << "You are not so good at " << ability.first << "..." << endl;
		}
		else
		{
			cout << "You are average at " << ability.first << "." << endl;
		}
	}

	DrawCustomSeparator(separator);

	//v Classes suggestions ==========================================
	bool didReceiveSuggestion = false;

	if ((abilities["Strength"] > 12) || (abilities["Constitution"] > 12))
	{
		cout << "You should consider being a Warrior!" << endl;
		didReceiveSuggestion = true;
	}

	if (abilities["Dexterity"] > 15 && abilities["Intelligence"] > 10)
	{
		cout << "You should consider being a Rogue Arcanist!" << endl;
		didReceiveSuggestion = true;
	}

	if (!didReceiveSuggestion)
	{
		cout << "Did you consider being a Bard?" << endl;
	}

	DrawCustomSeparator(separator);

	//v Class selection ==============================================
	cout << "But after all the decision is all yours. What do you want to be?" << endl;
	cout << "1. Warrior\n2. Rogue\n3. Barbarian\n4. Wizard" << endl;

	int classChoice = 0;

	cin >> classChoice;

	JumpLine();

	switch (classChoice)
	{
	case 1:
		cout << "You chose to be a Warrior. Always needed." << endl;
		break;
	case 2:
		cout << "You chose to be a Rogue, you sneaky squirrel." << endl;
		break;
	case 3:
		cout << "You chose to be a Barbarian. HIT!" << endl;
		break;
	case 4:
		cout << "You chose to be a Wizard, Mr Potter!" << endl;
		break;
	default:
		cout << "I'll choose for you then. Be a Bard and sing me something right away!" << endl;
		break;
	}

	DrawCustomSeparator(separator);

	//v The adventurer's inventory ===================================
	// -- The small bag --
	cout << "I imagine you didn't come empty handed. What did you bring?" << endl;

	string smallBag[5]{ "Pen", "Apple", "Dice", };

	size_t smallBagSize = sizeof(smallBag) / sizeof(smallBag[0]);

	cout << "Your small bag contains:" << endl;
	for (int i = 0; i < smallBagSize; i++)
	{
		if (smallBag[i] == "")
		{
			continue;
		}

		cout << "\t- " << smallBag[i] << endl;
	}

	DrawCustomSeparator(separator);

	// -- The magic bag --
	cout << "This small bag is nice and all, but I have something better for you..." << endl;
	cout << "A magic bag, full of magic stuff!" << endl;

	vector<string> magicBag{ "Magic Wand", "Magic Hat", "Magic Cloak" };

	magicBag.push_back("Magic Ring");
	magicBag.push_back("Magic Potion");
	magicBag.push_back("Magic Scroll");

	magicBag.pop_back();

	cout << "Your magic bag contains:" << endl;

	for (string item : magicBag)
	{
		cout << "\t- " << item << endl;
	}

	DrawCustomSeparator(separator);

	//v Wrapping up ==================================================
	cout << "You are now ready to start your adventure. Don't you think?" << endl;
	cout << "1. Sure!\n2. Nah." << endl;

	int wrapDialogChoice = 0;
	cin >> wrapDialogChoice;
	JumpLine();

	while (wrapDialogChoice != 1)
	{
		cout << "Come on, " << adventurerName << ", you can do it!" << endl;
		cout << "1. Sure!\n2. Nah." << endl;
		cin >> wrapDialogChoice;
		JumpLine();
	}

	int cookieChoice = 0;

	do
	{
		cout << "Do you want a cookie before you go?" << endl;
		cout << "1. Yes\n2. No" << endl;
		cin >> cookieChoice;
		JumpLine();
	} while (cookieChoice != 1);

	cout << "Good luck on your journey, " << adventurerName << "!" << endl;

	return 0;
}