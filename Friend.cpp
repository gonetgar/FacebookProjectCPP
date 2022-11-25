#include <iostream>
using namespace std;

#include "Friend.h"

Friend::Friend()
{
	_name = new char[MAX_CHARACTERS];
	//strcpy(_name, "new friend"); ERROR: doesn't recognize strcpy.

	_numOfFriends = 0;
	_birthday = Date(1, 1, 2000);
	_friendsList = new Friend[1];
	_statuses = new Status[1];
}

Friend::Friend(char* name, Date birthday, Status* statuses, Friend* friendsList, int numOfFriends)
{
	if (name) {
		_name = new char[strlen(name) + 1];
		//strcpy(_name, name); // TODO
	}

	_numOfFriends = 0;
	_birthday = birthday;
	_friendsList = friendsList ? friendsList : new Friend[1];
	_statuses = statuses ? statuses : new Status[1];
}

// copy the entire array and makes a new one, bigger by 1.
//Friend* Friend::reallocFriend(User* u)
//{
//	int num_of_friends = u->_numOfFriends;
//	Friend* newFriendList = new Friend[num_of_friends + 1]; // +1 for the new friend added
//	newFriendList = u->_friendList;
//
//	return newFriendList;
//}