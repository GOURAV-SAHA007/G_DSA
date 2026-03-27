#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *ptr){
    if(ptr -> top == -1){
        return 1;
    } else {
        return 0;
    }
}

int isFull(struct  Stack *ptr){
    if(ptr -> top == ptr -> size -1){
        return 1;
    } else {
        return 0;
    }    
}

void push(struct Stack *ptr, int value){
    if(isFull(ptr)){
        printf("Stack Overflow!, Cannot push the value %d \n", value);
    }else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct Stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow!");
        return -1;
    }else{
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}


int main(){
    struct Stack *s1=(struct Stack*)malloc(sizeof(struct Stack));
    s1 -> size = 5;
    s1 -> top = -1;
    s1 -> arr = (int*)malloc(s1 -> size * sizeof(int));

    if(isEmpty(s1)){
        printf("Stack is empty\n");
    } else {
        printf("stack is not empty\n");
    }

    if(isFull(s1)){
        printf("Stack is full\n");
    } else {
        printf("stack is not full\n");
    }

    printf("After Pushing the element.\n");

    push(s1, 90);
    push(s1, 12);
    push(s1, 98);
    push(s1, 6);
    
    if(isEmpty(s1)){
        printf("Stack is empty\n");
    } else {
        printf("stack is not empty\n");
    }

    if(isFull(s1)){
        printf("Stack is full\n");
    } else {
        printf("stack is not full\n");
    }

    printf("Popped values:\n");
    printf("%d\n", pop(s1));
    printf("%d\n", pop(s1));
    printf("%d\n", pop(s1));
    
    return 0;
}