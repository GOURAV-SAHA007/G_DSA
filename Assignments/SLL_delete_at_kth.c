#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node *deleteAtK(struct Node *head, int k){
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    if (k == 1) { // If the first node needs to be deleted
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node *p = head;
    for (int i = 1; p != NULL && i < k - 1; i++) {
        p = p->next;
    }
    if (p == NULL || p->next == NULL) {
        printf("Position out of range\n");
        return head;
    }
    struct Node *temp = p->next;
    p->next = temp->next;
    free(temp);
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
    
    second->data = 70;
    second->next = third;
    
    third->data = 80;
    third->next = fourth;
    
    fourth->data = 90;
    fourth->next = NULL;
    
    printf("Original Linked list:\n");
    display(head);
    
    int k = 3;
    printf("After Deleting %dth Node:\n", k);
    head = deleteAtK(head, k);
    display(head);
    
    return 0;
}

