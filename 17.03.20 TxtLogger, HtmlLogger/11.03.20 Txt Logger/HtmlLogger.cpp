#include "Header.h"
#include "HtmlLogger.h"

void HtmlLogger::WriteError(string message)
{
	if (_fout.is_open())
	{
		_fout << "<li> Error: " << message << "</li>" << endl;
	}
	else
	{
		throw string("The file has not been opened!");
	}
}

void HtmlLogger::WriteWarning(string message)
{
	if (_fout.is_open())
	{
		_fout << "<li> Warning: " << message << "</li>" << endl;
	}
	else
	{
		throw string("The file has not been opened!");
	}
}

HtmlLogger::HtmlLogger(string path)
{
	_path = path;
	_path += ".html";
	_fout.open(_path);
	if (_fout.is_open())
	{
		_fout << "<!DOCTYPE html>\n"
			<< "<html lang=\"en\">\n"
			<< "<head>\n"
			<< "<meta charset=\"UTF - 8\">\n"
			<< "<meta name=\"viewport\" content=\"width = device - width, initial - scale = 1.0\">\n"
			<< "<meta http-equiv=\"X - UA - Compatible\" content=\"ie = edge\">\n"
			<< "<link href=\"styles.css\" rel=\"stylesheet\">\n"
			<< "<title>Html Logger</title>\n"
			<< "</head>\n"
			<< "<body>\n"
			<< "<h1>Html Logger</h1>\n"
			<< "<ul>\n";
	}
	else
	{
		throw string("The file has not been created!");
	}
}

HtmlLogger::~HtmlLogger()
{
	if (_fout.is_open())
	{
		_fout << "</ul>\n"
			<< "</body>\n"
			<< "</html>\n";
		_fout.close();
	}
}
