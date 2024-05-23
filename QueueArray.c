#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void Create(struct Queue *q, int size){
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->Q = (int *)malloc(sizeof(int)*q->size);
    return;
}

int isEmpty(struct Queue *q){
    if(q->rear == q->front)
        return 1;
    return 0;
}

int isFull(struct Queue *q){
    if(q->rear == q->size - 1)
        return 1;
    return 0;
}

void enqueue(struct Queue *q, int x){
    if(isFull(q)){
        printf("Queue is full\n");
        return;
    }
    else{
        q->rear++;
        q->Q[q->rear] = x;
    }
}
int dequeue(struct Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        q->front++;
        return q->Q[q->front];
    }
}

void Display(struct Queue *q){
    for(int i = q->front + 1; i <= q->rear; ++i){
        printf("%d ", q->Q[i]);
    }
    printf("\n");
    return;
}

int main(){
    struct Queue q;
    Create(&q, 5);
    enqueue(&q, 0);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    Display(&q);
    dequeue(&q);
    dequeue(&q);
    Display(&q);
    return 0;
}