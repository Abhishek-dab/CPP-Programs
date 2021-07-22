#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

const int size = 5;

struct emp
{
	int empno;
	char empname[32], designation[32];
	float salary;
}e[size];

void getdata(emp&);
void I(emp[], emp, int&, int&);
void D(int&, int&);
void disp(emp[], int, int);

void main()
{
	clrscr();
	emp loyee;
	int front = -1, rear = -1;
	char ch;
	cout<<"\t\t\tStatic Implementation of Linear Queues";
	cout<<"\n\nInsertion of elements in Queue:\n";
	do
	{
		getdata(loyee);
		I(e, loyee, front, rear);
		clrscr();
		cout<<"Queue now looks like this:-\n";
		disp(e, front, rear);
		cout<<"\n\nDo you want to continue?\n";
		cin>>ch;
		clrscr();
	} while(ch == 'y' || ch == 'Y');

	clrscr();
	cout<<"Deleting elements from the queue:-\n";
	disp(e, front, rear);
	cout<<"\n\nDo you want to delete elements from the queue?\n";
	cin>>ch;
	if(ch == 'y' || ch == 'Y')
	{
		do
		{
			D(front, rear);
			clrscr();
			cout<<"Queue now looks like this:-\n";
			disp(e, front, rear);
			cout<<"\n\nDo you want to continue to delete elements from queue?\n";
			cin>>ch;
		} while(ch == 'y' || ch == 'Y');
	}
	clrscr();
	cout<<"Bye! Bye!";
	getch();
}

void getdata(emp &loyee)
{
	cout<<"\nEnter employee number: ";
	cin>>loyee.empno;
	cout<<"\nEnter employee name: ";
	gets(loyee.empname);
	cout<<"\nEnter employee designation: ";
	gets(loyee.designation);
	cout<<"\nEnter employee salary: ";
	cin>>loyee.salary;
}
void I(emp empl[], emp oyee, int &f, int &r)
{
	if(r == (size - 1))
	{
		cout<<"\nOverflow!";
		getch();
	}
	else if(r == -1)
	{
		f = r = 0;
		empl[r] = oyee;
	}
	else
	{
		r++;
		empl[r] = oyee;
	}
}
void D(int &f, int &r)
{
	if(f == -1)
		cout<<"\nUnderflow!";
	else if(f == r)
		f = r = -1;
	else
		f++;
}
void disp(emp em[], int f, int r)
{
	if(f == -1)
		cout<<"\nUnderflow!";
	else
	{
		for(int i = f; i <= r; i++)
		{
			cout<<"\nEmployee number: "<<em[i].empno;
			cout<<"\nEmployee name: "<<em[i].empname;
			cout<<"\nEmployee designation: "<<em[i].designation;
			cout<<"\nEmployee salary: "<<em[i].salary<<endl;
		}
		cout<<"END";
	}
}