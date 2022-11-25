#include <iostream>
using namespace std;

#include "Page.h"

Page::Page(const char* name)
{
	_name = name;
	_fansList = new User * [1];
	_fansList = new User * [1];
}

void Page::createStatus()
{
	cout << "createStatus" << endl;
}

void Page::displayAllStatuses()
{
	cout << "displayAllStatuses" << endl;
}

void Page::displayAllFans()
{
	cout << "displayAllFans" << endl;
}
