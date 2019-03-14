#pragma once
class Cell
{
public:
	Cell() : m_row(int()), m_col(int()), m_value(int()), m_isOriginal(true),
		m_isCorrect(true) {	}

	~Cell();
	int getValue() const { return m_value; }
	void setValue(int newValue) { m_value = newValue; }
	bool isCorrect() const { return m_isCorrect; }
	bool isOriginal() const { return m_isOriginal; }
private:
	int m_row;
	int m_col;
	int m_value;
	bool m_isOriginal;
	bool m_isCorrect;
};

