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
	cout << endl << "ALL ENTITIES: " << endl << endl;
	cout << "Current User: " << endl;
	cout << _currentUser.getName() << endl;

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

void Operation::getCurrentMemberInput() // todo - delete this?
{
	char* username = new char[MAX_CHARACTERS];

	cout << "Hello, please enter your name for varification: ";
	cin.getline(username, MAX_CHARACTERS);
	cout << endl;

	Clock birthDate = birthDate.getBirthdayInput();

	_currentUser.setName(username);
	_currentUser.setBirthday(birthDate);

	addUserToOperation(&_currentUser);

	cout << _currentUser.getName() << "," << endl;
}


void Operation::handleMenu(int userChoice)
{
	User* current_user = nullptr;
	Page* newPage;
	char friendToDisplay[MAX_CHARACTERS];

	if (userChoice > 0 && userChoice < 13)
	{
		switch (userChoice)
		{
		case 1:
			getUserInput(this); // this == system
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
			cout << "Your Friend's Name: \n";
			cin.ignore();
			cin.getline(friendToDisplay, MAX_CHARACTERS);
			_currentUser.displayRecentStatusesOfaFriend(friendToDisplay, this);
			break;
		case 6:
			_currentUser.addFriend(this);
			break;
		case 7:
			_currentUser.cancelFriendship(this);
			break;
		case 8:
			current_user = askForUsername(this);
			current_user->likePage(nullptr, this);
			break;
		case 9:
			current_user = askForUsername(this);
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

bool Operation::isValidUserName(char* userName)
{
	return true; // only for complier - TODO ori ? what is this
}

bool Operation::isValidPageName(char* pageName)
{
	return true; // only for complier
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