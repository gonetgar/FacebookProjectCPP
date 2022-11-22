#ifndef __USER_H__
#define __USER_H__

#include <string.h>
#include "Friend.h"
#include "Status.h"
#include "Page.h"
#include "Date.h"
#define _CRT_SECURE_NO_WARNINGS

const int MAX_CHARACTERS = 256;

class User
{
private:
	char* _name = new char[MAX_CHARACTERS]; // name of the user
	Date _birthday;
	Friend* _friendList;
	Status* _statuses; // array of statuses
	Page* _likedPages; // array of liked pages

public:
	User();
	User(char name[MAX_CHARACTERS], Date birthday, Friend* friendList, Status* statuses, Page* likedPages);

	Status createStatus();
	void addFriend();
	void cancelFriendship();
	void likePage();
	void dislikePage();
	void displayRecentStatusesOfFriends(); // 10 most recent statuses of all his friends
	void displayAllStatuses();
	void displayAllFriends();
};

#endif // __USER_H__