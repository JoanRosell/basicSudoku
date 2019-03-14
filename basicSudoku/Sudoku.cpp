#include "Sudoku.h"



Sudoku::Sudoku()
{

}


Sudoku::~Sudoku()
{
}

void Sudoku::loadFromFile(const std::string & fileName)
{
}

void Sudoku::setNumber(int number, int row, int col)
{
	board[row - 1][col - 1].setValue(number);
}
