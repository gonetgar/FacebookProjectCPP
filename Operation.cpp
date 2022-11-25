#include <iostream>
#include <string>
using namespace std;

#include "Operation.h"
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

//void Operation::addUserToOperation(User user) // in main
//{
//
//}
//
//void Operation::addPageToOperation(Page page) // in main
//{
//
//}

void Operation::displayAllEntities()
{
	cout << "ALL ENTITIES: " << endl;

	for (int i = 0; i < 5; i++)
		cout << *(_allUsers + i) << ", ";

	for (int i = 0; i < 5; i++)
		cout << *(_allPages + i) << ", ";
	cout << endl;
}

void Operation::getCurrentMember()
{
	char* username = new char[256];

	cout << "Hello, please enter your name for varification: ";
	cin >> username;

	_currentUser.setName(username);
	cout << _currentUser.getName();
}



void Operation::handleMenu(int userChoice)
{
	switch (userChoice)
	{
	case 1:
		cout << "add a freind";
		_currentUser.addFriend(_allUsers);
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
		// TODO: print in loop with indices
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

bool Operation::isValidUserName(char* userName)
{
	return true; // only for complier
}

bool Operation::isValidPageName(char* pageName)
{
	return true; // only for complier
}