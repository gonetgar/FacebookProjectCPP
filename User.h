#ifndef __USER_H__
#define __USER_H__

const int MAX_CHARACTERS = 256;

#include "Friend.h"
#include "Status.h"
#include "Page.h"
#include "Date.h"

class User
{
private:
	char* _name; // name of the user
	Date _birthday;
	Friend* _friendList;
	Status* _statuses; // array of statuses
	Page* _likedPages; // array of liked pages

public:
	User();
	User(char* name, Date birthday, Friend* friendList, Status* statuses, Page* likedPages);

	//char* createStatus();
	void createStatus();
	void addFriend();
	void cancelFriendship();
	void likePage();
	void dislikePage();
	void displayRecentStatusesOfFriends(); // 10 most recent statuses of all his friends
	void displayAllStatuses();
	void displayAllFriends();
};

#endif // __USER_H__