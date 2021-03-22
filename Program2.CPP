#include<iostream.h>
#include<conio.h>

void main()
{
	clrscr();
	int *ptr, num, i = 0;
	cout<<"\nEnter the numbers to store in the array.\nIf you wish to stop, enter the next number as \"-1\" (without quotes).\n";
	while(*ptr != -1)
	{
		ptr++;
		cout<<"\nElement number "<<++i<<": ";
		cin>>*ptr;
	}
	cout<<"\nHere's what the array contain:\n";
	i--;
	num = i;
	while(i > 0)
		ptr--, i--;
	i++;
	while(i <= num)
	{
		cout<<*ptr<<"\t";
		ptr++, i++;
	}
	getch();
}