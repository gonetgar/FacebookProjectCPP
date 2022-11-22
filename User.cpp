#include <iostream>
using namespace std;

#include "User.h"
#include "Date.h"


User::User()
{
	_name = new char[256];
	strcpy(_name, "new user");
	
	_birthday = Date(1,1,2000);

	_friendList = new Friend[1];
	_statuses = new Status[1];
	_likedPages = new Page[1];
}

User::User(char* name, Date birthday, Friend* friendList, Status* statuses, Page* likedPages)
{
	if(name){
	_name = new char[strlen(name)+1];
	strcpy(_name, name);
	}

	_birthday = birthday;

	_friendList = friendList ? friendList : new Friend[1];
	_statuses = statuses ? statuses: new Status[1];
	_likedPages = likedPages ? likedPages : new Page[1];
}

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
