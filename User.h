#ifndef __USER_H
#define __USER_H
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include "Friend.h"
#include "Date.h"
#include "Status.h"
#include "Page.h"
// do not call operation!

const int MAX_CHARACTERS = 256;

class User
{
	char* _name; // name of the user
	int _numOfFriends;
	Date _birthday;
	Friend* _friendList;
	Status* _statuses; // array of statuses
	Page* _likedPages; // array of liked pages

public:
	User();
	User(char name[MAX_CHARACTERS], int _numOfFriends, Date birthday, Friend* friendList, Status* statuses, Page* likedPages);
	Status createStatus();
	void setName(char* username);
	void addFriend(User* allUsers);
	void cancelFriendship(char friendToDelete);
	void likePage();
	void dislikePage();
	void displayRecentStatusesOfaFriend(Friend* friendToDisplay); // 10 most recent statuses of all his friends
	void displayAllStatuses();
	void displayAllFriends();
};

#endif // __USER_H
