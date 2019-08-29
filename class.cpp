#include "class.h"
#include <fstream>


void Room::room_change(void)
{
	if (empty == true)
	{
		empty = false;
	}
	else
	{
		empty = true;
	}
}

bool Room::room_empty(void)
{
	if (empty == true)
	{
		return true;
	}
}

void Room::room_show(void)
{
	cout <<	room_number << endl;
	cout <<	type << endl;
	cout <<	price << endl;
	if (empty == true)
	{
		cout << "空" << endl;
	}
	else
	{
		cout << "满" << endl;
	}
}

int Room::get_price(void)
{
	return price;
}

int Room::get_room_number(void)
{
	return room_number;
}




void Customer::customer_change1(int _time)
{
	int time1=time;
	int price1=price;
	time = _time+time1;
	price = (price1/time1)*time;
}

void Customer::customer_change2(int _number,int _time,int _price)
{
	time = _time;
	price += _price;
	room_number = _number;
}

void Customer::customer_show(void)
{
	cout << "------------------------------" << endl;
	cout << "姓名:" << name << endl;
	cout << "房号:" << room_number << endl;
	cout << "消费金额:" << price << endl;
	cout << "押金:" << deposit << endl;
	cout << "时间:" << time;
	if (room_number/100 == 1)
	{
		cout << "小时" << endl;
	}
	else
	{
		cout << "天" << endl;
	}
	if (0 == strcmp(accname,"null"))
	{
		cout << "无随行人员" << endl;
	}
	else
	{
		cout << "随行人员:" << accname << endl;
	}
	cout << "------------------------------" << endl;
}

char* Customer::get_name(void)
{
	return name;
}

int Customer::get_room_number(void)
{
	return room_number;
}
