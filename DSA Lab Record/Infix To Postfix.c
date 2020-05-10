#include <stdio.h>
#include <stdlib.h>
 
void Push(char x);
char Pop();
int Priority(char x);
 
int top = -1;
char STACK[100];
void main() {
    char exp[100], *ele, x;
    printf("Enter the Infix expression: ");
    scanf("%s", exp);
    ele = exp;
    printf("The Postfix expression: ");
    while (*ele != '\0') {
        if (isalnum(*ele)) {
            printf("%c", *ele);
        }
        else if (*ele == '(') {
            Push(*ele);
        }
        else if (*ele == ')') {
            while ((x = Pop()) != '(') {
                printf("%c", x);
            }
        }
        else {
            while(Priority(STACK[top]) >= Priority(*ele)) {
                printf("%c", Pop());
            }
            Push(*ele);
        }
        ele++;
    }
    while(top != -1) {
        printf("%c", Pop());
    }
}
 
void Push(char x) {
    STACK[++top] = x;
}
 
char Pop() {
    if (top == -1) {
        return -1;
    }
    else{
        return STACK[top--];
    }
}
 
int Priority(char x) {
    if (x == '(') {
        return 0;
    }
    if (x == '+' || x == '-') {
        return 1;
    }
    if (x == '*' || x == '/') {
        return 2;
    }
}
