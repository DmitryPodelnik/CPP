#pragma once
#include "Header.h"

class HtmlLogger final: public Logger
{
public:

	virtual void WriteError(string message) override;
	virtual void WriteWarning(string message) override;

	HtmlLogger(string path);
	~HtmlLogger();

private:

	string _path;
	ofstream _fout;

};

