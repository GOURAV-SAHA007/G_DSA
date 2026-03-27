#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void linkedlist_traverse(struct Node *ptr){
    while(ptr != NULL){
        printf("Elements : %d\n", ptr -> data);
        ptr = ptr -> next;
    }
}

struct Node *insert_at_end(struct Node *head, int data){

    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = data;
    struct Node *p = head;

    while(p -> next != NULL){
        p = p -> next;
    }

    p -> next = ptr;
    ptr -> next = NULL;

    return head;
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head -> data = 54;
    head -> next = second;

    second -> data = 33;
    second -> next = third;

    third -> data = 122;
    third -> next = fourth;

    fourth -> data = 756;
    fourth -> next = NULL;

    linkedlist_traverse(head);
    printf("After insertion:\n");
    head = insert_at_end(head, 77);
    linkedlist_traverse(head);
    return 0;
}