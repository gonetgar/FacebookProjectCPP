#include <iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

#include "User.h"
#include "Date.h"


User::User()
{
	_name = new char[256];
	//strcpy(_name, "new user"); ERROR: doesn't recognize strcpy.

	_birthday = Date(1, 1, 2000);

	_friendList = new Friend[1];
	_statuses = new Status[1];
	_likedPages = new Page[1];
}

User::User(char name[MAX_CHARACTERS], Date birthday, Friend* friendList, Status* statuses, Page* likedPages)
{
	if (name) {
		_name = new char[strlen(name) + 1];
		//strcpy(_name, name);
	}

	_birthday = birthday;

	_friendList = friendList ? friendList : new Friend[1];
	_statuses = statuses ? statuses : new Status[1];
	_likedPages = likedPages ? likedPages : new Page[1];
}

Status User::createStatus()
{
	Status status;

	status.text = new char[MAX_CHARACTERS];

	cout << "Please insert your status: ";
	cin.getline(status.text, MAX_CHARACTERS);


	// TODO: insert current time and date (automatically).
	// instead this is fictivi:
	status.date = Date(1, 1, 2022);

	// TODO: insert to statuses array of the user.

	cout << status.text;
	status.date.display();

	return status;
}

void User::addFriend()
{
	cout << "friend\n";
}

void User::cancelFriendship()
{
	cout << "bye bye :(\n";
}
void User::likePage()
{
	cout << "like\n";
}
void User::dislikePage()
{
	cout << "unlike\n";
}

void User::displayRecentStatusesOfFriends() // 10 most recent statuses of all his friends
{
	cout << ":)\n";
}

void User::displayAllStatuses()
{
	cout << "all statuses\n";
}

void User::displayAllFriends()
{
	cout << "hello friends\n";
}
