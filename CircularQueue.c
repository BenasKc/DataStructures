#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int *arr;
    int front;
    int rear;
    int size;
};

struct Queue * createQueue(int size){
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->arr = (int *)malloc(sizeof(int) * size);
    q->front = q->rear = 1;
    q->size = size;
    return q;
}

void enqueue(struct Queue *q, int x){
    if(q->front == (q->rear + 1) % q->size){
        printf("Queue is full");
    }
    else{
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = x;
    }
    return;
}

int dequeue(struct Queue *q){
    if(q->front == q->rear){
        printf("Queue is empty");
        return -1;
    }
    else{
        q->front = (q->front + 1) % q->size;
        return q->arr[q->front];
    }
}

int main(){
    struct Queue *q = createQueue(5);
    enqueue(q, 1);
    enqueue(q, 3);
    enqueue(q, 2);
    enqueue(q, 1);
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));

    
}