#pragma once
class Cell
{
public:
	Cell() : m_value(int()), m_isModificable(true),
		m_isCorrect(false) {	}

	~Cell();
	int getValue() const { return m_value; }
	void setValue(int newValue);
	void setCorrect(bool correct) { m_isCorrect = correct; }
	bool isCorrect() const { return m_isCorrect; }
	bool isOriginal() const { return m_isModificable; }
	void setModificable(bool isOriginal) { m_isModificable = isOriginal; }
private:
	int m_value;
	bool m_isModificable;
	bool m_isCorrect;
};

