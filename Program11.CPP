#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct emp
{
	char empname[10], desg[10];
	int empno, salary;
	emp *next;
}*front, *rear, *newptr, *ptr, *save;

emp* CNN(int, int, char[], char[]);
void Ins(emp*);
void Remove();
void Disp(emp*);

void main()
{
	int op, eno, sal;
	char en[10], dsg[10];
	rear = front = newptr= NULL;
	do
	{
		cout<<"\t\t\t\tMain Menu\n";
		cout<<"1.> Insert\n";
		cout<<"2.> Remove\n";
		cout<<"3.> Display Queue\n";
		cout<<"4.> Exit\n";
		cin>>op;
		switch(op)
		{
			case 1:		cout<<"Enter Employee Name(max 10 characters)\n";
					gets(en);
					cout<<"Enter Employee no.\n";
					cin>>eno;
					cout<<"Enter  Salary\n";
					cin>>sal;
					cout<<"Enter Employee Desg(max 10 characters)\n";
					gets(dsg);
					newptr = CNN(eno, sal, en, dsg);
					if(newptr == NULL)
					{
						cerr<<"Cannot Create Node\n";
						system("pause");
						return;
					}
					Ins(newptr);
					break;
			case 2:         cout<<"Removing\n";
					Remove();
					break;
			case 3:		cout<<"Displaying Queue\n";
					Disp(front);
					break;
			case 4:		break;
			default:	cout<<"Enter Valid Option\n";
					system("pause");
		}
		getch();
	}while(op != 4);
}

emp* CNN(int eno, int sal, char en[10], char dsg[10])
{
	ptr = new emp;
	ptr->empno = eno;
	ptr->salary = sal;
	strcpy(ptr->empname, en);
	strcpy(ptr->desg, dsg);
	return ptr;
}
void Ins(emp *np)
{
	if(np)
	{
		if(front == NULL)
		{
			rear = front = np;
			np->next = NULL;
		}
		else
		{
			rear->next = np;
			rear = np;
		}
	}
	else cout<<"Under Flow";
}
void Remove()
{
	save = front;
	front = front->next;
	delete save;
}

void Disp(emp *np)
{
	while(np != NULL)
	{
		cout<<"\nEmployee Number: "<<np->empno;
		cout<<"\nSalary: "<<np->salary;
		cout<<"\nName: "<<np->empname;
		cout<<"\nDesignatio: "<<np->desg;
		np = np->next;
	}
}
