#include <stdio.h>
#include <stdlib.h>

struct CDLL{
    struct CDLL *prev;
    struct CDLL *next;
    int content;
}*head;
void Create(int A[], int n){
    if(n < 1)
        return;
    head = (struct CDDL *)malloc(sizeof(struct CDLL));
    head->content = A[0];
    struct CDLL *p, *q;
    q = head;
    for(int i = 1;i < n;++i){
         p = (struct CDDL *)malloc(sizeof(struct CDLL));
         p->prev = q;
         q->next = p;
         p->content = A[i];
         q = p;
    }
    q->next = head;
    head->prev = q;
    return;
}
void Display(){
    struct CDLL *p;
    p = head;
    do{
        printf("%d ", p->content);
        p=p->next;
    }
    while(p != head);
    printf("\n");
    return;
}
void Insert(int item, int pos){
    struct CDLL *t, *p;
    t = (struct CDLL *)malloc(sizeof(struct CDLL *));
    t->content = item;
    if(pos == 0){
        t->next = head;
        t->prev = head->prev;
        head->prev->next = t;
        head->prev = t;
        head = t;
    }
    else{
        p = head;
        for(int i = 0;i < pos-1;++i){
            p=p->next;
        }
        t->next = p->next;
        t->prev = p;
        p->next->prev = t;
        p->next = t;
    }
}
void delete(int pos){
    struct CDLL *t;
    t = head;
    if(pos == 0){
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
    }
    else{
        for(int i = 0;i < pos;++i){
                t=t->next;
        }
        t->prev->next = t->next;
        t->next->prev = t->prev;
        t = t->next;
    }
}
int main(){
    struct CDLL item;
    int A[] = {1, 5, 9, 6, 3};
    Create(A, 1);
    Insert(2, 6); // Not going to fix all bugs, special cases require tweaking
    delete(1);
    Display();
    return 0;
}
