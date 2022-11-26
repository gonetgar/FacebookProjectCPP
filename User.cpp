#include <iostream>
using namespace std;

#include "User.h"

User::User()
{
	_name = new char[256];
	_name = _strdup("ori the king");

	//_birthday = Date(1, 1, 2020);
	_birthday = Clock(1, 1, 2000);

	_statuses = new Status * [_maxNumOfStatuses];
	_likedPages = new Page * [1];
	_friendsList = new User * [_maxNumOfFriends];
}

//User::User(const char* name, Date birthday)
User::User(const char* name, Clock birthday)
{
	_name = new char[256];
	_name = _strdup(name);
	_birthday = birthday;

	_statuses = new Status * [_maxNumOfStatuses];
	_likedPages = new Page * [1];
	_friendsList = new User * [_maxNumOfFriends];

	// for debugging:
	cout << "name: " << _name << endl;
	cout << "number of friends: " << _numOfFriends << endl;
	cout << "birthday is: ";
	cout << this->_birthday._day << "." << this->_birthday._month << "." << this->_birthday._year;
	//_birthday.display();
}

void User::setName(char* username)
{
	_name = username;
}

void User::createStatus()
{
	Status* newStatus;
	newStatus = new Status[MAX_CHARACTERS];

	if (_maxNumOfStatuses == _numOfStatuses)
	{
		_maxNumOfStatuses *= 2;
		Status** newStatuses = new Status * [_maxNumOfStatuses];
		for (int i = 0; i < _numOfStatuses; i++)
			newStatuses[i] = _statuses[i];

		delete[] _statuses; // ERROR doesnt delete the array for some reason
		_statuses = newStatuses;
	}

	newStatus = this->_statuses[_numOfStatuses]->createStatus();
	_numOfStatuses++;

	// for debugging:
	cout << "number of statuses: " << _numOfStatuses;
}

// searches the name in the system and if found, adds it to the user's friend list
void User::addFriend(User** allUsers)
{
	char* friendsName = new char[MAX_CHARACTERS];

	cout << "Enter friend's name: ";
	cin.getline(friendsName, MAX_CHARACTERS);

	// for debugging
	cout << "you entered: " << friendsName;

	/// 1. search this user in the array: // TODO: change it to binary search

	int numOfAllUsers = sizeof(*allUsers) / sizeof(User);
	// numOfAllUsers = getNumOfAllUsers;  // TODO take the phy size from AllUsers

	bool found = false;
	int i;
	for (i = 0; i < numOfAllUsers && !found; i++)
	{
		if (strcmp(allUsers[i]->_name, friendsName) == 0)
			found = true;
	}

	if (found == false)
	{
		cout << "User not found!\n";
	}
	else
	{
		cout << "you found this friend!"; // for debugging
		addFriendToFriendList(allUsers, this, allUsers[i]); // add him to my friends list
		addFriendToFriendList(allUsers, allUsers[i], this); // add myself to his friends list

		//// for debugging:
		cout << "you added: ";
		cout << "name: " << _friendsList[_numOfFriends]->_name;
		cout << ", birthday: ";
		_friendsList[_numOfFriends]->_birthday.displayDate();
	}

	delete[] friendsName;
}

// this function adds a friend to the user's friend list, and updates number of friends
void User::addFriendToFriendList(User** allUsers, User* currectUser, User* friendToAdd)
{
	// 2. check for room in the array:
	if (currectUser->_numOfFriends == currectUser->_maxNumOfFriends)
	{
		// reallocate more place
		currectUser->_numOfFriends *= 2;
		User** newFriendsList = new User * [currectUser->_numOfFriends];
		for (int i = 0; i < currectUser->_numOfFriends; i++)
		{
			newFriendsList[i] = currectUser->_friendsList[i];
		}
		delete[] currectUser->_friendsList;
		currectUser->_friendsList = newFriendsList;
	} // TODO : put it in a function

	//add this friend to my friends list :
	currectUser->_friendsList[_numOfFriends] = friendToAdd; // point at this friend
	currectUser->_numOfFriends++; // update number of friends
}

void User::cancelFriendship(char* friendToDelete)
{
	cout << "bye bye :(\n";
	cout << "Please enter friend's name you want to cancel: ";

	// search this friend in the friend list:
}

void User::likePage()
{
	cout << "like\n";
}

void User::dislikePage()
{
	cout << "unlike\n";
}

void User::displayRecentStatusesOfaFriend(char* friendToDisplay) // 10 most recent statuses of all his friends
{
	cout << ":)\n";
}

void User::displayAllStatuses()
{
	cout << "all statuses\n";

	for (int i = 0; i < _numOfStatuses; i++)
	{
		cout << "Date and time: ";
		_statuses[i]->_time.displayDate();
		_statuses[i]->_time.displayTime();

		cout << "Text: ";
		cout << _statuses[i]->_text << endl;
	}
}

void User::displayAllFriends()
{
	cout << "This is all your friends:\n";

	for (int i = 0; i < _numOfFriends; i++)
	{
		cout << "friend #" << i + 1 << ":\n";
		cout << "name: " << _friendsList[i]->getName() << endl;
		cout << "birthday: ";
		_friendsList[i]->_birthday.displayDate();
		cout << endl;
	}
}