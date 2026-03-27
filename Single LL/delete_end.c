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

struct Node *delete_at_end(struct Node *head)
{

    if (head == NULL)
    {
        printf("linked list is empty");
        return NULL;
    }

    if (head->NEXT == NULL)
    {
        free(head);
        printf("only one node was present");
    }

    struct Node *p = head;
    struct Node *q = p->NEXT;

    while (q->NEXT != NULL)
    {
        p = p->NEXT;
        q = q->NEXT;
    }
    p->NEXT = NULL;
    free(q);

    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 60;
    head->NEXT = second;

    second->data = 70;
    second->NEXT = third;

    third->data = 80;
    third->NEXT = fourth;

    fourth->data = 90;
    fourth->NEXT = NULL;

    traverse_list(head);
    printf("after deletion\n");
    head = delete_at_end(head);
    traverse_list(head);

    return 0;
}