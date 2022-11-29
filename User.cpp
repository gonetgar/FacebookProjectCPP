#include <iostream>
using namespace std;

#include "User.h"
#include "Functions.h"

User::User()
{
	_name = new char[256];
	_name = _strdup("ori the king");

	_birthday = Clock(2, 2, 2000);
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

	Status* newStatus = new Status();
	newStatus->getStatusInfo(newStatus);
	_statuses[_numOfStatuses] = newStatus;
	_numOfStatuses++;
	
	cout << "_numOfStatuses: " << _numOfStatuses << endl;
	// for debugging:
	cout << "number of statuses: " << _numOfStatuses << endl;
	cout << "text: " << _statuses[_numOfStatuses-1]->_text << endl; // todo: getStatusText()
}

// searches the name in the system and if found, adds it to the user's friend list
void User::addFriend(User** allUsers, Operation* system)
{
	char friendsName[MAX_CHARACTERS];

	// ERROR ERROR ERROR // TODO

	cout << "Enter friend's name: ";
	cin.ignore();
	cin.getline(friendsName, MAX_CHARACTERS);

	// searches friend in the system
	int friendIndex = doesUserExist(friendsName, system);

	if (friendIndex >= 0) // returns the friend's index
	{
		addFriendToFriendList(allUsers, this, allUsers[friendIndex]); // add him to my friends list
		addFriendToFriendList(allUsers, allUsers[friendIndex], this); // add myself to his friends list
	}
	else
		cout << "User not found!\n";
}

// this function adds a friend to the user's friend list, and updates number of friends
void User::addFriendToFriendList(User** allUsers, User* currectUser, User* friendToAdd)
{
	if (currectUser->_numOfFriends == currectUser->_maxNumOfFriends)
	{
		currectUser->_maxNumOfFriends *= 2;

		User** newFriendsList = new User * [currectUser->_maxNumOfFriends];

		for (int i = 0; i < currectUser->_numOfFriends; i++)
		{
			newFriendsList[i] = currectUser->_friendsList[i];
		}
		delete[] currectUser->_friendsList;
		currectUser->_friendsList = newFriendsList;
		//	TODO : in a function

		//reallocFriendList(currectUser->_friendsList, currectUser->_numOfFriends, currectUser->_maxNumOfFriends);
	}

	// TODO: sort array of friends by name

	//add this friend to my friends list :
	currectUser->_friendsList[_numOfFriends] = friendToAdd; // point at this friend
	currectUser->_numOfFriends++; // update number of friends
}



void User::cancelFriendship(Operation* system)
{
	char* friendToDelete = new char[MAX_CHARACTERS];
	cout << "Please enter friend's name you want to remove: ";
	cin.ignore();
	cin.getline(friendToDelete, MAX_CHARACTERS);

	int index;
	bool found = false;
	// search this friend in the friend list:
	for (index = 0; index < _numOfFriends && !found ; index++)
	{
		if (strcmp(_friendsList[index]->getName(), friendToDelete) == 0)
			found = true;
	}

	if (found)
	{
		// swap between the deleted friend and the last one on the array
		_friendsList[index] = _friendsList[_numOfFriends - 1]; // point at the last friend in the array
		_friendsList[_numOfFriends - 1] = nullptr; // point the last one on null
		_numOfFriends--;
	}
	else
		cout << "Friend was not found!\n";


	// debugging:
	cout << "\nUpdated list of friends is:\n";
	for (int i = 0; i < _numOfFriends; i++)
	{
		cout << "Friend #" << i << ": " << _friendsList[i]->getName() << endl;
	}
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
	// find friend using index = doesFriendExist()
	// loop friendToDisplay[index].friendsList
	// sort
	// display first 10 statuses
	cout << ":)\n";
}

void User::displayAllStatuses()
{
	cout << _name << " statuses:\n";

	for (int i = 0; i < _numOfStatuses; i++)
	{
		cout << "Date and time: ";
		_statuses[i]->_time.displayDate();
		_statuses[i]->_time.displayTime();
		cout << endl;

		cout << "Text: ";
		cout << _statuses[i]->_text << endl;
		cout << endl;

	}
}

void User::displayAllFriends()
{
	cout << _name << " friends:\n";

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