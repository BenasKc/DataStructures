#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev, *next;
    int data;
}*first = NULL;
void create(int A[], int n){
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev=first->next=NULL;
    last = first;
    for(int i = 1;i < n;++i){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}
void Display(struct Node *p){
    while(p){
        printf("%d ", p->data);
        p=p->next;
    }
    printf("\n");
    return;
}
int Length(struct Node *p){
    int len = 0;
    while(p){
        ++len;
        p=p->next;
    }
    return len;
}
void Insert(struct Node *p, int pos, int data){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    if(pos == 0){
        t->prev = NULL;
        t->next = first;
        first = t;
    }
    else{
        for(int i = 1;i < pos;++i){
            p=p->next;
        }
        t->prev = p;
        t->next = p->next;
        if(p->next)
            p->next->prev = t;
        p->next = t;
    }
}
void delete(struct Node *p, int pos){
    if(pos == 0){
        first=first->next;
        if(first)
            first->prev = NULL;
        free(p);
    }
    else{
        for(int i = 0; i < pos;++i){
            p=p->next;
        }
        p->prev->next = p->next;
        if(p->next)
            p->next->prev = p->prev;
        free(p);
    }
}

void reverse(struct Node *p){
    struct Node *temp;
    while(p != NULL){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p && p->next == NULL)
            first = p;
    }
    return p;
}
int main(){
    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);
    Insert(first, 2, 25);
    delete(first, 0);
    reverse(first);
    Display(first);
}
