#ifndef __USER_H__
#define __USER_H__

#include "Friend.h"
#include "Status.h"
#include "Page.h"

class User
{
public:
	char* name; // name of the user
	// birth date
	Friend* friendList;
	Status* status; // array of statuses
	Page* likedPages; // array of liked pages

	char* createStatus();
	void addFriend();
	void cancelFriendship();
	void likePage();
	void dislikePage();
	void displayRecentStatusesOfFriends();
};

#endif // __USER_H__