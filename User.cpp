#include <iostream>
using namespace std;

#include "User.h"
#include "Functions.h"
#define NOT_FOUND -1

User::User()
{
	_name = new char[256];
	_name = _strdup("ori the king");

	_birthday = Clock(1, 1, 2000);
	_statuses = new Status * [_maxNumOfStatuses];
	_likedPages = new Page * [_maxNumOfPages];
	_friendsList = new User * [_maxNumOfFriends];
}

User::User(const char* name, Clock birthday, int maxNumFriends, int numFriends, int maxPages, int numPages)
{
	_name = new char[256];
	_name = _strdup(name);
	_birthday = birthday;

	_maxNumOfFriends = maxNumFriends;
	_numOfFriends = numFriends;

	_maxNumOfPages = maxPages;
	_numOfPages = numPages;

	_statuses = new Status * [_maxNumOfStatuses];
	_likedPages = new Page * [_maxNumOfPages];
	_friendsList = new User * [_maxNumOfFriends];
}

void User::setName(char* username)
{
	_name = username;
}

void User::createStatus(Status* initStatus)
{
	if (_maxNumOfStatuses == _numOfStatuses)
	{
		_maxNumOfStatuses *= 2;
		Status** newStatuses = new Status * [_maxNumOfStatuses];
		for (int i = 0; i < _numOfStatuses; i++)
			newStatuses[i] = _statuses[i];

		delete[] _statuses;
		_statuses = newStatuses;
	}

	if (initStatus != nullptr) _statuses[_numOfStatuses] = initStatus;

	else {
		Status* newStatus = new Status();
		newStatus->getStatusInfo(newStatus);
		cout << endl << "Status Uploaded!" << endl;
		_statuses[_numOfStatuses] = newStatus;
	}
	_numOfStatuses++;

}

// this function connects 2 users to be friends
void User::addFriend(Operation* system)
{
	User** all_users = system->getAllUsers();

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	int user_index = askForName(system, 0);
	if (user_index < 0)
		return;

	int friend_index = askForName(system, 1);
	if (friend_index < 0)
		return;

	addFriendToFriendList(&all_users, user_index, friend_index);
	addFriendToFriendList(&all_users, friend_index, user_index);

	cout << "\nHello " << all_users[user_index]->getName() << ", you have added " << all_users[friend_index]->getName() << " to your friend list." << endl << endl;

	// ################################################ //
	//debugging - TODO delete later
	/*cout << "\n\n### debugging: ###\n";
	cout << all_users[user_index]->_name << "'s friend list:\n";
	for (int i = 0; i < all_users[user_index]->_numOfFriends; i++)
	{
		cout << "friend #" << i + 1 << ": ";
		cout << all_users[user_index]->_friendsList[i]->_name << endl;
	}
	cout << endl;
	cout << all_users[friend_index]->_name << "'s friend list:\n";
	for (int i = 0; i < all_users[friend_index]->_numOfFriends; i++)
	{
		cout << "friend #" << i + 1 << ": ";
		cout << all_users[friend_index]->_friendsList[i]->_name << endl;
	}
	cout << endl << endl;*/
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
	if (userIndex == NOT_FOUND)
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

// returns the friend's index in friendList array, and -1 if not found
int User::searchFriendInFriendList(User** allUsers, int userIndex, int friendIndex)
{
	int friend_to_delete = NOT_FOUND;

	// search this friend in the friend list:
	for (int i = 0; i < allUsers[userIndex]->_numOfFriends; i++)
	{
		if (strcmp(allUsers[userIndex]->_friendsList[i]->_name, allUsers[friendIndex]->_name) == 0)
		{
			friend_to_delete = i;
			break;
		}
	}

	if (friend_to_delete == NOT_FOUND)
		cout << "The friend was not found on your friend list!\n";

	return friend_to_delete;
}

// receives the user and an index of a friend to delete, removes him from his friend list by switching the pointers of the removed friend and the last one on the list
void User::removeFriendFromFriendList(User** all_users, int user_index, int friend_to_delete)
{
	if ((all_users[user_index]->_numOfFriends == 1) || (friend_to_delete == all_users[user_index]->_numOfFriends - 1))
	{ //    friend is the only one on the array        or       friend is the last on the array
		all_users[user_index]->_friendsList[friend_to_delete] = nullptr;
	}
	else // friend is in the "middle" of the array
	{
		all_users[user_index]->_friendsList[friend_to_delete] = all_users[user_index]->_friendsList[all_users[user_index]->_numOfFriends - 1];
		all_users[user_index]->_friendsList[all_users[user_index]->_numOfFriends - 1] = nullptr; // point the last friend on null
	}
	(all_users[user_index]->_numOfFriends)--; // update number of friends
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

	// debugging - TODO delete the debugging coutim
	/*cout << "\nBEFORE: list of friends:\n";
	cout << "for " << all_users[user_index]->_name << ":\n";
	cout << "number of friends: " << all_users[user_index]->_numOfFriends << endl;
	cout << "max number of friends: " << all_users[user_index]->_maxNumOfFriends << endl << endl;
	for (int i = 0; i < all_users[user_index]->_numOfFriends; i++)
	{
		cout << "Friend #" << i + 1 << ": " << all_users[user_index]->_friendsList[i]->getName() << endl;
	}
	cout << "\nfor " << all_users[friend_index]->_name << ":\n";
	cout << "number of friends: " << all_users[friend_index]->_numOfFriends << endl;
	cout << "max number of friends: " << all_users[friend_index]->_maxNumOfFriends << endl << endl;
	for (int i = 0; i < all_users[friend_index]->_numOfFriends; i++)
	{
		cout << "Friend #" << i + 1 << ": " << all_users[friend_index]->_friendsList[i]->getName() << endl;
	}
	cout << "\n\n";*/


	int iFriendToDelete = searchFriendInFriendList(all_users, user_index, friend_index);
	if (iFriendToDelete == NOT_FOUND)
		return;

	int iUserToDelete = searchFriendInFriendList(all_users, friend_index, user_index);
	if (iUserToDelete == NOT_FOUND)
		return;

	removeFriendFromFriendList(all_users, user_index, iFriendToDelete);
	removeFriendFromFriendList(all_users, friend_index, iUserToDelete);

	cout << "\nHello " << all_users[user_index]->getName() << ", you have removed " << all_users[friend_index]->getName() << " from your friend list." << endl << endl;

	// debugging: - TODO delete the debugging coutim
	/*cout << "\n\n\n######## Updated list of friends: #########\n\n";
	cout << "for " << all_users[user_index]->_name << ":\n";
	cout << "number of friends: " << all_users[user_index]->_numOfFriends << endl;
	cout << "max number of friends: " << all_users[user_index]->_maxNumOfFriends << endl << endl;
	for (int i = 0; i < all_users[user_index]->_numOfFriends; i++)
	{
		cout << "Friend #" << i + 1 << ": " << all_users[user_index]->_friendsList[i]->getName() << endl;
	}
	cout << "\nfor " << all_users[friend_index]->_name << ":\n";
	cout << "number of friends: " << all_users[friend_index]->_numOfFriends << endl;
	cout << "max number of friends: " << all_users[friend_index]->_maxNumOfFriends << endl << endl;
	for (int i = 0; i < all_users[friend_index]->_numOfFriends; i++)
	{
		cout << "Friend #" << i + 1 << ": " << all_users[friend_index]->_friendsList[i]->getName() << endl;
	}
	cout << "\n\n";*/
}


void User::likePage(Operation* system, User* current_user, Page* pageLiked)
{
	Page* new_page;

	if (current_user == nullptr)
		return;

	if (pageLiked != nullptr) // function recevied pointer to page, add the page to current_user
	{
		new_page = pageLiked;
	}
	else // the function recevied null, ask the user to input page name
	{
		// ask for page name and search it in the system:
		new_page = getPageDetails(system);
		if (new_page == nullptr) // the page user inserted wasn't found
		{
			cout << "Page doesn't exist." << endl << endl;
			return;
		}
	}	

	// add to user's likes pages
	if (_maxNumOfPages == _numOfPages)
	{
		_maxNumOfPages *= 2;
		Page** newPagesArray = new Page * [_maxNumOfPages];
		for (int i = 0; i < _numOfPages; i++)
			newPagesArray[i] = _likedPages[i];

		_likedPages = newPagesArray;
	}

	_likedPages[_numOfPages] = new_page;
	_numOfPages++;

	new_page->addFanToPage(system, this); // check

	//cout << endl << this->getName() << " liked " << page_liked->getName() << endl << endl;
	//cout << endl << this->getName() << " liked " << new_page->getName() << endl << endl;
}

// i changed the function
//void User::likePageORI(Page* newPage) // todo: change to ref&
//{
//	bool isPageInLikedPages = false;
//
//	for (int i = 0; i < _numOfPages; i++)
//	{
//		if (newPage == _likedPages[i]) // addresses compare
//			isPageInLikedPages = true;
//	}
//
//	if (!isPageInLikedPages) // stop infinite loop
//	{
//		if (_maxNumOfPages == _numOfPages) {
//			_maxNumOfPages *= 2;
//			Page** newPagesArray = new Page * [_maxNumOfPages];
//			for (int i = 0; i < _numOfPages; i++)
//				newPagesArray[i] = _likedPages[i];
//
//			delete[] _likedPages;
//			_likedPages = newPagesArray;
//		}
//
//		_likedPages[_numOfPages] = newPage;
//		_numOfPages++;
//
//		newPage->addFanORI(this);
//		cout << endl << this->getName() << " liked  " << newPage->getName() << endl << endl;
//	}
//}

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

		cout << endl << userToDisplay->getName() << "'s Recent 10 statuses:" << endl;
		for (int i = 0; i < numOfStatuses || numOfStatuses == NUM_STATUSES_TO_DISPLAY; i++)
		{
			cout << "---------------------------------" << endl;
			cout << "Status #" << i + 1 << endl;
			cout << "Text: " << statuses[i]->getText() << endl;
			cout << "Uploaded on: ";
			statuses[i]->getStatusTime().displayDate();
			cout << " | ";
			statuses[i]->getStatusTime().displayTime();
			cout << endl;
			cout << "---------------------------------" << endl << endl;
		}
	}
	else cout << "No statuses to display." << endl << endl;
}

void User::displayAllStatuses()
{
	cout << endl << _name << "'s Statuses:\n";
	if (_numOfStatuses == 0) cout << "None." << endl;
	else {
		for (int i = 0; i < _numOfStatuses; i++)
		{
			cout << "---------------------------------" << endl;
			cout << "Status #" << i + 1 << endl;
			cout << "Text: " << _statuses[i]->getText() << endl;
			cout << "Uploaded on: ";
			_statuses[i]->getStatusTime().displayDate();
			cout << " | ";
			_statuses[i]->getStatusTime().displayTime();
			cout << endl;
			cout << "---------------------------------" << endl << endl;
		}
	}
}

void User::displayAllFriends()
{
	cout << "\n" << _name << "'s friends:" << endl;

	if (_numOfFriends == 0)
		cout << "None :(" << endl;
	else
	{
		cout << endl;
		for (int i = 0; i < _numOfFriends; i++)
		{
			cout << "friend #" << i + 1 << ":\n";
			cout << "Name: " << _friendsList[i]->getName() << endl;
			cout << "Birthday: ";
			_friendsList[i]->_birthday.displayDate();
			cout << endl << endl;
		}
	}
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