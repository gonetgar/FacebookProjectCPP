#include <iostream>
using namespace std;

#include "User.h"

//char* User::createStatus()
void User::createStatus()
{
	cout << "this is status :)\n";
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
