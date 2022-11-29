#include <iostream>
using namespace std;

#include "User.h"
#include "Functions.h"

User::User()
{
	_name = new char[256];
	_name = _strdup("ori the king");

	_birthday = Clock(1, 1, 2000);
	_statuses = new Status * [_maxNumOfStatuses];
	_likedPages = new Page * [_maxNumOfPages];
	_friendsList = new User * [_maxNumOfFriends];
}

User::User(const char* name, Clock birthday)
{
	_name = new char[256];
	_name = _strdup(name);
	_birthday = birthday;

	_statuses = new Status * [_maxNumOfStatuses];
	_likedPages = new Page * [_maxNumOfPages];
	_friendsList = new User * [_maxNumOfFriends];

	// for debugging:
	//cout << "------- User Constructor --------\n";
	/*cout << "name: " << _name << endl;
	cout << "number of friends: " << _numOfFriends << endl;
	cout << "birthday is: ";
	cout << this->_birthday._day << "." << this->_birthday._month << "." << this->_birthday._year << endl;*/
}


void User::setName(char* username)
{
	_name = username;
}

void User::createStatus()
{
	if (_maxNumOfStatuses == _numOfStatuses)
	{
		_maxNumOfStatuses *= 2;
		Status** newStatuses = new Status * [_maxNumOfStatuses];
		for (int i = 0; i < _numOfStatuses; i++)
			newStatuses[i] = _statuses[i];

		delete[] _statuses; // ERROR doesnt delete the array for some reason
		_statuses = newStatuses;
	}

	Status* newStatus = this->_statuses[_numOfStatuses]->createStatus();
	_numOfStatuses++;

	// for debugging:
	cout << "number of statuses: " << _numOfStatuses;
}

// searches the name in the system and if found, adds it to the user's friend list
void User::addFriend(User** allUsers, Operation* system)
{
	char friendsName[MAX_CHARACTERS];

	cout << "Enter friend's name: ";
	cin.ignore();
	cin.getline(friendsName, MAX_CHARACTERS);

	int i = 1; // TO DO return from does user exist his index
	int friendIndex = doesUserExist(friendsName, system);

	// TODO get the return value frmo does user exist
	if (friendIndex >= 0) // returns the friend's index
	{
		cout << "you found the friend!" << endl; // for debugging
		addFriendToFriendList(allUsers, this, allUsers[friendIndex]); // add him to my friends list
		addFriendToFriendList(allUsers, allUsers[friendIndex], this); // add myself to his friends list

		//// for debugging:
		cout << "you added: ";
		cout << "Name: " << _friendsList[friendIndex]->_name; // error, i changed _numOfFriendsro 0 for debug
		cout << ", Birthday: ";
		_friendsList[friendIndex]->_birthday.displayDate();
	}
	else
		cout << "User not found!\n";

	delete friendsName;
}

// this function adds a friend to the user's friend list, and updates number of friends
void User::addFriendToFriendList(User** allUsers, User* currectUser, User* friendToAdd)
{
	if (currectUser->_numOfFriends == currectUser->_maxNumOfFriends)
	{
		currectUser->_maxNumOfFriends *= 2;
		reallocFriendList(currectUser->_friendsList, currectUser->_numOfFriends, currectUser->_maxNumOfFriends);
	}

	// TODO: sort array of friends by name

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

// adds more space in array "friendsList"
void User::reallocFriendList(User** friendsList, int logSize, int phySize)
{
	User** newFriendsList = new User * [phySize];

	for (int i = 0; i < logSize; i++)
	{
		newFriendsList[i] = friendsList[i];
	}
	delete[] friendsList;
	friendsList = newFriendsList;

	/*currectUser->_numOfFriends *= 2;
	User** newFriendsList = new User * [currectUser->_numOfFriends];
	for (int i = 0; i < currectUser->_numOfFriends; i++)
	{
		newFriendsList[i] = currectUser->_friendsList[i];
	}
	delete[] currectUser->_friendsList;
	currectUser->_friendsList = newFriendsList;*/
}

User::~User()
{
	delete[] _name;

	for (int i = 0; i < _numOfStatuses; i++)
	{
		delete[] _statuses[i];
	}
	delete[] _statuses;

	for (int i = 0; i < _numOfPages; i++)
	{
		delete[] _likedPages[i];
	}
	delete[] _likedPages;

	for (int i = 0; i < _numOfFriends; i++)
	{
		delete[] _friendsList[i];
	}
	delete[] _friendsList;

}