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
}


//User** Operation::getAllUsers()
//{
//	return _allUsers;
//}

void Operation::addUserToOperation(User* userToAdd)
{
	int i = 0;

	if (_maxUsers == _numOfUsers)
	{
		_maxUsers *= 2;
		User** newUsers = new User * [_maxUsers];
		for (i = 0; i < _numOfUsers; i++)
			newUsers[i] = _allUsers[i];

		//delete[] _allUsers;
		_allUsers = newUsers;
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

		//delete[] _allPages; // ERROR
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
		cout << _allUsers[i]->getName() << ", " << endl;

	cout << endl << "Pages: " << endl;
	for (int i = 0; i < _numOfPages; i++)
		cout << _allPages[i]->getName() << ", " << endl;

	cout << endl;
}


void Operation::getCurrentMember()
{
	char* username = new char[256];

	cout << "Hello, please enter your name for varification: ";
	cin.getline(username, 256);
	cout << endl;

	Clock birthDate = birthDate.getBirthdayInput();

	_currentUser.setName(username);
	_currentUser.setBirthday(birthDate);

	addUserToOperation(&_currentUser);

	cout << _currentUser.getName() << "," << endl;
}


void Operation::handleMenu(int userChoice)
{
	Page* newPage;
	Page* removePage;
	char friendToDisplay[256];

	if (userChoice > 0 && userChoice < 13) {
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
			cin.getline(friendToDisplay, 256);
			_currentUser.displayRecentStatusesOfaFriend(friendToDisplay);
			break;
		case 6:
			_currentUser.addFriend(_allUsers, this); // error: return different friend
			break;
		case 7:
			char friendToDelete[256]; // may cause error char[] and char*
			cout << "Your Friend's Name: \n";
			cin >> friendToDisplay;
			_currentUser.cancelFriendship(friendToDelete);
			break;
		case 8:
			newPage = getPageDetails(this);
			if (newPage)
				_currentUser.likePage(newPage);
			else cout << "no page found :(" << endl << endl;
			break;
		case 9:
			removePage = getPageDetails(this);
			if (removePage)
				_currentUser.dislikePage(removePage);
			else cout << "no page found :(" << endl << endl;
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
	return true; // only for complier
}

bool Operation::isValidPageName(char* pageName)
{
	return true; // only for complier
}