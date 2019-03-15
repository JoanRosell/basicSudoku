#include <iostream>
#include "Sudoku.h"
int main()
{
	Sudoku testSudoku;
	testSudoku.loadFromFile("inputFile.txt");
	std::cin.get();
	return 0;
}