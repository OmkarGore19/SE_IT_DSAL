/*
Assignment No.: 2.Implementation of Stack
***********************************************************************************
Problem Statement: Write a program to implement stack as an abstract data type
using linked list and use this ADT for conversion of infix expression to postfix,
prefix and evaluation of postfix/prefix expression.
***********************************************************************************
*/
#include <iostream>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;
typedef struct node
{
char data;
node *next;
} node;
node *top = NULL;
int priority(char x)
{
if (x == '+' || x == '-')
{
return 1;
}
else if (x == '*' || x == '/')
{
return 2;
}
else if (x == '^')
{
return 3;
}
else
{
return -1;
}
}
void push(char x)
{
node *ptr = (node *)malloc(sizeof(node));
ptr->data = x;
ptr->next = top;
top = ptr;
}

char pop()
{
if (top == NULL)
{
return 0;
}
else
{
node *ptr = top;
char temp = ptr->data;
top = top->next;
free(ptr);
return temp;
}
}
string infix_to_postfix(string s)
{
string postfix = "";
char x;
for (int i = 0; i < s.length(); i++)
{
if (isalnum(s[i]))
{
postfix += s[i];
}
else if (s[i] == '(')
{
push(s[i]);
}
else if (s[i] == ')')
{
while (top->data != '(')
{
postfix += pop();
}
x = pop();
}
else
{
while (top != NULL && priority(s[i]) <= priority(top->data))
{
postfix += pop();
}
push(s[i]);
}
}
while (top != NULL)
{
postfix += pop();
}
return postfix;
}
string infix_to_prefix(string s)

{
string prefix;
reverse(s.begin(), s.end());
for (int i = 0; i < s.length(); i++)
{
if (s[i] == '(')
{
s[i] = ')';
}
else if (s[i] == ')')
{
s[i] = '(';
}
}
prefix = infix_to_postfix(s);
reverse(prefix.begin(), prefix.end());
return prefix;
}
int postfix_eval(string s)
{
int op1, op2;
stack<int> stack;
for (int i = 0; i < s.length(); i++)
{
if (isdigit(s[i]))
{
stack.push(s[i] - '0');
}
else
{
op1 = stack.top();
stack.pop();
op2 = stack.top();
stack.pop();
switch (s[i])
{
case '+':
stack.push(op2 + op1);
break;
case '-':
stack.push(op2 - op1);
break;
case '*':
stack.push(op2 * op1);
break;
case '/':
stack.push(op2 / op1);
break;
case '^':
stack.push(pow(op2, op1));
break;

}
}
}
return stack.top();
}
int prefix_eval(string s)
{
reverse(s.begin(), s.end());
int result = postfix_eval(s);
return result;
}
int main()
{
string infix;
int next, choice1, choice2, temp = 0;
while (true)
{
cout << "Enter the infix expression" << endl;
cin >> infix;
cout << "What do you wish to do?\n"
<< "1. Convert entered expression to Postfix\n"
<< "2. Convert entered expression to Prefix"
<< endl;
cin >> choice1;
switch (choice1)
{
case 1:
cout << "The postfix conversion of " << infix << " is : " <<
infix_to_postfix(infix) << endl;
break;
case 2:
cout << "The prefix conversion of " << infix << " is : " <<
infix_to_prefix(infix) << endl;
break;
default:
cout << "INVALID CHOICE!!" << endl;
break;
}
cout << "Do you wish to evaluate the converted expression?\n1. Yes\n2. No"
<< endl;
cin >> choice2;
if (choice2 == 1)
{
for (int i = 0; i < infix.length(); i++)
{
if (isdigit(infix[i]))
{
temp++;
break;
}
}
if (temp == 0)
{
cout << "Cannot evaluate the string as it contains alphabets..." <<
endl;

}
else
{
switch (choice1)
{
case 1:
cout << "Value of the expression : " <<
postfix_eval(infix_to_postfix(infix)) << endl;
break;
case 2:
cout << "Value of the expression : " <<
prefix_eval(infix_to_prefix(infix)) << endl;
break;
}
}
}
cout << "PRESS 0 TO EXIT & PRESS 1 TO RETURN TO MENU" << endl;
cin >> next;
if (next != 1)
{
cout << "Thank You!!!";
break;
}
}
return 0;
}
/*
/tmp/3qBZuj76XA.o
Enter the infix expression
(a+b)*c
What do you wish to do?
1. Convert entered expression to Postfix
2. Convert entered expression to Prefix
1
The postfix conversion of (a+b)*c is : ab+c*
Do you wish to evaluate the converted expression?
1. Yes
2. No
2
PRESS 0 TO EXIT & PRESS 1 TO RETURN TO MENU
1
Enter the infix expression
(a+b)*c
What do you wish to do?
1. Convert entered expression to Postfix
2. Convert entered expression to Prefix
2
The prefix conversion of (a+b)*c is : *+abc
Do you wish to evaluate the converted expression?
1. Yes
2. No
2
PRESS 0 TO EXIT & PRESS 1 TO RETURN TO MENU
1
Enter the infix expression
5*2+3
What do you wish to do?

1. Convert entered expression to Postfix
2. Convert entered expression to Prefix
1
The postfix conversion of 5*2+3 is : 52*3+
Do you wish to evaluate the converted expression?
1. Yes
2. No
1
Value of the expression : 13
PRESS 0 TO EXIT & PRESS 1 TO RETURN TO MENU
1
Enter the infix expression
5*2+3
What do you wish to do?
1. Convert entered expression to Postfix
2. Convert entered expression to Prefix
2
The prefix conversion of 5*2+3 is : +*523
Do you wish to evaluate the converted expression?
1. Yes
2. No
1
Value of the expression : 13
PRESS 0 TO EXIT & PRESS 1 TO RETURN TO MENU
0
Thank You!!!
*/