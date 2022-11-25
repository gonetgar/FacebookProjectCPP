#ifndef __USER_H
#define __USER_H
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include "Friend.h"
#include "Date.h"
#include "Status.h"
#include "Page.h"
// do not call operation!

class User
{
public:
	char* _name;// = new char[MAX_CHARACTERS]; // name of the user
	int _numOfFriends; // logical size
	int _maxNumOfFriends; // physical size
	//Friend* _friendList;
	User** _friendsList; // trying without Class "Friend". array of pointers to Users (so that it wont go through c'tor)

private:
	Date _birthday;
	Status** _statuses; // array of statuses
	int _numOfStatuses;
	int _maxNumOfStatuses;
	Page* _likedPages; // array of liked pages

public:
	User();
	User(char* name, int numOfFriends, int maxNumOfFriends, int numOfStatuses, int maxNumOfStatuses, Date birthday, User** friendsList, Status** statuses, Page* likedPages);
	void createStatus();
	void setName(char* username);


	void addFriend(User* allUsers);
	void cancelFriendship(char* friendToDelete);
	void likePage();
	void dislikePage();

	void displayRecentStatusesOfaFriend(char* friendToDisplay); // 10 most recent statuses of all his friends
	void displayAllStatuses();
	void displayAllFriends();

	void myStrcpy(char* dest, char* source);
};

#endif // __USER_H
