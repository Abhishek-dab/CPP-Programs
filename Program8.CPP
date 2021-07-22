#include<iostream.h>
#include<conio.h>
#include<stdio.h>

const int size = 5;

struct stud
{
	int roll;
	char name[32];
	int std;
	float percent;
};

void getdata(stud&);
int push(stud[], int&, stud);
void pop(int&);
void disp(stud[], int);

void main()
{
	clrscr();
	stud stack[size], s;
	int top = -1, res;
	char ch;
	cout<<"\t\t\tStatic Implementation of Stacks";
	cout<<"\nInserting elements in stack:\n";
	do
	{
		getdata(s);
		res = push(stack, top, s);
		if(res == -1)
		{
			cout<<"\nOverflow!";
			getch();
			return;
		}
		clrscr();
		cout<<"Stack now looks like this:-\n";
		disp(stack, top);
//		getch();
//		clrscr();
		cout<<"\n\nDo you want to continue?\n";
		cin>>ch;
	} while(ch == 'y' || ch == 'Y');

	clrscr();
	cout<<"Deleting elements in stack:\n";
	disp(stack, top);
	cout<<"\n\nDo you want to delete elements?\n";
	cin>>ch;

	if(ch == 'y' || ch == 'Y')
	{
		do
		{
			pop(top);
			clrscr();
			cout<<"Stack now looks like this:-\n";
			disp(stack, top);
			cout<<"\n\nDo you want to continue?\n";
			cin>>ch;
			cout<<endl;
		} while(ch == 'y' || ch == 'Y');
	}

	clrscr();
	cout<<"Bye! Bye!";
	getch();
}

void getdata(stud &s)
{
	cout<<"\nEnter student roll number: ";
	cin>>s.roll;
	cout<<"\nEnter student name: ";
	gets(s.name);
	cout<<"\nEnter student standard: ";
	cin>>s.std;
	cout<<"\nEnter student marks percentage: ";
	cin>>s.percent;
}
int push(stud s[], int &t, stud _)
{
	if(t == size - 1)
		return -1;
	else
	{
		t++;
		s[t] = _;
		return 0;
	}
}
void pop(int &t)
{
	if(t == -1)
		cout<<"\nUnderflow!";
	else
		t--;
}
void disp(stud s[], int t)
{
	if(t == -1)
		cout<<"\nEND";
	else
	{
		for(int i = t, j = 1; i >= 0; j++, i--)
		{
			cout<<"\nStudent "<<j<<" roll number: "<<s[i].roll;
			cout<<"\nStudent "<<j<<" name: "<<s[i].name;
			cout<<"\nStudent "<<j<<" standard: "<<s[i].std;
			cout<<"\nStudent "<<j<<" marks percentage: "<<s[i].percent<<endl;
		}
		cout<<"END";
	}
}