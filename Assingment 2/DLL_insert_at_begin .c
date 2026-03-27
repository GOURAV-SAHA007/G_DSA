#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node *insertAtBegin(int data, struct Node *head){
    struct Node *NewNode = (struct Node*)malloc(sizeof(struct Node));
    
    NewNode->data = data;
    NewNode->next = head;
    NewNode->prev = NULL;
    
    if(head != NULL)
        head->prev = NewNode;
    
    head = NewNode;
    return head;
}

struct Node *insertAtEnd(int data, struct Node *head){
    struct Node *NewNode = (struct Node*)malloc(sizeof(struct Node));
    
    NewNode->data = data;
    NewNode->next = NULL;
    
    if(head == NULL){
        NewNode->prev = NULL;
        return NewNode;
    }
    
    struct Node *p = head;
    while(p->next != NULL){
        p = p->next;
    }
    
    p->next = NewNode;
    NewNode->prev = p;
    
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
    
    printf("After Inserting at Beginning:\n");
    head = insertAtBegin(50, head);
    display(head);
    
    printf("After Inserting at End:\n");
    head = insertAtEnd(100, head);
    display(head);
    
    return 0;
}

