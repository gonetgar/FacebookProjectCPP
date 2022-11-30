#ifndef __USER_H
#define __USER_H
#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include "Date.h"
#include "Status.h"
#include "Clock.h"

class Page;
class Operation;

class User
{
private:
	char* _name;
	//Date _birthday;
	Clock _birthday;

	int _numOfFriends = 0;
	int _maxNumOfFriends = 1;
	int _numOfStatuses = 0;
	int _maxNumOfStatuses = 1;
	int _numOfPages = 0;
	int _maxNumOfPages = 1;

	User** _friendsList;
	Status** _statuses;
	Page** _likedPages;

public:
	User(); // TODO: add delete. we don't want to create a new user without a name
	User(const char* name, Clock birthday);
	User(const User&) = delete; // copy c'tor - we delete cause we dont want to duplicate user

	const char* getName() const { return _name; };
	const int getNumOfStatuses() const { return _numOfStatuses; };
	Status** getAllStatuses() { return _statuses; };

	void setName(char* username);
	void setBirthday(Clock birthday) { _birthday = birthday; }
	const Clock getBirthday() const { return _birthday; }

	void createStatus();
	void addFriend(User** allUsers, Operation* system);
	void addFriendToFriendList(User** allUsers, User* currectUser, User* friendToAdd);
	void cancelFriendship(char* friendToDelete);

	void likePage(Page* newPage);
	void dislikePage(Page* removePage);
	void displayRecentStatusesOfaFriend(char* friendToDisplay, Operation* system); // 10 most recent statuses of all his friends
	void displayAllStatuses();
	void displayAllFriends();

	void reallocFriendList(User** friendsList, int logSize, int phySize);

	~User();
};

#endif // __USER_H
