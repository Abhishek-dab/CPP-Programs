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

### Program 3:
Write a C++ program to perform the following operations using user defined functions and pointers.
* String Comparison
* String Copy
* String concatenation 
* String Reversal (Do not use library functions)

### Program 4:
Write a program to accept the quarterly sales for the entire year of 5 salesman. Make a function to display the details of the salesman who has made the maximum total sales using pointers. Define appropriate functions for:
* calculating total sales 
* finding max_sales 
* printing details of salesman

### Program 5:
Suppose 5 names are stored in an array of pointers names[] as below:
```
char *names[]={“Anand”, “Naureen”, “Banjot”, “Wahid”, “Sheena”};
```
Write a program to reverse the order of these names.

### Program 6:
Write a C++ program to perform Merging of two arrays A and B into a third array C. Each
record in the array should contain record of employees in the following manner.
```
struct employee
{ 
int empno; float sal; char desig[10]; 
}; 
```

The data in array A is in ascending order of the salary, array B is in descending order and the
resultant array C should contain the data in descending order.

### Program 7:
Write a menu driven C++ program to depict the insertion (at both beginning and end) and
deletion in linked list using structures.

### Program 8:
Write a C++ program to show static implementation of Stack that contains student information
like roll no, name, std and percentage.

### Program 9:
Write a C++ program to show the dynamic implementation of Stack that contains student
information like roll no, name, std and percentage.

### Program 10:
Write a C++ program to show the static implementation of Linear Queue that contains
employees information like empno, empname, designation and salary.

### Program 11:
Write a C++ program to show the dynamic implementation of Linear Queue that contains
employees information like empno,empname, designation and salary.
