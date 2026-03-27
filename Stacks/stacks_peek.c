#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int *arr;
};

int peek(struct Stack *sp, int i){
    if(sp->top-i+1 < 0){
        printf("Invalid Position!\n");
        return -1;
    }else{
        return sp -> arr[sp->top-i+1];
    }
}

void push(struct Stack *ptr, int val){
    if(ptr->top == ptr-> size - 1){
        printf("Stack Overflow!");
    }else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int main(){
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = 50;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    push(sp, 90);
    push(sp, 12);
    push(sp, 98);
    push(sp, 98);
    push(sp, 11);
    push(sp, 9);
    push(sp, 6);

    for(int j=0; j <= sp->top; j++){
        printf("Element:%d  Position:%d\n", peek(sp, j), j);
    }

    return 0;
}