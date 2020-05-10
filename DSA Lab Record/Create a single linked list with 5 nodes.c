#include <stdio.h>
#include <stdlib.h>
 
typedef struct node {
    int data;
    struct node * next;
}node;
 
node * CreateNode(int);
void DisplayNode(node * head);
 
int main(void) {
    int n;
    printf("Enter how many nodes: ");
    scanf("%d", &n);
    node * HEAD = NULL;
    HEAD = CreateNode(n);
    DisplayNode(HEAD);
    return 0;
}
 
node * CreateNode(int n) {
    node * head = NULL;
    node * temp = NULL;
    node * tail = NULL;
    for (int i = 1; i <= n; i++) {
        temp = (node *)malloc(sizeof(node));
        printf("Enter the data for the node %d: ", i);
        scanf("%d", &temp->data);
        temp->next = NULL;
        if (head == NULL) {
           head = temp; 
        }
        else {
            tail = head;
            while (tail->next != NULL) {
                tail = tail->next;
            }
            tail->next = temp;
        }
    }
    return head;
}
 
void DisplayNode(node * head) {
    node * tail = head;
    while(tail != NULL) {
        printf("-> %d ", tail->data);
        tail = tail->next;
    }
}
