#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};


struct Node *insertAtEnd(int data, struct Node *head){
	struct Node *NewNode = (struct Node*)malloc(sizeof(struct Node));
	
	NewNode -> data = data;
	NewNode -> next = NULL;

	if(head == NULL){
		return NewNode;
	}
	
	struct Node *p = head;
	while(p -> next != NULL){
		p = p -> next;
	}
	
	p -> next = NewNode;
	
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
	
	printf("After Inserting at End:\n");
	head = insertAtEnd(100, head);
	display(head);
	
	
}
