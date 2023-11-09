/*
Assignment No.: 6.Threaded Binary Tree
***********************************************************************************

Problem Statement:Implement In-order Threaded Binary Tree and traverse it in In-
order and Pre-order.

***********************************************************************************
*/
#include<iostream>
using namespace std;
class node
{
public:
int data;
int lth,rth;
node *left,*right;
};
class thread
{
private:
node *dummy;
node *New,*root,*temp,*parent;
public:
thread();
void create();
void insert(node *,node *);
void display();
void find();
void delet();
void del(node *root,node *dummy,int key);
};
thread::thread()
{
root=NULL;
}
void thread::create()
{
New=new node;
New->left=NULL;
New->right=NULL;
New->lth=0;
New->rth=0;
cout<<"\nEnter The Element: ";
cin>>New->data;
if(root==NULL)

{
root=New;
dummy=new node;
dummy->data=-999;
dummy->left=root;
root->left=dummy;
root->right=dummy;
}
else
insert(root,New);
}
void thread::insert(node *root,node *New)
{
if(New->data<root->data)
{
if(root->lth==0)
{
New->left=root->left;
New->right=root;
root->left=New;
root->lth=1;
}
else
insert(root->left,New);
}
if(New->data>root->data)
{
if(root->rth==0)
{
New->right=root->right;
New->left=root;
root->rth=1;
root->right=New;
}
else
insert(root->right,New);
}
}
void thread::display()
{
void inorder(node*,node *dummy);
void preorder(node*,node *dummy);
if(root==NULL)
cout<<"Tree is not created";
else
{
cout<<"\nInorder Traversal...";
inorder(root,dummy);
cout<<"\nPreorder Traversal...";
preorder(root,dummy);
}

}
void inorder(node *temp,node *dummy)
{
while(temp!=dummy)
{
while(temp->lth==1)
temp=temp->left;
cout<<" "<<temp->data;
while(temp->rth==0)
{
temp=temp->right;
if(temp==dummy)
return;
cout<<" "<<temp->data;
}
temp=temp->right;
}
}
void preorder(node *temp,node *dummy)
{
int flag=0;
while(temp!=dummy)
{
if(flag==0)
cout<<" "<<temp->data;
if((temp->lth==1)&&(flag==0))
{
temp=temp->left;
}
else
{
while(1)
{
if(temp->rth==1)
{
flag=0;
temp=temp->right;
break;
}
else
{
if(temp!=dummy)
{
flag=1;
temp=temp->right;
break;
}
}
}
}

}
}
int main()
{
int choice,ans,cont;
thread th;
do
{
cout<<"\n\t Program For Threaded Binary Tree";
cout<<"\n1.Create \n2.Display\n";
cout<<"Select Operation: "<<endl;
cin>>choice;
switch(choice)
{
case 1:
do
{
th.create();
cout<<"\n Do u want to Enter more Elements?(1/0)"<<endl;
cin>>ans;
}while(ans==1);
break;
case 2:th.display();
break;
}
cout<<"\nEnter 0 to Exit & 1 Continue to Main menu.."<<endl;
cin>>cont;
}while(cont==1);
return 0;
}
/*
Program For Threaded Binary Tree
1.Create
2.Display
Select Operation:
1
Enter The Element: 42
Do u want to Enter more Elements?(1/0)
1
Enter The Element: 32
Do u want to Enter more Elements?(1/0)
1
Enter The Element: 65
Do u want to Enter more Elements?(1/0)
1
Enter The Element: 97
Do u want to Enter more Elements?(1/0)
1
Enter The Element: 25
Do u want to Enter more Elements?(1/0)
1
Enter The Element: 86
Do u want to Enter more Elements?(1/0)
0
Enter 0 to Exit & 1 Continue to Main menu..
1

Program For Threaded Binary Tree
1.Create
2.Display
Select Operation:
2
Inorder Traversal... 25 32 42 65 86 97
Preorder Traversal... 42 32 25 65 97 86
Enter 0 to Exit & 1 Continue to Main menu..*/