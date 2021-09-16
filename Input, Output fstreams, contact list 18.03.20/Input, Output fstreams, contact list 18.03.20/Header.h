#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

enum SearchBy
{
	BYPHONE = -1,
	NAME = 1,
	PHONE = 2,
	TELEGRAM = 3,
	EMAIL
};

using namespace std;

#include "ListItem.h"
#include "ContactList.h"
