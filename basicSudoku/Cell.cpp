#include "Cell.h"

Cell::~Cell()
{
}

void Cell::setValue(int newValue)
{
	if (m_isModificable)
		m_value = newValue;

	if (m_value == 0)
	{
		m_isCorrect = false;
	}	
}
