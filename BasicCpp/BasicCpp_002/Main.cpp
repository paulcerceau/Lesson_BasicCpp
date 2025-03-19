#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

using std::string;


int main()
{
	//v Presentation =================================================
	string narratorName = "The Almighty";

	cout << "Hello adventurer, I am " << narratorName << ".\nSounds cool right?" << endl;
	cout << "What is your name? " << endl;
	
	string adventurerName;
	cin >> adventurerName;

	cout << "I am glad to meet you " << adventurerName << "!" << endl;

	return 0;
}