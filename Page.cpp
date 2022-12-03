#include <iostream>
using namespace std;

#include "Page.h"
class User;
class Status;

Page::Page(const char* name)
{
	_name = new char[MAX_CHARACTERS];
	_name = _strdup(name);

	_fansList = new User * [1];
	_statuses = new Status * [1];
}

void Page::createStatus()
{
	if (_maxStatuses == _numOfStatuses)
	{
		_maxStatuses *= 2;
		Status** newStatuses = new Status * [_maxStatuses];
		for (int i = 0; i < _numOfStatuses; i++)
			newStatuses[i] = _statuses[i];

		delete[] _statuses;
		_statuses = newStatuses;
	}

	Status* newStatus = new Status();
	newStatus->getStatusInfo(newStatus);
	_statuses[_numOfStatuses] = newStatus;
	cout << "Status Uploaded!" << endl << endl;
	_numOfStatuses++;
}

void Page::displayAllStatuses()
{
	cout << endl << _name << " Statuses: " << endl;
	for (int i = 0; i < _numOfStatuses; i++)
	{
		cout << "---------------------------------" << endl;
		cout << "Status #" << i + 1 << ":\n";
		cout << "Text: " << _statuses[i]->getText() << endl;
		cout << "Uploaded on: ";
		_statuses[i]->getDateAndHour().displayDate();
		cout << " | ";
		_statuses[i]->getDateAndHour().displayTime();
		cout << endl << "---------------------------------" << endl << endl;
	}
	cout << endl;
}

void Page::displayAllFans()
{
	cout << _name << " Fans:\n";

	if (_numOfFans == 0)
		cout << "none :(" << endl;
	else {
		for (int i = 0; i < _numOfFans; i++)
			cout << _fansList[i]->getName() << endl;
	}

	cout << endl << endl;
}

// receives fan and adds him to the page's fan list
void Page::addFanToPage(Operation* system, User* current_user)
{
	if (_numOfFans == _maxFans)
	{
		_maxFans *= 2;
		User** new_fans_list = new User * [_maxFans];
		for (int i = 0; i < _numOfFans; i++)
		{
			new_fans_list[i] = _fansList[i];
		}
		_fansList = new_fans_list;
		new_fans_list = nullptr;
		delete[] new_fans_list;
	}

	_fansList[_numOfFans] = current_user;
	_numOfFans++;
}

// TODO not working
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

Page::~Page()
{
	delete _name; //  we dont use delete[] for char* only for const char*  

	for (int i = 0; i < _numOfStatuses; i++)
	{
		delete[] _statuses[i];
	}
	delete[] _statuses;

	for (int i = 0; i < _numOfFans; i++)
	{
		delete[] _fansList[i];
	}
	delete[] _fansList;
}