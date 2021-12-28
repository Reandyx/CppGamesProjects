#include <iostream>
#include <ctime>
#include "Windows.h"
void PrintInroduction(int Difficulty)
{
	//storyline sentances
	std::cout << "\n\nYou are a secret agent trying to break into a " << Difficulty;
	std::cout << " secure server room... \nEnter the correct code combination to continue... \n\n";

}
void PrintEnding()
{
	std::cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\n";
}

bool PlayGame(int Difficulty)
{
	PrintInroduction(Difficulty);

	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;
	const int CodeSum = CodeA + CodeB + CodeC;		//Sumes the code 
	const int CodeProduct = CodeA * CodeB * CodeC;

	//Print sum and product to the terminal 
	std::cout << std::endl;
	std::cout << "+ There are 3 numbers in the code";
	std::cout << "\n+ The codes add up to: " << CodeSum;
	std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

	//Store guesses by user
	int GuessA, GuessB, GuessC;
	std::cin >> GuessA >> GuessB >> GuessC;
	std::cout << "\nYou entered: " << GuessA << GuessB << GuessC;

	//User Guesses sum 
	int GuessSum;
	GuessSum = GuessA + GuessB + GuessC;
	std::cout << "\nGuess sum: " << GuessSum;

	//User Guess multiply product
	int GuessProduct;
	GuessProduct = GuessA * GuessB * GuessC;
	std::cout << "\nGuess multiply product: " << GuessProduct;

	//if that checks whether condition is true or false
	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		std::cout << "\n\n*** Well done agent! You have extracted a file! Keep going! ***";
		return true;
	}
	else
	{
		std::cout << "\n\n*** You entered the wrong code! Careful agent! Try again! ***";
		return false;
	}
}

int main()
{
	srand(time(NULL));
	int LevelDifficulty = 1;
	const int MaxDifficulty = 5;
	while (LevelDifficulty <= MaxDifficulty)	//Loop game until all levels are complete
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		std::cin.clear(); //Clears any errors
		std::cin.ignore(); //Discards the buffer

		if (bLevelComplete)		//increase the lvl difficulty
		{
			++LevelDifficulty;
		}
		Sleep(1000);
		system("cls");
	}
	PrintEnding();
	return 0;
}