#ifndef __USER_H
#define __USER_H

#define _CRT_SECURE_NO_WARNINGS

#include <string.h>

#include "Friend.h"
#include "Status.h"
#include "Page.h"
#include "Date.h"
#include "Operation.h"

class User
{
public:
	int _numOfFriends;
	Friend* _friendList;
private:
	char* _name; // name of the user
	Date _birthday;
	Status* _statuses; // array of statuses
	Page* _likedPages; // array of liked pages

public:
	User();
	User(char name[MAX_CHARACTERS], int _numOfFriends, Date birthday, Friend* friendList, Status* statuses, Page* likedPages);

	Status createStatus();
	void addFriend(User* allUsers);
	void cancelFriendship();
	void likePage();
	void dislikePage();
	void displayRecentStatusesOfFriends(); // 10 most recent statuses of all his friends
	void displayAllStatuses();
	void displayAllFriends();
};

#endif // __USER_H