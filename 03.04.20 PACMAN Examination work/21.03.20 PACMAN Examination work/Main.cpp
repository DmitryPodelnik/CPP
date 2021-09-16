#include "Headers.h"

int main()
{
	srand(time(NULL));
	Console::ShowCursor(FALSE);

	Game game;

	game.Run();

	Console::SetCoord(0, 30);

	return 0;
}