#include<iostream.h>
#include<conio.h>

struct some
{
	int thing;
	some *next;
}*ptr, *newptr, *start, *rear;

some* CNN(int);
void IB(some*);
void IR(some*);
void DB();
void Disp(some*);

void main()
{
	clrscr();
	int st, op;
	start = rear = newptr = NULL;
Menu:
	cout<<"\t\t\t\tMenu";
	cout<<"\n\n1.Insert in the beginning.\n2.Insert in the end.\n3.Delete from the beginning.\n4.Display from beginning.\n5.Exit.";
	cout<<"\n\nWhat do you want to do?\n";
	cin>>op;
	clrscr();
	switch(op)
	{
		case 1: cout<<"\tInsertion from the beginning of the linked list.";
			cout<<"\n\nEnter element content: ";
			cin>>st;
			newptr = CNN(st);
			if(newptr == NULL)
			{
				cout<<"\nCannot create new node! Overflow!";
				getch();
				return;
			}
			IB(newptr);
			cout<<"\nElement inserted at the beginning of the list.";
			break;
		case 2: cout<<"\tInsertion from the end of the linked list.";
			cout<<"\n\nEnter element content: ";
			cin>>st;
			newptr = CNN(st);
			if(newptr == NULL)
			{
				cout<<"\nCannot create new node! Overflow!";
				getch();
				return;
			}
			IR(newptr);
			cout<<"\nElement inserted at the end of the list.";
			break;
		case 3: cout<<"\tDeletion from the beginning of the linked list.";
			DB();
			break;
		case 4: cout<<"\tDisplaying the contents of the linked list from the beginning.\n";
			Disp(start);
			break;
		case 5: cout<<"Bye! Bye!";
			return;
		default:cout<<"Invalid Option! Enter a valid one!";
	}
	getch();
	clrscr();
	goto Menu;
}

some* CNN(int Int)
{
	ptr = new some;
	ptr -> thing = Int;
	ptr -> next = NULL;
	return ptr;
}

void IB(some *b)
{
	if(start == NULL)
		start = rear = b;
	else
	{
		b -> next = start;
		start = b;
	}
}

void IR(some *r)
{
	if(start == NULL)
		start = rear = r;
	else
	{
		rear -> next = r;
		rear = r;
	}
}

void DB()
{
	if(start == NULL)
		cout<<"\n\nUnderflow!";
	else
	{
		ptr = start;
		start = start -> next;
		delete ptr;
		cout<<"\n\nElement Deleted!";
	}
}

void Disp(some *s)
{
	while(s != NULL)
	{
		cout<<s -> thing<<endl;
		s = s -> next;
	}
	cout<<"END";
}