#include "Header.h"

ContactList::ContactList(string name, string phone, string telegram, string email)
{
	AddContact(name, phone, telegram, email);
}

void ContactList::AddContact(string name, string phone, string telegram, string email)
{
	ListItem* contact = new ListItem;
	contact->SetName(name);
	contact->SetPhone(phone);
	contact->SetTelegram(telegram);
	contact->SetEmail(email);
	_contacts.push_back(contact);
}

void ContactList::EditContact(string origin_phone, string name, string phone, string telegram, string email)
{
	size_t index = SearchContact(origin_phone, PHONE);

	if (!isEmpty(name))
	{
		_contacts[index]->SetName(name);
	}
	if (!isEmpty(phone))
	{
		_contacts[index]->SetPhone(phone);
	}
	if (!isEmpty(telegram))
	{
		_contacts[index]->SetTelegram(telegram);
	}
	if (!isEmpty(email))
	{
		_contacts[index]->SetEmail(email);
	}
}

void ContactList::DelContact(const string& origin_phone)
{
	size_t pos = 0;
	for (size_t i = 0; i < _contacts.size(); i++)
	{
		if (origin_phone == _contacts[i]->GetPhone())
		{
			pos = i;
		}
	}
	_contacts.erase(_contacts.begin() + pos);
}

size_t ContactList::SearchContact(const string& information, size_t method)
{
	size_t pos = INT_MAX;
	if (method == NAME)
	{
		for (size_t i = 0; i < _contacts.size(); i++)
		{
			if (information == _contacts[i]->GetName())
			{
				pos = i;
			}
		}
	}
	else if (method == PHONE)
	{
		for (size_t i = 0; i < _contacts.size(); i++)
		{
			if (information == _contacts[i]->GetPhone())
			{
				pos = i;
			}
		}
	}

	if (pos == INT_MAX)
	{
		throw string("The contact doesn't exist.");
	}

	return pos;
}

void ContactList::SaveContact(int i, const string& origin_phone)
{
	_path = "log.txt";
	_file.open(_path, ios::app);
	if (_file.is_open())
	{
		_file << "The file has been created!" << endl;
	}
	else
	{
		throw string("The file has not been created!");
	}

	if (i == -1)
	{
		i = SearchContact(origin_phone, PHONE);
	}
	_file << "Contact's name: " << _contacts[i]->GetName() << "\t";
	_file << "Contact's phone: " << _contacts[i]->GetPhone() << "\t";
	_file << "Contact's telegram: " << _contacts[i]->GetTelegram() << "\t";
	_file << "Contact's email: " << _contacts[i]->GetEmail() << endl;

	_file.close();
}

void ContactList::ReadContacts()
{
	_file.open(_path);
	if (_file.is_open())
	{
		_file << "The file has been opened!" << endl;
	}
	else
	{
		throw string("The file has not been created!");
	}

	char* buffer = new char[256];

	while (!_file.eof())
	{
		_file.getline(buffer, 256);
		cout << buffer << endl;
	}

	_file.close();

	delete[] buffer;
}

void ContactList::PrintContact(int i, const string& origin_phone)
{
	if (i == -1)
	{
		i = SearchContact(origin_phone, PHONE);
	}

	cout << "Contact's name: " << _contacts[i]->GetName() << "\t";
	cout << "Contact's phone: " << _contacts[i]->GetPhone() << "\t";
	cout << "Contact's telegram: " << _contacts[i]->GetTelegram() << "\t";
	cout << "Contact's email: " << _contacts[i]->GetEmail() << endl << endl;
}

void ContactList::PrintAllContacts()
{
	for (size_t i = 0; i < _contacts.size(); i++)
	{
		cout << "Contact's name: " << _contacts[i]->GetName() << "\t";
	    cout << "Contact's phone: " << _contacts[i]->GetPhone() << "\t";
	    cout << "Contact's telegram: " << _contacts[i]->GetTelegram() << "\t";
		cout << "Contact's email: " << _contacts[i]->GetEmail() << endl << endl;
	}
}

bool ContactList::isEmpty(string str)
{
	if (str.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}
