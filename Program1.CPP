#include<fstream.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

ifstream fin;
ofstream fout;

class Directory
{
	char Name[20], Address[30], AreaCode[5], PhoneNo[15];
	public :
	void Register();
	void Show();
	int checkCode(char AC[])
	{
		return strcmp(AreaCode, AC);
	}
	int checkPhoneNo(char PN[])
	{
		return strcmp(PhoneNo, PN);
	}
	char* getname()
	{
		return Name;
	}
}t, D;

void Crec();
void Drec();
void Arec();
void Mrec();

void main()
{
	clrscr();
	int op;
	menu :
	cout<<"\t\t\tMenu\n";
	cout<<"1.>Add Record\n";
	cout<<"2.>Delete Record\n";
	cout<<"3.>Modify Record\n";
	cin>>op;
	switch(op)
	{
		case 1 :	Arec();
				break;

		case 2 :	Drec();
				break;
		case 3 :	Mrec();
				break;
		default : 	cout<<"\nENTER VALID OPTION\n\n\n";
				system("pause");
				clrscr();
				goto menu;

	}
	getch();
}
void Directory :: Register()
{
	char wph[15];
	int f = 0;
	cout<<"Enter Name\n";
	gets(Name);
	cout<<"Enter Address\n";
	gets(Address);
	cout<<"Enter Area Code\n";
	gets(AreaCode);
	rnoe :
	f = 0;
	cout<<"Enter Phone No. wanted\n";
	fgets(wph, 11, stdin);
	Directory T;
	fin.open("Telephone.dat", ios::binary);
	while(fin)
	{
		fin.read( (char*)&T, sizeof(T));
		if(!strcmp(T.PhoneNo, wph))
		{
			f = 1;
			break;
		}
	}
	if(f == 1)
	{
		cout<<"This no. is not available\nEnter Another no. \n";
		goto rnoe;
	}
	strcpy(PhoneNo, wph);
	fin.close();
}
void Directory :: Show()
{
	cout<<"Phone no.\tName\tAddress\t\tArea Code\n";
	cout<<PhoneNo<<"\t"<<Name<<"\t"<<Address<<"\t\t"<<AreaCode;
}

void Crec()
{
	Directory T;
	fin.open("Telephone.dat", ios::binary);
	fout.open("Phone.dat", ios::binary, ios::app);
	while(fin)
	{
		fin.read( (char*)&T, sizeof(T));
		if(T.checkCode("23") == 0)
		{
			fout.write( (char*)&T, sizeof(T) );
		}
	}
	fin.close();
	fout.close();
}
void Arec()
{
	fin.open("Telephone.dat", ios::binary);
	fout.open("temp.dat", ios::binary | ios::app);
	int last = 0;
	t.Register();
	while(fin)
	{
		fin.read( (char*)&D, sizeof(D) );
		if(strcmpi(D.getname(), t.getname()) <= 0)
		{
			fout.write( (char*)&t, sizeof(t) );
			last = 1;
			break;
		}
		else
		fout.write( (char*)&t, sizeof(t) );

	}
	if(!last)
	fout.write( (char*)&t, sizeof(t) );
	else if(!fin.eof())
	{
		while(fin)
		{
			fout.write( (char*)&t, sizeof(t) );
			fin.read( (char*)&D, sizeof(D) );
		}
	}
	fout.close();
	fin.close();
	remove("Telephone.dat");
	rename("temp.dat", "Telephone.dat");
	Crec();
	cout<<"Registration Complete";
}

void Drec()
{
	char p[15];
	int f = 0;
	char yn;
	cout<<"Enter the Phone no. you want to Delete\n";
	gets(p);
	fin.open("Telephone.dat", ios::binary);
	fout.open("temp.dat", ios::binary | ios::app);
	while(!fin.eof())
	{
		fin.read( (char*) &t, sizeof(t));
		if(!t.checkPhoneNo(p))
		{
			f = 1;
			t.Show();
			cout<<"Are you sure you want to remove \nThis no. from Directory?\n";
			op :
			cin>>yn;
			if(yn == 'y' || yn == 'Y')
			continue;
			else if(yn == 'N' || yn == 'n')
			fout.write( (char*) &t, sizeof(t) );
			else
			{
				cout<<"Enter Valid option\n";
				goto op;
			}
		}
		fout.write( (char*) &t, sizeof(t) );
	}
	if(f == 0)
	cout<<"No Record found\n.";
	remove("Telephone.dat");
	rename("temp.dat", "Telephone.dat");
	fin.close();
	fout.close();
}
void Mrec()
{
	char Ar[5], Pn[15];
	fin.open("Telephone.dat", ios::binary);
	fout.open("Telephone.dat", ios::binary | ios::app);
	int op, pos, f = 0;
	cout<<"\t\t\t\tModify Menu\n1.>Area Code\n2.>Phone No.\n";
	vp :
	cin>>op;
	if(op == 1)
	{
		cout<<"Enter Area code : ";
		gets(Ar);
		while(fin)
		{
			pos = fin.tellg();
			fin.read( (char*)&t, sizeof(t) );
			if(t.checkCode(Ar) == 0)
			{
				fout.seekp(pos);
				D.Register();
				fout.write( (char*)&D, sizeof(D));
				f = 1;
				break;
			}
		}
		if(!f)
		{
			cout<<"No such Entry Found\n";
			return;
		}
	}
	else if(op == 2)
	{
		cout<<"Enter Phone number : ";
		gets(Pn);
		while(fin)
		{
			pos = fin.tellg();
			fin.read( (char*)&t, sizeof(t) );
			if(t.checkPhoneNo(Pn) == 0)
			{
				fout.seekp(pos);
				D.Register();
				fout.write( (char*)&D, sizeof(D));
				f = 1;
				break;
			}
		}
		if(!f)
		{
			cout<<"No such Entry Found\n";
			return;
		}

	}
	else
	{
		cout<<"Enter A Valid option(1 and 2 only)\n";
		goto vp;
	}
	fin.close();
}