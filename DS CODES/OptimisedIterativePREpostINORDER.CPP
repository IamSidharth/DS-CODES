//BINARY TREE IMPLEMENTATION
#include<iostream>
#include<string.h>
using namespace std;


class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;

    void create(int data);
    void inorder(Node * curr);
    void postorder(Node * curr);
    void preorder(Node *curr);
    Node* parentof(Node* curr,int x,Node *prev);
    int depth(Node *ptr);
    void ancestors(int ele);
    void leafNodes(Node * curr);
};
Node * root=NULL;

void Node::create(int x)
{
    Node *temp=new Node;
    temp->data=x;
    temp->lchild=temp->rchild=NULL;
    if(root==NULL)
        root=temp;
    else{
        cout<<"Enter direction string: ";
        char str[20];
        cin>>str;
        Node *curr;
        Node *prev;
        int i=0;
        for(curr=root;curr!=NULL,i<strlen(str);i++)
        {
            prev=curr;
            if(str[i]=='l')
                curr=curr->lchild;
            else if(str[i]=='r')
                curr=curr->rchild;
        }
        if(curr!=NULL||i!=strlen(str))
        {
            cout<<"not poosible";
            return;
        }
        if(str[i-1]=='l')
        {
            prev->lchild=temp;
        }
        if(str[i-1]=='r')
        {
            prev->rchild=temp;
        }
    }
}

 void Node::inorder(Node * curr)
 {
     //for recurssive
     /*
     if(curr==NULL)
        return;

    inorder(curr->lchild);
    cout<<curr->data<<" ";
    inorder(curr->rchild);  */

    Node *s[20];int top=-1;
	if(root==NULL)
	{
		cout<<"Empty Tree\n";return;
	}
	curr=root;
	for(;;)
	{
		while(curr!=NULL)
		{
			s[++top]=curr;
			curr=curr->lchild;
		}
		if(top!=-1)
		{
			curr=s[top--];
			cout<<curr->data;
			curr=curr->rchild;
		}
		else
		{
			cout<<endl;
			return;
		}
	}



 }
 void Node::postorder(Node * curr)
 {
     /*
     if(curr==NULL)
        return;

     postorder(curr->lchild);
     postorder(curr->rchild);
     cout<<curr->data;  */

    Node *s[20];int top=-1;
	if(root==NULL)
	{
		cout<<"Empty Tree\n";return;
	}
	curr=root;
	do
	{
		while(curr!=NULL)
		{
			if(curr->rchild!=NULL)
				s[++top]=curr->rchild;
			s[++top]=curr;
			curr=curr->lchild;
		}
		curr=s[top--];
		if(curr->rchild!=NULL&&curr->rchild==s[top])
		{
			top--;
			s[++top]=curr;
			curr=curr->rchild;
		}
		else
		{
			cout<<curr->data;
			curr=NULL;
		}
	}while(top!=-1);
 }
 void Node::preorder(Node * curr)
 {
     /*
     if(curr==NULL)
        return;

     cout<<curr->data;
     preorder(curr->lchild);
     preorder(curr->rchild);
     */

     Node *s[20];int top=-1;
	if(root==NULL)
	{
		cout<<"Empty Tree\n";return;
	}
	curr=root;
	for(;;)
	{
		while(curr!=NULL)
		{
			cout<<curr->data;
			s[++top]=curr;
			curr=curr->lchild;
		}
		if(top!=-1)
		{
			curr=s[top--];
			curr=curr->rchild;
		}
		else
			{
				cout<<endl;
				return;
			}
	}
 }
 Node* Node::parentof(Node* curr,int x,Node *prev)
 {


if(curr!=NULL)
{
parentof(curr->lchild, x, curr);
if(x==curr->data)
{
cout<<"\n parent : "<<prev->data;
return prev;
}
parentof(curr->rchild, x , curr);
}
 }


 int Node::depth(Node *ptr)
{
int ldepth,rdepth;
if(ptr==NULL) return 0;
else
{ ldepth=depth(ptr->lchild);
rdepth=depth(ptr->rchild);
if(ldepth>rdepth) return ldepth+1;
else return rdepth+1;
}
}

void Node::ancestors(int ele)
{
Node *p;
cout<<ele;
p=parentof(root, ele, root);
while(1)
{
p=parentof(root, p->data, root);
if(p==root) break;
}

}
int count=0;

 void Node::leafNodes(Node * curr)
 {
   if(curr==NULL)
        return ;

    leafNodes(curr->lchild);
    if(curr->lchild==NULL&&curr->rchild==NULL)
    {
        count++;
        return;
    }
    leafNodes(curr->rchild);
 }



 int main()
 {
     Node n1;
     n1.create(1);
     n1.create(2);
     n1.create(3);

     n1.postorder(root);
     n1.parentof(root,5,root);
     cout<<n1.depth(root);
     n1.leafNodes(root);
     cout<<"leaf"<<count;



 }

