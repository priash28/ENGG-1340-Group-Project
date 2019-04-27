#ifndef ITEM_CPP
#define ITEM_CPP
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include "item.h"
using namespace std;

void clrscr()
{
  system("clear");
}

//***************************************************************
// function to draw a line
//***************************************************************
void drawline(char x,int n)
{
 cout<<endl;
	for(int i=0;i<n;i++)
	{cout<<x;}
 cout<<endl;
}


void date::show_date()
{
cout<<dd<<"/"<<mm<<"/"<<yy;
}

void date::get_date()
	{
	start:
	cout<<endl;
	cout<<"\tdate (dd) :" ;
	cin>>dd;
		if(dd<=0||dd>31)
		{
		cout<<"INVALID DATE !" ;
		goto start;
		}
	cout<<"\tmonth (mm) :" ;
	cin>>mm;
		if(mm<=0||mm>12)
		{
		cout<<"INVALID MONTH !" ;
		goto start;
		}
	cout<<"\tyear (yy) :" ;
	cin>>yy;
		if(yy<=1900||yy>=2500)
		{
		cout<<"INVALID YEAR !" ;
		goto start;
		}
	cout<<endl;
	}

int item::reticode()
{return icode;}

double item::retprice()
{return price;}

string item::retname()
{return name;}

int item::retdis()
{return dis;}

void item::show_item()
{
	cout<<"\nThe item No. is : "<<icode;
	cout<<"\nThe Name of the item : ";
	cout<<name;
	cout<<"\nEXPIRATION DATE : ";
	exp_date.show_date();
	cout<<"\nThe Price of the item : "<<price;
	cout<<"\nDiscount (%): "<<dis;
}

void item::get_item()
	{
	g1:
		cout<<"\nEnter the Item code>>";
		cin>>icode;
		drawline();
			if(icode<=0)
			{
			cout<<" INVALID ICODE ! ";
			goto g1;
			}
		cout<<"Enter The Name of The Item >>";
    cin >> name;
		drawline();
		cout<<"Enter The EXPIRATION DATE >>";
		exp_date.get_date();
	g2:
		cout<<"Enter The Price of The Item >>";
		cin>>price;
		if(price<=0)
			{
			cout<<" INVAID PRICE ! ";
			goto g2;
			}
	 g3:
		cout<<"Enter The Discount (%) >>";
		cin>>dis;
		drawline();
		if(dis<0||dis>=100)
			{
			cout<<" INVAID DISCOUNT ! ";
			goto g3;
			}
	}

	//**************************************************************
	// global declaration for stream object, object
	//**************************************************************
	fstream str;
	item A;
	//***************************************************************
	// function to write in file
	//***************************************************************

	void write_item()     //this function writes new records in the database
	{
	str.open("DUKES.DAT",ios::out|ios::app);
	char ch;

	do{
		A.get_item();
		str.write((char*)&A,sizeof(item));
		drawline();
		cout<<"\nThe item Has Been Created ";
		cout<<"\nadd another?(y/n)";
		cin>>ch;
		clrscr();
	}while(ch=='y'||ch=='Y');
	str.close();
	}

	//***************************************************************
	// function to read all records from file
	//***************************************************************

	void display_all()     //to display all items present in the database
	{
	clrscr();
	cout<<"\n\n\n"<<setw(30)<<"<< LIST OF ALL ITEMS >>";
	drawline('=');
	str.open("DUKES.DAT",ios::in);

	while(str.read((char*)&A,sizeof(item)))
	{
		A.show_item();
		drawline('=');
		getchar();
	}
	str.close();
	getchar();
	}

	//***************************************************************
	// function to read specific record from file
	//****************************************************************

	void display_sp(int n)  //function to search for a record
	{
	int flag=0;
	str.open("DUKES.DAT",ios::in);
	while(str.read((char*)&A,sizeof(item)))
	{
		if(A.reticode()==n)
		{
		A.show_item();
		flag=1;
		}
	}
	str.close();
	if(flag==0)
	cout<<"\n\nrecord does not exist!!";
	getchar();
	}

	//***************************************************************
	// function to modify record of file
	//****************************************************************
	/*{

	int no,found=0;
	clrscr();
	cout<<"\n\n\tMODIFY RECORD ";
	cout<<"\n\n\tPlease Enter The item No. of The item";
	cin>>no;
	str.open("DUKES.DAT",ios::in|ios::out);
	while(str.read((char*)&A,sizeof(item)) && found==0)
	{
		if(A.reticode()==no)
		{
		A.show_item();
		cout<<"\nPlease Enter The New Details of item"<<endl;
		A.get_item();
		int pos=-1*sizeof(A);
		str.seekp(pos,ios::cur);
		str.write((char*)&A,sizeof(item));
		cout<<"\n\n\t Record Updated";
		found=1;
		}
	}
	str.close();
	if(found==0)
	cout<<"\n\n Record Not Found ";
	getchar();
	}*/
	//***************************************************************
	// function to delete record of file
	//****************************************************************
	void delete_item()
	{
	int no;
	clrscr();
	cout<<"\n\n\n\tDELETE RECORD";
	cout<<"\n\nPlease Enter The item no. of The item You Want To Delete :";
	cin>>no;
	display_sp(no);
	str.open("DUKES.DAT",ios::in|ios::out|ios::binary);
	fstream str2;
	str2.open("Temp.dat",ios::out|ios::binary);
	str.seekg(0,ios::beg);

	while(str.read((char*)&A,sizeof(item)))
	{
		if(A.reticode()!=no)
		{
		str2.write((char*)&A,sizeof(item));
		}
	}
	str2.close();
	str.close();
	remove("DUKES.DAT");
	rename("Temp.dat","DUKES.DAT");

	cout<<"\n\n\tRecord Deleted ..";

	getchar();
	}
#endif
