#pragma once
#include <string>
#include "Cell.h"
class Sudoku
{
public:
	Sudoku();
	~Sudoku();
	void loadFromFile(const std::string& fileName);
	void setNumber(int number, int row, int col);
	bool checkWinCondition() const;
	bool cellIsCorrect() const { return checkRow && checkCol && checkQuadrant; }
	

private:
	static const int MAX_ROWS = 9;
	static const int MAX_COLS = 9;
	Cell board[MAX_ROWS][MAX_COLS];

	bool checkRow() const;
	bool checkCol() const;
	bool checkQuadrant() const;
};

