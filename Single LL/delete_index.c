#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *NEXT;
};

void traverse_list(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->NEXT;
    }
}

struct Node *delete_at_index(struct Node *head, int k){

    if(head == NULL){
        printf("list is empty");
        return NULL;
    }

    struct Node *p = head;
    struct Node *q = p -> NEXT;
    int count = 0;
    
    while(count != k-1){
        p = p->NEXT;
        q = q->NEXT;
        count++;
    }

    p -> NEXT = q -> NEXT;
    q -> NEXT = NULL;
    free(q);
    
    return head;
}


int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 60;
    head->NEXT = second;

    second->data = 70;
    second->NEXT = third;

    third->data = 80;
    third->NEXT = fourth;

    fourth->data = 90;
    fourth->NEXT = fifth;

    fifth-> data = 100;
    fifth->NEXT = NULL;

    traverse_list(head);
    printf("after deletion\n");
    head = delete_at_index(head, 3);
    traverse_list(head);

    return 0;
}