#include<stdio.h>
#include<stdlib.h>

struct treeNode{
    int data;
    struct treeNode *left;
    struct treeNode *right;
};

struct treeNode *createNode(int value){
    struct treeNode *newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
    newNode->left=newNode->right=NULL;
    newNode->data = value;
    return newNode;
}

void inorder(struct treeNode *root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
}

void preorder(struct treeNode *root){
    if(root==NULL)return;
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct treeNode *root){
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
}

int main(){
    struct treeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Inorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);
}