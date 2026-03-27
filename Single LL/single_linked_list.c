#include<stdio.h>
#include<stdlib.h>

//struct Node defined globally
struct Node{
    int data;
    struct Node *next;
};


//function to print the list 
void linkedlist_traverse(struct Node *ptr){
    while(ptr != NULL){
        printf("Element : %d\n", ptr->data);
        ptr = ptr -> next;
    }
}

int main(){

    //defining the Nodes using global struct Node
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    //Allocate memory for the nodes
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    //giving the value to the nodes and point to the next node
    head -> data = 7;
    head -> next = second;

    second -> data = 19;
    second -> next = third;

    third -> data = 42;
    third -> next = fourth;

    //final node given with data and pointed to the NULL to end the linked list
    fourth -> data = 81;
    fourth -> next = NULL;

    linkedlist_traverse(head);
    return 0;
}