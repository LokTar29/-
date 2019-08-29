#include "func.h"
#include "class.h"
#include "tools.h"
#include <stdlib.h>

int num=0;
Room* room[40];
Customer* customer[40];

void run(void)
{
	while(1)
	{
		system("clear");
		menu1();
		switch(get_cmd('1','4'))
		{
			case '1':open();break;
			case '2':query();break;
			case '3':out();break;
			case '4':return;
		}
	}
}

void room_init(void)
{
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=10;j++)
		{
			if (i==1)
			{
				room[(i-1)*10+j] = new Room(i*100+j,i,20);
			}
			if (i==2)
			{
				room[(i-1)*10+j] = new Room(i*100+j,i,100);
			}
			if (i==3)
			{
				room[(i-1)*10+j] = new Room(i*100+j,i,200);
			}
			if (i==4)
			{
				room[(i-1)*10+j] = new Room(i*100+j,i,300);
			}
			
		}
	}
}


void open(void)
{
	char name[20];
	int room_number;
	int price;
	int deposit;
	int time;
	char accname[20];
	
	cout << "请输入您的姓名" << endl;
	cin >> name;
	menu2();
	int n=0;
	cin >> n;
	if (n == 5) 
	{
		return;
	}
	for(int i=1+10*(n-1);i<=10+10*(n-1);i++)
	{
		if (room[i]->room_empty() == true)
		{
			room_number = room[i]->get_room_number();
			deposit = 100;
			if (n == 1)
			{
				cout << "请输入要住几小时的钟点房" << endl;
			}
			else
			{
				cout << "请输入要住的天数" << endl;
			}
			cin >> time;
			price = time*(room[i]->get_price());
			char c;
			while(1)
			{
				cout << "是否有随行人员(限1个) (y/n)" << endl;
				cin >> c;
				if (c == 'y'|c == 'n')
				{
					break;
				}
				cout << "输入格式错误" << endl;
			}
			if (c == 'y')
			{
				cout << "请输入随行人员的姓名" << endl;
				cin >>accname;
			}
			else 
			{
				strcpy(accname,"null");
			}
			customer[num++] = new Customer(name,room_number,price,deposit,time,accname);
			room[i]->room_change();
			break;
		}
		if (i == 10+10*(n-1))
		{
			cout << "抱歉，房间已满!" << endl;
		}
	}
}
void query(void)
{
	char name[20];
	cout << "请输入您的姓名" << endl;
	cin >> name;
	for(int i=0;i<num;i++)
	{
		if (0 == strcmp(customer[i]->get_name(),name))
		{
			customer[i]->customer_show();
			cout << "1、当前房间续费" << endl;
			cout << "2、换一种房间" << endl;
			cout << "3、返回" << endl;
			switch (get_cmd('1','3'))
			{
				case '1':
				{
					int time = 0;
					if (customer[i]->get_room_number()/100 == 1)
					{
						cout << "请输入要续费的小时:" << endl;
					}
					else
					{
						cout << "请输入要续费的天数:" << endl;
					}
					cin >> time;
					customer[i]->customer_change1(time);
					cout << "续费成功！" << endl;
					break;
				}
				case '2':
				{
					menu2();
					int time=0;
					int n=0;
					int number=0;
					int price=0;
					cin >> n;
					if (n == 5) 
					{
						return;
					}
					for(int j=1+10*(n-1);j<=10+10*(n-1);j++)
					{
						if (room[j]->room_empty() == true)
						{
							if (n == 1)
								{
								cout << "请输入要住几小时的钟点房" << endl;
							}
							else
							{
								cout << "请输入要住的天数" << endl;
							}
							cin >> time;
							price = time*(room[j]->get_price());
							number = room[j]->get_room_number();
							room[j]->room_change();
							int _number = customer[i]->get_room_number();
							_number = (_number/100-1)*10+_number%100;
							room[_number]->room_change();
							customer[i]->customer_change2(number,time,price);
							break;
						}
						if (j == 10+10*(n-1))
						{
							cout << "抱歉，该种房间已满!" << endl;
						}
					}
				}
				case '3':return;
			}
			
		}
	}
	cout << "无该顾客" << endl;
}

void out(void)
{
	char name[20];
	cout << "请输入您的姓名" << endl;
	cin >> name;
	for(int i=0;i<num;i++)
	{
		if (0 == strcmp(customer[i]->get_name(),name))
		{
			int number = customer[i]->get_room_number();
			number = (number/100-1)*10+number%100;
			room[number]->room_change();
			cout << "退回您的100元押金，欢迎再次光临" << endl;
			Customer *p =customer[i];
			delete p;
			for(int j=i;j<num;j++)
			{
				customer[j]=customer[j+1];
			}
			customer[--num]=NULL;
			return;
		}	
	}
	cout << "无该顾客" << endl;
}
void menu1(void)
{
	cout << "*****欢迎来到指针宾馆*****" << endl;
	cout << "1、开房" << endl;
	cout << "2、查询及续费" << endl;
	cout << "3、退房" << endl;
	cout << "4、退出" << endl;
	cout << "************************" << endl;
}
void menu2(void)
{
	cout << "************************" << endl;
	cout << "1、钟点房 20/hour" << endl;
	cout << "2、标间 100/day" << endl;
	cout << "3、高级标间 200/day" << endl;
	cout << "4、豪华套房 300/day" << endl;
	cout << "5、退出" << endl;
	cout << "************************" << endl;
}
