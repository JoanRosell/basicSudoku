#include "ConsoleHandler.h"

ConsoleHandler::ConsoleHandler()
{
	origin = { 0, 0 };
	currentY = OFFSET_Y;
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &screenBuffer);
	screenCenter = screenBuffer.dwSize.X / 2;
	SetConsoleCursorPosition(console, { screenCenter, currentY });
}
ConsoleHandler::~ConsoleHandler()
{
}

void ConsoleHandler::printMsg(const std::string& buffer)
{
	int bufferSize = buffer.size();
	short offset = screenCenter - (bufferSize / 2);
	SetConsoleCursorPosition(console, { offset, currentY });
	WriteConsole(console, buffer.data(), bufferSize, &written, NULL);
	jumpToNextLine();
}

void ConsoleHandler::jumpToNextLine()
{
	SetConsoleCursorPosition(console, { screenCenter, ++currentY });
}

