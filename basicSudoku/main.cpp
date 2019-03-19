#include <iostream>
#include "Sudoku.h"
int main()
{
	Sudoku testSudoku;
	testSudoku.loadSudokuFromFile("inputFile.txt");
	testSudoku.printBoard();
	testSudoku.printMenu();
	std::cin.get();
	return 0;
}