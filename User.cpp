#include <iostream>
using namespace std;

#include "User.h"
#include "Functions.h"
#define NOT_FOUND -1

class Page;

User::User()
{
	_name = new char[MAX_CHARACTERS];
	_name = _strdup("ori the king");

	_birthday = Clock(1, 1, 2000);
	_statuses = new Status * [_maxNumOfStatuses];
	_likedPages = new Page * [_maxNumOfPages];
	_friendsList = new User * [_maxNumOfFriends];
}

User::User(const char* name, Clock birthday, int maxNumFriends, int numFriends, int maxPages, int numPages)
{
	_name = new char[MAX_CHARACTERS];
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
		cout << "Status Uploaded!" << endl << endl;
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

	int iFriendToDelete = searchFriendInFriendList(all_users, user_index, friend_index);
	if (iFriendToDelete == NOT_FOUND)
		return;

	int iUserToDelete = searchFriendInFriendList(all_users, friend_index, user_index);
	if (iUserToDelete == NOT_FOUND)
		return;

	removeFriendFromFriendList(all_users, user_index, iFriendToDelete);
	removeFriendFromFriendList(all_users, friend_index, iUserToDelete);

	cout << "\n" << all_users[user_index]->getName() << ", you have removed " << all_users[friend_index]->getName() << " from your friend list." << endl << endl;
}

void User::addPageToLikedPagesList(Operation* system, Page* pageToLike)
{
	if (_numOfPages == _maxNumOfPages)
	{
		_maxNumOfPages *= 2;
		Page** new_liked_pages = new Page * [_maxNumOfPages];

		for (int i = 0; i < _numOfPages; i++)
			new_liked_pages[i] = _likedPages[i];

		_likedPages = new_liked_pages;
		new_liked_pages = nullptr;
		delete[] new_liked_pages;
	}

	_likedPages[_numOfPages] = pageToLike;
	_numOfPages++;

	// here add fan to page:
	pageToLike->addFanToPage(system, this);
}

// receives pointer to a page or null
void User::likePage(Page* pageToLike, Operation* system)
{
	if (pageToLike != nullptr) // we need to add this page to user
	{
		addPageToLikedPagesList(system, pageToLike);
		cout << _name << " liked " << pageToLike->getName() << endl;
	}
	else // we need to ask the user which page to add
	{
		Page* new_page = getPageDetails(system);
		if (new_page == nullptr)
		{
			cout << "Page doesn't exist.\n";
			return;
		}

		addPageToLikedPagesList(system, new_page);
		cout << endl << this->getName() << " liked " << new_page->getName() << endl << endl;
	}	
}

void User::dislikePage(Operation* system) // todo: change to ref&
{
	Page* page_to_dislike = getPageDetails(system);
	bool found = false;

	if (page_to_dislike == nullptr)
	{
		cout << "Page was not found." << endl;
		return;
	}

	for (int i = 0; i < _numOfPages && !found ; i++)
	{
		if (page_to_dislike == _likedPages[i]) // page is in likedPages
		{
			// there is only one page in the array, or the page to dislike is the last one
			if (i == _numOfPages - 1)
			{
				_likedPages[i] = nullptr;
			}
			else // in the "middle"
			{ // swap the one we dislike, with the last one
				_likedPages[i] = _likedPages[_numOfPages - 1];
				_likedPages[_numOfPages - 1] = nullptr;
			}
			_numOfPages--;
			page_to_dislike->removeFan(this);
			found = true;
		}
	}

	if (!found)
		cout << "Page was not found on your Liked Pages list." << endl << endl;
	else
		cout << endl << this->getName() << " disliked " << page_to_dislike->getName() << endl << endl;
}

// 10 most recent statuses of all his friends
void User::displayRecentStatusesOfaFriend(Operation* system)
{
	const int NUM_STATUSES_TO_DISPLAY = 10;

	if (_numOfFriends == 0)
		cout << "No friends to display." << endl << endl;
	for (int i = 0; i < _numOfFriends; i++) // go over friends list
	{
		cout << "---------------------------------" << endl;
		cout << "Friend's name: " << _friendsList[i]->getName() << endl;
		cout << _friendsList[i]->getName() << "'s 10 Most Recent Statuses Are:" << endl;
		Status** friend_status_list = _friendsList[i]->getAllStatuses();
		int num_statuses = _friendsList[i]->getNumOfStatuses();

		if(num_statuses == 0)
			cout << "No statuses to display." << endl;
		else
		{
			int stop_loop;
			(num_statuses < NUM_STATUSES_TO_DISPLAY) ? (stop_loop = 0) : (stop_loop = num_statuses - NUM_STATUSES_TO_DISPLAY);

			for (int j = num_statuses - 1; j >= stop_loop; j--)
			{
				cout << endl << "Status:" << endl;
				cout << "Text: " << friend_status_list[j]->getText() << endl;
				cout << "Uploaded On: ";
				friend_status_list[j]->getStatusTime().displayDate();
				cout << " |";
				friend_status_list[j]->getStatusTime().displayHour();
				cout << endl;
			}
		}
		cout << "---------------------------------" << endl;
	}
}

// shows all statuses of a chosen user
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
			cout << " |";
			_statuses[i]->getStatusTime().displayHour();
			cout << endl;
			cout << "---------------------------------" << endl << endl;
		}
	}
}

// shows all friends of a user
void User::displayAllFriends()
{
	cout << "\n" << _name << "'s friends:" << endl;

	if (_numOfFriends == 0)
		cout << "None :(" << endl << endl;
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