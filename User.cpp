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

		// delete[] _statuses; // ERROR doesnt delete the array for some reason
		_statuses = newStatuses;
	}

	Status* newStatus = new Status();
	newStatus->getStatusInfo(newStatus);
	_statuses[_numOfStatuses] = newStatus;
	_numOfStatuses++;

	// for debugging:
	cout << "_numOfStatuses: " << _numOfStatuses << endl;
	cout << "number of statuses: " << _numOfStatuses << endl;
	cout << "text: " << _statuses[_numOfStatuses - 1]->_text << endl; // todo: getStatusText()
}

// ask for name and search it on allUsers array, returns the user's index, or -1 if not found
int User::askForName(Operation* system, int flag)
{
	char* username = new char[MAX_CHARACTERS];
	int userIndex;

	cout << "Please enter ";
	flag == 0 ? cout << "your username: " : cout << "friend's name: ";
	cin.getline(username, MAX_CHARACTERS);
	userIndex = doesUserExist(username, system);
	if (userIndex < 0)
		cout << "User not found!\n\n";

	delete[] username;
	return userIndex;
}

// reallocate more place in the user's friendlist
void User::reallocateFriendList(User*** allUsers, int user_index)
{
	(*allUsers)[user_index]->_maxNumOfFriends *= 2;
	User** newFriendList = new User * [(*allUsers)[user_index]->_maxNumOfFriends];

	for (int i = 0; i < (*allUsers)[user_index]->_numOfFriends; i++)
		newFriendList[i] = (*allUsers)[user_index]->_friendsList[i];

	delete[] (*allUsers)[user_index]->_friendsList;
	(*allUsers)[user_index]->_friendsList = newFriendList;
}

// this function connect 2 users to be friends
void User::addFriend(User** allUsers, Operation* system)
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	int userIndex = askForName(system, 0);
	if(userIndex < 0)
		return;

	int friendIndex = askForName(system, 1);
	if (friendIndex < 0)
		return;

	// realloc
	int user_num_friends = allUsers[userIndex]->_numOfFriends;
	int user_max_num_friends = allUsers[userIndex]->_maxNumOfFriends;
	if (user_num_friends == user_max_num_friends)
	{
		reallocateFriendList(&allUsers, userIndex);

		// debugging
		cout << allUsers[userIndex]->_name << "'s:\n";
		cout << "num of friends: " << allUsers[userIndex]->_numOfFriends;
		cout << " max num of friends: " << allUsers[userIndex]->_maxNumOfFriends << endl;
	}
	// end of reaqlloc

	// add friend to user's friend list:
	allUsers[userIndex]->_friendsList[user_num_friends] = allUsers[friendIndex];
	(allUsers[userIndex]->_numOfFriends)++;

	//  debugging:
	cout << allUsers[userIndex]->_name << "'s friend list:\n";
	for (int i = 0; i < allUsers[userIndex]->_numOfFriends; i++)
	{
		cout << "friend #" << i + 1 << ": ";
		cout << allUsers[userIndex]->_friendsList[i]->_name << endl;
	}
	cout << endl;

	// ################################################# //

	int friend_num_friends = allUsers[friendIndex]->_numOfFriends;
	int friend_max_num_friends = allUsers[friendIndex]->_maxNumOfFriends;
	// the other way around:
	if (friend_num_friends == friend_max_num_friends)
	{
		reallocateFriendList(&allUsers, friendIndex);

		// debugging
		cout << allUsers[friendIndex]->_name << "'s:\n";
		cout << "num of friends: " << allUsers[friendIndex]->_numOfFriends;
		cout << " max num of friends: " << allUsers[friendIndex]->_maxNumOfFriends << endl;
	}

	allUsers[friendIndex]->_friendsList[friend_num_friends] = allUsers[userIndex];
	(allUsers[friendIndex]->_numOfFriends)++;

	//  debugging:
	cout << allUsers[friendIndex]->_name << "'s friend list:\n";
	for (int i = 0; i < allUsers[friendIndex]->_numOfFriends; i++)
	{
		cout << "friend #" << i + 1 << ": ";
		cout << allUsers[friendIndex]->_friendsList[i]->_name << endl;
	}
	cout << endl;
}

// this function adds a friend to the user's friend list, and updates number of friends
void User::addFriendToFriendList(User** allUsers, User* currectUser, User* friendToAdd)
{
	if (currectUser->_numOfFriends == currectUser->_maxNumOfFriends)
	{
		cout << "enters to if\n"; // debugging
		currectUser->_maxNumOfFriends *= 2;

		cout << "num max friends: " << _maxNumOfFriends << endl; // debugging


		User** newFriendsList = new User * [currectUser->_maxNumOfFriends];

		for (int i = 0; i < currectUser->_numOfFriends; i++)
		{
			newFriendsList[i] = currectUser->_friendsList[i];
		}
		delete[] currectUser->_friendsList;
		currectUser->_friendsList = newFriendsList;

		// debugging:
		cout << "print the new friend list:\n";
		for (int i = 0; i < _numOfFriends; i++)
		{
			cout << _friendsList[i]->getName() << endl;
		}
		cout << "\n\n";

		//	TODO : in a function

		//reallocFriendList(currectUser->_friendsList, currectUser->_numOfFriends, currectUser->_maxNumOfFriends);
	}

	// TODO: sort array of friends by name

	//add this friend to my friends list :
	currectUser->_friendsList[_numOfFriends] = friendToAdd; // point at this friend
	currectUser->_numOfFriends++; // update number of friends

	// debugging:
	cout << "print " << currectUser->_name << "'s list of friends:\n";
	for (int i = 0; i < _numOfFriends; i++)
	{
		cout << _friendsList[i]->getName() << endl;
	}
	cout << "\n\n";
}



void User::cancelFriendship(Operation* system)
{
	char* username = new char[MAX_CHARACTERS];
	char* friendToDelete = new char[MAX_CHARACTERS];
	int userIndex, friendIndex;
	User** all_users = system->getAllUsers();

	cout << "Please enter username: ";
	cin.ignore();
	cin.getline(username, MAX_CHARACTERS);
	userIndex = doesUserExist(username, system);

	if (userIndex < 0)
	{
		cout << "User was not found!\n";
		return; // TODO gon
	}

	cout << "Please enter friend's name you want to remove: ";
	cin.ignore();
	cin.getline(friendToDelete, MAX_CHARACTERS);
	friendIndex = doesUserExist(friendToDelete, system);

	if (friendIndex < 0)
	{
		cout << "User was not found!\n";
		return; // TODO gon
	}

	int iFriendToDelete;
	bool found = false;
	int user_num_of_friends = all_users[userIndex]->_numOfFriends;
	int user_max_num_of_friends = all_users[userIndex]->_maxNumOfFriends;

	// search this friend in the friend list:
	for (iFriendToDelete = 0; iFriendToDelete < user_num_of_friends && !found; iFriendToDelete++)
	{
		if (strcmp(all_users[userIndex]->_friendsList[iFriendToDelete]->_name, friendToDelete) == 0)
		{
			found = true;
			cout << "friend was found!!!!\n"; // debugging
		}
	}

	if (found)
	{
		// put the last on in his place:
		all_users[userIndex]->_friendsList[iFriendToDelete] = all_users[userIndex]->_friendsList[user_num_of_friends - 1];
		// point the last on null
		all_users[userIndex]->_friendsList[user_num_of_friends - 1] = nullptr;
		(all_users[userIndex]->_numOfFriends)--;
		// TODO: sort
	}
	else
		cout << "The friend was not found on your friend list!\n";

	// debugging:
	cout << "\nUpdated list of friends is:\n";
	for (int i = 0; i < all_users[userIndex]->_numOfFriends; i++)
	{
		cout << "Friend #" << i << ": " << all_users[userIndex]->_friendsList[i]->getName() << endl;
	}
	

	// TODO; check the free
	//delete username;
	//delete friendToDelete;
}

void User::likePage(Page* newPage) // todo: change to ref&
{
	bool isPageInLikedPages = false;

	for (int i = 0; i < _numOfPages; i++)
	{
		if (newPage == _likedPages[i]) // addresses compare
			isPageInLikedPages = true;
	}

	if (!isPageInLikedPages) // stop infinite loop
	{
		if (_maxNumOfPages == _numOfPages) {
			_maxNumOfPages *= 2;
			Page** newPagesArray = new Page * [_maxNumOfPages];
			for (int i = 0; i < _numOfPages; i++)
				newPagesArray[i] = _likedPages[i];

			delete[] _likedPages;
			_likedPages = newPagesArray;
		}

		_likedPages[_numOfPages] = newPage;
		_numOfPages++;

		newPage->addFan(this);
		cout << endl << this->getName() << " liked  " << newPage->getName() << endl << endl;
	}
}

void User::dislikePage(Page* removePage) // todo: change to ref&
{
	for (int i = 0; i < _numOfPages; i++)
	{
		if (removePage == _likedPages[i]) // page is in likedPages
		{
			// Swap the page with last element
			swap(_likedPages[i], _likedPages[_numOfPages - 1]);
			// decrement log size of array
			_numOfPages--;
			// call within page (this)
			removePage->removeFan(this);
		}
	}

	cout << endl << this->getName() << " disliked  " << removePage->getName() << endl << endl;

}

void User::displayRecentStatusesOfaFriend(char* friendToDisplay, Operation* system) // 10 most recent statuses of all his friends
{
	const int NUM_STATUSES_TO_DISPLAY = 10;
	User** allUsers = system->getAllUsers();
	User* userToDisplay;
	Status** statuses;
	int index = 0;
	int numOfStatuses = 0;

	// find friend using index = doesFriendExist()
	index = doesUserExist(friendToDisplay, system);
	userToDisplay = allUsers[index];
	// loop friendToDisplay[index].statuses
	numOfStatuses = userToDisplay->getNumOfStatuses();

	if (numOfStatuses > 0)
	{
		statuses = userToDisplay->getAllStatuses();

		cout << endl << userToDisplay->getName() << " Recent 10 statuses: " << endl << endl;
		for (int i = 0; i < numOfStatuses || numOfStatuses == NUM_STATUSES_TO_DISPLAY; i++)
		{
			cout << "Status #" << i;
			cout << endl << "------------------------" << endl;
			cout << "Date and time: ";
			statuses[i]->_time.displayDate();
			statuses[i]->_time.displayTime();
			cout << endl;

			cout << "Text: " << statuses[i]->_text << endl;
			cout << "------------------------" << endl;
			cout << endl;
		}
	}
	else cout << "No statuses to display." << endl << endl;
}

void User::displayAllStatuses()
{
	cout << _name << " statuses: ";
	if (_numOfStatuses == 0) cout << "none" << endl;
	else {
		for (int i = 0; i < _numOfStatuses; i++)
		{
			cout << endl << "------------------------" << endl;
			cout << "Date and time: ";
			_statuses[i]->_time.displayDate();
			_statuses[i]->_time.displayTime();
			cout << endl;

			cout << "Text: " << _statuses[i]->_text << endl;
			cout << "------------------------" << endl;
			cout << endl;
		}
	}
}

void User::displayAllFriends()
{
	cout << _name << " friends:";

	if (_numOfFriends == 0)
		cout << " none :(" << endl;
	else {
		cout << endl;
		for (int i = 0; i < _numOfFriends; i++)
		{
			cout << "friend #" << i + 1 << ":\n";
			cout << "name: " << _friendsList[i]->getName() << endl;
			cout << "birthday: ";
			_friendsList[i]->_birthday.displayDate();
			cout << endl;
		}
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