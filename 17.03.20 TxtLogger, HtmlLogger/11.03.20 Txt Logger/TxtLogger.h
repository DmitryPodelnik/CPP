#pragma once
#include "Header.h"

class TxtLogger final: public Logger 
{
public:

    virtual void WriteError(string message) override;
    virtual void WriteWarning(string message) override;

    TxtLogger(string path);
    ~TxtLogger();

private:

    string _path;
    ofstream _fout;
};

