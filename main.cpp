#include <iostream>
#include "class.h"
#include "func.h"
using namespace std;

extern Room* room[40];
extern Customer* customer[40];

int main()
{
	room_init();
	run();
}

