/*
Assignment No.: 1.Searching and Sorting
***********************************************************************************
Problem Statement:Consider a student database of SEIT class (at least 15 records).
Database contains different fields of
every student like Roll No, Name and SGPA.(array of structure)
a) Design a roll call list, arrange list of students according to roll numbers in
ascending order (Use
Bubble Sort)
b) Arrange list of students alphabetically. (Use Insertion sort)
c) Arrange list of students to find out first ten toppers from a class. (Use Quick
sort)
d) Search students according to SGPA. If more than one student having same SGPA,
then print list
of all students having same SGPA.
e) Search a particular student according to name using binary search without
recursion. (all the student records having the presence of search key should be
displayed)
(Note: Implement either Bubble sort or Insertion Sort.)
***********************************************************************************
*/ 
  
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

struct studentinfo
{
  
int rollno;
   
char name[25];
   
float sgpa;
 
};

//display Information
  void
display (struct studentinfo s[], int n)
{
  
cout << left << setw (10) << "Sr.No." << left << setw (10) << "Roll No." <<
    left << setw (20) << "Name" << left << setw (10) << "SGPA" << endl;
  
for (int y = 0; y < n; y++)
    
    {
      
cout << left << setw (10) << (y +
				     1) << left << setw (10) << s[y].
	rollno << left << setw (20) << s[y].
	name 
 <<left << setw (10) << s[y].sgpa << endl;

} 
} 

//display sorting sgpa using quick sort
  void
sortingSGPA_view (struct studentinfo s[], int n)
{
  
cout << left << setw (10) << "Sr.No." << left << setw (10) << "Roll No." <<
    left << setw (20) << "Name" << left << setw (10) << "SGPA" << endl;
  
 
for (int i = 0; i < 10; i++)
    
    {
      
cout << left << setw (10) << (i +
				     1) << left << setw (10) << s[i].
	rollno << left << setw (20) << s[i].
	name 
 <<left << setw (10) << s[i].sgpa << endl;

} 
} 

//sorting Roll No. using bubble sort
  void
bsort_rollno (struct studentinfo s[], int n) 
{
  
for (int i = 0; i < n; i++)
    
    {
      
for (int j = 0; j < n - 1; j++)
	
	{
	  
if ((s[j].rollno) > (s[j + 1].rollno))
	    
	    {
	      
struct studentinfo temp;
	      
temp = s[j];
	      
s[j] = s[j + 1];
	      
s[j + 1] = temp;
	    
}

} 
} 
} 

//sorting name using insertion sort
  void
sortingName (struct studentinfo s[], int n) 
{
  
char key[25];
  
for (int i = 1; i < n; i++)
    
    {
      
strcpy (key, s[i].name);
      
int j = i - 1;
      
while (j >= 0 && strcmp (s[j].name, key) > 0)
	
	{
	  
struct studentinfo temp;
	  
temp = s[j];
	  
s[j] = s[j + 1];
	  
s[j + 1] = temp;
	  
j = j - 1;
	
} 
strcpy (s[j + 1].name, key);

} 
} 

//sorting sgpa using quick sort
  void
sortingSGPA (struct studentinfo s[], int n, int first, int last) 
{
  
int i, j, pivot;
  
struct studentinfo temp;
  
pivot = i = first;
  
j = last;
  
if (first < last)
    
    {
      
while (i < j)
	
	{
	  
 
while (s[i].sgpa >= s[pivot].sgpa && i < last)
	    
	    {
	      
i++;
	    
}
	  
while (s[j].sgpa < s[pivot].sgpa)
	    
	    {
	      
j--;
	    
}
	  
if (i < j)
	    
	    {
	      
temp = s[i];
	      
s[i] = s[j];
	      
s[j] = temp;
	    
}
	
}
      
temp = s[j];
      
s[j] = s[pivot];
      
s[pivot] = temp;
      
sortingSGPA (s, n, first, j - 1);
      
sortingSGPA (s, n, j + 1, last);
    
}

}


//Searching sgpa using linear serach
  void
LS_sgpa (struct studentinfo s[], int n) 
{
  
int t = 1;
  
float key;
  
cout << "\nPlease Enter The SGPA You Want To Find: ";
  
cin >> key;
  
cout << "\n" << "Details of Student with SGPA " << key << endl;
  
cout << left << setw (10) << "Sr.No." << left << setw (10) << "Roll No." <<
    left << setw (20) << "Name" << left << setw (10) << "SGPA" << endl;
  
for (int l = 0; l < n; l++)
    
    {
      
if (s[l].sgpa == key)
	
	{
	  
cout << left << setw (10) << (l +
					 1) << left << setw (10) << s[l].
	    rollno << left << setw (20) << s[l].
	    name 
 <<left << setw (10) << s[l].sgpa << endl;
	  
t++;
	  
continue;
	
}
    
}
  
if (t == 1)
    
    {
      
cout << "\nSTUDENT WITH SGPA '" << key << "' NOT FOUND.\n";
    
}

}


//Searching name using binary serach
  int
searchStudentName (struct studentinfo s[], int n) 
{
  
sortingName (s, n);
  
int low = 0;
  
int high = n - 1;
  
char search[25];
  
 
cout << "\nEnter the name you want to find : \n";
  
cin >> search;
  
cout << endl;
  
while (low <= high)
    
    {
      
int mid = (low + high) / 2;
      
if (strcmp (search, s[mid].name) == 0)
	
	{
	  
return mid;
	
}
      
if (strcmp (search, s[mid].name) > 0)
	
	{
	  
low = mid + 1;
	
}
      
if (strcmp (search, s[mid].name) < 0)
	
	{
	  
high = mid - 1;
	
}
    
}
  
return -1;

}


//display Searching name using binary serach
  void
displaySearchName (struct studentinfo s[], int n) 
{
  
int x = searchStudentName (s, n);
  
if (x == -1)
    
    {
      
cout << "*****MATCH NOT FOUND*****\n\n";
    
}
  
  else
    
    {
      
cout << left << setw (10) << "Sr.No." << left << setw (10) <<
	"Roll No." << left << setw (20) << "Name" << left << setw (10) <<
	"SGPA" << endl;
      
cout << left << setw (10) << (1) << left << setw (10) << s[x].
	rollno << left << setw (20) << s[x].
	name << 
left << setw (10) << s[x].sgpa << endl;
    
}

}


int
main ()
{
  
struct studentinfo s[15];
  
int n = 15;
  
int i = 0;
  
for (int i = 0; i < n; i++)
    
    {
      
cout << "Enter Roll No Of Student: \n";
      
cin >> s[i].rollno;
      
cout << "Enter Name Of Student: \n";
      
cin >> s[i].name;
      
cout << "Enter SGPA Of Student: \n";
      
cin >> s[i].sgpa;
    
};
  
int choice, cont;
  
  do
    {
      
cout <<
	"Select The Option: \n1.Display The Student Data.\n2.To Arrange List of Students According to Roll Numbers.\n3.To Arrange list of students alphabetically.\n4.Arrange list of students to find out first ten toppers from a class.\n5.Search students according to SGPA.\n6.Search a particular student according to name.\n";
      
cout << "\nYour Choice: ";
      
cin >> choice;
      
switch (choice)
	{
	
case 1:
	  
	  {
	    
cout << "\
n------------------------------------------------------";
	    
cout << "\nSTUDENT DATA \
n------------------------------------------------------\n";
	    
display (s, n);
	    
break;
	  
}
	
case 2:
	  
	  {
	    
cout << "\
n------------------------------------------------------";
	    
cout <<
	      "\nSORTING STUDENT ACCORDING TO ROLL NUMBER(BUBBLE SORT)\
n------------------------------------------------------\n";
	    
bsort_rollno (s, n);
	    
display (s, n);
	    
break;
	  
}
	
case 3:
	  
	  {
	    
cout << "\
n------------------------------------------------------";
	    
cout << "\nSORTING STUDENT ACCORDING TO NAME(INSERTION SORT)\
n------------------------------------------------------\n";
	    
sortingName (s, n);
	    
display (s, n);
	    
break;
	  
}
	
case 4:
	  
	  {
	    
cout << "\
n------------------------------------------------------";
	    
cout << "\nSORTING STUDENT ACCORDING TO SGPA(QUICK SORT)\
n------------------------------------------------------\n";
	    
sortingSGPA (s, n, 0, n - 1);
	    
sortingSGPA_view (s, n);
	    
break;
	  
}
	
case 5:
	  
	  {
	    
cout << "\
n------------------------------------------------------";
	    
cout << "\nSEARCHING IN SGPA (LINEAR SEARCH)\
n-----------------------------------------------";
	    
LS_sgpa (s, n);
	    
break;
	  
}
	
case 6:
	  
	  {
	    
 
cout << "\
n------------------------------------------------------";
	    
cout << "\nSEARCHING IN NAME (BINARY SEARCH)\
n------------------------------------------------------\n";
	    
displaySearchName (s, n);
	    
break;
	  
}
	
}
      
cout << "\nPlease Enter 0 to Exit Or Enter 1 to Continue\n";
      
cin >> cont;
    
}
  while (cont == 1);
  
if (cont == 0)
    {
      
cout << "\n\nThank You!!";
    
}
  
return 0;

}


//OUTPUT
/*
Enter Roll No Of Student:
1908
Enter Name Of Student:
Tanmay
Enter SGPA Of Student:
9.55
Enter Roll No Of Student:
1913
Enter Name Of Student:
Kedar
Enter SGPA Of Student:
8.45
Enter Roll No Of Student:
1927
Enter Name Of Student:
Kaustubh
Enter SGPA Of Student:
8.35
Enter Roll No Of Student:
1944
Enter Name Of Student:
Prajwal
Enter SGPA Of Student:
9.02
Enter Roll No Of Student:
1920
Enter Name Of Student:
Adesh
Enter SGPA Of Student:
8.85
Enter Roll No Of Student:
1915
Enter Name Of Student:
Chaitanya
Enter SGPA Of Student:
8.89
Enter Roll No Of Student:

1923
Enter Name Of Student:
Sahil
Enter SGPA Of Student:
7.21
Enter Roll No Of Student:
1969
Enter Name Of Student:
Yash
Enter SGPA Of Student:
8.13
Enter Roll No Of Student:
1925
Enter Name Of Student:
Omkar
Enter SGPA Of Student:
9.16
Enter Roll No Of Student:
1932
Enter Name Of Student:
Sidhesh
Enter SGPA Of Student:
8.45
Enter Roll No Of Student:
1935
Enter Name Of Student:
Pratik
Enter SGPA Of Student:
8.47
Enter Roll No Of Student:
1948
Enter Name Of Student:
Vaibhav
Enter SGPA Of Student:
9.16
Enter Roll No Of Student:
1924
Enter Name Of Student:
Govind
Enter SGPA Of Student:
8.04
Enter Roll No Of Student:
1955
Enter Name Of Student:
Prem
Enter SGPA Of Student:
9.01
Enter Roll No Of Student:
1967
Enter Name Of Student:
Suresh
Enter SGPA Of Student:
8.34
Select The Option:
1.Display The Student Data.
2.To Arrange List of Students According to Roll Numbers.
3.To Arrange list of students alphabetically.
4.Arrange list of students to find out first ten toppers from a class.
5.Search students according to SGPA.

6.Search a particular student according to name.
Your Choice: 1
------------------------------------------------------
STUDENT DATA
------------------------------------------------------
Sr.No. Roll No. Name SGPA
1 1908 Tanmay 9.55
2 1913 Kedar 8.45
3 1927 Kaustubh 8.35
4 1944 Prajwal 9.02
5 1920 Adesh 8.85
6 1915 Chaitanya 8.89
7 1923 Sahil 7.21
8 1969 Yash 8.13
9 1925 Omkar 9.16
10 1932 Sidhesh 8.45
11 1935 Pratik 8.47
12 1948 Vaibhav 9.16
13 1924 Govind 8.04
14 1955 Prem 9.01
15 1967 Suresh 8.34
Please Enter 0 to Exit Or Enter 1 to Continue
1
Select The Option:
1.Display The Student Data.
2.To Arrange List of Students According to Roll Numbers.
3.To Arrange list of students alphabetically.
4.Arrange list of students to find out first ten toppers from a class.
5.Search students according to SGPA.
6.Search a particular student according to name.
Your Choice: 2
------------------------------------------------------
SORTING STUDENT ACCORDING TO ROLL NUMBER(BUBBLE SORT)
------------------------------------------------------
Sr.No. Roll No. Name SGPA
1 1908 Tanmay 9.55
2 1913 Kedar 8.45
3 1915 Chaitanya 8.89
4 1920 Adesh 8.85
5 1923 Sahil 7.21
6 1924 Govind 8.04
7 1925 Omkar 9.16
8 1927 Kaustubh 8.35
9 1932 Sidhesh 8.45
10 1935 Pratik 8.47
11 1944 Prajwal 9.02
12 1948 Vaibhav 9.16
13 1955 Prem 9.01
14 1967 Suresh 8.34
15 1969 Yash 8.13
Please Enter 0 to Exit Or Enter 1 to Continue
1
Select The Option:

1.Display The Student Data.
2.To Arrange List of Students According to Roll Numbers.
3.To Arrange list of students alphabetically.
4.Arrange list of students to find out first ten toppers from a class.
5.Search students according to SGPA.
6.Search a particular student according to name.
Your Choice: 3
------------------------------------------------------
SORTING STUDENT ACCORDING TO NAME(INSERTION SORT)
------------------------------------------------------
Sr.No. Roll No. Name SGPA
1 1920 Adesh 8.85
2 1915 Chaitanya 8.89
3 1924 Govind 8.04
4 1927 Kaustubh 8.35
5 1913 Kedar 8.45
6 1925 Omkar 9.16
7 1944 Prajwal 9.02
8 1935 Pratik 8.47
9 1955 Prem 9.01
10 1923 Sahil 7.21
11 1932 Sidhesh 8.45
12 1967 Suresh 8.34
13 1908 Tanmay 9.55
14 1948 Vaibhav 9.16
15 1969 Yash 8.13
Please Enter 0 to Exit Or Enter 1 to Continue
1
Select The Option:
1.Display The Student Data.
2.To Arrange List of Students According to Roll Numbers.
3.To Arrange list of students alphabetically.
4.Arrange list of students to find out first ten toppers from a class.
5.Search students according to SGPA.
6.Search a particular student according to name.
Your Choice: 4
------------------------------------------------------
SORTING STUDENT ACCORDING TO SGPA(QUICK SORT)
------------------------------------------------------
Sr.No. Roll No. Name SGPA
1 1908 Tanmay 9.55
2 1948 Vaibhav 9.16
3 1925 Omkar 9.16
4 1944 Prajwal 9.02
5 1955 Prem 9.01
6 1915 Chaitanya 8.89
7 1920 Adesh 8.85
8 1935 Pratik 8.47
9 1932 Sidhesh 8.45
10 1913 Kedar 8.45
Please Enter 0 to Exit Or Enter 1 to Continue
1
Select The Option:

1.Display The Student Data.
2.To Arrange List of Students According to Roll Numbers.
3.To Arrange list of students alphabetically.
4.Arrange list of students to find out first ten toppers from a class.
5.Search students according to SGPA.
6.Search a particular student according to name.
Your Choice: 5
------------------------------------------------------
SEARCHING IN SGPA (LINEAR SEARCH)
-----------------------------------------------
Please Enter The SGPA You Want To Find: 9.16
Details of Student with SGPA 9.16
Sr.No. Roll No. Name SGPA
2 1948 Vaibhav 9.16
3 1925 Omkar 9.16
Please Enter 0 to Exit Or Enter 1 to Continue
1
Select The Option:
1.Display The Student Data.
2.To Arrange List of Students According to Roll Numbers.
3.To Arrange list of students alphabetically.
4.Arrange list of students to find out first ten toppers from a class.
5.Search students according to SGPA.
6.Search a particular student according to name.
Your Choice: 5
------------------------------------------------------
SEARCHING IN SGPA (LINEAR SEARCH)
-----------------------------------------------
Please Enter The SGPA You Want To Find: 6.23
Details of Student with SGPA 6.23
Sr.No. Roll No. Name SGPA
STUDENT WITH SGPA '6.23' NOT FOUND.
Please Enter 0 to Exit Or Enter 1 to Continue
1
Select The Option:
1.Display The Student Data.
2.To Arrange List of Students According to Roll Numbers.
3.To Arrange list of students alphabetically.
4.Arrange list of students to find out first ten toppers from a class.
5.Search students according to SGPA.
6.Search a particular student according to name.
Your Choice: 6
------------------------------------------------------
SEARCHING IN NAME (BINARY SEARCH)
------------------------------------------------------
Enter the name you want to find :
Suresh

Sr.No. Roll No. Name SGPA
1 1967 Suresh 8.34
Please Enter 0 to Exit Or Enter 1 to Continue
1
Select The Option:
1.Display The Student Data.
2.To Arrange List of Students According to Roll Numbers.
3.To Arrange list of students alphabetically.
4.Arrange list of students to find out first ten toppers from a class.
5.Search students according to SGPA.
6.Search a particular student according to name.
Your Choice: 6
------------------------------------------------------
SEARCHING IN NAME (BINARY SEARCH)
------------------------------------------------------
Enter the name you want to find :
Dinesh
*****MATCH NOT FOUND*****
Please Enter 0 to Exit Or Enter 1 to Continue
0
Thank You!!
*/
