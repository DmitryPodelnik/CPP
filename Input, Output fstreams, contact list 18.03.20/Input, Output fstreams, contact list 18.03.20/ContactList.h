#pragma once
#include "Header.h"

class ContactList
{
public:

	ContactList() = default;
	ContactList(string name, string phone, string telegram = (""), string email = (""));
	ContactList(const ContactList&) = delete;

	ContactList& operator =(const ContactList&) = delete;

	void AddContact(string name, string phone, string telegram = (""), string email = (""));
	void DelContact(const string& origin_phone);
	void EditContact(string origin_phone, string name = (""), string phone = (""), string telegram = (""), string email = (""));
	size_t SearchContact(const string& information, size_t method);
	void SaveContact(int i = -1, const string& origin_phone = (""));
	void ReadContacts();
	void PrintContact(int i = -1, const string& origin_phone = (""));
	void PrintAllContacts();


private:
    
	vector<ListItem*> _contacts;
	fstream _file;
	string _path;

	bool isEmpty(string str);

};

