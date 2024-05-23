// must be compiled with QueueLinkedList.c
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

struct LimitedPriorityQueue{
    struct Queue **arrayOfQueues;
};

struct LimitedPriorityQueue * createPriorityQueue(int size){
    struct LimitedPriorityQueue *q = (struct LimitedPriorityQueue *)malloc(sizeof(struct LimitedPriorityQueue));
    if(q){
        q->arrayOfQueues = (struct Queue **)malloc(sizeof(struct Queue *) * size);
        for(int i = 0; i < size; ++i){
            q->arrayOfQueues[i] = createQueue();
            struct Queue *qt = q->arrayOfQueues[i];
        }
        return q;
    }
    return q;
}

void insert(struct LimitedPriorityQueue *q, int priority, int val){
    enqueue(val, q->arrayOfQueues[priority]);
    return;
}

int delete(struct LimitedPriorityQueue *q, int priority){
   return dequeue(q->arrayOfQueues[priority]);
}

int main(){
    struct LimitedPriorityQueue *q = createPriorityQueue(50);
    insert(q, 0, 5);
    insert(q, 4, 6);
    insert(q, 2, 7);
    printf("%d\n", delete(q, 0));
    printf("%d\n", delete(q, 0));
    printf("%d\n", delete(q, 4));
    printf("%d\n", delete(q, 2));
    printf("%d\n", delete(q, 5));

}