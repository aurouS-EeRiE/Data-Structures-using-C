#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
void Push(char x);
char Pop();
void Prefix(char prefix[]);
void Postfix(char postfix[]);
 
int top = -1;
int STACK[100];
void main() {
    int choice;
    char exp[100];
    printf("\n1. Prefix \n2. Postfix \nEnter you choice: ");
    scanf("%d", &choice);
    if (choice == 1){
        printf("Enter the Prefix expression: ");
        scanf("%s", exp);
        Prefix(exp);
    }
    else if (choice == 2) {
        printf("Enter the Postfix expression: ");
        scanf("%s", exp);
        Postfix(exp);
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
 
void Prefix(char prefix[]) {
    int i, a, b, temp, result;
    printf("The evaluation Prefix expression: ");
    for (i = strlen(prefix) -1; i >= 0; i--) {
        if (prefix[i] <= '9' && prefix[i] >= '0') {
            Push(prefix[i] -48);
        }
        else {
            b = Pop();
            a = Pop();
            switch (prefix[i]){
                case '+': temp = b +a;
                    break;
                case '-': temp = b -a;
                    break;
                case '*': temp = b *a;
                    break;
                case '/': temp = b /a;
                    break;
                case '^': temp = pow(b, a);
            }
            Push(temp);
        }
    }
    printf("%d", Pop());
}
 
void Postfix(char postfix[]) {
    int i, a, b, temp, result;
    printf("The evaluation Postfix expression: ");
    for (i = 0; i < strlen(postfix); i--) {
        if (postfix[i] <= '9' && postfix[i] >= '0') {
            Push(postfix[i] -'0');
        }
        else {
            a = Pop();
            b = Pop();
            switch (postfix[i]){
                case '+': temp = b +a;
                    break;
                case '-': temp = b -a;
                    break;
                case '*': temp = b *a;
                    break;
                case '/': temp = b /a;
                    break;
                case '^': temp = pow(b, a);
            }
            Push(temp);
        }
    }
    printf("%d", Pop());
}
