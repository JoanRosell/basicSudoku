#include "Sudoku.h"

Sudoku::~Sudoku()
{
}

void Sudoku::loadSudokuFromFiles(const std::string & initialBoardFile, const std::string& finalBoardFile)
{
	loadOriginalValues(initialBoardFile);
	loadCorrectValues(finalBoardFile);
	formatValueStrings();
	loadBoardFromString();
}

void Sudoku::loadOriginalValues(const std::string & fileName)
{
	std::ifstream file;
	std::string row;

	row.reserve(17);
	originalValues.reserve((row.size()+1)*MAX_ROWS);

	file.open(fileName);
	if (file.is_open())
	{
		while (getline(file, row))
		{
			row += " ";
			originalValues.append(row);
			row.clear();
		}
	}
	file.close();
}

void Sudoku::loadCorrectValues(const std::string & fileName)
{
	std::ifstream file;
	std::string row;

	row.reserve(17);
	correctValues.reserve((row.size() + 1)*MAX_ROWS);

	file.open(fileName);
	if (file.is_open())
	{
		while (getline(file, row))
		{
			row += " ";
			correctValues.append(row);
			row.clear();
		}
	}
	file.close();
}

void Sudoku::formatValueStrings()
{
	/*
	*	std::remove(iterator_first, iterator_last, valueToRemove);
	*	Flushes all the elements that match the valueToRemove to the end of the range,
	*	then returns an iterator that points to the first valueToRemove
	*
	*	Usually, to get rid of those elements you erase them by calling your container's erase functions.
	*/
	std::string::iterator newEnd = std::remove(originalValues.begin(), originalValues.end(), ' ');
	originalValues.erase(newEnd, originalValues.end());

	newEnd = std::remove(correctValues.begin(), correctValues.end(), ' ');
	correctValues.erase(newEnd, correctValues.end());
}

void Sudoku::loadBoardFromString()
{
	int stringSize = originalValues.size();
	int boardElements = MAX_ROWS * MAX_COLS;
	int stringIndex(0);

	if (stringSize == boardElements)
		for (int row = 0; row < MAX_ROWS; row++)
			for (int col = 0; col < MAX_COLS; col++)
			{
				int originalValue = originalValues.at(stringIndex) - '0';
				if (originalValue != 0)
				{
					board[row][col].setValue(originalValue);
					board[row][col].setModifiable(false);
					board[row][col].setCorrect(true);
				}
				stringIndex++;
			}
}



void Sudoku::setNumber(int number, int row, int col)
{
	board[row - 1][col - 1].setValue(number);
}

bool Sudoku::checkWinCondition() const
{
	bool cellIsCorrect(true);
	int row(0);
	int col(0);

	while (cellIsCorrect && row < MAX_ROWS && col < MAX_COLS)
	{
		cellIsCorrect = board[row][col].isCorrect();
		col++;

		if (col == MAX_COLS)
		{
			col = 0;
			row++;
		}
	}

	return cellIsCorrect;
}



