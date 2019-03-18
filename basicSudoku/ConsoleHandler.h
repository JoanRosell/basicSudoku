#pragma once
#include <Windows.h>
#include <string>

class ConsoleHandler
{
public:
	ConsoleHandler();
	~ConsoleHandler();
	void printMsg(const std::string& buffer);

private:
	COORD origin;
	short screenCenter;
	short currentY;
	static const short OFFSET_Y = 5;

	HANDLE console;
	CONSOLE_CURSOR_INFO cursorInfo;
	CONSOLE_SCREEN_BUFFER_INFO screenBuffer;
	DWORD written;
	
	void jumpToNextLine();
};

