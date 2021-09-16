#pragma once
#include "Headers.h"

class Timer
{
public:

	static void ShowTime();
	static void SetDefaultValues();
	static void SetTmpMin();
	static ushort GetResultSeconds();
	static ushort GetTmpSeconds();
	static ushort GetCurrentSeconds();
	static ushort GetCurrentMinutes();


private:

	static void CalculateTime();

	static long long _initial_time;
	static long long _end_time;
	static ushort _result_seconds;
	static ushort _result_minutes;
	static ushort _tmp_result_sec;

};

