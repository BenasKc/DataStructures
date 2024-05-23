#include <stdio.h>

struct Node{
    int data;
    struct Node * next;
}*head;
void create(int A[], int n){
    struct Node *t, *last;
    head=(struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    last=head;
    for(int i = 1;i < n;++i){
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
void Display(struct Node *p){
    do{
        printf("%d ", p->data);
        p=p->next;
    }
    while(p!=head);
    printf("\n");
}
void Display_r(struct Node *p){
    static int flag = 0;
    if(p != head || flag == 0){
        flag = 1;
        printf("%d ", p->data);
        Display_r(p->next);
    }
    flag = 0;
}
void Insert(struct Node *p, int pos, int data){
    struct Node *t;
    if(pos == 0){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = data;
            if(head == NULL){
                head = t;
                head->next = t;
            }
            else{
                while(p->next != head){
                    p=p->next;
                }
                p->next = t;
                t->next = head;
                head = t;
            }
    }
    else{
        for(int i = 0;i < pos - 1;++i)p=p->next;
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = data;
        t->next = p->next;
        p->next = t;
    }
}
void delete(struct Node *p, int index){
    if(1); // foolproof the index
    struct Node *q;
    if(index == 0){
        while(p->next != head)
            p=p->next;
        q=p->next;
        p->next = q->next;
        free(q);
        head = p->next;
    }
    else{
        for(int i = 0;i < index - 1;++i)
            p=p->next;
        q=p->next;
        p->next = q->next;
        free(q);
    }
}
int main(){
    int A[] = {2, 3, 4 ,5 ,6};
    create(A, 5);
    Insert(head, 2, 8);
    delete(head, 5);
    Display_r(head);
}
