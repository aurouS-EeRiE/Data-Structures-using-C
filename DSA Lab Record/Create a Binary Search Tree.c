#include <stdio.h>
#include <stdlib.h>
 
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;
 
node* NewNode(int data);
node* InsertNode(node* root, int data);
node* SearchTree(node* root, int search);
void Inorder(node* Node);
 
void main(){
    node* root = NULL;
    int option, data, search;
    while(1){
        printf("\n1. To insert an element into the BST.");
        printf("\n2. To search for an element in the BST.");
        printf("\n3. To print Inorder traversal of BST.");
        printf("\n4. Exit.");
        printf("\nEnter your choice: ");
        scanf("%d", &option);
        switch(option){
            case 1: printf("\nEnter an element to insert into the BST: ");
                scanf("%d", &data);
                if (root == NULL){
                    root = InsertNode(root, data);
                }
                else{
                    InsertNode(root, data);
                }
                break;
            case 2: printf("\nEnter an element to search: ");
                scanf("%d", &search);
                SearchTree(root, search);
                break;
            case 3: printf("\nInorder Traversal: ");
                Inorder(root);
                printf("\n");
                break;
            case 4: exit(0);
            default: printf("\nEnter a valid option!!!");
        }
    }
}
 
node* NewNode(int data){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
node* InsertNode(node* Node, int data){
    if (Node == NULL){
        return NewNode(data);
    }
    if (data < Node->data){
        Node->left = InsertNode(Node->left, data);
    }
    else if (data > Node->data){
        Node->right = InsertNode(Node->right, data);
    }
    return Node;
}
 
node* SearchTree(node* Node, int search){
    if (Node == NULL){
        printf("\nThe entered element is not found in the BST!!!\n");
        return;
    }
    if (Node->data == search){
        printf("\nThe element %d is found in the BST!!!\n", search);
        return;
    }
    if (search < Node->data){
        SearchTree(Node->left, search);
    }
    else if (search > Node->data){
        SearchTree(Node->right, search);
    }
}
 
void Inorder(node* Node){
    if (Node == NULL){
        return;
    }
    Inorder(Node->left);
    printf("->  %d  ", Node->data);
    Inorder(Node->right);
}