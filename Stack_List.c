#include "LinkedList.c"

struct Stack{
    struct Node *top;
};

void pushStack(struct Stack *st, int x){
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if(!p){
        printf("Stack is full");
        return;
    }
    p->next = st->top;
    p->data = x;
    st->top = p;
    return;
}

int popStack(struct Stack *st){
    int x;
    if(!st || !st->top){
        printf("Stack is empty");
    }
    else{
        struct Node *p = st->top;
        st->top = st->top->next;
        x = p->data;
        free(p);
        return x;
    }
    return -1;
}

void DisplayStack(struct Stack * st){
    if(!st)
        return;
    struct Node *p = st->top;
    while(p){
        printf("%d\n", p->data);
        p = p->next;
    }
    return;
}

int main(){
    struct Stack *st;
    st = (struct Stack *)malloc(sizeof(struct Stack));
    pushStack(st, 5);
    pushStack(st, 8);
    pushStack(st, 9);
    DisplayStack(st);
    printf("%d\n\n", popStack(st));
    DisplayStack(st);
}