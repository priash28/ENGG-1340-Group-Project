#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <iomanip>
using namespace std;

struct date
{
int dd;
int mm;
int yy;
void get_date();
void show_date();
};

class item
{

int icode;
string name;
char supplier[50];
date exp_date;
double price,qty,tax,dis;
item *next;

public:

void get_item();
void show_item();


int reticode();

double retprice();

string retname();

int retdis();

}; //class ends here

void drawline(char x='-',int n=80);
void clrscr();
void write_item();
void display_all();
void display_sp(int n);
void delete_item();

#endif
