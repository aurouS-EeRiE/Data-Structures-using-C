#include <stdio.h>
#include <stdlib.h>
 
typedef struct node {
    int data;
    struct node * next;
}node;
 
node * CreateNode(int n);
void SearchNode(node * head, int search);
 
int main(void) {
    int n, choice, search;
    printf("Enter how many nodes: ");
    scanf("%d", &n);
    node * HEAD = NULL;
    HEAD = CreateNode(n);
    
    while(1)
    {
        printf("\n\n*** MENU ***\n");
        printf("1. Search an element \n2. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch(choice)
        {
            case 1: printf("Enter an element to search in the Linked List: ");
                scanf("%d", &search);
                SearchNode(HEAD, search);
                break;
            case 2: exit(0);
            default: printf("\nWrong selection!!! Try again!!!");
        }
    }
    return 0;
}
 
node * CreateNode(int n) {
    node * head = NULL;
    node * temp = NULL;
    node * nodes = NULL;
    for (int i = 1; i <= n; i++) {
        temp = (node *)malloc(sizeof(node));
        printf("Enter the data for the node %d: ", i);
        scanf("%d", &temp->data);
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
        }
        else {
            nodes = head;
            while (nodes->next != NULL) {
                nodes = nodes->next;
            }
            nodes->next = temp;
        }
    }
    return head;
}
 
void SearchNode(node * head, int search) {
    node * nodes = head;
    int counter = 0, check = 0;
    while (nodes != NULL) {
        counter++;
        if (nodes->data == search){
            check++;
            break;
        }
        nodes = nodes->next;
    }
    if (check > 0){
        printf("The element is found in the node %d", counter);
    }
    else{
        printf("The entered is not found in the Linked List");
    }
}
