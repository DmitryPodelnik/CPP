#include "Header.h"


int main()
{
	try
	{
		ContactList list1(("Dmitry Almazov"), ("+380505852173"), ("@kysupreme"), ("kanyesupreme@ukr.net"));
		list1.PrintAllContacts();
		list1.AddContact(("Petr Ivanov"), ("+380685738473"));
		list1.PrintContact(BYPHONE, ("+380685738473"));
		list1.EditContact(("+380685738473"), (""), (""), ("@privet"), ("123@gmail.com"));
		list1.PrintContact(BYPHONE, ("+380685738473"));
		list1.DelContact(("+380685738473"));
		list1.PrintAllContacts();
		cout << list1.SearchContact(("+380505852173"), PHONE) << endl << endl;
		list1.PrintContact(BYPHONE, ("+380505852173"));
		list1.PrintContact(0);

		list1.SaveContact(0);
		list1.AddContact(("Petr Ivanov"), ("+380685738473"));
		list1.SaveContact(1);

		cout << "----------------" << endl;
		list1.ReadContacts();
	}
	catch (string message)
	{
		cout << message << endl;
	}



	return 0;
}