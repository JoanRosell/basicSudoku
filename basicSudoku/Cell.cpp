#include "Cell.h"

Cell::~Cell()
{
}

void Cell::setValue(int newValue)
{
	if (m_isModifiable)
		m_value = newValue;

	if (m_value < 1 || m_value > 9)
	{
		m_isCorrect = false;
	}	
}
