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
	m_originalValues.reserve(boardElements);
	m_correctValues.reserve(boardElements);

	file.open(fileName);
	if (file.is_open())
	{
		while (getline(file, m_originalValues) && getline(file, m_correctValues));
	}
	file.close();
}

void Sudoku::loadBoardFromString()
{
	int stringSize = m_originalValues.size();
	int boardElements = MAX_ROWS * MAX_COLS;
	int stringIndex(0);

	if (stringSize == boardElements)
		for (int row = 0; row < MAX_ROWS; row++)
			for (int col = 0; col < MAX_COLS; col++)
			{
				int originalValue = m_originalValues.at(stringIndex) - '0';

				if (originalValue != 0)
				{
					m_board[row][col].setValue(originalValue);
					m_board[row][col].setModifiable(false);
					m_board[row][col].setCorrect(true);
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

	if (m_board[row - 1][col - 1].isModifiable())
	{
		m_board[row - 1][col - 1].setValue(number);
		checkCell(row - 1, col - 1);
	}

	if (number != 0)
		m_nOfCellsFilled++;
}

void Sudoku::eraseNumber(int row, int col)
{
	if (row < 1 || row > 9 || col < 1 || col > 9)
		throw std::out_of_range("Invalid position accessed");

	if (m_board[row - 1][col - 1].isModifiable())
	{
		m_board[row - 1][col - 1].setValue(0);
		checkCell(row - 1, col - 1);
	}

	m_nOfCellsFilled--;
}

void Sudoku::checkCell(int row, int col)
{
	int value = m_board[row][col].getValue();

	if ((value + '0') == m_correctValues.at((row*MAX_ROWS) + col))
		m_board[row][col].setCorrect(true);
	else
		m_board[row][col].setCorrect(false);
}

bool Sudoku::isCorrect()
{
	if (m_nOfCellsFilled == MAX_ROWS * MAX_COLS)
	{
		bool cellIsCorrect(true);
		int row(0);
		int col(0);

		while (cellIsCorrect && row < MAX_ROWS && col < MAX_COLS)
		{
			cellIsCorrect = m_board[row][col].isCorrect();
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
	m_console.printMsg(numberDesc);
	m_console.showPrompt(userPrompt);
}

void Sudoku::askForErase()
{
	m_console.printMsg(eraseNumberDesc);
	m_console.showPrompt(userPrompt);
}

void Sudoku::printBoard()
{
	for (int i = 0; i < MAX_ROWS; i++)
	{
		m_console.printMsg(makeRow(i));
		if (i == 2 || i == 5)
			m_console.printMsg(separatorRow);
	}
	m_console.jumpToNextLine();
}

void Sudoku::printMenu()
{
	m_console.printMsg(playDesc);
	m_console.printMsg(eraseDesc);
	m_console.printMsg(returnDesc);
	m_console.jumpToNextLine();
	m_console.showPrompt(userPrompt);
}

void Sudoku::update()
{
	m_console.clearConsole();
	printBoard();
	printMenu();
}

void Sudoku::printFinalMsg()
{
	m_console.clearConsole();

	if (m_isCorrect)
		m_console.printMsg(victoryMsg);
	else
		m_console.printMsg(defeatMsg);
}

void Sudoku::originalLoadValues(const std::string & fileName)
{
	std::ifstream file;
	std::string row;
	int linesRead(0);
	row.reserve(17);
	m_originalValues.reserve((row.size() + 1)*MAX_ROWS);

	file.open(fileName);
	if (file.is_open())
	{
		while (getline(file, row))
		{
			row += " ";
			if (linesRead < 9)
				m_originalValues.append(row);
			else
				m_correctValues.append(row);
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
	std::string::iterator newEnd = std::remove(m_originalValues.begin(), m_originalValues.end(), ' ');
	m_originalValues.erase(newEnd, m_originalValues.end());

	newEnd = std::remove(m_correctValues.begin(), m_correctValues.end(), ' ');
	m_correctValues.erase(newEnd, m_correctValues.end());
}

std::string Sudoku::makeRow(int rowIndex) const
{
	std::string row = "| ";

	for (int col = 0; col < MAX_COLS; col++)
	{
		row += m_board[rowIndex][col].getValue() + '0';
		row += " ";
		if ((col == 2) || (col == 5))
			row += "| ";
	}

	row += "|";
	return row;
}
