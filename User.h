#ifndef __USER_H
#define __USER_H
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include "Friend.h"
#include "Date.h"
#include "Status.h"

class Page;
// do not call operation!

class User
{
	char* _name; // :-)
	Date _birthday;

	int _numOfFriends = 0; // logical size
	int _maxNumOfFriends = 1; // physical size
	int _numOfStatuses = 0;
	int _maxNumOfStatuses = 1;
	int _numOfPages = 0;
	int _maxNumOfPages = 1;


	User** _friendsList; // array of friends
	Status** _statuses; // array of statuses
	Page** _likedPages; // array of liked pages

public:
	User(); // we don't want to create a new user without a name
	User(const char* name, Date birthday);
	User(const User&) = delete; // copy c'tor - we delete cause we dont want to duplicate user
	
	void setName(char* username);
	char* getName(char* username);

	void createStatus();
	void addFriend(User** allUsers);
	void cancelFriendship(char* friendToDelete);
	void likePage();
	void dislikePage();
	void displayRecentStatusesOfaFriend(char* friendToDisplay); // 10 most recent statuses of all his friends
	void displayAllStatuses();
	void displayAllFriends();
};

#endif // __USER_H
