# CPP-Programs

### Program 1:

Given a binary file Telephone.dat, containing records of the following class Directory:

```
class Directory
{ char Name[20];	  
  char Address[30];
  char AreaCode[5]; 
  char PhoneNo[15];
public:
  void Register();
  void Show();	
  int checkCode(char AC[]){
    return strcmp(AreaCode, AC);	
  }
};
```
Write functions for the following:

* To copy all the records from Telephone.dat to phone.dat where AreaCode=23
* To delete a particular record based on phone number.
* To add a record. ( The Data is sorted in ascending order of name.)
* To modify a particular record. Search by AreaCode and phone number.

### Program 2:
 Write a program to enter data in a dynamic array. The program should keep reading the numbers and inserting in the array. Stop when the user enters -1.
