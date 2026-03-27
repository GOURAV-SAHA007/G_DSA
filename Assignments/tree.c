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

int main(){
    struct Node *p = create_node(2);
    struct Node *p1 = create_node(1);
    struct Node *p2 = create_node(4);

    p->left = p1;
    p->right = p2;

    return 0;
}