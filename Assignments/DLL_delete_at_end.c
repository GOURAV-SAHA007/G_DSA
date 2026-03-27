#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node *deleteLast(struct Node *head){
    if(head == NULL){
        printf("List is empty\n");
        return head;
    }
    if(head->next == NULL){ // If only one node is present
        free(head);
        return NULL;
    }
    struct Node *p = head;
    while(p->next != NULL){
        p = p->next;
    }
    p->prev->next = NULL;
    free(p);
    return head;
}

void display(struct Node *head){
    struct Node *p = head;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *second = (struct Node*)malloc(sizeof(struct Node));
    struct Node *third = (struct Node*)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node*)malloc(sizeof(struct Node));
    
    head->data = 60;
    head->next = second;
    head->prev = NULL;
    
    second->data = 70;
    second->next = third;
    second->prev = head;
    
    third->data = 80;
    third->next = fourth;
    third->prev = second;
    
    fourth->data = 90;
    fourth->next = NULL;
    fourth->prev = third;
    
    printf("Original Doubly Linked list:\n");
    display(head);
    
    printf("After Deleting Last Node:\n");
    head = deleteLast(head);
    display(head);
    
    return 0;
}

