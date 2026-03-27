#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Global pointers for the start and end of the linked list
struct Node* start = NULL;
struct Node* end = NULL;

// Function prototypes
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtPosition(int data, int position);
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtPosition(int position);
void displayList();
void exitProgram();

int main() {
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at kth position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at kth position\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter position to delete at: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 7:
                displayList();
                break;
            case 8:
                exitProgram();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = start;
    start = newNode;
    if (end == NULL) {
        end = newNode;
    }
}

void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (end) {
        end->next = newNode;
        end = newNode;
    } else {
        start = end = newNode;
    }
}

void insertAtPosition(int data, int position) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(data);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;

    struct Node* temp = start;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    if (newNode->next == NULL) {
        end = newNode;
    }
}

void deleteAtBeginning() {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = start;
    start = start->next;
    free(temp);

    if (start == NULL) {
        end = NULL;
    }
}

void deleteAtEnd() {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (start == end) {
        free(start);
        start = end = NULL;
        return;
    }

    struct Node* temp = start;
    while (temp->next != end) {
        temp = temp->next;
    }
    free(end);
    end = temp;
    end->next = NULL;
}

void deleteAtPosition(int position) {
    if (position < 1 || start == NULL) {
        printf("Invalid position or list is empty.\n");
        return;
    }
    if (position == 1) {
        deleteAtBeginning();
        return;
    }

    struct Node* temp = start;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);

    if (temp->next == NULL) {
        end = temp;
    }
}

void displayList() {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = start;
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void exitProgram() {
    struct Node* temp;
    while (start != NULL) {
        temp = start;
        start = start->next;
        free(temp);
    }
    printf("Exiting program. Memory freed.\n");
    exit(0);
}

