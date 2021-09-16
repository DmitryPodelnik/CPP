#include "Headers.h"

Game::Game()
{
	pacman = new Pacman;
	Inky = new StupidGhost(ForegroundColor::WHITE, 15);
	Pinky = new StupidGhost(ForegroundColor::MAGENTA, 16, Direction::LEFT);
	Blinky = new CleverGhost(ForegroundColor::RED, 15);
	Clyde = new CleverGhost(ForegroundColor::DARKYELLOW, 16, Direction::RIGHT);
}

Game::~Game()
{
	delete pacman;
	delete Inky;
	delete Pinky;
	delete Blinky;
	delete Clyde;
}

void Game::ShowPosition()
{
	Console::SetColor(ForegroundColor::DARKGREEN);
	Console::SetCoord(5, 4);
	cout << "Pacman: " << "X: " << pacman->GetXPos() << "   Y:" << pacman->GetYPos() << "   aM:" << pacman->GetAM();
	cout << "   ";

	Console::SetCoord(5, 5);
	cout << "Inky:   " << "X: " << Inky->GetXPos() << "   Y:" << Inky->GetYPos() << "   aM:" << Inky->GetAM();
	cout << "   ";
	
	Console::SetCoord(5, 6);
	cout << "Pinky:  " << "X: " << Pinky->GetXPos() << "   Y:" << Pinky->GetYPos() << "   aM:" << Pinky->GetAM();
	cout << "   ";
	
	Console::SetCoord(5, 7);
	cout << "Blinky: " << "X: " << Blinky->GetXPos() << "   Y:" << Blinky->GetYPos() << "   aM:" << Blinky->GetAM();
	cout << "   ";
	
	Console::SetCoord(5, 8);
	cout << "Clyde:  " << "X: " << Clyde->GetXPos() << "   Y:" << Clyde->GetYPos() << "   aM:" << Clyde->GetAM();
	cout << "   ";
}

void Game::ShowPrivateInfo()
{
	pacman->CalculatePos();
	Inky->CalculatePos();
	Pinky->CalculatePos();
	Blinky->CalculatePos();
	Clyde->CalculatePos();
	ShowPosition();
}

void Game::DrawEverybody()
{
	pacman->Draw();
	Inky->Draw();
	Pinky->Draw();
	Blinky->Draw();
	Clyde->Draw();
}

void Game::MovingEverybody(bool& wall)
{
	if (wall == false)
	{
		pacman->Moving(pacman, wall);
	}
	Inky->Moving(pacman, wall);
	Pinky->Moving(pacman, wall);
	Blinky->Moving(pacman, wall);
	Clyde->Moving(pacman, wall);
}

void Game::CheckForCorrectKey()
{
	Keys tmp = _key;
	_key = Console::GetKey();

	if (pacman->isWall())
	{
		_key = tmp;
	}
}

void Game::SetSpeed()
{
	for (size_t i = 1; i < Statistics::GetLevel(); i++)
	{
		_speed -= 30;
	}
}

void Game::TransitionAfterDeath()
{
	system("cls");
	Console::SetCoord(50, 17);
	Console::SetColor(ForegroundColor::RED);
	cout << "You were eaten!";
	Console::SetCoord(45, 18);
	cout << "Now you have ";
	cout << Statistics::GetLives() << " lives. Be more carefull!";
	Console::SetCoord(30, 19);
	Console::SetColor(ForegroundColor::GREEN);
	cout << "You will be redirected to the start position after pressing any key.";
	Console::GetKey();
	system("cls");
}

void Game::TransitionToNewLevel()
{
	system("cls");
	Console::SetCoord(50, 17);
	Console::SetColor(ForegroundColor::GREEN);
	cout << "Congratulations!";
	Console::SetCoord(45, 18);
	cout << "You have completed level: ";
	Statistics::SetColorForLevel();
	cout << Statistics::GetLevel();
	Console::SetCoord(30, 19);
	Console::SetColor(ForegroundColor::GREEN);
	cout << "You will be redirected to the next level after pressing any key.";
	Console::GetKey();
	system("cls");
}

void Game::SuccessfulEndGame()
{
	system("cls");
	Console::SetCoord(50, 17);
	Console::SetColor(ForegroundColor::GREEN);
	cout << "Congratulations!";
	Console::SetCoord(40, 18);
	cout << "You have completed the last level: ";
	Statistics::SetColorForLevel();
	cout << Statistics::GetLevel();
	Console::SetCoord(30, 19);
	Console::SetColor(ForegroundColor::GREEN);
	cout << "You will be redirected to the main menu after pressing any key.";
	Console::GetKey();
	system("cls");
}

void Game::UnsuccessfulEndGame()
{
	system("cls");
	Console::SetCoord(50, 17);
	Console::SetColor(ForegroundColor::RED);
	cout << "Unfortunately, you lost.";
	Console::SetCoord(30, 18);
	cout << "You will be redirected to the main menu after pressing any key.";
	Console::GetKey();
	system("cls");
}

bool Game::isWin()
{
	if (_count == AMOUNT_OF_DOTS)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Game::isLose()
{
	if (Statistics::GetLives() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::SetInitialData(bool condition)
{
	if (condition == true)
	{
		Statistics::SetDefaultValues(Statistics::GetLevel(), Statistics::GetLives());
	}
	else
	{
		Timer::SetDefaultValues();
		Statistics::SetDefaultValues();
	}
	pacman->SetDefaultValues();
	Inky->SetDefaultValues(ForegroundColor::WHITE, 15);
	Pinky->SetDefaultValues(ForegroundColor::MAGENTA, 16, Direction::LEFT);
	Blinky->SetDefaultValues(ForegroundColor::RED, 15);
	Clyde->SetDefaultValues(ForegroundColor::DARKYELLOW, 16, Direction::RIGHT);
	Ghost::SetDefaultValues();
	Field::CopyField(TRUE);
	Bonus::SetDefaultValues();
	_count = 0;
	_prev_count = 0;
	_speed = 500;
	_release_check = false;
	_is_pacman_eaten = false;
	_is_bigdot_eaten = false;
}

void Game::SetDataAfterDeath()
{
	pacman->SetDefaultValues();
	Inky->SetDefaultValues(ForegroundColor::WHITE, 15, Direction::RIGHT, TRUE);
	Pinky->SetDefaultValues(ForegroundColor::MAGENTA, 16, Direction::LEFT, TRUE);
	Blinky->SetDefaultValues(ForegroundColor::RED, 15, Direction::LEFT, TRUE);
	Clyde->SetDefaultValues(ForegroundColor::DARKYELLOW, 16, Direction::RIGHT, TRUE);
	Bonus::SetDefaultValues();
	_release_check = false;
	_prev_count = _count;
	_is_bigdot_eaten = false;
}

void Game::Run()
{
	Keys choice;
	bool check = false;

	do {
		do {
			Menu::ShowMainMenu();
			choice = Console::GetKey();
			system("cls");
		} while (choice != Keys::SPACE && choice != Keys::ESC && choice != Keys::TAB && choice != Keys::BACKSPACE);

		switch (choice)
		{
		case Keys::SPACE:
		{

			Menu::PrintLoading();
			system("cls");

			_field.PrintField();
			Statistics::ShowStatistic();
			Timer::ShowTime();
			Menu::PrintStartMessage();
			DrawEverybody();
			ShowPrivateInfo();

			do {
				_key = Console::GetKey();
			} while (_key != Keys::UP && _key != Keys::DOWN && _key != Keys::RIGHT && _key != Keys::LEFT);

			bool wall;

			while (!isWin() && !isLose())
			{
				if (Statistics::GetLevel() > 1 && check == false || _is_pacman_eaten == true)
				{
					_field.PrintField();
					Statistics::ShowStatistic();
					Timer::ShowTime();
					Menu::PrintStartMessage();
					DrawEverybody();
					ShowPrivateInfo();
					SetSpeed();
					check = true;
					SetPacmanCondition(FALSE);

					do {
						_key = Console::GetKey();
					} while (_key != Keys::UP && _key != Keys::DOWN && _key != Keys::RIGHT && _key != Keys::LEFT);
				}

				pacman->SetDirection(DirectionMoving());

				wall = false;

				while (!_kbhit() && !isWin() && !isLose() && _is_pacman_eaten == false) // пока не нажата клавиша
				{
					if (_is_bigdot_eaten == true)
					{
						if (Timer::GetResultSeconds() > (Timer::GetTmpSeconds() + 9))
						{
							_is_bigdot_eaten = false;
							Bonus::IncreaseEnergyNumber();
						}
					}
					ReleaseEveryGhost();
					MovingEverybody(wall);
					Sleep(_speed);
					ShowPrivateInfo();
					Statistics::ShowStatistic();
					Timer::ShowTime();
				}
				
				if (!isWin() && !isLose() && _is_pacman_eaten == false)
				{
					CheckForCorrectKey();
				}

				if (_is_pacman_eaten == true)
				{
					Statistics::DecreaseLives();
					TransitionAfterDeath();
					SetDataAfterDeath();
					continue;
				}

				if (isWin())
				{
					if (Statistics::GetLevel() >= 10)
					{
						break;
					}
					else
					{
						TransitionToNewLevel();
						SetInitialData(TRUE);
						check = false;
					}
					Statistics::IncreaseLevel();
				}
				else if (isLose())
				{
					break;
				}

			}

			try
			{
				if (isWin())
				{
					SuccessfulEndGame();
					Retention::WriteAchievement();
				}
				else if (isLose())
				{
					UnsuccessfulEndGame();
					Retention::WriteAchievement();
				}
			}
			catch (exception& ex)
			{
				cout << ex.what() << endl;
			}

			SetInitialData();
			break;
		}
		case Keys::TAB:

			Menu::ShowAchievements();

			break;

		case Keys::BACKSPACE:

			Menu::ShowReference(choice);

			break;

		case Keys::ESC:


			Sleep(1000);
			exit(1);
		}

		system("cls");
	} while (choice != Keys::ESC);
}

void Game::FinishTheGame()
{
	system("cls");
	Console::SetCoord(50, 17);
	Console::SetColor(ForegroundColor::RED);
	cout << "The game is finished!";
	Sleep(2000);
	Console::SetCoord(0, 30);
	exit(1);
}

void Game::ReleaseEveryGhost()
{
	if (_release_check == false)
	{
		Inky->ReleaseGhost();
		if (_count > _prev_count + 2)
		{
			Pinky->ReleaseGhost();
			if (_count > _prev_count + 5)
			{
				Blinky->ReleaseGhost();
				if (_count > _prev_count + 8)
				{
      				Clyde->ReleaseGhost();
					_release_check = true;
				}
			}
		}
	}
}

void Game::SetBigDotCondition(bool cond)
{
	_is_bigdot_eaten = cond;
}

void Game::SetPacmanCondition(bool cond)
{
	_is_pacman_eaten = cond;
}

void Game::SetKey(Keys key)
{
	_key = key;
}

void Game::IncreaseCount()
{
	_count++;
}

Keys Game::GetKey()
{
	return _key;
}

size_t Game::GetSpeed()
{
	return _speed;
}

bool Game::GetBigDotCondition()
{
	return _is_bigdot_eaten;
}

Direction Game::DirectionMoving()
{
	switch (_key)
	{
	case Keys::UP:

		return Direction::UP;

	case Keys::DOWN:

		return Direction::DOWN;

	case Keys::RIGHT:

		return Direction::RIGHT;

	case Keys::LEFT:

		return Direction::LEFT;
	}
}

Field Game::_field;
Keys Game::_key;
size_t Game::_count = 0;
size_t Game::_prev_count;
size_t Game::_speed = 500;
bool Game::_release_check = false;
bool Game::_is_pacman_eaten = false;
bool Game::_is_bigdot_eaten = false;