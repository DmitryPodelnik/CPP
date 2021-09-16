#pragma once
#include "Headers.h"

class Retention
{
public:

	static void WriteAchievement() noexcept(false);
	static void ReadAchievments() noexcept(false);

	static void SetPath(string path);

private:

	static fstream _file;
	static string _path;

};


