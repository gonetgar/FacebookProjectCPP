#include <iostream>
#include <string>
using namespace std;

#include "Operation.h"

Operation::Operation()
{
	User** allUsers = new User * [1];
	Page** allPages = new Page * [1];
}

Operation::Operation(User** allUsers, Page** allPages)
{
	User** allUsers = new User * [1];
	Page** allPages = new Page * [1];
}

void Operation::initiateData(User** users, int usersSize, Page** pages, int pagesSize)
{
	_allUsers = new User[usersSize];
	_allPages = new Page[pagesSize];


	_allUsers = users;
	_allPages = pages;
}


User* Operation::getAllUsers()
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
	cout << "\n";
	cout << _allUsers[0]._name << endl;
	cout << _allUsers[1]._name << endl;
	cout << _allUsers[2]._name << endl;

	// TODO: find and fix arrays length 
	int users_length = sizeof(_allUsers) / sizeof(_allUsers[0]);
	cout << "length: " << users_length << endl;
	int pages_length = sizeof(_allPages) / sizeof(_allPages[0]);

	if (users_length != 0) {
		for (int i = 0; i < users_length; i++)
		{
			cout << "user " << i << " " << _allUsers[i]._name << endl;
		}
	}
	else cout << "no users" << endl;

	if (pages_length != 0) {
		for (int i = 0; i < pages_length; i++)
		{
			cout << "page " << i << " " << _allUsers[i]._name << endl;
		}
	}
	else cout << "no pages" << endl;
}

void Operation::getCurrentMember()
{
	char* username = new char[256];

	cout << "Hello, please enter your name for varification: ";
	cin >> username;

	_currentUser.setName(username);
}



void Operation::displayMenu()
{
	int userChoice = 0;

	cout << "1 -הוספת חבר   \n 2 - הוספת דף אוהדים \n 3 - הוספת סטטוס .\n 4 - הצגת כל הסטטוסים  \n 5 - הצגת 10 הסטטוסים העדכניים ביותר של חבריו של חבר מסויים \n 6 - קישור חברות בין שני חברים \n 7 - ביטול חברות בין שני חברים \n 8 - הוספת אוהד לדף \n 9 - הסרת אוהד מדף \n 10 - הצגת כל הישויות הרשומות למערכת \n 11 - הצגת כל החברים של חבר מסויים / האוהדים של דף מסויים \n 12 - יציאה";
	cin >> userChoice;

	// validation
	if (userChoice < 1 || userChoice > 12)
	{
		cout << "Invalid Input, try again.";
		displayMenu();
	}

	switch (userChoice)
	{
	case 1:
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