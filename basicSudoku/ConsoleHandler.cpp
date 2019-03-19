#include "ConsoleHandler.h"

ConsoleHandler::ConsoleHandler()
{
	origin = { 0, 0 };
	currentY = TOP_MARGIN;

	console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &screenBuffer);

	screenCenter = screenBuffer.dwSize.X / 2;
	promptPositionX = screenCenter - 15;

	initialCursorPosition = { screenCenter, TOP_MARGIN };
	SetConsoleCursorPosition(console, initialCursorPosition);
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

void ConsoleHandler::clearConsole()
{
	FillConsoleOutputCharacterA(
		console, ' ', screenBuffer.dwSize.X * screenBuffer.dwSize.Y, origin, &written
	);

	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screenBuffer.dwSize.X * screenBuffer.dwSize.Y, origin, &written
	);

	currentY = TOP_MARGIN;
	SetConsoleCursorPosition(console, initialCursorPosition);
}

void ConsoleHandler::jumpToNextLine()
{
	SetConsoleCursorPosition(console, { screenCenter, ++currentY });
}

void ConsoleHandler::showPrompt(const std::string & prompt)
{
	int promptSize = prompt.size();
	SetConsoleCursorPosition(console, {promptPositionX, currentY});
	WriteConsole(console, prompt.data(), promptSize, &written, NULL);
}

