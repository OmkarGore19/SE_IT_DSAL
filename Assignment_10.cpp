/*
Assignment No.: 10.FILE Handling
***********************************************************************************
Problem Statement: Department maintains student’s database. The file contains roll
number, name, division and address.
Write a program to create a sequential file to store and maintain student data. It
should allow the
user to add, delete information of student. Display information of particular
student. If record of
student does not exist an appropriate message is displayed. If student record is
found it should
display the student details.
***********************************************************************************
*/
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class file {
int roll;
float age;
char division;
char address[100];
char name[100];
public:
void input();
void show();
char * getn() {
return name;
}
};
file fileobj;
fstream fil;
void file::input() {
cout << "Enter the Roll No., Age, Address and Division:" << endl;
cin >> roll >> age >> address >> division;
cout << "Enter name:";
cin >> name;
}
void file::show() {
int i;
for (i = 0; i < 1; i++) {
cout << "\n";
cout << "\n" << "\t" << "Roll_no." << "\t" << "Name" << "\t" << "Age" << "\
t" << "Division" << "\t" << "Address" << endl;
cout << "\t" << roll << "\t" << name << "\t" << age << "\t" << division <<
"\t" << address << endl;
}
}
void Create() {
char ch = 'y';

fil.open("binary.dat", ios::out | ios::binary);
while (ch == 'y' || ch == 'Y') {
fileobj.input();
fil.write((char * ) & fileobj, sizeof(fileobj));
cout << "Want to Continue.....";
cin >> ch;
}
fil.close();
}
void Add() //Function to Add New Record in Data File
{
char ch = 'y';
fil.open("binary.dat", ios::out | ios::app | ios::binary);
while (ch == 'y' || ch == 'Y') {
fileobj.input();
fil.write((char * ) & fileobj, sizeof(fileobj));
cout << "Want to Continue.....";
cin >> ch;
}
fil.close();
}
void Display() //Function to Display All Record from Data File
{
fil.open("binary.dat", ios::in | ios::binary);
if (!fil) {
cout << "File not Found";
exit(0);
} else {
fil.read((char * ) & fileobj, sizeof(fileobj));
while (!fil.eof()) {
fileobj.show();
fil.read((char * ) & fileobj, sizeof(fileobj));
}
}
fil.close();
}
void DisplayP() //Function to Display particular Record from Data File
{
char n[100];
cout << "Enter Name that should be searched:";
cin >> n;
fil.open("binary.dat", ios::in | ios::binary);
if (!fil) {
cout << "File not Found";
exit(0);
} else {
fil.read((char * ) & fileobj, sizeof(fileobj));
while (!fil.eof()) {
if (strcmp(n, fileobj.getn()) == 0) {
fileobj.show();
fil.close();
return;
}
fil.read((char * ) & fileobj, sizeof(fileobj));
}
cout << "Record not found\n";
}
fil.close();
}

void Modify() //Function to Modify Particular Record from Data File
{
char n[100];
cout << "Enter name that should be searched:";
cin >> n;
fil.open("binary.dat", ios::in | ios::out | ios::binary);
if (!fil) {
cout << "File not Found";
exit(0);
} else {
fil.read((char * ) & fileobj, sizeof(fileobj));
while (!fil.eof()) {
if (strcmp(n, fileobj.getn()) == 0) {
fil.seekg(0, ios::cur);
cout << "Enter New Record.." << endl;
fileobj.input();
int p = fil.tellg();
int q = sizeof(fileobj);
fil.seekp(p - q);
fil.write((char * ) & fileobj, sizeof(fileobj));
fil.close();
return;
}
fil.read((char * ) & fileobj, sizeof(fileobj));
}
cout << "Record not found\n";
}
fil.close();
}
void Delete() //Function to Delete Particular Record from Data File
{
int flag = 0;
char n[100];
cout << "Enter roll no. that should be Deleted :";
cin >> n;
ofstream o;
o.open("new.dat", ios::out | ios::binary);
fil.open("binary.dat", ios::in | ios::binary);
if (!fil) {
cout << "File not Found";
exit(0);
} else {
fil.read((char * ) & fileobj, sizeof(fileobj));
while (!fil.eof()) {
if (strcmp(n, fileobj.getn()) != 0)
o.write((char * ) & fileobj, sizeof(fileobj));
else
flag = 1;
fil.read((char * ) & fileobj, sizeof(fileobj));
}
if (flag == 0)
cout << "Record not found\n";
}
o.close();
fil.close();
remove("binary.dat");
rename("new.dat", "binary.dat");
}
int main() {

int opt;
while (1) {
cout << "1.Create Data File" << endl;
cout << "2.Add New Record in Data File" << endl;
cout << "3.Display Record From Data File" << endl;
cout << "4.Display Particular Record From Data File" << endl;
cout << "5.Modify Paricular Record From Data File" << endl;
cout << "6.Delete Particular Record From Data File" << endl;
cout << "7.Exit From the Program" << endl;
cout << "Enter your Option : " << endl;
cin >> opt;
switch (opt) {
case 1:
Create();
cout << "Display Main Menu" << endl;
break;
case 2:
Add();
cout << "Display Main Menu" << endl;
break;
case 3:
Display();
cout << "Display Main Menu" << endl;
break;
case 4:
DisplayP();
cout << "Display Main Menu" << endl;
break;
case 5:
Modify();
cout << "Display Main Menu" << endl;
break;
case 6:
Delete();
cout << "Display Main Menu" << endl;
break;
case 7:
exit(0);
default:
cout << "Wrong Choice....Press Key For View the Main Menu";
}
}
}
/* Output
1.Create Data File
2.Add New Record in Data File
3.Display Record From Data File
4.Display Particular Record From Data File
5.Modify Paricular Record From Data File
6.Delete Particular Record From Data File
7.Exit From the Program
Enter your Option :
1
Enter the roll, Age,Address and Division:25025
18
Pune
A
Enter name:Omkar
Want to Continue.....1

Display Main Menu
1.Create Data File
2.Add New Record in Data File
3.Display Record From Data File
4.Display Particular Record From Data File
5.Modify Paricular Record From Data File
6.Delete Particular Record From Data File
7.Exit From the Program
Enter your Option :
2
Enter the roll, Age,Address and Division:25080
19
Mumbai
A
Enter name:Ajay
Want to Continue.....1
Display Main Menu
1.Create Data File
2.Add New Record in Data File
3.Display Record From Data File
4.Display Particular Record From Data File
5.Modify Paricular Record From Data File
6.Delete Particular Record From Data File
7.Exit From the Program
Enter your Option :
2
Enter the roll, Age,Address and Division:25081
19
Pune
A
Enter name:Mayur
Want to Continue.....1
Display Main Menu
1.Create Data File
2.Add New Record in Data File
3.Display Record From Data File
4.Display Particular Record From Data File
5.Modify Paricular Record From Data File
6.Delete Particular Record From Data File
7.Exit From the Program
Enter your Option :
3
Roll_no. Name Age Division Address
25025 Omkar 18 A Pune
Roll_no. Name Age Division Address
25080 Ajay 19 A Mumbai
Roll_no. Name Age Division Address
25081 Mayur 19 A Pune
Display Main Menu
1.Create Data File
2.Add New Record in Data File
3.Display Record From Data File
4.Display Particular Record From Data File
5.Modify Paricular Record From Data File
6.Delete Particular Record From Data File
7.Exit From the Program
Enter your Option :
4
Enter Name that should be searched:Omkar

Roll_no. Name Age Division Address
25025 Omkar 18 A Pune
Display Main Menu
1.Create Data File
2.Add New Record in Data File
3.Display Record From Data File
4.Display Particular Record From Data File
5.Modify Paricular Record From Data File
6.Delete Particular Record From Data File
7.Exit From the Program
Enter your Option :
5
Enter name that should be searched:Ajay
Enter New Record..
Enter the roll, Age,Address and Division:25020
19
Pune
A
Enter name:Adesh
Display Main Menu
1.Create Data File
2.Add New Record in Data File
3.Display Record From Data File
4.Display Particular Record From Data File
5.Modify Paricular Record From Data File
6.Delete Particular Record From Data File
7.Exit From the Program
Enter your Option :
6
Enter roll no. that should be Deleted :25081
Record not found
Display Main Menu
1.Create Data File
2.Add New Record in Data File
3.Display Record From Data File
4.Display Particular Record From Data File
5.Modify Paricular Record From Data File
6.Delete Particular Record From Data File
7.Exit From the Program
Enter your Option :
7
--------------------------------
*/