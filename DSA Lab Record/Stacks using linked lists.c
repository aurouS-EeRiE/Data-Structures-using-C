#include <stdio.h>
#include<stdlib.h>

typedef struct element{
  int data;
  struct element * next;
}element;

element * Push(element * head, int value, int size);
void Display(element * head);
element * Pop(element * head);
void Peek(element * head);

int main(void) {
  int size, choice, value;
  element * stack = NULL;
  printf("Enter the size of the stack: ");
  scanf("%d",&size);
  while(1){
    printf("\n1. Push \n2. Pop \n3. Display \n4. Peek \n5. Exit \n");
    printf("Select an option: ");
    scanf("%d",&choice);
    switch(choice) {
      case 1: printf("Enter a value: ");
              scanf("%d",&value);
              stack = Push(stack, value, size);
              break;
      case 2:stack = Pop(stack);
              break;
      case 3: Display(stack);
              break;
      case 4: Peek(stack);
              break;
      case 5: exit(0);
              break;
      default: printf("\nEnter correct choice\n");
              break;
    } 
  } 
}

element * Push(element * head, int value, int size) {
  element * temp = NULL;
  element * tail = NULL;
  temp = (element *)malloc(sizeof(element));
  temp->data = value;
  temp->next = NULL;
  if (head == NULL) {
    head = temp;
    printf("\nINSERTION SUCCESS!!!\n");
  }
  else {
    tail = head;
    int check = 0;
    while(tail->next != NULL) {
      tail = tail->next;
      check ++;
      if(check == size) {
        printf("\nStack overflow\n");
        break;
      }
    }
    tail->next = temp;
    printf("\nInsertion successful!!\n");
  }
  return head;
}

void Display(element * head) {
  element * tail = head;
  if(head == NULL) {
    printf("\nStack is empty\n");
  }
  else {
    while(tail != NULL) {
    printf("\n->%d ",tail->data);
    tail = tail->next;
    }

  }
}

element * Pop(element * head) {
  element * tail = head;
  element * pop = head;
  if(tail == NULL) {
    printf("\n Stack is empty!!\n");
  }  
  else{
    int count = 0;
    while(tail->next != NULL) {
      count++;
      pop = tail;
      tail = tail->next;
    }
    printf("\nPopped element = %d\n",tail->data);
    pop->next = NULL;
    if(count == 0) {
      head = NULL;
    }
  }
  return head;
}

void Peek(element * head) {
  element * tail = head;
  if(tail == NULL) {
    printf("\nStack is empty\n");
  }
  else {
    while(tail->next != NULL) {
      tail = tail->next;
    }
    printf("\nPeek element = %d\n", tail->data);
  }
}