#ifndef __FRIEND_H
#define __FRIEND_H

#include "Status.h"
#include "Date.h"
// do not call user!

const int MAX_CHARACTERS = 256;

class Friend
{
public:
	char* _name;
	Date _birthday;
	Status* _statuses;
	Friend* _friendsList;
	int _numOfFriends;

	Friend();
	Friend(char* name, Date birthday, Status* statuses, Friend* friendsList, int numOfFriends);
	//Friend* reallocFriend(User* u);
};
#endif // __FRIEND_H
