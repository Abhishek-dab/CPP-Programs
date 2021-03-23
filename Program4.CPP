#include<iostream.h>
#include<conio.h>
#include<stdio.h>

void compare(char*, char*);
void copy(char*, char*, int);
void concat(char*, char*);
void reversal(char*);

void main()
{
	clrscr();
	int op, ch;
	char ptr[50], ptr1[50], ptr2[50];
Menu:
	cout<<"\t\t\t\tMain Menu";
	cout<<"\n\n1. String Comparison.\n2. String Copy.\n3. String concatenation.\n4. String Reversal.\n5. Exit";
	cout<<"\n\nWhat do you want to do?\n";
	cin>>op;
	switch(op)
	{
		case 1: cout<<"\nEnter a string: ";
			gets(ptr1);
			cout<<"\nEnter another string: ";
			gets(ptr2);
			compare(ptr1, ptr2);
			break;
		case 2: cout<<"\nEnter a string to be copied: ";
			gets(ptr);
			cout<<"\nTo which string should it be copied?";
			cout<<"\n1. "<<ptr1<<"\n2. "<<ptr2<<endl;
			cin>>ch;
			if(ch == 1)
			{
				copy(ptr, ptr1, 50);
			}
			else if(ch == 2)
			{
				copy(ptr, ptr2, 50);
			}
			break;
		case 3:	cout<<"\nChoose the string to be concatenated:\n1. "<<ptr1<<"\n2. "<<ptr2<<endl;
			cin>>ch;
			cout<<"\nWhat must be concatenated?";
			gets(ptr);
			if(ch == 1)
			{
				concat(ptr1, ptr);
				cout<<"\nThis is your concatenated string:\n"<<ptr1;
			}
			else if(ch == 2)
			{
				concat(ptr2, ptr);
				cout<<"\nThis is your concatenated string:\n"<<ptr2;
			}
			break;
		case 4: cout<<"\nWhich string must be reversed?\n1. "<<ptr1<<"\n2. "<<ptr2<<endl;
			cin>>ch;
			if(ch == 1)
			{
				reversal(ptr1);
			}
			else if(ch == 2)
			{
				reversal(ptr2);
			}
			break;
		case 5: return;
		default:cout<<"\nInvalid option. Enter a valid one!";
	}
	getch();
	clrscr();
	goto Menu;
}
void compare(char *ptr1, char *ptr2)
{
	int i = 0, len = 0, c = 0;
	while(*ptr1 != '\0' || *ptr2 != '\0')
	{
		if(*ptr1 == *ptr2 || (*ptr1 + 32) == *ptr2 || (*ptr1 - 32) == *ptr2)
			i++;
		ptr1++, ptr2++, c++;
	}
	len = c;
	if(i == 0)
	{
		cout<<"\nStrings are completely different!";
	}
	else if(i == len)
		cout<<"\nStrings are identical!";
	else
		cout<<"\nString have a difference of "<<len - i<<" characters.";
}
void copy(char *source, char *destination, int size)
{
	while(size > 0)
	{
		*destination = *source;
		size--, destination++, source++;
	}
	cout<<"\nString copied.\nHere's your string: ";
	cout<<destination;
}
void concat(char *ptr1, char *ptr2)
{
	while(*ptr1 != '\0')
		ptr1++;
	while(*ptr2 != '\0')
	{
		*ptr1 = *ptr2;
		ptr1++, ptr2++;
	}
}
void reversal(char *ptr1)
{
	char *ptr2;
	int i = 0, len = 0;
	while(*ptr1 != '\0')
	{
		ptr1++, i++;
	}
	len = i;
	while(i >= 0)
	{
		*ptr2 = *ptr1;
		ptr1--, ptr2++, i--;
	}
	while(i < len - 1)
	{
		ptr2--, i++;
	}
	cout<<"\nThis is your reversed string: "<<ptr2;
	}