#include<iostream>
using namespace std;

class Node{

public:
    int data;
    Node *next;
    void make_list();
    void insertBefore();
    void insertAfter();
    void deletee();
    void traverse();
    void Reverse();
    void Sort();
    void deleteAlternate();
    void insertInSorted();
};

Node * first=NULL;

void Node::make_list()
{


    cout<<"Enter the element: ";
    Node * temp=new Node;
    cin>>temp->data;
    temp->next=NULL;
    if(first==NULL)
  {
    first =temp;
  }
    else
  {
    Node *curr;
    for(curr=first;curr->next!=NULL;curr=curr->next);
    curr->next=temp;
  }


}

void Node::insertBefore()
{
    Node *temp=new Node;
    cout<<"enter the element you wanna enter: "<<endl;
    cin>>temp->data;
    cout<<"enter the element before which you want to enter this element: "<<endl;
    int before;
    cin>>before;
    int flag=0;
    if(first->data==before)
    {
        temp->next=first;
        first=temp;
        flag=1;
    }
    else
    {
        Node *temp1;
        Node *curr;
        for(curr=first;curr->data!=before;curr=curr->next)
        {
            temp1=curr;
        }
        if(curr->data==before)
        {
            flag=1;
            temp1->next=temp;
            temp->next=curr;
        }
    }
    if(flag==0)cout<<"Elemnt not found."<<endl;

}


void Node::insertAfter()
{
    Node *temp=new Node();
    cout<<"enter the element you want to enter: "<<endl;
    cin>>temp->data;
    cout<<"enter the element after which you would like to enter: ";
    int element;
    cin>>element;
    Node *curr;
    int flag=0;
    for(curr=first;curr->data!=element;curr=curr->next);
    if(curr->data==element)
    {
        temp->next=curr->next;
        curr->next=temp;
        flag=1;
    }
    if(flag==0)cout<<"Element not found"<<endl;
}

void Node::deletee()
{
    cout<<"Enter the element you want to delete: "<<endl;
    int ele;
    cin>>ele;
    Node *temp;
    int flag=0;
    if(first->data==ele)
    {

        temp=first;
        first=first->next;
        delete temp;
        flag=1;
    }
    else
    {
        Node *curr;
        for(curr=first;curr->data!=ele;curr=curr->next)
        {
            temp=curr;
        }
        if(curr->data==ele)
        {
            temp->next=curr->next;
            delete curr;
            flag =1;
        }

        if(flag==0)cout<<"element not found"<<endl;
    }
}

void Node::traverse()
{
    Node *curr;
    for(curr=first;curr->next!=NULL;curr=curr->next)
        cout<<curr->data<<"\t";
    cout<<curr->data;

}

void Node::Reverse()
{
    int count=1;
    Node *curr0;
    for(curr0=first;curr0->next!=NULL;curr0=curr0->next)
        count++;

    Node * ret=new Node;
    Node * curr=first;
    ret->data=curr->data;
    curr=curr->next;
    ret->next=NULL;
    for(int i=1;i<count;i++)
    {
        Node *temp=new Node();
        temp->data=curr->data;
        curr=curr->next;
        temp->next=ret;
        ret=temp;
    }

    first->data=ret->data;
    Node *curr1=first->next;
    ret=ret->next;
    for(int i=1;i<count;i++)
    {
        curr1->data=ret->data;
        curr1=curr1->next;
        ret=ret->next;
    }
}

void Node::Sort()
{
Node * temp1;
Node * temp2;
int temp;
for(temp1=first;temp1->next!=NULL;temp1=temp1->next)
{
    for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
    {
        if(temp1->data>temp2->data)
        {
            temp=temp1->data;
            temp1->data=temp2->data;
            temp2->data=temp;
        }
    }
}

}

 void Node::deleteAlternate()
 {
     Node * temp;
     Node*temp1;
     Node * curr;
     int count=0;
     for(curr=first;curr!=NULL;curr=curr->next)
        count++;
     if(count%2==0)
     {
     for(temp=first;temp!=NULL;temp=temp->next)
     {
        temp1=temp->next;
        temp->next=temp1->next;
        delete temp1;
     }
     }
     else
     for(temp=first;temp->next!=NULL;temp=temp->next)
     {
        temp1=temp->next;
        temp->next=temp1->next;
        delete temp1;
     }

 }
 void Node::insertInSorted()
 {

     cout<<"Enter the element you want to enter ";
     Node * temp=new Node;
     int element;
     cin>>temp->data;
     element=temp->data;
     Node *temp1;
     Node * curr;
     int flag=0;
     if(element<first->data)
     {
         temp->next=first;
         first=temp;
         flag=1;
     }
     else
     {
         for(curr=first;curr!=NULL;curr=curr->next)
         {
             if(curr->data>element)
             {
                 temp->next=temp1->next;
                 temp1->next=temp;
                 flag=1;
                 break;
             }
             temp1=curr;
         }
     }
     if(flag==0)
     {
        for(curr=first->next;curr->next!=NULL;curr=curr->next);
        curr->next=temp;
        temp->next=NULL;

     }



 }






int main()
{
    Node n1;

    cout<<"Enter the number of elements you want in your list: "<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
       n1.make_list();
    }
    cout<<"What would you like to do today? "<<endl;


    while(1){
    cout<<" 1)Insert before an element"<<endl;
    cout<<" 2)Insert After an element"<<endl;
    cout<<" 3)Delete an element"<<endl;
    cout<<" 4) Traverse"<<endl;
    cout<<" 5)Reverse the list"<<endl;
    cout<<" 6)Sort the list"<<endl;
    cout<<" 7) delete Alternate Node"<<endl;

    int response;
    cin>>response;

    switch(response)
    {
    case 1:
        n1.insertBefore();
        break;
    case 2:
        n1.insertAfter();
        break;
    case 3:
        n1.deletee();
        break;
    case 4:
        n1.traverse();
        break;
    case 5:
        n1.Reverse();
        break;
    case 6:
        n1.Sort();
        break;
    case 7:
        n1.deleteAlternate();
        break;
    case 8:
        n1.Sort();
        n1.insertInSorted();
        break;
    }

    cout<<"\n Do you want to continue(y/n)?"<<endl;
    char ch;
    cin>>ch;
    if(ch=='y')continue;
    else break;
    }

}




