#include<iostream.h>
#include<conio.h>
#include<stdio.h>

class Salesman
{
	char name[11];
	float q1, q2, q3, q4, tot;
	public :
	void getdata()
	{
		cout<<"Enter Name\n";
		gets(name);
		cout<<"Enter quaterly Sales\n";
		cin>>q1>>q2>>q3>>q4;
	}
	float gettot()
	{
		return tot;
	}
	Salesman* max(Salesman *s)           //Function 2
	{       if(!s)
		{
			s = this;
		}
		else
		{
			float f1, f2;
			f1 = s->tot;
			f2 = this->tot;
			if(f1<f2)
			s = this;
		}
		return s;
	}
	void calctot()                      //Function 1
	{
		tot = q1 + q2 + q3 + q4;
	}
	char* getname()
	{
		return name;
	}
} *sp;

void printit(Salesman*); //Funtion 3

void main()
{
	clrscr();
	Salesman S[4];
	sp = &S[0];
	for(int i= 0; i<4; i++)
	{
		S[i].getdata();
		S[i].calctot();
		sp = S[i].max(sp);
	}
	printit(sp);
	getch();
}

void printit(Salesman *s)
{
	cout<<"\nSalesman with Maximum Sales\n";
	cout<<"Name : "<<s->getname()<<"\nTotal Sales : "<<s->gettot()<<endl;

}