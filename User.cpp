#include <iostream>
using namespace std;

#include "User.h"

User::User()
{
	char temp_name[9] = "new user";
	_name = new char[MAX_CHARACTERS];

	myStrcpy(_name, temp_name);
	cout << "\n" << _name; // for debugging

	_numOfFriends = 0;
	cout << "\nnumber of friends: " << _numOfFriends << endl; // for debugging

	_birthday.display(); // for debugging
	//_birthday = Date(1, 1, 2000); // ERROR: we dont need this because Date goes through the c'tor.

	_statuses = new Status[1];
	_likedPages = new Page[1];

	_friendsList = new User*[1]; // array of pointers so it wont go through c'tor =
}

User::User(char* name, int numOfFriends, Date birthday, User** friendsList, Status* statuses, Page* likedPages)
{
	_name = name;
	cout << "name: ";
	int len = strlen(_name); // for debugging
	for (int i = 0; i < len; i++)
		cout << _name[i];

	_numOfFriends = numOfFriends;

	cout << "\nnumber of friends: " << _numOfFriends << endl; // for debugging

	_birthday = birthday;

	cout << "birthday is: "; // for debugging
	_birthday.display(); // for debugging

	_friendsList = friendsList;
	_statuses = statuses;
	_likedPages = likedPages;
}

// trying a new c'tor:
//User::User(char name[MAX_CHARACTERS], int _numOfFriends, Date birthday, Friend* friendList, Status* statuses, Page* likedPages)
//{
//	if (name) {
//		_name = new char[strlen(name) + 1];
//		//strcpy(_name, name); // TODO
//	}
//
//	_numOfFriends = 0;
//	_birthday = birthday;
//	_friendList = friendList ? friendList : new Friend[1];
//	_statuses = statuses ? statuses : new Status[1];
//	_likedPages = likedPages ? likedPages : new Page[1];
//}

void User::setName(char* username)
{
	_name = username;
}

Status User::createStatus()
{
	Status status;

	status.text = new char[MAX_CHARACTERS];

	cout << "Please insert your status: ";
	cin.getline(status.text, MAX_CHARACTERS);


	// TODO: insert current time and date (automatically).
	// instead this is fictivi:
	status.date = Date(1, 1, 2022);

	// TODO: insert to statuses array of the user.

	cout << status.text;
	status.date.display();

	return status;
}

//// 1. searches this person in the system
//// 2. if found -> add it to my friend list
//// 3. add myself to his friend list. :-)
void User::addFriend(User* allUsers)
{
	char* friendsName = new char[MAX_CHARACTERS];
	int index = _numOfFriends;

	cout << "Enter friend's name: ";
	cin.getline(friendsName, MAX_CHARACTERS);
	// TODO: shrink the name back

	cout << "you entered: " << friendsName; // for debugging

	int numOfAllUsers = sizeof(*allUsers) / sizeof(User); // check

	//search this user in the array: // TODO: change it to binary search
	bool found = false;
	int i;
	for (i = 0; i < numOfAllUsers && !found; i++)
	{
		if (strcmp(allUsers[i]._name, friendsName) == 0)
			found = true;
	}

	if (found == false)
	{
		cout << "User not found!\n";
	}
	else
	{
		cout << "you found this friend!"; // for debugging

		// reallocate the array of friends:
		User** newFriendList = new User * [_numOfFriends + 1]; // make a new bigger one
		newFriendList = _friendsList; // point at the old one
		delete[] _friendsList; // delete the old one
		_friendsList = newFriendList; // point back at the original
		// TODO : put it in a function


		// add this new friend to the user's friends list:
		// TODO: change "allUsers" array to type "User**"
		// and then we can point at this sepceific person
		//_friendsList[_numOfFriends + 1] = *allUsers[i];
	


		// for debugging:
		cout << "you added: ";
		cout << _friendsList[index]->_name << ", birthday: ";
		_friendsList[index]->_birthday.display();
		cout << "\nlist of statuses:\n";
		int numOfStatuses = sizeof(_friendsList[index]->_statuses) / sizeof(Status);
		for (int j = 0; j < numOfStatuses; j++)
		{
			cout << _friendsList[index]->_statuses[j].text << endl;
		}

		// add myself to his friend list:
		// 1. make room
		int hisNumOfFriends = allUsers[i]._numOfFriends;
		User** newFriendListTemp = new User * [hisNumOfFriends];
		newFriendListTemp = allUsers[i]._friendsList;
		delete[](allUsers[i]._friendsList);
		allUsers[i]._friendsList = newFriendListTemp; // TODO: a function of this (same as above)


		// 3. point at myself // TODO
		//allUsers[i]._friendsList[hisNumOfFriends] = 

		
		_numOfFriends++; // updates the number of my friends
		(allUsers[i]._numOfFriends)++; // updates number of his friends.
	}

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