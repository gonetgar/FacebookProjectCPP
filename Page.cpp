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
	if (_maxStatuses == _numOfStatuses)
	{
		_maxStatuses *= 2;
		Status** newStatuses = new Status * [_maxStatuses];
		for (int i = 0; i < _numOfStatuses; i++)
			newStatuses[i] = _statuses[i];

		_statuses = newStatuses;
		// todo delete newStatuses
		// error - delete[] newStatuses
	}

	Status* newStatus = new Status();
	newStatus->getStatusInfo(newStatus);
	_statuses[_numOfStatuses] = newStatus;
	_numOfStatuses++;


	// ################################################ // for debugging // TODO delete later
	cout << "\n--------------------------------\n";
	cout << "List of statuses:\n\n";
	for (int i = 0; i < _numOfStatuses; i++)
	{
		cout << "Text: " << _statuses[i]->getText() << endl;
		cout << "Date: ";
		_statuses[i]->getDateAndHour().displayDate();
		cout << "\nHour: ";
		_statuses[i]->getDateAndHour().displayTime();
		cout << endl << endl;
	}
	cout << "--------------------------------\n";
}

void Page::displayAllStatuses()
{
	cout << _name << " Statuses: " << endl;
	for (int i = 0; i < _numOfStatuses; i++)
		cout << _statuses[i]->getText() << ", " << endl;
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


// this function adds a user to the page's fans
void Page::addFanToPage(Operation* system, User* current_user)
{
	if (_maxFans == _numOfFans)
	{
		_maxFans *= 2;
		User** newFans = new User * [_maxFans];
		for (int i = 0; i < _numOfFans; i++)
			newFans[i] = _fansList[i];

		delete _fansList;
		_fansList = newFans;
	}

	_fansList[_numOfFans] = current_user;
	_numOfFans++;

	//cout << current_user->getName() << " is now a fan of: " << this->getName() << endl;
}

// I AM CHANING LIKE PAGE SO I AM CHANING THIS FUNC - TODO DELETE LATER
//void Page::addFanORI(User* newUser)
//{
//	if (_maxFans == _numOfFans) {
//		_maxFans *= 2;
//		User** newFans = new User * [_maxFans];
//		for (int i = 0; i < _numOfFans; i++)
//			newFans[i] = _fansList[i];
//
//		delete[] _fansList;
//		_fansList = newFans;
//	}
//
//	_fansList[_numOfFans] = newUser;
//	_numOfFans++;
//
//	newUser->likePageORI(this);
//
//	cout << newUser->getName() << " is now a fan of: " << this->getName();
//}

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