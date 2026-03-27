#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
// Queue for BFS
#define MAX 100
struct Node* queue[MAX];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    if (rear == MAX - 1) return; // overflow
    if (front == -1) front = 0;
    queue[++rear] = node;
}

struct Node* dequeue() {
    if (front == -1 || front > rear) return NULL; // underflow
    return queue[front++];
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL) return;
    enqueue(root);
    while (front <= rear) {
        struct Node* current = dequeue();
        printf("%d ", current->data);
        if (current->left != NULL) enqueue(current->left);
        if (current->right != NULL) enqueue(current->right);
    }
}


int main(){
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("\nLevel Order: ");
    levelOrder(root);

    return 0;
}