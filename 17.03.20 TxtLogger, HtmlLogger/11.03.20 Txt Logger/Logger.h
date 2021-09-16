#pragma once
#include "Header.h"

using namespace std;

class Logger
{
public:

	virtual void WriteError(string message) = 0;
	virtual void WriteWarning(string message) = 0;
	virtual ~Logger() = 0 {};

};

