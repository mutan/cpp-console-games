#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {

	enum fields {WORD, HINT, NUM_FIELDS};
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] = 
	{
		{"wall", "We don't need you education!"},
		{"earth", "Our planet."},
		{"crown", "On monarch's head."},
		{"brain", "Zombies like it."},
		{"strike", "Better then spare"}
	};

	srand(static_cast<unsigned int> (time(NULL)));
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD];
	string theHint = WORDS[choice][HINT];

	string jumble = theWord;

	random_shuffle(jumble.begin(), jumble.end());

	cout << "Welcome to the WORD JUMBLE!" << endl << endl;
	cout << "Unscrumble the letters to make a word." << endl;
	cout << "Enter 'hint' for a hint." << endl;
	cout << "Enter 'quit' to quit the game." << endl << endl;
	cout << "Jumble is: " << jumble << endl << endl;
	string guess;
	cout << "Your guess: ";
	cin >> guess;

	while ( (guess != theWord) && (guess != "quit") )
	{
		if (guess == "hint")
		{
			cout << theHint << endl << endl;
		}
		else
		{
			cout << "Sorry, you're wrong." << endl;
		}

		cout << "Your guess: ";
		cin >> guess;
	}

	if (guess == theWord)
	{
		cout << "You win!" << endl << endl;
	}

	cout << "Thank you for playing!" << endl << endl;


	return 0;
}