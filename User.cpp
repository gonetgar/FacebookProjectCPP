#include <iostream>
using namespace std;

#include "User.h"

User::User()
{
	_name = new char[MAX_CHARACTERS];
	//strcpy(_name, "new user"); ERROR: doesn't recognize strcpy.
	_numOfFriends = 0;
	_birthday = Date(1,1,2000);
	_friendList = new Friend[1];
	_statuses = new Status[1];
	_likedPages = new Page[1];
}

User::User(char name[MAX_CHARACTERS], int _numOfFriends, Date birthday, Friend* friendList, Status* statuses, Page* likedPages)
{
	if(name){
	_name = new char[strlen(name)+1];
	//strcpy(_name, name); // TODO
	}

	_numOfFriends = 0;
	_birthday = birthday;
	_friendList = friendList ? friendList : new Friend[1];
	_statuses = statuses ? statuses: new Status[1];
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


//// 1. searches this person in the system
//// 2. if found -> add it to my friend list
//// 3. add myself to his friend list. :-)
void User::addFriend(User* allUsers)
{
	char* friendsName = new char[MAX_CHARACTERS];
	int index = _numOfFriends;

	cout << "Enter friend's name: ";
	cin.getline(friendsName, MAX_CHARACTERS);

	// TODO: search this friend in the system:
	int numOfAllUsers = sizeof(allUsers) / sizeof(User); // check

	//search this user in the array:
	bool found = false;
	int i = 0;
	for (i = 0; i < numOfAllUsers && !found; i++) // TODO: change it to binary search. like a boss
	{
		if (strcmp(allUsers[i]._name, friendsName) == 0)
			found = true;
	}

	if (found == false)
	{
		cout << "User not found!\n";
	}
	else
	{
		// reallocate the array of friends:
		Friend* newFriendList = new Friend[index + 1];
		newFriendList = _friendList;

		_friendList = new Friend[index + 1];
		_friendList = newFriendList;
		delete[] newFriendList;

		// add this new friend to the user's friend list.
		//_friendList[index] = allUsers[i];

		// TODO: add myself to his friend list
		//allUsers[i];

		_numOfFriends++; // updates the number of friends
	}

}

void User::cancelFriendship(char friendToDelete)
{
	cout << "bye bye :(\n";
	cout << "Please enter friend's name you want to cancel: ";

}

void User::likePage()
{
	cout << "like\n";
}

void User::dislikePage()
{
	cout << "unlike\n";
}

void User::displayRecentStatusesOfaFriend(Friend* friendToDisplay) // 10 most recent statuses of all his friends
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
