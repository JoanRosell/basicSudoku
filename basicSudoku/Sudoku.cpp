#include "Sudoku.h"

Sudoku::~Sudoku()
{
}

void Sudoku::loadBoardFromString()
{
	int stringSize = originalBoardValues.size();
	int boardElements = MAX_ROWS * MAX_COLS;
	
	if (stringSize == boardElements)
		for (int i = 0; i < MAX_ROWS; i++)
			for (int j = 0; j < MAX_COLS; j++)
			{
				int thisValue = originalBoardValues.at(i*j) - 48;
				board[i][j].setValue(thisValue);

				if (thisValue != 0)
				{
					board[i][j].setModificable(false);
					board[i][j].setCorrect(true);
				}
			}
				
}

void Sudoku::loadFromFile(const std::string & fileName)
{
	std::ifstream file;
	std::string row;

	row.reserve(17);
	originalBoardValues.reserve(row.size()*MAX_ROWS);

	file.open(fileName);
	if (file.is_open())
	{
		while (getline(file, row))
		{
			row += " ";
			originalBoardValues.append(row);
			row.clear();
		}
	}

	formatString();
	loadBoardFromString();
	file.close();
}

void Sudoku::setNumber(int number, int row, int col)
{
	board[row - 1][col - 1].setValue(number);
}

bool Sudoku::checkWinCondition() const
{
	bool gameWon(true);
	int row(0);
	int col(0);

	while (gameWon)
	{
		gameWon = board[row][col].isCorrect();
		row++;
		col++;
	}

	return gameWon;
}

void Sudoku::formatString()
{
	std::string::iterator stringEnd = std::remove(originalBoardValues.begin(), originalBoardValues.end(), ' ');
	originalBoardValues.erase(stringEnd, originalBoardValues.end());
}

bool Sudoku::checkRow() const
{
	return false;
}

bool Sudoku::checkCol() const
{
	return false;
}

//	More work needed, end check loop
bool Sudoku::checkQuadrant() const
{
	int row(0);
	int col(0);
	bool quadrantCorrect(true);

	while (row < MAX_ROWS && quadrantCorrect)
	{
		int firstRow = (row / 3) * 3;
		int lastRow = firstRow + 3;
		int firstCol = (col / 3) * 3;
		int lastCol = firstCol + 3;

		for (int thisRow = firstRow; firstRow < lastRow; firstRow++)
			for (int thisCol = firstCol; firstCol < lastCol; firstCol++)
				quadrantCorrect = board[thisRow][thisCol].isCorrect();
		
		row += 3;
	}
	return quadrantCorrect;
}


