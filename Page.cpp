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
	cout << _name << " Fans: ";

	if (_numOfFans == 0)
		cout << "none :(" << endl;
	else {
		for (int i = 0; i < _numOfFans; i++)
			cout << _fansList[i]->getName() << " , ";
	}

	cout << endl << endl;
}

void Page::addFan(User* newUser)
{
	if (_maxFans == _numOfFans) {
		_maxFans *= 2;
		User** newFans = new User * [_maxFans];
		for (int i = 0; i < _numOfFans; i++)
			newFans[i] = _fansList[i];

		delete[] _fansList;
		_fansList = newFans;
	}

	_fansList[_numOfFans] = newUser;
	_numOfFans++;

	newUser->likePage(this);

	cout << newUser->getName() << " is now a fan of: " << this->getName();
}
