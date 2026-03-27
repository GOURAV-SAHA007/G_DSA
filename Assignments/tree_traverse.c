#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *create_node(int val){
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void pre_order(struct Node *root){
    if(root != NULL){
        printf("%d ", root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void post_order(struct Node *root){
    if(root != NULL){
        post_order(root->left);
        post_order(root->right);
        printf("%d ", root->data);
    }
}

void in_order(struct Node *root){
    if(root != NULL){
        in_order(root->left);
        printf("%d ", root->data);
        in_order(root->right);
    }
}

int main(){
    struct Node *p = create_node(4);
    struct Node *p1 = create_node(1);
    struct Node *p2 = create_node(5);
    struct Node *p3 = create_node(2);
    struct Node *p4 = create_node(6);

    p->left = p1;
    p->right = p4;
    p1->left = p2;
    p1->right = p3;

    printf("Pre-Oreder:");
    pre_order(p);

    printf("\nIn-Order:");
    in_order(p);
    
    printf("\nPost-Order:");
    post_order(p);
    
    return 0;
}