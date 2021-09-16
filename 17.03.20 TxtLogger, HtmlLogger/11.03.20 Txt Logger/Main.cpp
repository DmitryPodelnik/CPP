#include "Header.h"

int main()
{
	try
	{
		TxtLogger log1("log1");
		log1.WriteError("The first string");
		log1.WriteError("The second string");
		log1.WriteError("The third string");
		log1.WriteWarning("The fouth string");
	}
	catch (string message)
	{
		cout << message << endl;
	}

	try
	{
		HtmlLogger hlog2("log2");
		hlog2.WriteWarning("First string");
		hlog2.WriteWarning("Second string");
		hlog2.WriteError("Third string");
		hlog2.WriteError("Fouth string");
	}
	catch (string message)
	{
		cout << message << endl;
	}
	
	
	









	return 0;
}