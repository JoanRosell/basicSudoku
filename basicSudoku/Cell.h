#pragma once
class Cell
{
public:
	Cell() : m_value(int()), m_isOriginal(true),
		m_isCorrect(true) {	}

	~Cell();
	int getValue() const { return m_value; }
	void setValue(int newValue) { m_value = newValue; }
	bool isCorrect() const { return m_isCorrect; }
	bool isOriginal() const { return m_isOriginal; }
	void setCorrect(bool correct) { m_isCorrect = correct; }
private:
	int m_value;
	bool m_isOriginal;
	bool m_isCorrect;
};

