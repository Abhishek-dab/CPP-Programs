#include<iostream.h>
#include<conio.h>
#include<stdio.h>

struct employee
{
	int empno;
	float sal;
	char desig[10];
}A[50], B[50], C[100];

void main()
{
	clrscr();
	int a, b, c, i, j, k;
	cout<<"Enter A Size : ";
	cin>>a;
	cout<<"Enter A Elements : \n";
	for(i = 0; i<a; i++)
	{
		cout<<"Enter Emp No.\n";
		cin>>A[i].empno;
		cout<<"Enter Salary\n";
		cin>>A[i].sal;
		cout<<"Enter Desg\n";
		gets(A[i].desig);
	}
	cout<<"Enter B Size : ";
	cin>>b;
	cout<<"Enter B Elements : \n";
	for(i = 0; i<b; i++)
	{
		cout<<"Enter Emp No.\n";
		cin>>B[i].empno;
		cout<<"Enter Salary\n";
		cin>>B[i].sal;
		cout<<"Enter Desg\n";
		gets(B[i].desig);
	}
	c = a+b;
	for(i = (a-1), j = 0, k = 0; i>=0 && j<b;)
	{
		if(A[i].sal>B[j].sal)
		{
			C[k++] = A[i--];
		}
		else
		{
			C[k++] = B[j++];
		}
	}
	if(i>=0)
	{
		while(i<a)
		{
			C[k++] = A[i--];
		}
	}
	else if(j<b)
	{
		while(j<b)
		{
			C[k++] = B[j++];
		}
	}

	cout<<"The Merged Arary looks like\n\n";
	cout<<"Emp No.\tSalary\tDesignation\n\n";
	for(k = 0; k<c; k++)
	{
		cout<<C[i].empno<<"\t"<<C[i].sal<<"\t"<<C[i].desig<<endl;
	}
	getch();
}