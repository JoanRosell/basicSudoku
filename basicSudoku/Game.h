#pragma once
#include "syncFile.h"
#include "userInterface.h"
#include "Controller.h"
#include "Model.h"
#include "fileHandler.h"

class Game
{
public:
	Game();
	~Game();
private:
	/**	Summary
	*	This class should: 
	*	ask the user for input
	*	
	*	Based on the input it should:
	*	Delegate operations on the controller, userInterface,
	*	and sudoku.
	*	Load fresh from a file, optionally load its latest state.
	*/
	userInterface m_userInterface;
	Controller m_controller;
	Model m_model;
	fileHandler m_fileHandler;
};

