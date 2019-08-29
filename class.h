#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <string.h>

using namespace std;

class Room
{
	int room_number;
	int type;
	int price;
	bool empty;
public:
	Room(int room_number=0,int type=0,int price =0)
	{
		this->room_number = room_number;
		this->type = type;
		this->price = price;
		this->empty = true;
	}
	void room_change(void); 
	bool room_empty(void);
	void room_show(void);
	int get_price(void);
	int get_room_number(void);
};

class Customer
{
	char* name;
	int room_number;
	int price;
	int deposit;
	int time;
	char* accname;
public:
	Customer(char* name,int room_number,int price,int deposit,int time,char* accname)
	{
		this->name = new char[strlen(name)+1];
		this->accname = new char[strlen(accname)+1];
		strcpy(this->name,name);
		strcpy(this->accname,accname);
		this->room_number = room_number;
		this->price = price;
		this->deposit = deposit;
		this->time = time;
	}
	void customer_change1(int _time);
	void customer_change2(int _number,int _time,int _price);
	void customer_show(void);
	char* get_name(void);
	int get_room_number(void);
};




#endif//CLASS_H
