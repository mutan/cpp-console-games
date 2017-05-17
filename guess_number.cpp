#include <iostream>
#include <ctime>

using namespace std;

const int MIN = 1;
const int MAX = 100;

int getRandom(int min, int max);
void instruct();
int getPlayerChoice();

int main() {

	int tries = 0;

	instruct();
	int comp_number = getRandom(MIN, MAX);
	int guess = getPlayerChoice();
	tries++;

	while (guess != comp_number)
	{
		if (guess < comp_number)
		{
			cout << "Too low! Wrong tries = " << tries << ". Try again." << endl;
		}
		else if (guess > comp_number)
		{
			cout << "Too high! Wrong tries = " << tries << ". Try again." << endl;
		}

		guess = getPlayerChoice();
		tries++;
	}

	cout << "You won in " << tries << " tries!" << endl;

	return 0;
}

int getRandom(int min, int max)
{
	srand(static_cast<unsigned int>(time(0)));
	int number = rand() % (max - min + 1) + min;

	return number;
}

void instruct()
{
	cout << "Greetings! GUESS NUMBER game welcomes you!\n\n";
	cout << "The computer guessed a number between " << MIN << " and " << MAX << ". Try to guess it!\n\n";
}

int getPlayerChoice()
{
	int guess;
	do
	{
		cout << "Guess a number (" << MIN << "-" << MAX << "):" << endl;
		cin >> guess;
	} while (guess < MIN || guess > MAX);
	return guess;
}
