#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL, *last=NULL, *second=NULL, *third=NULL;
void Create(int A[], int n){
    int i;
    struct Node *t, *last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last = first;
    for(i = 1;i < n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void middle_node(){
    struct Node *p, *q;
    p = first;
    q = first;
    while(p){
        p=p->next;
        if(p){
            p=p->next;
        }
        if(p)
            q=q->next;
    }
    printf("Middle node is %d\n", q->data);
}
void Create2(int A[], int n){
    int i;
    struct Node *t, *last_0;
    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=A[0];
    second->next=NULL;
    last_0=second;
    for(i = 1;i < n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next=NULL;
        last_0->next=t;
        last_0=t;
    }
}
int count(struct Node *p){
    int c = 0;
    while(p){
        c++;
        p=p->next;
    }
    return c;
}
int count_r(struct Node *p){
    if(!p)return 0;
    else return count_r(p->next)+1;
}
int sum(struct Node *p){
    int sum = 0;
    while(p){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}
int sum_r(struct Node *p){
    if(!p)return 0;
    return sum_r(p->next)+p->data;
}
void Display(struct Node *p){
    while(p){
        printf("%d ", p->data);
        p=p->next;
    }
}
void Display_recursively(struct Node *p){
    if(p){
        printf("%d ", p->data);
        Display_recursively(p->next);
    }
}
long long max(struct Node *p){
    long long max = -92233720368547758 ;
    while(p){
        if(p->data > max)
            max = p->data;
        p=p->next;
    }
    return max;
}
long long max_r(struct Node *p){
    long long x = -92233720368547758;
    if(!p)return -92233720368547758;
    x = max(p->next);
    return x > p->data ? x : p->data;
}
struct Node * linear_search(struct Node *p, int key){
    struct Node *q;
    while(p){
        if(key==p->data){
            if(p->next == NULL){
                last = q;
            }
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}
struct Node * linear_search_r(struct Node *p, int key){
    if(p==NULL)
        return NULL;
    if(key == p->data)
        return p;
    return linear_search(p->next, key);
}
void Insertion(struct Node *p, int pos, int key){
    if(pos < 0)return;
    struct Node *t;
    if(pos == 0){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->next =  first ? first->next : NULL;
        first = t;
    }
    else{
        p = first;
        for(int i = 0;i < pos-1 && p;i++){
            p=p->next;
        }
        if(!p)return;
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->next = p->next;
        if(p->next == NULL){
            last = t;
        }
        p->next=t;
    }
    return;
}
void InsertLast(int key){
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = key;
    t->next = NULL;
    if(first == NULL){
        first = t;
        last = t;
    }
    else{
        last->next = t;
        last = t;
    }
    return;
}
void InsertSorted(int key){
    struct Node *t, * q, *p;
    p = first;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = key;
    t->next = NULL;
    if(first == NULL){
        first = t;
        last = t;
    }
    else{
        while(p && p->data<key){
            q=p;
            p=p->next;
        }
        if(p==first){
            if(first == last){
                last = t;
            }
            t->next=first;
            first = t;
        }
        else{
            if(p == NULL)last = t;
            t->next = q->next;
            q->next = t;
        }
    }
}
int Delete(struct Node *first_p, int index){
    struct Node *q, *p;
    p = first_p;
    int x=-1, i;
    if(index < 0)return 0;
    if(index == 0){
        p = first;
        x=first->data;
        first = first->next;
        free(p);
        return x;
    }
    else{
        p = first;
        q=NULL;
        for(i = 0;i < index && p;i++){
            q=p;
            p = p->next;
        }
        if(!p)
            return -1;
        q->next = p->next;
        x=p->data;
        if(p->next == NULL)last = q;
        free(p);
        return x;
    }
}
int is_sorted(struct Node *p){
    int x = -99999999;
    while(p){
        if(x > p->data)
            return 0;
        x= p->data;
        p=p->next;
    }
    return 1;
}
void remove_dup(struct Node *a){
    struct Node *p, *q;
    p = a;
    q = p->next;
    while(q){
        if(q->data != p->data){
            p=q;
            q=q->next;
        }
        else{
            p->next = q->next;
            free(q);
            q=p->next;
            if(q==NULL)last=p;
        }
    }
    return;
}
void Reverse(struct Node *a){ //sliding pointers method
    struct Node *p, *q, *r;
    p = a;
    q=NULL;
    r=NULL;
    while(p){
        r=q;
        q=p;
        p=p->next;
        q->next = r ;
    }
    first = q;
}
void concatenate(struct Node *a, struct Node *b){
    third = a;
    while(a->next){
        a=a->next;
    }
    a->next = b;
    return;
}
void Merge(struct Node *a, struct Node *b){
    if(a->data < b->data){
        third=last=a;
        a=a->next;
        third->next = NULL;
    }
    else{
        third=last=b;
        b=b->next;
        third->next = NULL;
    }
    while(a && b){
        if(a->data < b->data){
            last->next = a;
            last = a;
            a=a->next;
            last->next = NULL;
        }
        else{
            last->next = b;
            last = b;
            b=b->next;
            last->next = NULL;
        }
    }
    if(a)last->next = a;
    if(b)last->next = b;
}
int isLoop(struct Node *p){
    struct Node *a, *b;
    a=b=p;
    do{
        a = a->next;
        b=b->next;
        if(b)b=b->next;
    }
    while(a && b && a != b);
    if(a == b)return 1;
    return 0;
}
/*
int main(){
    struct Node *t1, *t2;
    int A[]={3, 5,7,10, 12,15};
    int B[]={4,9,12,45,68};
    Create(A,6);
    middle_node();
}
*/