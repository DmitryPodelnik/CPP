#include "Header.h"

void TxtLogger::WriteError(string message)
{
	if (_fout.is_open())
	{
		_fout << "Error: " << message << endl;
	}
	else
	{
		throw string("The file has not been opened!");
	}
}

void TxtLogger::WriteWarning(string message)
{
	if (_fout.is_open())
	{
		_fout << "Warning: " << message << endl;
	}
	else
	{
		throw string("The file has not been opened!");
	}
}

TxtLogger::TxtLogger(string path)
{
	_path = path;
	_path += ".txt";
	_fout.open(_path, ios::app);
	if (_fout.is_open())
	{
		_fout << "The file has been created!" << endl;
	}
	else
	{
		throw string("The file has not been created!");
	}
}

TxtLogger::~TxtLogger()
{
	if (_fout.is_open())
	{
		_fout.close();
	}
}
