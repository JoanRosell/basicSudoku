#include <iostream>
#include "Sudoku.h"
int main()
{
	Sudoku testSudoku;
	testSudoku.loadSudokuFromFiles("boardsFile.txt", "resultsFile.txt");
	std::cin.get();
	return 0;
}