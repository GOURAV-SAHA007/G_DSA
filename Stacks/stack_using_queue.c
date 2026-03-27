#include <stdio.h>

#define MAX 100

struct Queue {
    int arr[MAX];
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int queueFull(struct Queue *q) {
    return q->rear == MAX - 1;
}

int queueEmpty(struct Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(struct Queue *q, int x) {
    if (queueFull(q)) {
        printf("Queue Overflow!\n");
    } else {
        if (q->front == -1) q->front = 0;
        q->rear++;
        q->arr[q->rear] = x;
    }
}

int dequeue(struct Queue *q) {
    if (queueEmpty(q)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int x = q->arr[q->front];
    q->front++;
    return x;
}

int top(struct Queue *q) {
    if (!queueEmpty(q))
        return q->arr[q->front];
    return -1;
}

struct Stack {
    struct Queue q1;
    struct Queue q2;
};

void initStack(struct Stack *s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
}

void push(struct Stack *s, int val) {
    enqueue(&s->q2, val);

    while (!queueEmpty(&s->q1)) {
        enqueue(&s->q2, dequeue(&s->q1));
    }

    // Swap q1 and q2
    struct Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

int pop(struct Stack *s) {
    return dequeue(&s->q1);
}

int stackTop(struct Stack *s) {
    return top(&s->q1);
}

int main() {
    struct Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 30);
    push(&s, 20);
    push(&s, 40);

    printf("\nPopped element from stack: %d", pop(&s));
    printf("\nTop element of stack is: %d", stackTop(&s));
    printf("\nPopped element from stack: %d", pop(&s));
    printf("\nPopped element from stack: %d", pop(&s));

    return 0;
}
