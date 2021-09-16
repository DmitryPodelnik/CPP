#include "Headers.h"

void Menu::ShowMainMenu()
{
	Console::SetCoord(40, 0);
	Console::SetColor(ForegroundColor::GREY, BackgroundColor::DARKBLUE);
	cout << "WELCOME TO THE GAME \"PAC-MAN\"\n";
	Console::SetColor(ForegroundColor::BLACK, BackgroundColor::CYAN);
	cout << "SPACE to continue\n\n";
	Console::SetColor(ForegroundColor::GREY);
	cout << "TAB to see a top list\n\n"
		<< "BACKSPACE to see the rules\n\n";
	Console::SetColor(ForegroundColor::WHITE, BackgroundColor::DARKRED);
	cout << "ESC to exit";
	Console::SetColor(ForegroundColor::GREY);
}

void Menu::ShowReference(Keys& choice)
{
	Console::SetCoord(40, 0);
	cout << "THE RULES OF \"PAC-MAN\"\n";
	cout << "1. Your purpose is to eat all of yellow dots;\n"
		<< "2. Yellow dots are your way of moving;\n"
		<< "3. You have 4 enemies who will always chase you;\n"
		<< "4. If you bump into even though with one of them, you will lose 1 of your lives;\n"
		<< "5. If you have had more than 0 lives, you can continue the game;\n"
		<< "6. On the field of game you also have 4 BOLD dots;\n"
		<< "7. If you eat these points, you will become a SUPER-MAN for a while, and you will be able to devour your enemies;\n"
		<< "8. If you eat all yellow dots, you will complete a level, and you will be moved up to the next level;\n"
		<< "9. With each level, your speed and the speed of enemies increases;\n"
		<< "10. For each eaten dot, you will gain 10 points, for each BOLD dot you gain 50 points;\n"
		<< "11. For eating the first enemy you will gain 200 points;\n"
		<< "12. For each subsequent enemy you will receive 2 times more, respectively;\n"
		<< "13. The game has only 10 levels, but you can finish the game anytime.";
	choice = Console::GetKey();
	system("cls");
}

void Menu::PrintLoading()
{
	Console::SetCoord(40, 12);
	cout << "The game will be started in several seconds...";
	Console::SetCoord(40, 13);

	for (int i = 0; i < 41; i++)
	{
		cout << "_";
		Sleep(50);
	}
}

void Menu::PrintStartMessage()
{
	Console::SetColor(ForegroundColor::GREY);
	Console::SetCoord(50, 19);
	cout << "READY!!!";
	Sleep(2000);
	Console::SetCoord(50, 19);
	cout << "        ";
}

void Menu::ShowAchievements()
{
	try
	{
		Retention::ReadAchievments();
		Console::GetKey();
		system("cls");
	}
	catch (exception& ex)
	{
		Console::SetColor(ForegroundColor::RED);
		Console::SetCoord(35, 16);
		cout << ex.what() << endl;
		Console::GetKey();
	}
}
