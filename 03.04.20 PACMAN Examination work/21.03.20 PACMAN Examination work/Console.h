#pragma once
#include "Headers.h"

class Console
{
private:

	static HANDLE h;
	static size_t _activeMesh;


public:

	static void SetColor(ForegroundColor fColor, BackgroundColor bColor = BackgroundColor::BLACK)
	{
		SetConsoleTextAttribute(h, (int)fColor | (int)bColor);
	}

	static void SetCoord(short x, short y)
	{
		SetConsoleCursorPosition(h, COORD{ x, y });
	}

	static void ShowCursor(bool isShow)
	{
		CONSOLE_CURSOR_INFO structCursorInfo;
		GetConsoleCursorInfo(h, &structCursorInfo);
		structCursorInfo.bVisible = isShow;
		SetConsoleCursorInfo(h, &structCursorInfo);
	}

	static Keys GetKey()
	{
		Keys key = (Keys)_getch();

		if (key == Keys::ARROWS)
		{
			key = (Keys)_getch();
		}

		return key;
	}

	static COORD GetConsoleCursorPosition()
	{
		CONSOLE_SCREEN_BUFFER_INFO cbsi;
		if (GetConsoleScreenBufferInfo(h, &cbsi))
		{
			return cbsi.dwCursorPosition;
		}
		else
		{
			// The function failed. Call GetLastError() for details.
			COORD invalid = { 0, 0 };
			return invalid;
		}
	}

};

