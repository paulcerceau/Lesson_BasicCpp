
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

	//v Simple rolls with a map and for loop ==========================
	// Create the abilities map
	map<string, int> abilities{
		{ "Strength", 0 },
		{ "Dexterity", 0 },
		{ "Constitution", 0 },
		{ "Intelligence", 0 }
	};

	for (std::pair<const string, int>& ability : abilities) // <--- Don't mind me too much for now
	{
		ability.second = ((rand() % 6) + 1) * 3;

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

	cout << separator << endl;

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

	/*
	cout << separator << endl;

	//v The adventurer's inventory ===================================
		// -- The small bag --
	cout << "I imagine you didn't come empty handed. What did you bring?" << endl;

	string smallBag[5]{ "Pen", "Apple", "Pineapple" };

	cout << "The first item in your small bag is a " << smallBag[0] << " and the second one is a " << smallBag[1] << ". Okay, interesting!" << endl;

	// Get the last item...
	cout << "But what is the last item?" << endl;

	size_t smallBagSize = sizeof(smallBag) / sizeof(smallBag[0]);
	int lastItemIndex = smallBagSize - 1;
	cout << "Hun, it's a... " << smallBag[lastItemIndex] << "?" << endl;

	// ...and replace it
	cout << "I shall replace it with something more useful..." << endl;
	smallBag[lastItemIndex] = "Dice";
	cout << "Isn't a " << smallBag[lastItemIndex] << " better?" << endl;

	cout << separator << endl;

	// -- The magic bag --
	cout << "This small bag is nice and all, but I have something better for you..." << endl;
	cout << "A magic bag, full of magic stuff!" << endl;

	vector<string> magicBag{ "Magic Wand", "Magic Hat", "Magic Cloak" };

	cout << "The first item in your magic bag is a " << magicBag[0] << ". Yeah, something magic, you figured" << endl;

	cout << "You can easily add or remove stuff. And if it is full, it will expand on its own. But be careful, this comes at a price." << endl;

	magicBag.push_back("Magic Ring");
	magicBag.push_back("Magic Potion");
	magicBag.push_back("Magic Scroll");

	cout << "Your magic bag contains " << magicBag.size() << " items." << endl;

	cout << "The last item is a " << magicBag[magicBag.size() - 1] << ". This might be too much, let's remove it!" << endl;

	magicBag.pop_back();

	cout << "The newest last item is a " << magicBag[magicBag.size() - 1] << "." << endl;

	cout << "This bag is really magic, isn't it?" << endl;

	*/

	return 0;
}