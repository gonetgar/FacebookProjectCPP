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


	User** _friendsList; // trying without Class "Friend". array of pointers to Users (so that it wont go through c'tor)
	Status** _statuses; // array of statuses
	Page** _likedPages; // array of liked pages

public:
	User(); // we don't want to create a new user without a name
	User(const char* name, Date birthday);
	User(const User&) = delete; // copy c'tor - we delete cause we dont want to duplicate user
	void createStatus();
	void setName(char* username);
	char* getName(char* username);

	void addFriend(User** allUsers);
	void cancelFriendship(char* friendToDelete);
	void likePage();
	void dislikePage();

	void displayRecentStatusesOfaFriend(char* friendToDisplay); // 10 most recent statuses of all his friends
	void displayAllStatuses();
	void displayAllFriends();

	//void myStrcpy(char* dest, const char* source);
};

#endif // __USER_H
