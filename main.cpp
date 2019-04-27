//***************************************************************
// HEADER FILE USED IN PROJECT
//****************************************************************
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include "item.h"

using namespace std;



//***************************************************************
// Employee Record for authorisation into the Admin Menu
//***************************************************************

struct Employee
{
  string name;
  string id;
};
//
// void drawline(char x='-',int n=80)
// {
//  cout<<endl;
// 	for(int i=0;i<n;i++)
// 	{cout<<x;}
//  cout<<endl;
// }
extern item A;

extern fstream str;

void intro();

Employee employees[100];

int employ_database()
{
  string b = "EmployeeList.txt";
  ifstream fin( b.c_str());

  int count = 0;

  string x;
  while(getline(fin, x))
  {
    string name = "";
    string id = "";

    for (int i = 0; i < x.length(); i++)
    {
      if (isalpha(x[i]))
      {
        name += x[i];
      }
      else if ((!(isalpha(x[i]))) && (x.substr(i,1) != " "))
      {
        id += x[i];

      }

    }
    employees[count].name = name;
    employees[count].id = id;
    count++;
  }

  fin.close();
  return count;
}

bool pass(int count)
{
  drawline();
  intro();
  cout << "Enter Employee Name: ";
  string entry;
  int tracker = 0;
  string a = "";
  cin >> entry;
  while (tracker != count)
  {
    if (entry == employees[tracker].name)
    {
      cout << "Enter ID: ";
      string entry2;
      cin >> entry2;
      a += "b";
      if (entry2 == employees[tracker].id)
      {
        cout << "Access Granted" << endl;
        return true;
        break;
      }
      else
      {
        cout << "Access Denied.";
        exit(0);
      }
    }
    tracker++;
  }
  if (a == "")
  {
    cout << "Access Denied.";
    exit(0);
  }
}


//***************************************************************
// Linked List used in program
//***************************************************************

struct Node //linked list to track all orders
{
  int order_num;
  double totalprice;
  int items;
  Node *next;
};
Node *n;
Node *t;
Node *head;



void create_order_record(double total, int order_arr[], int order_arr_length)
{
  ofstream fout;
  fout.open("LinkedList.txt",ios::app);
  int orderno;

  int number_customers;
  ifstream fin;
  string a = "LinkedList.txt";
  fin.open(a.c_str());
  string x;
  orderno = 100100100;
  while (getline(fin, x))
  {
    if (x.substr(0,1) == "0")
    {
      n = new Node;

      n->totalprice = total;
      n->items = order_arr_length;
      n->order_num = orderno + int(total)+ n->items; //Unique Identification for all orders

      t = n;
      head = n;
      number_customers = atoi(x.substr(0,1).c_str());

      fout <<"ORDER NUMBER: "<< n->order_num << " TOTAL PRICE: " << n->totalprice << " NUMBER OF DIFFERENT ITEMS PURCHASED: " << n->items << endl;
      break;

      fout.close();
      orderno++;
      getline(fin,x);

    }
  }

}


//***************************************************************
// function to display all items price list
//****************************************************************
void item_menu()
{
clrscr();
str.open("DUKES.DAT",ios::in);

if(!str)
{
cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File\n";
getchar();

}

cout<<setw(50)<<"\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3";
cout<<"\n"<<setw(50)<<"DUKE'S BAKERS MENU\n";
cout<<setw(50)<<"\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3";
drawline('=',60);
cout<<"I.NO."<<setw(20)<<"NAME"<<setw(20)<<"PRICE";
drawline('=',60);

while(str.read((char*)&A,sizeof(item)))
{
	if(A.retdis()>0)
	{
	cout<<A.reticode()<<setw(20)<<A.retname()<<"("<<A.retdis()<<"%off)"<<setw(20)<<A.retprice()<<endl;
	}
	else
	{
	cout<<A.reticode()<<setw(20)<<A.retname()<<setw(28)<<A.retprice()<<endl;
	}
}
drawline('=',60);
str.close();
}

//***************************************************************
// function to place order and generating bill for items
//****************************************************************

void place_order()
{
int order_arr[50],quan[50],c=0;
double amt,damt,total=0;
char ch='Y';

	do
	{
	clrscr();
	item_menu();
	cout<<"\nPLACE ORDER: " ;
	cout<<"\n\nEnter The item No. Of The item : ";
	cin>>order_arr[c];
	cout<<"Quantity in number : ";
	cin>>quan[c];
	c++;
	cout<<"\nDo You Want To Order Another item ? (y/n)";
	cin>>ch;
	}while(ch=='y' ||ch=='Y');

cout<<"\n\nThank You For Placing The Order";
getchar();

clrscr();
drawline('=',80);
cout<<setw(25)<<"DUKE'S BAKERY SHOP\n";
cout<<setw(30)<<"BILL";
drawline('=',80);
cout<<"I.NO."<<setw(15)<<"NAME"<<setw(15)<<"QTY"<<setw(15)<<"RATE"<<setw(15)<<"AMOUNT"<<setw(15)<<"AFTER DISCOUNT";

for(int x=0;x<=c;x++)
{
	str.open("DUKES.DAT",ios::in);
	str.read((char*)&A,sizeof(item));
	while(!str.eof())
	{
		if(A.reticode()==order_arr[x])
		{
		amt=A.retprice()*quan[x];
		damt=amt-(amt*A.retdis()/100);

		cout<<"\n"<<order_arr[x]<<setw(15)<<A.retname()
		<<setw(15)<<quan[x]<<setw(15)<<A.retprice()<<setw(15)<<amt<<setw(15)<<damt;

		total+=damt;
	}
str.read((char*)&A,sizeof(item));
}


str.close();
}

drawline('=',80);
cout<<setw(50)<<"SUB TOTAL = "<<total<<endl;
cout<<setw(50)<<"GST (9%) = "<<total*0.09<<endl;
cout<<setw(50)<<"TOTAL PAYABLE AMT = "<<total*1.09;
drawline('=',80);
create_order_record(total, order_arr,c);
}
//***************************************************************
// INTRODUCTION FUNCTION
//****************************************************************
void intro()
{
clrscr();
//char loda;
cout<<"\n\n\n\n\n";
cout<<"\t\t\t   DUKE'S BAKERY SHOP\n";
cout
<<"\n\t\t\t  _____        _               "
<<"\n\t\t\t |  __ \\      | |              "
<<"\n\t\t\t | |  | |_   _| | _____  ___   "
<<"\n\t\t\t | |  | | | | | |/ / _ \\/ __|  "
<<"\n\t\t\t | |__| | |_| |   <  __/\\__ \\  "
<<"\n\t\t\t |_____/ \\__,_|_|\\_\\___||___/  ";
cout<<"\n\n\n\n\nMADE BY : MANIK SOIN & PRIYANSH SHANDILYA";
cout<<"\n\nGROUP: 60";
cout << endl;
getchar();
}

//***************************************************************
// ADMINSTRATOR MENU FUNCTION
//****************************************************************
void admin_menu()
{
clrscr();
char ch2;
drawline();
int counter;
counter = employ_database();

//if (pass(counter))
//{
  clrscr();
  cout<<setw(40)<<"\nADMINISTRATOR MENU";
  drawline();
  cout<<setw(20)<<"\n1)Create a new item";
  cout<<setw(20)<<"\n2)Display all items in database";
  cout<<setw(20)<<"\n3)Search for an item";
  cout<<setw(20)<<"\n4)Modify item listing";
  cout<<setw(20)<<"\n5)Delete item";
  cout<<setw(20)<<"\n6)Reset MENU";
  cout<<setw(20)<<"\n7)GO BACK TO MAIN MENU";
  cout<<setw(20)<<"\n\nPlease Enter Your Choice >> ";
  cin>>ch2;
  switch(ch2)
  {
  case '1': clrscr();
  write_item();
  break;
  case '2': display_all();break;
  case '3':

  	int num;
  	clrscr();
  	cout<<setw(30)<<"\nEnter the ITEM NO. you want to search >>";
  	cin>>num;
  	display_sp(num);
  break;

  //case '4': modify_item();break;
  case '5': delete_item();break;
  case '6':
  str.open("DUKES.DAT",ios::out|ios::trunc);
  str.close();
  break;
  case '7': break;
  default:cout<<"\a";
  admin_menu();
 // }
}


}
//***************************************************************
// THE MAIN FUNCTION OF PROGRAM
//****************************************************************
int main()
{
char ch;
intro();

do{
clrscr();
item_menu();

cout<<"\n[P]: Place a new order";
cout<<"\n[A]: Administrator Login ";
cout<<"\n[C]: Contact us ";
cout<<"\n[E]: EXIT ";
cout<<"\nYour choice :";
cin >> ch;
switch(ch)
{
case 'P':
case 'p':
	place_order();
	getchar();
break;
case 'A':
case 'a':
	p1:
	clrscr();
  admin_menu();
break;
case 'C':
case 'c':
clrscr();
cout<<"\n\n\t\tDUKE'S BAKE GOODS INC";
cout<<"\n\n\tManik Soin: manik@connect.hku.hk\n\tPriyansh Shandilya: priash28@connect.hku.hk";
cout<<endl<<endl;
system("PAUSE");
break;
case 'E':
case 'e':
exit(0);
break;

default :cout<<"\a";
}
}while(ch!='E');

}
//***************************************************************
// END OF PROJECT
//***************************************************************
