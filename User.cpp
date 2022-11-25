#include <iostream>
using namespace std;

#include "User.h"

User::User(const char* name, Date birthday)
{
	_name = new char[256];
	strcpy(_name, name);
	_birthday = birthday;

	_statuses = new Status * [_maxNumOfStatuses];
	_likedPages = new Page*[1];
	_friendsList = new User * [_maxNumOfFriends]; // array of pointers so it wont go through c'tor

	///////////////////////////////////////////////////////////////////////////////////////////
	// for debugging:
	cout << "name: " << _name << endl;
	cout << "number of friends: " << _numOfFriends << endl;
	cout << "birthday is: ";
	_birthday.display();
}

void User::setName(char* username)
{
	_name = username;
}

void User::createStatus()
{
	Status* newStatus;
	newStatus = new Status[MAX_CHARACTERS];

	cout << "Please insert your status: ";
	cin.getline(newStatus->_text, MAX_CHARACTERS);	//TODO shrink?

	// TODO: insert current time and date (automatically).
	// 	maybe we need to do this in the c'tor

	// insert to statuses array of the user.
	if (_numOfStatuses == _maxNumOfStatuses) // TODO: in a function
	{
		_maxNumOfStatuses *= 2;
		Status** newStatuses = new Status*[_maxNumOfStatuses];
		for (int i = 0; i < _numOfStatuses; i++)
			newStatuses[i] = _statuses[i];

		delete[] _statuses; // ERROR doesnt delete the array for some reason
		_statuses = newStatuses;
	}
	_statuses[_numOfStatuses] = newStatus;
	_numOfStatuses++;

	// for debugging:
	cout << newStatus->_text;
	newStatus->_date.display();
}

//// 1. searches this person in the system
//// 2. if found -> add it to my friend list
//// 3. add myself to his friend list. :-)
void User::addFriend(User* allUsers)
{

}
//{
//	char* friendsName = new char[MAX_CHARACTERS];
//	int index = _numOfFriends;
//
//	cout << "Enter friend's name: ";
//	cin.getline(friendsName, MAX_CHARACTERS);
//	// TODO: shrink the name back
//
//	cout << "you entered: " << friendsName; // for debugging
//
//	int numOfAllUsers = sizeof(*allUsers) / sizeof(User); // check
//
//	//search this user in the array: // TODO: change it to binary search
//	bool found = false;
//	int i;
//	for (i = 0; i < numOfAllUsers && !found; i++)
//	{
//		if (strcmp(allUsers[i]._name, friendsName) == 0)
//			found = true;
//	}
//
//	if (found == false)
//	{
//		cout << "User not found!\n";
//	}
//	else
//	{
//		cout << "you found this friend!"; // for debugging
//
//		// reallocate the array of friends:
//		User** newFriendList = new User * [_numOfFriends + 1]; // make a new bigger one
//		newFriendList = _friendsList; // point at the old one
//		delete[] _friendsList; // delete the old one
//		_friendsList = newFriendList; // point back at the original
//		// TODO : put it in a function
//
//
//		// add this new friend to the user's friends list:
//		// TODO: change "allUsers" array to type "User**"
//		// and then we can point at this sepceific person
//		//_friendsList[_numOfFriends + 1] = *allUsers[i];
//	
//
//
//		// for debugging:
//		cout << "you added: ";
//		cout << _friendsList[index]->_name << ", birthday: ";
//		_friendsList[index]->_birthday.display();
//		cout << "\nlist of statuses:\n";
//		int numOfStatuses = sizeof(_friendsList[index]->_statuses) / sizeof(Status);
//		for (int j = 0; j < numOfStatuses; j++)
//		{
//			cout << _friendsList[index]->_statuses[j]->_text << endl;
//		}
//
//		// add myself to his friend list:
//		// 1. make room
//		int hisNumOfFriends = allUsers[i]._numOfFriends;
//		User** newFriendListTemp = new User * [hisNumOfFriends];
//		newFriendListTemp = allUsers[i]._friendsList;
//		delete[](allUsers[i]._friendsList);
//		allUsers[i]._friendsList = newFriendListTemp; // TODO: a function of this (same as above)
//
//
//		// 3. point at myself // TODO
//		//allUsers[i]._friendsList[hisNumOfFriends] = 
//
//		
//		_numOfFriends++; // updates the number of my friends
//		(allUsers[i]._numOfFriends)++; // updates number of his friends.
//	}
//
//}

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
		cout << "Date: ";
		_statuses[i]->_date.display();

		cout << "Text: ";
		cout << _statuses[i]->_text << endl;
	}
}

void User::displayAllFriends()
{
	cout << "hello friends\n";
}

void User::myStrcpy(char* dest, char* source)
{
	int len = strlen(source);
	for (int i = 0; i < len; i++)
	{
		dest[i] = source[i];
	}

	dest[len] = '\0';
}