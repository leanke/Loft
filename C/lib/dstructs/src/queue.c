#include <stdio.h>

typedef struct {
    int front, rear;
    int items[100];
} Queue;

// Enqueue an item into the queue
void enqueue(Queue* q, int val) {
    if (q->rear == 99) {
        printf("Queue is full\n");
        return;
    }
    q->items[++q->rear] = val;
    if (q->front == -1) {
        q->front = 0;
    }
}

// Dequeue an item from the queue
int dequeue(Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}
