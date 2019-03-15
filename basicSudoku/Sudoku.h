#pragma once
#include <string>
#include "Cell.h"
#include <iostream>
#include <fstream>
class Sudoku
{
public:
	Sudoku() : originalBoardValues(""), correctBoardValues("") {	}
	~Sudoku();
	void loadFromFile(const std::string& fileName);
	void setNumber(int number, int row, int col);
	bool checkWinCondition() const;
	bool cellIsCorrect() const { return checkRow() && checkCol() && checkQuadrant(); }
	

private:
	static const int MAX_ROWS = 9;
	static const int MAX_COLS = 9;
	Cell board[MAX_ROWS][MAX_COLS];
	std::string originalBoardValues;
	std::string correctBoardValues;
	bool checkRow() const;
	bool checkCol() const;
	bool checkQuadrant() const;
};

