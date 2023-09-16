#include <stdio.h>
#include <stdlib.h>
#define MAX 5


//Push operation

void printst(int st[]
{})









// peek operation

int peek(int st[]){
    if (top == -1)
    {
        printf("stack is empty");
        return -1;

    }else{
        return st[top];
    }
}


int main()
{
    int value;
    do{
        printf("\n 1.PUSH");
        printf("\n 2.POP");
        printf("\n 3.PUSH");
        printf("\n 4.PRINT");
        printf("\n 5.EXIT");
        printf("\n Enter the option");
        scanf("&d", & option);
        switch (option)
        {
            case 1:
            printf("Enter the number to push");
            sacnf("%d", &val);
            push(stack,value);
            break;

            case 2:
            value = pop(stack);
            if (value != -1){
                printf("The value is deleted : %d", val);
            }
            break;

            case 3: // peek operation

            val = peek(stack);
            if (value != -1)
            {
                printf("The value is sirted at the top : %d", value)
            }

            break;
}           

            case 

    }
}