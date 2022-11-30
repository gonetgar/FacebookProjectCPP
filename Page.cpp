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

void Page::removeFan(User* removeUser)
{
	for (int i = 0; i < _numOfFans; i++)
	{
		if (removeUser == _fansList[i]) // user is a fan
		{
			// Swap the page with last element
			swap(_fansList[i], _fansList[_numOfFans - 1]);
			// decrement log size of array
			_numOfFans--;
			// call within page (this)
			removeUser->dislikePage(this);
		}
	}

	cout << endl << removeUser->getName() << " is no more a fan of:  " << this->getName() << endl << endl;

}
