//Program-for postfix to infix
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
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
void postfix_infix()
{
    Stack obj; int i;
    char op1[20],op2[20];
    char symbol[20],postfix[20];
    cout<<"Enter a postfix expression...";
    cin>>postfix;
    for(i=0;postfix[i]!='\0';i++)
    {
        char t1[20],t2[20];
        t1[0] = postfix[i];
        t1[1] = '\0';
        strcpy(symbol,t1);
        if(!isalpha(symbol[0]))
        {
            strcpy(op2,obj.pop());
            strcpy(op1,obj.pop());
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
int main()
{
    postfix_infix();
}
