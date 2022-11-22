#ifndef __FRIEND_H
#define __FRIEND_H

#include "Status.h"
#include "Date.h"
// do not call user!

class Friend
{
public:
	char* name;
	Date birthday;
	Status* statuses;

	//Friend* reallocFriend(User* u);
};
#endif // __FRIEND_H
