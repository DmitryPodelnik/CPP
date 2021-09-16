#include "Headers.h"



void Retention::WriteAchievement() noexcept(false)
{
	_file.open(_path, ios::app);
	if (!_file.is_open())
	{
		throw exception(("The file has not been created!"));
	}
	_file << "Level: " << Statistics::GetLevel() << "\t";
	_file << "Remaining lives: " << Statistics::GetLives() << "\t";
	_file << "Remaining ghosts: " << Ghost::GetAmount() << "\t";
	_file << "Score: " << Statistics::GetScore() << "\t";
	_file << "Timer: ";
	_file << Timer::GetCurrentMinutes() << ":";
	if (Timer::GetCurrentSeconds() < 10)
	{
		_file << "0" << Timer::GetCurrentSeconds() << endl;
	}
	else
	{
		_file << Timer::GetCurrentSeconds() << endl;
	}

	_file.close();
}

void Retention::ReadAchievments() noexcept(false)
{
	_file.open(_path);
	if (!_file.is_open())
	{
		throw exception(("The file has not been opened or file is not existed"));
	}

	char* buffer = new char[256];

	while (!_file.eof())
	{
		_file.getline(buffer, 256);
		cout << buffer << endl;
	}

	_file.close();
}

void Retention::SetPath(string path)
{
	_path = path;
}

fstream Retention::_file;
string Retention::_path = ("achievments.txt");



