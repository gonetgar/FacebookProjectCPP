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

// this function connect 2 users to be friends
void User::addFriend(Operation* system)
{
	User** all_users = system->getAllUsers();

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	int userIndex = askForName(system, 0);
	if(userIndex < 0)
		return;

	int friendIndex = askForName(system, 1);
	if (friendIndex < 0)
		return;

	addFriendToFriendList(&all_users, userIndex, friendIndex);
	addFriendToFriendList(&all_users, friendIndex, userIndex);

	// ################################################ //
	//debugging:
	cout << "\n\n### debugging: ###\n";
	cout << all_users[userIndex]->_name << "'s friend list:\n";
	for (int i = 0; i < all_users[userIndex]->_numOfFriends; i++)
	{
		cout << "friend #" << i + 1 << ": ";
		cout << all_users[userIndex]->_friendsList[i]->_name << endl;
	}
	cout << endl;


	cout << all_users[friendIndex]->_name << "'s friend list:\n";
	for (int i = 0; i < all_users[friendIndex]->_numOfFriends; i++)
	{
		cout << "friend #" << i + 1 << ": ";
		cout << all_users[friendIndex]->_friendsList[i]->_name << endl;
	}
	cout << endl << endl;
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

	delete[](*allUsers)[user_index]->_friendsList;
	(*allUsers)[user_index]->_friendsList = newFriendList;
}

// this function adds a friend to the user's friend list, and updates number of friends
void User::addFriendToFriendList(User*** allUsers, int user_index, int friend_index)
{
	int user_num_friends = (*allUsers)[user_index]->_numOfFriends;

	if (user_num_friends == (*allUsers)[user_index]->_maxNumOfFriends)
		reallocateFriendList(allUsers, user_index);

	(*allUsers)[user_index]->_friendsList[user_num_friends] = (*allUsers)[friend_index];
	((*allUsers)[user_index]->_numOfFriends)++;
}

// this function cancel friendship between 2 users
void User::cancelFriendship(Operation* system)
{
	User** all_users = system->getAllUsers();

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	int user_index = askForName(system, 0);
	if (user_index < 0)
		return;

	int friend_index = askForName(system, 1);
	if (friend_index < 0)
		return;

	// debugging
	cout << "username: " << all_users[user_index]->_name << endl;
	cout << "friends name: " << all_users[friend_index]->_name << endl;
	// so far so good


	// function taht searches friend on friendlist and returns  the friends index TODO
	// for user:
	int iFriendToDelete = 0;
	bool found = false;
	int user_num_of_friends = all_users[user_index]->_numOfFriends;
	int user_max_num_of_friends = all_users[user_index]->_maxNumOfFriends;

	// search this friend in the friend list:
	for (iFriendToDelete = 0; iFriendToDelete < user_num_of_friends && !found; iFriendToDelete++)
	{
		if (strcmp(all_users[user_index]->_friendsList[iFriendToDelete]->_name, all_users[friend_index]->_name) == 0)
		{
			found = true;
			cout << "friend was found on your friend list\n"; // debugging
		}
	}
	iFriendToDelete--;
	if (!found)
	{
		cout << "The friend was not found on your friend list!\n";
		return;
	}


	////// //// /// //. //////
	// for friend:

	int iUserToDelete = 0;
	found = false;
	int friend_num_of_friends = all_users[friend_index]->_numOfFriends;
	int friend_max_num_of_friends = all_users[friend_index]->_maxNumOfFriends;

	// search this friend in the friend list:
	for (iUserToDelete = 0; iUserToDelete < friend_num_of_friends && !found; iUserToDelete++)
	{
		if (strcmp(all_users[friend_index]->_friendsList[iUserToDelete]->_name, all_users[user_index]->_name) == 0)
		{
			found = true;
			cout << "user was found on Friend's friend list\n"; // debugging
		}
	}
	iUserToDelete--;
	if (!found) // TODO not important cause he is definetly in there
	{
		cout << "User was not found on your friend list!\n";
		return;
	}




	//

	

	/// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% //


	// remove friend from user:
	if ((all_users[user_index]->_numOfFriends == 1) || (iFriendToDelete == all_users[user_index]->_numOfFriends - 1))
	{ //    friend is the only one on the array        or       friend is the last on the array
		all_users[user_index]->_friendsList[iFriendToDelete] = nullptr;
	}
	else
	{
		all_users[user_index]->_friendsList[iFriendToDelete] = all_users[user_index]->_friendsList[user_num_of_friends - 1];
		all_users[user_index]->_friendsList[user_num_of_friends - 1] = nullptr; // point the last on null
	}
	(all_users[user_index]->_numOfFriends)--;


	/// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% //

	// remove user from friend:
	if ((all_users[friend_index]->_numOfFriends == 1) || (iUserToDelete == all_users[friend_index]->_numOfFriends - 1))
	{ //    friend is the only one on the array        or       friend is the last on the array
		all_users[friend_index]->_friendsList[iUserToDelete] = nullptr;
	}
	else
	{
		all_users[friend_index]->_friendsList[iUserToDelete] = all_users[friend_index]->_friendsList[friend_num_of_friends - 1];
		all_users[friend_index]->_friendsList[friend_num_of_friends - 1] = nullptr; // point the last on null
	}
	(all_users[friend_index]->_numOfFriends)--;




	/// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% //

	// debugging:

	user_num_of_friends = all_users[user_index]->_numOfFriends;
	cout << "\n\n\n######## Updated list of friends: #########\n\n";

	cout << "for user:\n";
	for (int i = 0; i < all_users[user_index]->_numOfFriends; i++)
	{
		cout << "Friend #" << i + 1 << ": " << all_users[user_index]->_friendsList[i]->getName() << endl;
	}
	cout << "\n\nfor friend:\n";
	for (int i = 0; i < all_users[friend_index]->_numOfFriends; i++)
	{
		cout << "Friend #" << i + 1 << ": " << all_users[friend_index]->_friendsList[i]->getName() << endl;
	}
	cout << "\n\n";
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