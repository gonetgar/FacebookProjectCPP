#ifndef __USER_H__
#define __USER_H__

#include "Friend.h"
#include "Status.h"
#include "Page.h"
#include "Date.h"

class User
{
public:
	char* name; // name of the user
	Date birthday;
	Friend* friendList;
	Status* statuses; // array of statuses
	Page* likedPages; // array of liked pages

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