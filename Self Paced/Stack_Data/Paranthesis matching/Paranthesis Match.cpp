#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;



struct Node
{
    char data;
    struct Node *next;
}*top=NULL;


void push(char x)
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));

    if (t==NULL)
        printf("Stack is full\n");
    else{
        t->data=x;
        t->next=top;
        top=t;
    }

}


char pop()
{
    struct Node *t;
    char

}


int main()
{

}


