#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include<bits/stdc++.h>
using namespace std;

const int MAX=50;
class Stack
{
    int top;
    char s[MAX][MAX];
    public:
     Stack(){ top = -1;}
     void push(char []);
     char* pop();
};
void Stack::push(char operand[])
{
    top++;
    strcpy(s[top],operand);
}
char* Stack::pop()
{
    if(top == -1)
        return "X";
    else
        return s[top--];
}
int main()
{
    Stack obj; int i;
    char op1[20],op2[20];
    char symbol[20];
    string prefix,postfix;
    cout<<"Enter a prefix expression...";
    cin>>prefix;

    reverse(prefix.begin(),prefix.end());
  //  strcpy(postfix,prefix);
    for(i=0;prefix[i]!='\0';i++)
    {
        char t1[20],t2[20];
        t1[0] = prefix[i];
        t1[1] = '\0';
        strcpy(symbol,t1);
        if(!isalpha(symbol[0]))
        {
            strcpy(op1,obj.pop());
            strcpy(op2,obj.pop());
            strcpy(t2, "(");
            strcat(t2,op1);
            strcat(t2,symbol);
            strcat(t2,op2);
            strcat(t2,")");
            obj.push(t2);
        }
        else
        {
            obj.push(t1);
        }
    }
    cout<<"Equivalent infix expression: "<<obj.pop();
}
