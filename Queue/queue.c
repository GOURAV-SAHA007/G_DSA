#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q){
    if(q->f==-1){
        return 1;
    }
    return 0;
}

void Enqueue(struct queue *q, int value){
    if(isFull(q)){
        printf("Queue is Full.");
        return;
    }if(q->f == -1){
        q->f = 0;
    }
        q->r++;
        q->arr[q->r] = value;
}

int Dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue is Empty.");
        return -1;
    }
    a = q->arr[q->f];
    q->f++;
    
    if(q->f > q->r){
        q->f = -1;
        q->r = -1;
    }

    return a;
}

void display(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is empty.");
    }else{
        printf("\nElement are :");
        for(int i = q->f; i <= q->r; i++){
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main(){
    struct queue q;
    q.size = 5;
    q.f = -1;
    q.r = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));

    Enqueue(&q, 89);
    Enqueue(&q, 5);
    Enqueue(&q, 88);

    display(&q);

    printf("\nDequeued element : %d", Dequeue(&q));
    printf("\nDequeued element : %d", Dequeue(&q));

    display(&q);

}