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
	char* _name;
	Clock _birthday;
	User** _friendsList;
	Status** _statuses;
	Page** _likedPages;

	int _numOfFriends = 0;
	int _maxNumOfFriends = 1;
	int _numOfStatuses = 0;
	int _maxNumOfStatuses = 1;
	int _numOfPages = 0;
	int _maxNumOfPages = 1;
public:
	User(); // TODO: add delete. we don't want to create a new user without a name
	User(const char* name, Clock birthday, int maxNumFriends, int numFriends, int maxPages, int numPages);
	User(const User&) = delete; // we delete the copy c'tor because we dont want to duplicate a user

	const char* getName() const { return _name; }// ERROR
	// - is falling with the realloc of the all users array I DONT KNOW WHY ORI
	User** getFriendsList() { return _friendsList; }
	Page** getLikedPagesList() { return _likedPages; }
	const int getNumOfStatuses() const { return _numOfStatuses; };
	const int getNumOfFriends() const { return _numOfFriends; }
	const int getNumOfPages() const { return _numOfPages; }
	Status** getAllStatuses() { return _statuses; }
	void setName(char* username);
	void setBirthday(Clock birthday) { _birthday = birthday; }
	const Clock getBirthday() const { return _birthday; }

	void createStatus(Status* status);

	void addFriend(Operation* system);
	int askForName(Operation* system, int flag);
	void reallocateFriendList(User*** allUsers, int user_index);
	void addFriendToFriendList(User*** allUsers, int user_index, int friend_index);

	void cancelFriendship(Operation* system);
	int searchFriendInFriendList(User** allUsers, int userIndex, int friendIndex);
	void removeFriendFromFriendList(User** all_users, int user_index, int friend_to_delete);

	void likePage(Page* pageToLike, Operation* system);
	void addPageToLikedPagesList(Operation* system, Page* pageToLike);

	void dislikePage(Operation* system);
	void displayRecentStatusesOfaFriend(Operation* system); // 10 most recent statuses of all his friends
	void displayAllStatuses();
	void displayAllFriends();

	~User();
};

#endif // __USER_H
