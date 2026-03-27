#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void linkedlist_transverse(struct Node *ptr){
    while(ptr != NULL){
        printf("Elements : %d\n", ptr -> data);
        ptr = ptr -> next;
    }

}

struct Node *insert_at_beginning(struct Node *head, int data){
   struct Node *ptr1 = (struct Node*)malloc(sizeof(struct Node));

    ptr1 -> next = head;
    ptr1 -> data = data;

    return ptr1;

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

head -> data = 12;
head -> next = second;

second -> data = 26;
second -> next = third;

third -> data = 92;
third -> next = fourth;

fourth -> data = 82;
fourth -> next = NULL;

linkedlist_transverse(head);
printf("After Insertion:\n");
head = insert_at_beginning(head, 55);
linkedlist_transverse(head);
return 0;
}