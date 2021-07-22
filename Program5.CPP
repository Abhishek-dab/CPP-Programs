#include<iostream.h>
#include<conio.h>

void main()
{
	clrscr();
	char *names[] = {"Anand", "Naureen", "Banjot", "Wahid", "Sheena"};
	char *t;
	cout<<"Current Order of Names\n";
	for(int i = 0; i<5; i++)
	{
		cout<<names[i]<<endl;
	}
	for(i = 0; i<3; i++)
	{
		t = names[i];
		names[i] = names[4-i];
		names[4-i] = t;
	}
	cout<<"The Strings are Reversed\n";
	for(i = 0; i<5; i++)
	{
		cout<<names[i]<<endl;
	}
	getch();
}