#include <stdio.h>
#include <string.h>
#include "Stack_Array.c"

int isBalanced(char *exp){
    struct Stack *st = create(strlen(exp));
    char *temp = malloc(strlen(exp));
    strcpy(temp, exp);
    for(int i = 0; exp[i] != '\0'; ++i){
        if(exp[i] == '(')
            push(st, '(');
        else if(exp[i] == ')'){
            if(isEmpty(st))
                return 0;
            pop(st);
        }
    }
    if(!isEmpty(st))
        return 0;
    return 1;
}
int main(){
    char *str = "((a+b)*(c-d))";
    printf("%d\n", isBalanced(str));
}