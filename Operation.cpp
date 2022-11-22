#include <iostream>
#include <string>
using namespace std;

#include "Operation.h"

// no default constructor is needed
Operation::Operation(User* allUsers = new User[1], Page* allPages = new Page[1])
{
	_allUsers = allUsers;
	_allPages = allPages;
}


void Operation::initiateData(User* users, int usersSize, Page* pages, int pagesSize)
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

void Operation::addUserToOperation(User user, User* allUsers)
{

}

void Operation::addPageToOperation(Page page, Page* allPages)
{

}

void Operation::displayAllEntities(User* allUsers, Page* allPages)
{

}

void Operation::getCurrentMember()
{
	char username[256];

	cout << "Hello, please enter your name for varification: ";
	cin >> username;

	// TODO: setName for User class   
	//_currentMember.setName(username);
}

void Operation::displayMenu()
{
	int userChoice = 0;

	cout << "1 -הוספת חבר   \n 2 - הוספת דף אוהדים \n 3 - הוספת סטטוס לחבר / דף אוהדים.בשלב זה סטטוס הוא רק טקסט \n 4 - הצגת כל הסטטוסים של חבר / דף אוהדים.בשלב זה סטטוס הוא רק טקסט \n 5 - הצגת 10 הסטטוסים העדכניים ביותר של חבריו של חבר מסויים \n 6 - קישור חברות בין שני חברים \n 7 - ביטול חברות בין שני חברים \n 8 - הוספת אוהד לדף \n 9 - הסרת אוהד מדף \n 10 - הצגת כל הישויות הרשומות למערכת \n 11 - הצגת כל החברים של חבר מסויים / האוהדים של דף מסויים \n 12 - יציאה";
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
	default:
		break;
	}
}

bool Operation::isValidUserName(char* userName, User* allUsers)
{
	return true; // only for complier
}

bool Operation::isValidPageName(char* pageName, Page* allPages)
{
	return true; // only for complier
}
