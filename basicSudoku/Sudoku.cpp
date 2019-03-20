#include "Sudoku.h"

Sudoku::~Sudoku()
{
}

void Sudoku::loadSudokuFromFile(const std::string & file)
{
	//Suponiendo que guardemos los sudoku como una matriz 9 x 9 en el archivo:
		//originalLoadValues(initialBoardFile);
		//formatStoredValues();
	loadValues(file);
	loadBoardFromString();
}

void Sudoku::loadValues(const std::string & fileName)
{
	std::ifstream file;
	std::string board;
	int boardElements(MAX_ROWS*MAX_COLS);

	board.reserve(boardElements);
	originalValues.reserve(boardElements);
	correctValues.reserve(boardElements);

	file.open(fileName);
	if (file.is_open())
	{
		while (getline(file, originalValues) && getline(file, correctValues));
	}
	file.close();
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
	if (row < 1 || row > 9 || col < 1 || col > 9)
		throw std::out_of_range("Invalid position accessed");

	if (number < 1 || number > 9)
		throw "Invalid value";

	if (board[row - 1][col - 1].isModifiable())
	{
		board[row - 1][col - 1].setValue(number);
		checkCell(row - 1, col - 1);
	}

	if (number != 0)
		nOfCellsFilled++;
}

void Sudoku::eraseNumber(int row, int col)
{
	if (row < 1 || row > 9 || col < 1 || col > 9)
		throw std::out_of_range("Invalid position accessed");

	if (board[row - 1][col - 1].isModifiable())
	{
		board[row - 1][col - 1].setValue(0);
		checkCell(row - 1, col - 1);
	}

	nOfCellsFilled--;
}

void Sudoku::checkCell(int row, int col)
{
	int value = board[row][col].getValue();

	if ((value + '0') == correctValues.at((row*MAX_ROWS) + col))
		board[row][col].setCorrect(true);
	else
		board[row][col].setCorrect(false);
}

bool Sudoku::isCorrect()
{
	if (nOfCellsFilled == MAX_ROWS * MAX_COLS)
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
		m_isCorrect = cellIsCorrect;
	}
	
	return m_isCorrect;
		
}

void Sudoku::askForInsert()
{
	console.printMsg(numberDesc);
	console.showPrompt(userPrompt);
}

void Sudoku::askForErase()
{
	console.printMsg(eraseNumberDesc);
	console.showPrompt(userPrompt);
}

void Sudoku::printBoard()
{
	for (int i = 0; i < MAX_ROWS; i++)
	{
		console.printMsg(makeRow(i));
		if (i == 2 || i == 5)
			console.printMsg(separatorRow);
	}
	console.jumpToNextLine();
}

void Sudoku::printMenu()
{
	console.printMsg(playDesc);
	console.printMsg(eraseDesc);
	console.printMsg(returnDesc);
	console.jumpToNextLine();
	console.showPrompt(userPrompt);
}

void Sudoku::update()
{
	console.clearConsole();
	printBoard();
	printMenu();
}

void Sudoku::printFinalMsg()
{
	console.clearConsole();

	if (m_isCorrect)
		console.printMsg(victoryMsg);
	else
		console.printMsg(defeatMsg);
}

void Sudoku::originalLoadValues(const std::string & fileName)
{
	std::ifstream file;
	std::string row;
	int linesRead(0);
	row.reserve(17);
	originalValues.reserve((row.size() + 1)*MAX_ROWS);

	file.open(fileName);
	if (file.is_open())
	{
		while (getline(file, row))
		{
			row += " ";
			if (linesRead < 9)
				originalValues.append(row);
			else
				correctValues.append(row);
			row.clear();
			linesRead++;

			if (linesRead == 19)
				linesRead = 0;
		}
	}
	file.close();
}

void Sudoku::formatStoredValues()
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

std::string Sudoku::makeRow(int rowIndex) const
{
	std::string row = "| ";

	for (int col = 0; col < MAX_COLS; col++)
	{
		row += board[rowIndex][col].getValue() + '0';
		row += " ";
		if ((col == 2) || (col == 5))
			row += "| ";
	}

	row += "|";
	return row;
}
