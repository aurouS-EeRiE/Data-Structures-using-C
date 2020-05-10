#include<stdio.h>
#include<stdlib.h>

typedef struct element {
    int data; 
    struct element * next;
}element;

element *front = NULL, *rear = NULL;

void enQueue(int value) {
    element * NewElement = (element *)malloc(sizeof(element));
    NewElement->data =  value;
    NewElement->next = NULL;
    if (front == NULL && rear == NULL) {
        front = rear = NewElement;
    }
    else {
        rear->next = NewElement;
        rear = NewElement;
    }
    printf("Insertion Successfull");
}

void Display() {
    if (front == rear) {
        printf("Queue is empty");
    }
    else {
        element * temp = front;
        while(temp) {
            printf("-> %d  ", temp->data);
	        temp = temp -> next;
        }
    }
}

void deQueue() {
    if (front == rear) {
        printf("Queue is empty");
    }
    else {
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        printf("deQueue successfull");
    }
}

void Peek() {
    if (front == rear) {
        printf("Queue is empty");
    }
    else {
        while(rear->next != NULL) {
        rear = rear->next;
        }
        printf("\nPeek element = %d\n", rear->data);
    }
}

void main() {
  int choice, value;
  element * Queue = NULL;
  while(1){
    printf("\n1. enQueue \n2. deQueue \n3. Display \n4. Peek \n5. Exit \n");
    printf("Select an option: ");
    scanf("%d",&choice);
    switch(choice) {
      case 1: printf("Enter a value: ");
              scanf("%d", &value);
              enQueue(value);
              break;
      case 2: deQueue();
              break;
      case 3: Display(Queue);
              break;
      case 4: Peek();
              break;
      case 5: exit(0);
              break;
      default: printf("\nEnter correct choice\n");
              break;
    } 
  } 
}