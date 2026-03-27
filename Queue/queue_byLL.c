#include<stdio.h>
#include<stdlib.h>

struct queueNode{
    int data;
    struct queueNode *next;
};

struct queueNode *front = NULL;
struct queueNode *rear = NULL;

void Enqueue(int value){
    struct queueNode *newNode = (struct queueNode*)malloc(sizeof(struct queueNode));
    newNode->next = NULL;
    newNode->data = value;

    if(!newNode){
        printf("Queue is Full. Memory not allocated.");
        return;
    }
        
    if(rear == NULL){
        rear = front = newNode;
    }else{
        rear->next = newNode;
        rear = newNode;
    }

}

void Dequeue(){
    if(rear == NULL){
        printf("Queue is Empty.");
        return -1;
    }

    struct queueNode *temp = front;
    printf("%d\n", temp->data);
    front = front->next;

    free(temp);
}

void peek(){
    if(rear == NULL){
        printf("No elements.");
        return;
    }
    printf("front element is %d\n", front->data);
}

void display(){
    if(rear == NULL){
        printf("Queue is empty.");
    }else{
        printf("\nElement are :");
        struct queueNode *temp = front;
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
        
        printf("\n");
    }
}

int main(){

    Enqueue(89);
    Enqueue(5);
    Enqueue(88);

    display();

    Dequeue();
    Dequeue();

    display();

    return 0;
}