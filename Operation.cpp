#include <iostream>
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
	initiateStatuses(this);
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

		_allUsers = newUsers;
		newUsers = nullptr;
		delete[] newUsers;
	}

	_allUsers[_numOfUsers] = userToAdd;
	_numOfUsers++;
	cout << endl << "Hey, " << userToAdd->getName() << " Welcome to Facebook :) " << endl << endl;
}

void Operation::addPageToOperation(Page* pageToAdd)
{
	int i = 0;

	if (_maxPages == _numOfPages)
	{
		_maxPages *= 2;
		Page** newPages = new Page * [_maxPages];
		for (i = 0; i < _numOfPages; i++)
			newPages[i] = _allPages[i];

		_allPages = newPages;
	}

	_allPages[_numOfPages] = pageToAdd;
	_numOfPages++;

	cout << "Congrats! Your page: " << pageToAdd->getName() << " is Live on Facebook." << endl << endl;
}

void Operation::displayAllEntities()
{
	cout << endl << "ALL ENTITIES: " << endl;

	cout << endl << "Users: " << endl;
	for (int i = 0; i < _numOfUsers; i++)
		cout << _allUsers[i]->getName() << endl;

	cout << endl << "Pages: " << endl;
	for (int i = 0; i < _numOfPages; i++)
		cout << _allPages[i]->getName() << endl;

	cout << endl;
}

User* Operation::getCurrentUser()
{
	return &_currentUser;
}

// this function navigates the user's choice from the menu to the relevent functions
void Operation::handleMenu(int userChoice)
{
	User* current_user = nullptr;

	if (userChoice > 0 && userChoice < 13)
	{
		switch (userChoice)
		{
		case 1:
			getUserInput(this);
			break;
		case 2:
			addPageToSystem(this);
			break;
		case 3:
			getUserOrPageInput(3, this);
			break;
		case 4:
			getUserOrPageInput(4, this);
			break;
		case 5:
			cout << endl;
			current_user = askForUsername(this);
			cout << endl;
			if(current_user)
				current_user->displayRecentStatusesOfaFriend(this);
			break;
		case 6:
			_currentUser.addFriend(this);
			break;
		case 7:
			_currentUser.cancelFriendship(this);
			break;
		case 8:
			current_user = askForUsername(this);
			if(current_user)
				current_user->likePage(nullptr, this);
			break;
		case 9:
			current_user = askForUsername(this);
			if(current_user)
				current_user->dislikePage(this);
			break;
		case 10:
			displayAllEntities();
			break;
		case 11:
			getUserOrPageInput(11, this);
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

Operation::~Operation()
{
	for (int i = 0; i < _numOfUsers; i++)
	{
		delete[] _allUsers[i];
	}
	delete[] _allUsers;

	for (int i = 0; i < _numOfPages; i++)
	{
		delete[] _allPages[i];
	}
	delete[] _allPages;
}