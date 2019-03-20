#pragma once
#include <Windows.h>
#include <string>

class ConsoleHandler
{
public:
	ConsoleHandler();
	~ConsoleHandler();

	void printMsg(const std::string& buffer);
	void clearConsole();
	void jumpToNextLine();
	void showPrompt(const std::string& prompt);
	COORD getCurrentCursorPos() { return { screenCenter - 20, ++currentY }; }

private:
	COORD origin;
	COORD initialCursorPosition;
	short promptPositionX;
	short screenCenter;
	short currentY;
	static const short TOP_MARGIN = 5;

	HANDLE console;
	CONSOLE_CURSOR_INFO cursorInfo;
	CONSOLE_SCREEN_BUFFER_INFO screenBuffer;
	DWORD written;
	
	
};

