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
	int _numOfFriends = 0; // logical size
	int _maxNumOfFriends = 1; // physical size
	//Friend* _friendList;
	User** _friendsList; // trying without Class "Friend". array of pointers to Users (so that it wont go through c'tor)

private:
	Date _birthday;
	Status** _statuses; // array of statuses
	int _numOfStatuses = 0;
	int _maxNumOfStatuses = 1;
	Page* _likedPages; // array of liked pages

public:
	User() = delete;
	User(char* name, Date birthday, User** friendsList, Status** statuses, Page* likedPages);
	User(const User&) = delete; // copy c'tor - we delete cause we dont want to duplicate user
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
