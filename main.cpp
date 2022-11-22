#include <iostream>
using namespace std;

#include "User.h"
#include "Operation.h"
#include "Status.h"
#include "Friend.h"
#include "Page.h"
#include "Date.h"

int main()
{
	User gon;
	User ori;

	gon.createStatus();
	ori.createStatus();

	return 0;
}
