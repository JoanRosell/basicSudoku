#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Cell.h"
#include "ConsoleHandler.h"

class Sudoku
{
public:
	Sudoku() : originalValues(""), correctValues("") {	}
	~Sudoku();
	void loadSudokuFromFile(const std::string& initialBoardFile);
	void setNumber(int number, int row, int col);
	bool checkWinCondition() const;
	void printBoard();
	void printMenu();

private:
	static const int MAX_ROWS = 9;
	static const int MAX_COLS = 9;
	Cell board[MAX_ROWS][MAX_COLS];
	std::string originalValues;
	std::string correctValues;
	ConsoleHandler console;
	
	void loadValues(const std::string& fileName);
	void loadBoardFromString();

	std::string makeRow(int rowPointer) const;
	const std::string separatorRow = " | - - - | - - - | - - - | ";

	const std::string playDesc = "To introduce a number in the sudoku press 'i'";
	const std::string eraseDesc = "To erase a number from the sudoku press 'e'";
	const std::string returnDesc = "To return to the main menu press 'r'";
	const std::string userPrompt = ">> ";

	//	DEPRECATED METHODS
	void originalLoadValues(const std::string& fileName);
	void formatStoredValues();

	
	
};

