#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *next;
    struct Node *prev;
    int value;
};

struct DEQueue{
    struct Node *front, *rear;
};

struct Node *createNode(int value){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if(!node)
        printf("Not enough memory");
    else{
        node->next = NULL;
        node->prev = NULL;
        node->value = value;
    }
    return node;
}

struct DEQueue *createQueue(){
    struct DEQueue *dq = (struct DEQueue *)malloc(sizeof(struct DEQueue));
    if(!dq)
        printf("Not enough memory");
    else{
        dq->front = dq->rear = NULL;
    }
    return dq;
}

void pushFront(int value, struct DEQueue *dq){
    struct Node *new_node = createNode(value);
    if(new_node){
        if(dq->front == NULL){
            dq->front = dq->rear = new_node;
        }
        else{
            new_node->next = dq->front;
            dq->front->prev = new_node;
            dq->front = new_node;
        }
    }
}

void pushRear(int value, struct DEQueue *dq){
    struct Node *new_node = createNode(value);
    if(new_node){
        if(dq->rear == NULL){
            dq->front = dq->rear = new_node;
        }
        else{
            dq->rear->next = new_node;
            new_node->prev = dq->rear;
            dq->rear = new_node;
        }
    }
}

int popFront(struct DEQueue *dq){
    int x = -1;
    if(dq->front){
        if(dq->front == dq->rear){
            x = dq->front->value;
            free(dq->front);
            dq->front = dq->rear = NULL;
        }
        else{
            struct Node *node = dq->front;
            dq->front = node->next;
            dq->front->prev = NULL;
            x = node->value;
            free(node);
        }
    }
    return x;
}

int popRear(struct DEQueue *dq){
    int x = -1;
    if(dq->rear){
        if(dq->front == dq->rear){
            x = dq->front->value;
            free(dq->front);
            dq->front = dq->rear = NULL;
        }
        else{
            struct Node *node = dq->rear->prev;
            x = dq->rear->value;
            free(dq->rear);
            dq->rear = node;
            dq->rear->next = NULL;
        }
    }
    return x;
}

int main(){
    struct DEQueue *dq = createQueue();
    pushFront(1, dq);
    pushRear(2, dq);
    printf("%d\n", popFront(dq));
    pushRear(8, dq);
    pushRear(10, dq);
    printf("%d\n", popFront(dq));
    printf("%d\n", popRear(dq));
    printf("%d\n", popFront(dq));
    printf("%d\n", popFront(dq));
    printf("%d\n", popFront(dq));
    pushFront(6, dq);
}