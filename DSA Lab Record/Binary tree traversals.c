#include <stdio.h>
 
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;
 
node* NewNode(int data);
void Inorder(node* Node);
void Preorder(node* Node);
void Postorder(node* Node);
 
void main(){
    node* root = NewNode(1);
    root->left = NewNode(2);
    root->right = NewNode(3);
    root->left->left = NewNode(4);
    root->left->right = NewNode(5);
 
    printf("Inorder traversal: ");
    Inorder(root);
    printf("\n\nPreorder traversal: ");
    Preorder(root);
    printf("\n\nPostorder traversal: ");
    Postorder(root);
}
 
node* NewNode(int data){
    node* Node = (node*)malloc(sizeof(node));
    Node-> data = data;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}
 
void Inorder(node* Node){
    if (Node == NULL){
        return;
    }
    Inorder(Node->left);
    printf("-> %d ", Node->data);
    Inorder(Node->right);
}
 
void Preorder(node* Node){
    if (Node == NULL){
        return;
    }
    printf("-> %d ", Node->data);
    Preorder(Node->left);
    Preorder(Node->right);
}
 
void Postorder(node* Node){
    if (Node == NULL){
        return;
    }
    Postorder(Node->left);
    Postorder(Node->right);
    printf("-> %d ", Node->data);
}
