#include <stdio.h>
#include <stdlib.h>
 
typedef struct node {
    int data;
    struct node * prev;
    struct node * next;
}node;
 
node * CreateNode(int n);
void DisplayNodes(node * head);
 
int main(void) {
    int n;
    printf("Enter how many nodes: ");
    scanf("%d", &n);
    node * HEAD = NULL;
    HEAD = CreateNode(n);
    DisplayNodes(HEAD);
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
        temp->prev = NULL;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
        }
        else {
            nodes = head;
            while (nodes->next != NULL) {
                nodes = nodes->next;
            }
            head->prev = temp;
            nodes->next = temp;
            temp = nodes;
            nodes = nodes->next;
            nodes->prev = temp;
        }
    }
    return head;
}
 
void DisplayNodes(node * head) {
    node * nodes = head;
    while (nodes != NULL) {
        printf("-> %d ", nodes->data);
        nodes = nodes->next;
    }
}
