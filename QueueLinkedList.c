#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *next;
    int value;
};

struct Queue{
    struct Node *front;
    struct Node *rear;
};

struct Node *createNode(int value){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->value = value;
    node->next = NULL;
    return node;
}

struct Queue *createQueue(){
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(int value, struct Queue *q){
    struct Node *new_node = createNode(value);
    if(!new_node){
        printf("Queue is full");
    }
    else{
        if(q->front == NULL){
            q->front = q->rear = new_node;
        }
        else{
            q->rear->next = new_node;
            q->rear = new_node;
        }
    }
    return;
}

int dequeue(struct Queue *q){
    int x = -1;
    if(q->front == NULL){
        printf("Queue is empty");
    }
    else{
        struct Node *node = q->front;
        q->front = q->front->next;
        x = node->value;
        free(node);
    }
    return x;
}

int top(struct Queue *q){
    if(q->front)
        return q->front->value;
    return -1;
}

/*
int main(){
    struct Queue *q = createQueue();
    dequeue(q);
    enqueue(1, q);
    enqueue(5, q);
    enqueue(8, q);
    for(int i = 0; i < 3; ++i)
        printf("%d\n", dequeue(q));
}*/