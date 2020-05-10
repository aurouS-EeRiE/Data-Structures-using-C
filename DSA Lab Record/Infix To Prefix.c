#include <stdio.h>
#include <stdlib.h>
 
void Push(char x);
char Pop();
void Push_Prefix(char x);
char Pop_Prefix();
int Priority(char x);
 
int top = -1, TOP = -1;
char STACK[100], PREFIX[100];
void main() {
    int i, j;
    char exp[100], rev_exp[100], *ele, x;
    printf("Enter the Infix expression: ");
    scanf("%s", exp);
    for (i = strlen(exp) - 1, j = 0; i + 1 != 0; i--, j++) {
        if (exp[i] == '(') {
            rev_exp[j] = ')';
        }
        else if (exp[i] == ')') {
            rev_exp[j] = '(';
        }
        else {
            rev_exp[j] = exp[i];
        }
    }
    ele = rev_exp;
    printf("The Prefix expression: ");
    while (*ele != '\0') {
        if (isalnum(*ele)) {
            Push_Prefix(*ele);
        }
        else if (*ele == '(') {
            Push(*ele);
        }
        else if (*ele == ')') {
            while ((x = Pop()) != '(') {
                Push_Prefix(x);
            }
        }
        else {
            while(Priority(STACK[top]) >= Priority(*ele)) {
                Push_Prefix(Pop());
            }
            Push(*ele);
        }
        ele++;
    }
    while(top != -1) {
        Push_Prefix(Pop());
    }
    while (TOP != -1) {
        printf("%c", Pop_Prefix());
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
    if(x == '^') {
        return 3;
    }
}
 
void Push_Prefix(char x) {
    PREFIX[++TOP] = x;
}
char Pop_Prefix() {
    return PREFIX[TOP--];
}
