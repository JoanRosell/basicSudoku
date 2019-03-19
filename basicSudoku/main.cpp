#include <iostream>
#include "Sudoku.h"

bool processInput(Sudoku& s)
{
	bool keepPlaying(true);
	std::string line;

	switch (std::cin.get())
	{
	case 'i':
		s.askForInsert();

		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		getline(std::cin, line);

		if (!line.empty())
			s.setNumber(line.at(0) - '0', line.at(2) - '0', line.at(4) - '0');

		if (s.isCorrect())
			keepPlaying = false;
		break;

	case 'e':
		s.askForErase();

		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		getline(std::cin, line);

		if (!line.empty())
			s.eraseNumber(line.at(0) - '0', line.at(2) - '0');
		break;

	case 'f':
		keepPlaying = false;
		break;

	default:
		break;
	}
	return keepPlaying;
}
int main()
{
	Sudoku testSudoku;

	testSudoku.loadSudokuFromFile("inputFile.txt");
	testSudoku.printBoard();
	testSudoku.printMenu();

	bool gameIsOnProgress(true);
	while (gameIsOnProgress)
	{
		gameIsOnProgress = processInput(testSudoku);
		testSudoku.update();
	}

	testSudoku.printFinalMsg();

	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
	std::cin.get();
	return 0;
}