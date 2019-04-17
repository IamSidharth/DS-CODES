#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node * next;
    void create();
    void traverse();
    void swap();
};
Node *first=NULL;

void Node::create()
{
    Node * temp=new Node;
    cin>>temp->data;
    temp->next=NULL;
    if(first==NULL)
        first=temp;
    else
    {
        Node * curr;
        for(curr=first;curr->next!=NULL;curr=curr->next);
        curr->next=temp;
    }
}

void Node::traverse()
{
    Node *curr;
    for(curr=first;curr!=NULL;curr=curr->next)
        cout<<curr->data;
}

void Node::swap()
{
    Node * curr;
    int count=0;
    for(curr=first;curr!=NULL;curr=curr->next)
        count++;

     Node * temp1;
     Node * temp2;
     curr=first;
     int flag=0;

    for(int i=0;i<count/2;i++)
    {
        temp1=curr;
        temp2=curr->next;
        temp1->next=temp2->next;
        temp2->next=temp1;
        if(flag==0)
        {
            first=temp2;
            flag=1;
        }
        else
        {
            Node * yeah;
            for(yeah=first;yeah->next!=curr;yeah=yeah->next);
            yeah->next=temp2;

        }
        curr=curr->next;
    }
}
int main()
{
    Node n1;
    n1.create();
    n1.create();
    n1.create();
    n1.create();
    n1.create();
    n1.create();
    n1.traverse();
    n1.swap();
    n1.traverse();


}
