#include "Stack_Array.c"

int pre(char x){
    if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
    return 0;
}
int isOperand(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/'){
        return 0;
    }
    return 1;
}

char *InfixToPostfix(char *infix){
    char *postfix;
    Stack *st = create(500);
    push(st, '#');
    int len = strlen(infix);
    postfix = (char *)malloc(sizeof(char)*(len + 2)); // no check here, should be added
    int i = 0, j = 0;
    while(infix[i] != '\0'){
        if(isOperand(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(pre(infix[i]) > pre(stackTop(st))){
                push(st, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(st);
                j++;
            }
        }
    }

    while(!isEmpty(st)){
        postfix[j] = pop(st);
        j++;
    }
    postfix[--j] = '\0';
    return postfix;
}
int main(){
    printf("%s\n", InfixToPostfix("a+b*c-d/e"));

}