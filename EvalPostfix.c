#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int size;
    int top;
    int *s;
}Stack;

Stack * create(int size){
    if(size > 0){
        Stack *st = (Stack *)malloc(sizeof(Stack));
        if(!st)
            return 0;

        st->top = -1;
        st->size = size;
        st->s = (char *)malloc(sizeof(sizeof(int))*size);
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
        printf("%d ", st->s[i]);
    }
    printf("\n");
    return;
}

void push(Stack *st, int x){
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

int pop(Stack *st){
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

int peek(Stack *st, int pos){
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

int stackTop(Stack *st){
    return st->top != -1 ? st->s[st->top] : 0;
}


int isOperand(char a){
    if(a == '/' || a == '+' || a == '-' || a == '*')
        return 0;
    return 1;
}

int Eval(char* postfix){
    Stack *st;
    st = create(200);
    int i, x1, x2, r;
    for(int i = 0; postfix[i] != '\0'; ++i){
        if(isOperand(postfix[i])){
            push(st, postfix[i] - '0');
        }
        else{
            x2 = pop(st);
            x1 = pop(st);
            switch(postfix[i]){
                case '+': r = x1 + x2; push(st, r); break;
                case '-': r = x1 - x2; push(st, r); break;
                case '*': r = x1 * x2; push(st, r); break;
                case '/': r = x1 / x2; push(st, r); break;
            }
        }
    }
    return pop(st);
}
int main(){
    char *postfix = "234*+82/-";
    printf("%d\n", Eval(postfix));
}