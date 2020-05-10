#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10
void push(char);
void pop();
void display();
int top = -1;
char stack[SIZE];
void main()
{
    int choice;
    char value;
    while(1)
    {
        printf("\n\n*** MENU ***\n");
        printf("1. Push \n2. Pop \n3. Display \n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch(choice)
        {
            case 1: printf("Enter the value to be insert: ");
                value = getchar();
                push(value);
                break;
            case 2: pop();
                break;
            case 3: display();
                break;
            case 4: exit(0);
                default: printf("\nWrong selection!!! Try again!!!");
        }
    }
}
void push(char value){
    if(top == SIZE-1)
    {
        printf("\nStack is Full!!! Insertion is not possible!!!");
    }    
    else
    {
        top++;
        stack[top] = value;
        printf("\nInsertion success!!!");
    }
}
void pop(){
    if(top == -1)
    {
        printf("\nStack is Empty!!! Deletion is not possible!!!");
    }
    else{
        printf("\nDeleted : %c", stack[top]);
        top--;
    }
}
void display(){
    if(top == -1)
    {
        printf("\nStack is Empty!!!");
    }
    else
    {
        int i;
        printf("\nStack elements are:\n");
        for(i = top; i >= 0; i--)
        printf("%c ", stack[i]);
    }
}
