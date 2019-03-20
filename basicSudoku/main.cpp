#include <iostream>
#include "Sudoku.h"
#include <sstream>

bool processInput(Sudoku& s)
{
	bool keepPlaying(true);
	try
	{
		std::string line;

		switch (std::cin.get())
		{
		case 'i':
		{
			s.askForInsert();

			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			getline(std::cin, line);

			std::stringstream lineStream(line);
			std::string value;
			std::string row;
			std::string col;
			lineStream >> value;
			lineStream >> row;
			lineStream >> col;
			lineStream.clear();

			if (!line.empty())
				s.setNumber(std::stoi(value), std::stoi(row), std::stoi(col));

			if (s.isCorrect())
				keepPlaying = false;
			break;
		}
		case 'e':
		{
			s.askForErase();

			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			getline(std::cin, line);

			std::stringstream lineStream(line);
			std::string row;
			std::string col;

			lineStream >> row;
			lineStream >> col;
			lineStream.clear();

			if (!line.empty())
				s.eraseNumber(std::stoi(row), std::stoi(col));
			break;
		}
		case 'f':
			keepPlaying = false;
			break;

		default:
			std::cerr << "Introduce any of the above options";
			std::cin.get();
			break;
		}
	}

	catch (const std::out_of_range& oor)
	{
		std::cerr << oor.what() << ", introduce numbers from 1 to 9";
		std::cin.get();
		return keepPlaying;
	}

	catch (const std::invalid_argument& ia)
	{
		std::cerr << "Invalid input, introduce numbers from 1 to 9";
		std::cin.get();
		return keepPlaying;
	}

	catch (const char* msg)
	{
		std::cerr << msg;
		std::cin.get();
		return keepPlaying;
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