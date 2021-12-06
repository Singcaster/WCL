#pragma once

#include <string>
#include <iostream>
#include <Windows.h>

using namespace std;

class Console {
private:
	static bool handling;
	static CONSOLE_CURSOR_INFO cursorInformations;
	static HANDLE standardInputHandle, standardOutputHandle;
	static CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInformations;

public:
	enum Color { Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, Gray = 8, Yellow = 14, White = 15 };

	static void clear();
	static unsigned long getConsoleMode();
	static string getLine();
	static bool isHandling();
	static void print(const Color& color, const string& line);
	static void printLine(const Color& color, const string& line);
	static int readConsoleASCII(char* characters, const unsigned long& characterCount, unsigned long* readCount);
	static void setCodePage(const unsigned int& codePage);
	static void setConsoleMode(const unsigned long& consoleMode);
	static void setColumn(const short& column);
	static void setCtrlHandler(int(*ctrlHandler)(unsigned long));
	static void setRow(const short& row);
	static void unsetCtrlHandler(int(*ctrlHandler)(unsigned long));
	static int writeConsoleASCII(const char* characters, const unsigned long& characterCount, unsigned long* writeCount);
};