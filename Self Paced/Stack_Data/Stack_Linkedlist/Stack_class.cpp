#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};


class stack
{
    private:
        Node *top;
    public:
        stack(){top=NULL;}
        void push(int x);
        int pop();
        void Display();
};

void stack::push(int x)
{
    Node *t=new Node;
    if(t==NULL)
        cout<<"Stack is full\n";
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }

}

int stack::pop()
{

    int x=-1;
    if(top==NULL)
        cout<<"Stack is Empty \n";
    else
    {
        x=top->data;
        Node *t=top;
        top=top->next;
        delete t;
    }
    return x;
}

void stack::Display()
{
    Node *p=top;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main()
{
    stack stk;

    stk.push(10);
    stk.push(20);
    stk.push(30);



    stk.Display();
    cout<<stk.pop();

}