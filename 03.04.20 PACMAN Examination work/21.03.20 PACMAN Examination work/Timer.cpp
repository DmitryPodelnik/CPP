#include "Headers.h"

void Timer::CalculateTime()
{
	static int tmp_seconds = 0;

	if (_initial_time == -1)
	{
		_initial_time = time(NULL);
	}

	_end_time = time(NULL);
	_result_seconds = (_end_time - _initial_time) + tmp_seconds;

	if (_result_seconds > 59)
	{
		_initial_time = time(NULL);
		for (; _result_seconds > 59;)
		{
			_result_minutes++;
			_result_seconds -= 60;
			tmp_seconds = _result_seconds;
		}

		Console::SetCoord(40, 0);
		cout << "  ";
	}
}

void Timer::ShowTime()
{
	CalculateTime();
	Console::SetCoord(52, 0);
	Console::SetColor(ForegroundColor::WHITE);
	cout << _result_minutes << ":";
	if (_result_seconds < 10)
	{
		cout << "0" << _result_seconds;
	}
	else
	{
		cout << _result_seconds;
	}
	Console::SetColor(ForegroundColor::GREY);
}

void Timer::SetDefaultValues()
{
	_initial_time = -1;
	_end_time = 0;
	_result_minutes = 0;
	_result_seconds = 0;
}

void Timer::SetTmpMin()
{
	_tmp_result_sec = GetResultSeconds();
}

ushort Timer::GetResultSeconds()
{
	ushort tmp;
	tmp = (_result_minutes + 1) * _result_seconds;
	return tmp;
}

ushort Timer::GetTmpSeconds()
{
	return _tmp_result_sec;
}

ushort Timer::GetCurrentSeconds()
{
	return _result_seconds;
}

ushort Timer::GetCurrentMinutes()
{
	return _result_minutes;
}

long long Timer::_initial_time = -1;
long long Timer::_end_time;
ushort Timer::_result_minutes;
ushort Timer::_result_seconds;
ushort Timer::_tmp_result_sec;
