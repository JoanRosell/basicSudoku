#pragma once
class Cell
{
public:
	Cell() : m_value(int()), m_isModifiable(true), m_isCorrect(false) {	}
	~Cell();

	int getValue() const { return m_value; }
	bool isCorrect() const { return m_isCorrect; }
	bool isModifiable() const { return m_isModifiable; }
	
	void setValue(int newValue);
	void setCorrect(bool correct) { m_isCorrect = correct; }
	void setModifiable(bool isOriginal) { m_isModifiable = isOriginal; }

private:
	int m_value;
	bool m_isModifiable;
	bool m_isCorrect;
};

