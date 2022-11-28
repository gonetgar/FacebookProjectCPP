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
	int userChoice = 0;

	Operation system;
	User** initUsers = new User * [5];
	Page** initPages = new Page * [3];

	// ################################ initiate data ################################ 
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

	//initFriendsLists(&initUsers, 5);

	system.initiateData(initUsers, initPages);
	system.getCurrentMember();


	//// ################################ Menu ################################ 
	userChoice = displayMenu();
	system.handleMenu(userChoice);

	while (userChoice > 0 || userChoice < 13)
	{
		userChoice = displayMenu();
		system.handleMenu(userChoice);
	}


	cout << "end of main()." << endl;

	return 0;
}
