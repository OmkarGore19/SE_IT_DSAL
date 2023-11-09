/*
Assignment No.: 3.Circular Queue
***********************************************************************************
Problem Statement: Implement Circular Queue using Array. Perform following
operations on it.
a) Insertion (Enqueue)
b) Deletion (Dequeue)
c) Display
(Note: Handle queue full condition by considering a fixed size of a queue.)
***********************************************************************************
*/ 
  
#include <iostream>
  using namespace std;

int cqueue[5];

int front = -1, rear = -1, n = 5;

void
insertCQ (int val) 
{
  
if ((front == 0 && rear == n - 1) || (front == rear + 1))
    
    {
      
cout << "Queue Overflow" << endl;
      
return;
    
}
  
if (front == -1)
    
    {
      
front = 0;
      
rear = 0;
    
}
  
  else
    
    {
      
if (rear == n - 1)
	
rear = 0;
      
      else
	
rear = rear + 1;
    
}
  
cqueue[rear] = val;

}


void
deleteCQ () 
{
  
if (front == -1)
    
    {
      
cout << "Queue Underflow";
      
return;
    
}
  
cout << "Element deleted from queue is : " << cqueue[front] << endl;
  
if (front == rear)
    
    {
      
front = -1;
      
 
rear = -1;
    
}
  
  else
    
    {
      
if (front == n - 1)
	
	{
	  
front = 0;
	
}
      
      else
	
	{
	  
front = front + 1;
	
}
    
}

}


void
displayCQ () 
{
  
int f = front, r = rear;
  
if (front == -1)
    
    {
      
cout << "Queue is empty" << endl;
      
return;
    
}
  
cout << "Queue elements are :";
  
if (f <= r)
    
    {
      
while (f <= r)
	
	{
	  
cout << cqueue[f] << " ";
	  
f++;
	
}
    
}
  
  else
    
    {
      
while (f <= n - 1)
	
	{
	  
cout << cqueue[f] << " ";
	  
f++;
	
}
      
f = 0;
      
while (f <= r)
	
	{
	  
cout << cqueue[f] << " ";
	  
f++;
	
}
    
}
  
cout << endl;

}


int
main () 
{
  
int ch, val;
  
cout << "1)Insert" << endl;
  
cout << "2)Delete" << endl;
  
cout << "3)Display" << endl;
  
cout << "4)Exit" << endl;
  
  do
    {
      
cout << "Select the Operation : " << endl;
      
cin >> ch;
      
 
switch (ch)
	
	{
	
case 1:
	  
cout << "Input for Insertion: " << endl;
	  
cin >> val;
	  
insertCQ (val);
	  
break;
	
case 2:
	  
deleteCQ ();
	  
break;
	
case 3:
	  
displayCQ ();
	  
break;
	
case 4:
	  
cout << "Exit";
	  
break;
	
default:
	  cout << "Enter Valid Input!!" << endl;
	
}
    
}
  while (ch != 4);
  
return 0;

}


/*
/tmp/1k9e8oUW7l.o
1)Insert
2)Delete
3)Display
4)Exit
Select the Operation :
1
Input for Insertion:
21
Select the Operation :
1
Input for Insertion:
55
Select the Operation :
1
Input for Insertion:
82
Select the Operation :
1
Input for Insertion:
32
Select the Operation :
1
Input for Insertion:
98
Select the Operation :
1
Input for Insertion:
58
Queue Overflow
Select the Operation :
3
Queue elements are :21 55 82 32 98
Select the Operation :
2
Element deleted from queue is : 21

Select the Operation :
2
Element deleted from queue is : 55
Select the Operation :
2
Element deleted from queue is : 82
Select the Operation :
2
Element deleted from queue is : 32
Select the Operation :
2
Element deleted from queue is : 98
Select the Operation :
3
Queue is empty
Select the Operation :
4
Exit
*/
