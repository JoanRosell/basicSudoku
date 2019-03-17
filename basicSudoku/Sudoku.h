#pragma once
#include <string>
#include "Cell.h"
#include <iostream>
#include <fstream>
#include <algorithm>
class Sudoku
{
public:
	Sudoku() : originalBoardValues(""), correctBoardValues("") {	}
	~Sudoku();
	void loadBoardFromString();
	void loadFromFile(const std::string& fileName);
	void setNumber(int number, int row, int col);
	bool checkWinCondition() const;
	
private:
	static const int MAX_ROWS = 9;
	static const int MAX_COLS = 9;
	Cell board[MAX_ROWS][MAX_COLS];
	std::string originalBoardValues;
	std::string correctBoardValues;
	void formatString();
	bool checkRow() const;
	bool checkCol() const;
	bool checkQuadrant() const;
};

