#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int size;
    int top;
    char *s;
}Stack;

Stack * create(int size){
    if(size > 0){
        Stack *st = (Stack *)malloc(sizeof(Stack));
        if(!st)
            return 0;

        st->top = -1;
        st->size = size;
        st->s = (char *)malloc(sizeof(sizeof(char))*size);
        if(!st)
            return 0;
        return st;
    }
    else{
        return 0;
    }
}

void Display(Stack *st){
    for(int i = st->top; i >= 0; --i){
        printf("%c ", st->s[i]);
    }
    printf("\n");
    return;
}

void push(Stack *st, char x){
    if(st->top >= st->size - 1){
        printf("Stack overflow\n");
        return;
    }
    else{
        st->top++;
        st->s[st->top] = x;
    }
    return;
}

char pop(Stack *st){
    int x=-1;
    if(st->top==-1){
        printf("Stack overflow");
        // here should be some error handling 
    }
    else{
        x = st->s[st->top--];
    }
    return x;
}

char peek(Stack *st, int pos){
    int x = -1;
    if(st->top - pos + 1 < 0){
        printf("Invalid position\n");
    }
    else{
        x = st->s[st->top - pos + 1];
    }
    return x;
}

int isEmpty(Stack *st){
    return st->top == -1 ? 1 : 0;
}

int isFull(Stack *st){
    return st->top == st->size - 1 ? 1 : 0;
}

char stackTop(Stack *st){
    return st->top != -1 ? st->s[st->top] : 0;
}

/*
int main(){
    Stack *st;
    st = create(2);
    push(st, 20);
    push(st, 15);
    int m = pop(st);
    Display(st);
    push(st, 25);
    printf("%d\n", peek(st,1 ));
    Display(st);
}
*/