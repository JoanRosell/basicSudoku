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
	void loadSudokuFromFiles(const std::string& initialBoardFile, const std::string& correctBoardFile);
	
	void setNumber(int number, int row, int col);
	bool checkWinCondition() const;
	
private:
	static const int MAX_ROWS = 9;
	static const int MAX_COLS = 9;
	Cell board[MAX_ROWS][MAX_COLS];
	std::string originalValues;
	std::string correctValues;
	
	void loadOriginalValues(const std::string& fileName);
	void loadCorrectValues(const std::string & fileName);
	void formatValueStrings();
	void loadBoardFromString();
};

