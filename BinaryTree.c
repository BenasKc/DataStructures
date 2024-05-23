#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    struct TreeNode *left;
    struct TreeNode *right;
    int value;
};

struct Node{
    struct Node *next;
    struct TreeNode *value;
};

struct Queue{
    struct Node *front;
    struct Node *rear;
};

struct Node *createNode(struct TreeNode *value){
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

void enqueue(struct TreeNode *value, struct Queue *q){
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

struct TreeNode * dequeue(struct Queue *q){
    struct TreeNode *x;
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

struct TreeNode * top(struct Queue *q){
    if(q->front)
        return q->front->value;
    return 0;
}

int isEmpty(struct Queue *q){
    if(q->front == NULL)
        return 1;
    return 0;
}

struct TreeNode *createTree(){
    struct TreeNode *p, *t, *root;
    int x;
    struct Queue *q = createQueue();
    printf("Enter root value:\n");
    scanf("%d", &x);
    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->value = x;
    root->left = root->right = 0;
    enqueue(root, q);
    while(!isEmpty(q)){
        p = dequeue(q);
        printf("Enter value of left child for %d:\n", p->value);
        scanf("%d", &x);
        if(x != -1){
            t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            t->value = x;
            t->left = t->right = 0;
            p->left = t;
            enqueue(t, q);
        }
        printf("Enter value of right child for %d:\n", p->value);
        scanf("%d", &x);
        if(x != -1){
            t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            t->value = x;
            t->left = t->right = 0;
            p->right = t;
            enqueue(t, q);
        }
    }

    return root;
}

void Preorder(struct TreeNode *root){
    struct TreeNode *node = root;
    if(node){
        printf("%d\n", node->value);
        Preorder(node->left);
        Preorder(node->right);
    }
}

void Inorder(struct TreeNode *root){
    struct TreeNode *node = root;
    if(node){
        Inorder(node->left);
        printf("%d\n", node->value);
        Inorder(node->right);
    }
}

void Postorder(struct TreeNode *root){
    struct TreeNode *node = root;
    if(node){
        Postorder(node->left);
        Postorder(node->right);
        printf("%d\n", node->value);
    }
}

int main(){
    struct TreeNode *root = createTree();
    Preorder(root);
    printf("\n");
    Inorder(root);
    printf("\n");
    Postorder(root);
}