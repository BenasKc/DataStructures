#include <stdio.h>

struct term{
    int coef;
    int exp;
};
struct poly{
    int n;
    struct term *t;
};
void create(struct poly * a){
    printf("Enter the number of terms:\n");
    scanf("%d", &(*a).n);
    (*a).t = (struct term *)malloc(sizeof(struct term)*(*a).n);
    for(int i = 0;i < (*a).n;i++){
        printf("Coefficient and exponent, number %d\n", i+1);
        scanf("%d %d", &(*a).t[i].coef, &(*a).t[i].exp);
    }
    return;
}
void display(struct poly *a){
    for(int i = 0;i < (*a).n;i++){
        if((*a).t[i].coef != 0)
            printf("+(%d*x^%d) ", (*a).t[i].coef, (*a).t[i].exp);
    }
    printf("\n\n");
    return;
}
struct poly add(struct poly *a, struct poly *b){
    int i = 0, j = 0, k = 0;
    struct poly c;
    c.t = (struct term *)malloc(sizeof(struct term)*((*a).n+(*b).n));
    c.n = (*a).n + (*b).n;
    while(i < (*a).n && j < (*b).n){
        if((*a).t[i].exp > (*b).t[j].exp){
            (c).t[k++] = (*a).t[i++];
        }
        else if((*a).t[i].exp < (*b).t[j].exp){
            (c).t[k++] = (*b).t[j++];
        }
        else {
            (c).t[k].exp = (*a).t[i].exp;
            (c).t[k++].coef = (*b).t[j++].coef + (*a).t[i++].coef;
        }
    }
    while(i < (*a).n){
        (c).t[k++] = (*a).t[i++];
    }
    while(j < (*b).n){
        (c).t[k++] = (*b).t[j++];
    }
    return c;
}
int main(){
    struct poly a, b, c;
    create(&a);
    create(&b);
    display(&a);
    display(&b);
    c = add(&a, &b);
    display(&c);
}
