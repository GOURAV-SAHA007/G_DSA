#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node *deleteFirst(struct Node *head){
	if(head == NULL){
		printf("List is empty");
		return head;
	}
	struct Node *p = head;
	head = head -> next;
	return head;
}

void display(struct Node *head){
	struct Node *p = head;
	while(p != NULL){
		printf("%d ", p -> data);
		p = p -> next;
	}
}

int main(){
	struct Node *head = (struct Node*)malloc(sizeof(struct Node));
	struct Node *second = (struct Node*)malloc(sizeof(struct Node));
	struct Node *third = (struct Node*)malloc(sizeof(struct Node));
	struct Node *fourth = (struct Node*)malloc(sizeof(struct Node));
	
	head -> data = 60;
	head -> next = second;
	
	second -> data = 70;
	second -> next = third;
	
	third -> data = 80;
	third -> next = fourth;
	
	fourth -> data = 90;
	fourth -> next = NULL;
	
	printf("Original Linked list:\n");
	display(head);
	
	printf("After Deleting First Node:\n");
	head = deleteFirst(head);
	display(head);
	
	
}
