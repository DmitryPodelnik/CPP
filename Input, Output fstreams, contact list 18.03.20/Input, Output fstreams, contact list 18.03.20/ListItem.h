#pragma once
#include "Header.h"

class ListItem 
{
public:

	void SetName(const string& name) { _name = name; }
	void SetPhone(const string& phone) { _phone = phone; }
	void SetTelegram(const string& telegram) { _telegram = telegram; }
	void SetEmail(const string& email) { _email = email; }

	string GetName() { return _name; }
	string GetPhone() { return _phone; }
	string GetTelegram() { return _telegram; }
	string GetEmail() { return _email; }

private:

	string _name;
	string _phone;
	string _telegram;
	string _email;
};
