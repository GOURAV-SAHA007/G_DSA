#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *PREV;
    int data;
    struct  Node *NEXT;
};

void display_dll(struct Node *ptr){
    while(ptr != NULL){
        printf("%d\n", ptr -> data);
        ptr = ptr -> NEXT;
    }
}

struct Node *Insert_at_end(struct Node *head, int value){
    struct Node *NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode -> data = value;

    if(head == NULL){
        NewNode -> PREV = NULL;
        NewNode -> NEXT = NULL;

        return NewNode;
    }

    struct Node *ptr = head;
    
    while(ptr -> NEXT != NULL){
        ptr = ptr -> NEXT;
    }

    ptr -> NEXT = NewNode;
    NewNode -> PREV = ptr;
    NewNode -> NEXT = NULL;

    return head;
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));

    head -> PREV = NULL;
    head -> data = 60;
    head -> NEXT = second;

    second -> PREV = head;
    second -> data = 70;
    second -> NEXT = third;

    third -> PREV = second;
    third -> data = 80;
    third -> NEXT = fourth;

    fourth -> PREV = third;
    fourth -> data = 90;
    fourth -> NEXT = fifth;

    fifth -> PREV = fourth;
    fifth -> data = 100;
    fifth -> NEXT = NULL;

    printf("Original List :\n");
    display_dll(head);

    printf("After Insertion:\n");
    head = Insert_at_end(head, 101);
    display_dll(head);

}