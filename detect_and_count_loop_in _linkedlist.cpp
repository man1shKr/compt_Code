#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *head =NULL;
node *link;
node *start;
void insert(int newdata)
{
    node *temp=head;
    node *newnode=new node;
    newnode->data=newdata;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    if(newdata==2)
    {
       link=newnode; 
    }
}
void display()
{
    node *temp1=head;
    while(temp1!=NULL)
    {
        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
}
void createloop()
{
    node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=link;
}
bool detectloop()
{
    node *temp=head;
    unordered_set<node *> s;
    while(temp!=NULL)
    {
    	
    	// If we have already has this node
        // in hashmap it means their is a cycle
        // (Because you we encountering the
        // node second time).
    	
        if(s.find(temp)!=s.end())
        {
            start=temp;
            return true;
        }
        else
        {
        	// If we are seeing the node for
        // the first time, insert it in hash
            s.insert(temp);
            temp=temp->next;
        }
    }
    if(temp==NULL)
    return false;
}
int count()
{
    int c=1;
    node *t=start->next;
    while(t!=start)
    {
        c++;
        t=t->next;
    }
    return c;
}
int main() {
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	display();
	loop();
	cout<<endl;
	bool x=detectloop();
	if(x==true)
	cout<<"loop exists";
	else
	cout<<"loop doesnot exists";
	int z=count();
	cout<<endl;
	cout<<"length of loop is: "<<z<<endl;
	return 0;
}
