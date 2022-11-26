﻿#include <iostream>
#include <string>
using namespace std;

#include "Operation.h"
#include "Functions.h"
class User;
class Page;

Operation::Operation()
{
	_allUsers = nullptr;
	_allPages = nullptr;
}


void Operation::initiateData(User** initUsers, Page** initPages)
{
	_allUsers = initUsers;
	_allPages = initPages;
}


User** Operation::getAllUsers()
{
	return _allUsers;
}

void Operation::addUserToOperation(User* userToAdd)
{
	int i = 0;

	if (_maxUsers == _numOfUsers)
	{
		_maxUsers *= 2;
		User** newUsers = new User * [_maxUsers];
		for (i = 0; i < _numOfUsers; i++)
			newUsers[i] = _allUsers[i];

		delete[] _allUsers;
		_allUsers = newUsers;
		_allUsers[i + 1] = userToAdd;
	}

	_allUsers[_numOfUsers] = userToAdd;
	_numOfUsers++;

	cout << "Hey, " << userToAdd->getName() << " Welcome to Facebook :) " << endl << endl;

}

void Operation::addPageToOperation(Page* page)
{
	// same as addUserToOperation()
}

void Operation::displayAllEntities()
{
	cout << endl << "ALL ENTITIES: " << endl;
	cout << "Current User: " << endl;
	cout << _currentUser.getName() << endl;

	cout << "Users: " << endl;
	for (int i = 0; i < _numOfUsers; i++)
		cout << _allUsers[i]->getName() << ", " << endl;

	cout << "Pages: " << endl;
	for (int i = 0; i < _numOfPages; i++)
		cout << _allPages[i]->getName() << ", " << endl;

	cout << endl;
}


void Operation::getCurrentMember()
{
	char* username = new char[256];

	cout << "Hello, please enter your name for varification: ";
	cin >> username;
	cout << endl;

	_currentUser.setName(username);
	cout << _currentUser.getName() << "," << endl;
}


void Operation::handleMenu(int userChoice)
{
	if (userChoice > 0 && userChoice < 13) {
		switch (userChoice)
		{
		case 1:
			addUserToSystem(this); // this == system
			break;
		case 2:
			_currentUser.likePage();
			break;
		case 3:
			_currentUser.createStatus();
			break;
			// TODO: check inside function if create for user or page
		case 4:
			_currentUser.displayAllStatuses();
			// TODO: check inside function if display user or page
			break;
		case 5:
			char friendToDisplay[256];
			cout << "Your Friend's Name: \n";
			cin >> friendToDisplay;
			_currentUser.displayRecentStatusesOfaFriend(friendToDisplay);
			break;
		case 6:
			_currentUser.addFriend(_allUsers);
			break;
		case 7:
			char friendToDelete[256]; // may cause error char[] and char*
			cout << "Your Friend's Name: \n";
			cin >> friendToDisplay;
			_currentUser.cancelFriendship(friendToDelete);
			break;
		case 8:
			_currentUser.likePage();
			break;
		case 9:
			_currentUser.dislikePage();
			break;
		case 10:
			displayAllEntities();
			break;
		case 11:
			// TODO: check inside function if create for user or page
			break;
		case 12:
			cout << "GoodBye";
			exit(1);
		default:
			break;
		}
	}
	else {
		cout << endl << "Invalid Input, try again." << endl << endl;
		return;
	}
}

bool Operation::isValidUserName(char* userName)
{
	return true; // only for complier
}

bool Operation::isValidPageName(char* pageName)
{
	return true; // only for complier
}