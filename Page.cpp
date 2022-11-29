#include <iostream>
using namespace std;

#include "Page.h"
class User;
class Status;

Page::Page(const char* name)
{
	_name = new char[256];
	_name = _strdup(name);

	_fansList = new User * [1];
	_statuses = new Status * [1];
}

void Page::createStatus()
{
	cout << "createStatus" << endl;
}

void Page::displayAllStatuses()
{
	cout << _name << " Statuses: " << endl;
	for (int i = 0; i < _numOfStatuses; i++)
		cout << _statuses[i]->_text << ", " << endl;
}

void Page::displayAllFans()
{
	cout << _name << " Fans: " << endl;
	for (int i = 0; i < _numOfFans; i++)
		cout << _fansList[i]->getName() << ", " << endl;
}

