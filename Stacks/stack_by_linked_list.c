#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Stack Overflow! Cannot insert %d\n", value);
    }else{
        newNode -> data = value;
        newNode -> next = top;
        top = newNode;
    }
}

void pop(){
    struct Node *temp = top;
    if(temp == NULL){
        printf("Stack Underflow!");
    }else{
        printf("%d\n ", temp->data);
        top = temp->next;
    }
    free(temp);
}

void display(){
    struct Node *temp = top;
    if(top == NULL){
        printf("No elements are present\n");
        return -1;
    }

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    
}

int main(){

    push(34);
    push(90);

    display();

    pop();
    pop();

    display();

    return 0;
}