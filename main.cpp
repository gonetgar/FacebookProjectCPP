#include <iostream>
using namespace std;

#include "User.h"
#include "Operation.h"
#include "Status.h"
#include "Friend.h"
#include "Page.h"
#include "Date.h"
#include "Functions.h"

int main()
{
	Operation system;
	User** initUsers = new User * [5];
	Page** initPages = new Page * [3];
	User** test;
	int userChoice = 0;

	// ################################ initiate data ################################ 
	//for (int i = 0; i < 3; i++)
	//{
	//	cout << "user #" << i << ":\n";
	//	//User user("gon", Date(i + 1, i + 1, 2020));
	//	User user("gon", Clock(i + 1, i + 1, 2020));
	//	Page page("page test");
	//	initUsers[i] = &user;
	//	initPages[i] = &page;
	//	cout << endl;
	//}

	/// @@@@@@@@@ gon try @@@@@@@@@
	User user1("Keren Kalif", Clock(15, 4, 1980));
	initUsers[0] = &user1;
	User user2("Steve Jobs", Clock(1, 3, 1960));
	initUsers[1] = &user2;
	User user3("Mark Zuckerberg", Clock(6, 8, 1976));
	initUsers[2] = &user3;
	User user4("Ori Nurieli", Clock(1, 7, 1997));
	initUsers[3] = &user4;
	User user5("Gon Etgar", Clock(21, 10, 1996));
	initUsers[4] = &user5;

	Page page1("Maccabi Haifa");
	initPages[0] = &page1;
	Page page2("Harry Potter");
	initPages[1] = &page2;
	Page page3("Pink Floyd");
	initPages[2] = &page3;

	initFriendsLists(&initUsers, 5);


	system.initiateData(initUsers, initPages);
	

	/// @@@@@@@@@ gon finish @@@@@@@@@
	system.displayAllEntities(); // TODO: print names and not addresses
	system.getCurrentMember();

	bool flag = doesUserExist("gon", initUsers);
	cout << "flag: " << flag << endl;


	//// ################################ Menu ################################ 
	userChoice = displayMenu();
	system.handleMenu(userChoice);

	while (userChoice < 0 || userChoice > 13)
	{
		cout << "Invalid Input, try again." << endl;
		userChoice = displayMenu();
		system.handleMenu(userChoice);
	}


	// ####### ori try 19:00 #######

	//Status stat;
	//stat.createStatus();


	// gon try 10:00 //



	return 0;
}
