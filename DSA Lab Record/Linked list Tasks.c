#include<stdlib.h>
#include <stdio.h>

typedef struct node {
        int data;
        struct node *next;
}node;

node *start = NULL;

void create() {
        node *temp, *ptr;
        temp = (node *)malloc(sizeof(node));
        if (temp == NULL) {
                printf("\nOut of Memory Space:");
                exit(0);
        }
        printf("\nEnter the data value for the node:");
        scanf("%d", &temp -> data);
        temp -> next = NULL;
        if (start == NULL) {
                start = temp;
        }
        else {
                ptr = start;
                while(ptr -> next != NULL) {
                        ptr = ptr -> next;
                }
                ptr -> next = temp;
        }
}

void display() {
        node *ptr;
        if(start == NULL) {
                printf("\nList is empty");
                return;
        }
        else {
                ptr = start;
                printf("\nThe List elements are: \n");
                while (ptr != NULL) {
                        printf("%d\t", ptr -> data );
                        ptr = ptr -> next ;
                }
        }
}

void insert_begin() {
        node *temp;
        temp = (node *)malloc(sizeof(node));
        if (temp == NULL) {
                printf("\nOut of Memory Space:");
                return;
        }
        printf("\nEnter the data value for the node:" );
        scanf("%d", &temp -> data);
        temp -> next = NULL;
        if (start == NULL) {
                start = temp;
        }
        else {
                temp -> next = start;
                start = temp;
        }
}
void insert_end() {
        node *temp, *ptr;
        temp = (node *)malloc(sizeof(node));
        if (temp == NULL) {
                printf("\nOut of Memory Space:");
                return;
        }
        printf("\nEnter the data value for the node:\t" );
        scanf("%d", &temp -> data);
        temp -> next = NULL;
        if (start == NULL) {
                start = temp;
        }
        else {
                ptr = start;
                while(ptr -> next != NULL) {
                        ptr = ptr -> next ;
                }
                ptr -> next = temp;
        }
}

void insert_pos() {
        node *ptr, *temp;
        int i, pos;
        temp = (node *)malloc(sizeof(node));
        if(temp == NULL) {
                printf("\nOut of Memory Space:");
                return;
        }
        printf("\nEnter the position for the new node to be inserted:\t");
        scanf("%d", &pos);
        printf("\nEnter the data value of the node:\t");
        scanf("%d", &temp -> data) ;  
        temp -> next = NULL;
        if(pos == 0) {
                temp -> next = start;
                start = temp;
        }
        else {
                for(i = 0, ptr = start; i < pos - 1; i++) { 
                        ptr = ptr -> next;
                        if (ptr == NULL) {
                                printf("\nPosition not found:[Handle with care]");
                                return;
                        }
                }
                temp -> next = ptr -> next ;
                ptr -> next = temp;
        }
}

void delete_begin() {
        node *ptr;
        if(ptr == NULL) {
                printf("\nList is Empty:");
                return;
        }
        else {
                ptr = start;
                start = start -> next ;
                printf("\nThe deleted element is: %d\t", ptr -> data);
                free(ptr);
        }
}

void delete_end() {
        node *temp, *ptr;
        if(start == NULL) {
                printf("\nList is Empty:");
                exit(0);
        }
        else if(start->next ==NULL) {
                ptr = start;
                start = NULL;
                printf("\nThe deleted element is: %d\t", ptr -> data);
                free(ptr);
        }
        else {
                ptr = start;
                while (ptr -> next != NULL) {
                        temp = ptr;
                        ptr = ptr -> next;
                }
                temp -> next = NULL;
                printf("\nThe deleted element is: %d\t", ptr -> data);
                free(ptr);
        }
}

int main() {
        int choice;
        while(1){
                printf("\n 1.Create\n 2.Display\n 3.Insert at the beginning\n 4.Insert at the end\n 5.Insert at specified position\n 6.Delete from beginning\n 7.Delete from the end\n 8.Exit       \n");
                printf("\nEnter your choice:");
                scanf("%d",&choice);
                switch(choice) {
                        case 1: create();
                                break;
                        case 2: display();
                                break;
                        case 3: insert_begin();
                                break;
                        case 4: insert_end();
                                break;
                        case 5: insert_pos();
                                break;
                        case 6: delete_begin();
                                break;
                        case 7: delete_end();
                                break;
                        case 8: exit(0);
                                break;                             
                        default: printf("\n Wrong Choice");
                                 break;
                }
        }
        return 0;
}
