#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

struct stud
{
	int roll, std;
	char name[32];
	float percent;
	stud *next;
}*top, *ptr, *newptr;

void getdata(int&, char[], int&, float&);
stud* CNN(int, char[], int, float);
void push(stud*);
void pop();
void disp(stud*);

void main()
{
	clrscr();
	newptr = top = NULL;
	int r, s;
	char n[32], ch;
	float p;
	cout<<"\t\t\tDynamic Implementation of Stacks";
	cout<<"\n\nInserting elements in stack:\n";
	do
	{
		getdata(r, n, s, p);
		newptr = CNN(r, n, s, p);
		if(newptr == NULL)
		{
			cout<<"\n\nOverflow! Exiting!";
			getch();
			return;
		}
		push(newptr);
		clrscr();
		cout<<"Stack now looks like this:-\n";
		disp(top);
		cout<<"\n\nDo you want to continue?\n";
		cin>>ch;
		clrscr();
	} while(ch == 'y' || ch == 'Y');

	clrscr();
	disp(top);
	cout<<"\n\nDo you want to delete elements?\n";
	cin>>ch;

	if(ch == 'y' || ch == 'Y')
	{
		do
		{
			pop();
			clrscr();
			cout<<"Stack now looks like this:-\n";
			disp(top);
			cout<<"\n\nDo you want to continue to delete elements?\n";
			cin>>ch;
		} while(ch == 'y' || ch == 'Y');
	}

	clrscr();
	cout<<"Bye! Bye!";
	getch();
}

void getdata(int &r, char n[], int &s, float &p)
{
	cout<<"\nEnter student roll number: ";
	cin>>r;
	cout<<"\nEnter student name: ";
	gets(n);
	cout<<"\nEnter student standard: ";
	cin>>s;
	cout<<"\nEnter student marks percentage: ";
	cin>>p;
}
stud* CNN(int r, char n[], int s, float p)
{
	ptr = new stud;
	ptr -> roll = r;
	strcpy(ptr -> name, n);
	ptr -> std = s;
	ptr -> percent = p;
	ptr -> next = NULL;
	return ptr;
}
void push(stud *ent)
{
	if(top == NULL)
		top = ent;
	else
	{
		ent -> next = top;
		top = ent;
	}
}
void pop()
{
	if(top == NULL)
		cout<<"\nUnderflow!";
	else
	{
		ptr = top;
		top = top -> next;
		delete ptr;
	}
}
void disp(stud *ent)
{
	while(ent != NULL)
	{
		cout<<"\nStudent roll number: "<<ent -> roll;
		cout<<"\nStudent name: "<<ent -> name;
		cout<<"\nStudent standard: "<<ent -> std;
		cout<<"\nStudent marks percentage: "<<ent -> percent<<endl;
		ent = ent -> next;
	}
	cout<<"END";
}