#include <stdio.h>
#include <stdlib.h>

// Functions:
// [x] Init
// [x] Insert
// [x] Add polynomials
// [x] Evaluate polynomial
// [x] Print

typedef struct{
    int coeff;
    int exp;
    struct Node *next;
}Node;

Node * InsertNode(int coeff, int exp, Node *first){
    if(!first){
        first = (Node *)malloc(sizeof(Node));
        first->coeff = coeff;
        first->exp = exp;
        first->next = NULL;
        return first;
    }
    else if(first->exp > exp){
        Node *inserted_first = (Node *)malloc(sizeof(Node));
        inserted_first->coeff = coeff;
        inserted_first->exp = exp;
        inserted_first->next = (struct Node *)first;
        first = inserted_first;
        return first;
    }
    Node *prev = first;
    while(first && first->exp < exp){
        if(first->exp == exp){
            return NULL;
        }
        if(first->next != NULL){
            prev = first;
            first = (Node *)first->next;
        }
        else 
            break;
    }
    if(first->exp == exp){
        return NULL;
    }
    if(first->exp > exp){
        Node *inserted = (Node *)malloc(sizeof(Node));
        inserted->coeff = coeff;
        inserted->exp = exp;
        inserted->next = prev->next;
        prev->next = (struct Node *)inserted;
        return NULL;
    }
    else{
        Node *inserted_last = (Node *)malloc(sizeof(Node));
        inserted_last->coeff = coeff;
        inserted_last->exp = exp;
        inserted_last->next = first->next;
        first->next = (struct Node *)inserted_last;
        return NULL;
    }    
}

Node * init(int coeff[], int n, int exp[], int m){
    if(n != m || m < 1){
        return NULL;
    }
    Node *first = NULL;
    int index = 0;
    while(index < n){
        Node *temporary = InsertNode(coeff[index], exp[index], first);
        if(temporary){
            first = temporary;
        }
        index++;
    }
    return first;
}

void Print(Node *first){
    while(first){
        printf("%d*x^%d ", first->coeff, first->exp);
        first = (Node *)first->next;
    }
    printf("\n");
    return;
}

double pow(double base, double exp){
    if(exp < 0)
        return -1;
    double result = 1;
    for(int i = 0; i < exp; ++i){
        result *= base;
    }
    return result;
}

double EvaluatePolynomial(double x, Node *first){
    double sum = 0;
    while(first){
        sum += first->coeff * pow(x, first->exp);
        first = first->next;
    }
    return sum;
}

Node * AddPolynomials(Node *first, Node *second){
    Node *new = NULL;
    while(first && second){
        if(first->exp == second->exp){
            Node *temporary = InsertNode(first->coeff + second->coeff, first->exp, new);
            if(temporary)
                new = temporary;
            first = (Node *)first->next;
            second = (Node *)second->next;
        }
        else if(first->exp > second->exp){
            Node *temporary = InsertNode(second->coeff, second->exp, new);
            if(temporary)
                new = temporary;
            second = (Node *)second->next;
        }
        else{
            Node *temporary = InsertNode(first->coeff, first->exp, new);
            if(temporary)
                new = temporary;
            first = (Node *)first->next;
        }
    }
    while(first){
        Node *temporary = InsertNode(first->coeff, first->exp, new);
        if(temporary)
            new = temporary;
        first = (Node *)first->next;
    }
    while(second){
        Node *temporary = InsertNode(second->coeff, second->exp, new);
        if(temporary)
            new = temporary;
        second = (Node *)second->next;
    }
    return new;
}

int main(){
    int exponents[] = {9, 5, 3, 2};
    int exponents2[] = {2, 5, 3 ,7};
    int coefficients[] = {1, -5, 3, 4};
    int n = 4;
    Node *first = init(coefficients, n, exponents, n);
    Print(first);
    Node *second = init(coefficients, n, exponents2, n);
    Print(second);
    Node *new = AddPolynomials(first, second);
    Print(new);
}