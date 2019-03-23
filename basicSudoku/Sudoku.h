#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Cell.h"
#include "ConsoleHandler.h"

using namespace std;
class Sudoku
{
public:
	Sudoku() : nOfCellsFilled(0), m_isCorrect(false) {	}
	~Sudoku();
	void loadSudokuFromFile(const std::string& initialBoardFile);
	void setNumber(int number, int row, int col);
	void eraseNumber(int row, int col);
	bool isCorrect();
	void askForInsert();
	void askForErase();
	void printBoard();
	void printMenu();
	void update();
	void printFinalMsg();
	std::string getOriginalValues() const { return originalValues; }
	std::string getCorrectValues() const { return correctValues; }

private:
	static const int MAX_ROWS = 9;
	static const int MAX_COLS = 9;
	Cell board[MAX_ROWS][MAX_COLS];
	std::string originalValues;
	std::string correctValues;
	ConsoleHandler console;
	int nOfCellsFilled;
	bool m_isCorrect;

	void loadValues(const std::string& fileName);
	void loadBoardFromString();
	void checkCell(int row, int col);
	std::string makeRow(int rowPointer) const;

	const std::string separatorRow = " | - - - | - - - | - - - | ";
	const std::string playDesc = "To introduce a number in the sudoku press 'i'";
	const std::string numberDesc = "Introduce number, row and column separated by spaces";
	const std::string eraseNumberDesc = "Introduce row and column separated by spaces";
	const std::string eraseDesc = "To erase a number from the sudoku press 'e'";
	const std::string returnDesc = "To end the game press 'f'";
	const std::string userPrompt = ">> ";
	const std::string victoryMsg = "Congratulations, you won";
	const std::string defeatMsg = "Better luck next time";

	//	DEPRECATED METHODS
	void originalLoadValues(const std::string& fileName);
	void formatStoredValues();
};

